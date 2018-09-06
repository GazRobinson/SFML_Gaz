#include "Animation.h"



Animation::Animation()
{
	currentFrame = 0;
	elapsedTime = 0;
	isPlaying = true;
	isLooping = true;
}


Animation::~Animation()
{
}

void Animation::AddFrame(sf::IntRect rect) {
	frames.push_back(rect);
}

int Animation::GetSize() {
	return frames.size();
}

sf::IntRect Animation::GetCurrentFrame() {
	frame = frames[currentFrame];
	if (flipped) {
		frame = sf::IntRect(frame.left + frame.width, frame.top, -frame.width, frame.height);
	}
	return frame;
}

void Animation::Animate(float dt) {
	if (isPlaying) {
		elapsedTime += dt;
		if (elapsedTime >= animationSpeed) {
			currentFrame++;
			if (currentFrame >= (int)frames.size()) {
				if (isLooping) {
					currentFrame = 0;
				}
				else {
					currentFrame--;
				}
			}
			elapsedTime = 0;
		}
	}
}

void Animation::Reset() {
	currentFrame = 0;
	elapsedTime = 0;
}

void Animation::SetFrameSpeed(float speed) {
	animationSpeed = speed;
}