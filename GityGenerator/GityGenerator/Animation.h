#pragma once
#include <SFML\Graphics.hpp>
#include <vector>

class Animation
{
public:
	enum class AnimationType {
		Once,
		Loop,
		PingPong
	};

	Animation();
	~Animation();

	void AddFrame(sf::IntRect rect);
	void SetFrameSpeed(float speed);
	int GetSize();

	//update/reset animation
	void Animate(float dt);
	void Reset();

	//Get current frame of animation
	sf::IntRect GetCurrentFrame();

	//Animation controls
	float GetFrameSpeed() { return animationSpeed; };
	void SetFlipped(bool flip) { flipped = flip; };
	bool GetFlipped() { return flipped; };
	void SetLooping(bool loop) { isLooping = loop; };
	bool GetLooping() { return isLooping; };
	void SetPlaying(bool play) { isPlaying = play; };
	bool GetPlaying() { return isPlaying; };
	void SetAnimationType(AnimationType animType);


protected:
	std::vector<sf::IntRect>	frames;
	sf::IntRect					frame;
	int							currentFrame;
	float						animationSpeed;
	bool						flipped;
	bool						isLooping;
	bool						isPlaying;
	float						elapsedTime;
	AnimationType				animationType;
};

