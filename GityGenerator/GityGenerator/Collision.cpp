#include "Collision.h"

// check AABB
bool Collision::CheckBoundingBox(GSprite* s1, GSprite* s2)
{
	if (s1->GetCollisionBox().left + s1->GetCollisionBox().width < s2->GetCollisionBox().left)
		return false;
	if (s1->GetCollisionBox().left > s2->GetCollisionBox().left + s2->GetCollisionBox().width)
		return false;
	if (s1->GetCollisionBox().top + s1->GetCollisionBox().height < s2->GetCollisionBox().top)
		return false;
	if (s1->GetCollisionBox().top > s2->GetCollisionBox().top + s2->GetCollisionBox().height)
		return false;

	return true;
}

// check AABB with Overlap
sf::Vector2f Collision::CheckBoundingBoxOverlap(GSprite* s1, GSprite* s2)
{
	sf::Vector2f overlap;
	//To the right
	if (s1->GetCollisionBox().left + (s1->GetCollisionBox().width*0.5f) > s2->GetCollisionBox().left + (s2->GetCollisionBox().width*0.5f)) {
		overlap.x = s1->GetCollisionBox().left  -( s2->GetCollisionBox().left + (s2->GetCollisionBox().width));
	}
	else
	{
		overlap.x =( s1->GetCollisionBox().left + s1->GetCollisionBox().width) - s2->GetCollisionBox().left;
	}

	//Below
	if (s1->GetCollisionBox().top + (s1->GetCollisionBox().height*0.5f) > s2->GetCollisionBox().top + (s2->GetCollisionBox().height*0.5f)) {
		overlap.y = s1->GetCollisionBox().top - (s2->GetCollisionBox().top + (s2->GetCollisionBox().height));
	}
	else
	{
		overlap.y = (s1->GetCollisionBox().top + s1->GetCollisionBox().height) - s2->GetCollisionBox().top;
	}

	return overlap;
}
// check Sphere bounding collision
bool Collision::CheckBoundingSphere(GSprite* s1, GSprite* s2)
{
	// Get radius and centre of sprites.
	float radius1 = s1->getSize().x / 2;
	float radius2 = s2->getSize().x / 2;
	float xpos1 = s1->getPosition().x + radius1;
	float xpos2 = s2->getPosition().x + radius2;
	float ypos1 = s1->getPosition().y + radius1;
	float ypos2 = s2->getPosition().y + radius2;

	if (pow(xpos2 - xpos1, 2) + pow(ypos2 - ypos1, 2) < pow(radius1 + radius2, 2))
	{
		return true;
	}
	return false;
}

bool Collision::LineIntersect(Line a, Line b) {
	
	float x1 = a.startPoint.x;    // line controlled by mouse
	float y1 = a.startPoint.y;
	float x2 = a.endPoint.x;   // fixed end
	float y2 = a.endPoint.y;

	float x3 = b.startPoint.x;  // static line
	float y3 = b.startPoint.y;
	float x4 = b.endPoint.x;
	float y4 = b.endPoint.y;

	float uA = ((x4 - x3)*(y1 - y3) - (y4 - y3)*(x1 - x3)) / ((y4 - y3)*(x2 - x1) - (x4 - x3)*(y2 - y1));

	float uB = ((x2 - x1)*(y1 - y3) - (y2 - y1)*(x1 - x3)) / ((y4 - y3)*(x2 - x1) - (x4 - x3)*(y2 - y1));

	if (uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1) {
		std::cout << "Intersect\n";
		return true;
	}
	printf("No Intersect\n");
	return false;
}

bool Collision::LineIntersect(Line a, Line b, sf::Vector2f& point) {

	float x1 = a.startPoint.x;    // line controlled by mouse
	float y1 = a.startPoint.y;
	float x2 = a.endPoint.x;   // fixed end
	float y2 = a.endPoint.y;

	float x3 = b.startPoint.x;  // static line
	float y3 = b.startPoint.y;
	float x4 = b.endPoint.x;
	float y4 = b.endPoint.y;

	float uA = ((x4 - x3)*(y1 - y3) - (y4 - y3)*(x1 - x3)) / ((y4 - y3)*(x2 - x1) - (x4 - x3)*(y2 - y1));

	float uB = ((x2 - x1)*(y1 - y3) - (y2 - y1)*(x1 - x3)) / ((y4 - y3)*(x2 - x1) - (x4 - x3)*(y2 - y1));


	if (uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1) {

		float intersectionX = x1 + (uA * (x2 - x1));
		float intersectionY = y1 + (uA * (y2 - y1));

		point = sf::Vector2f(intersectionX, intersectionY);
		return true;
	}
	printf("No Intersect\n");
	return false;
}

bool Collision::Contains(GSprite* s1, const sf::Vector2f point) {
	bool inX = false;
	bool inY = false;
	if (point.x > s1->GetCollisionBox().left && point.x < (s1->GetCollisionBox().left + s1->GetCollisionBox().width))
		inX = true;

	if (point.y > s1->GetCollisionBox().top && point.y < (s1->GetCollisionBox().top + s1->GetCollisionBox().height))
		inY = true;

	return (inX && inY);
}

bool Collision::LineSpriteIntersect(GSprite* s1, Line A) {
	bool ret = false;

	for (int i = 0; i < 4; i++) {
		Line l = s1->GetEdge(i);
		if (LineIntersect(A, l)) {
			return true;
		}
	}
	return false;
}


bool Collision::LineMapIntersect(MapTile* s1, Line A) {
	bool ret = false;
	if (s1->IsSolid(MapTile::Edge::UP)) {
		ret = ret || LineIntersect(A, s1->GetEdge(MapTile::Edge::UP));
	}
	if (s1->IsSolid(MapTile::Edge::RIGHT)) {
		ret = ret || LineIntersect(A, s1->GetEdge(MapTile::Edge::RIGHT));
	}
	if (s1->IsSolid(MapTile::Edge::DOWN)) {
		ret = ret || LineIntersect(A, s1->GetEdge(MapTile::Edge::DOWN));
	}
	if (s1->IsSolid(MapTile::Edge::LEFT)) {
		ret = ret || LineIntersect(A, s1->GetEdge(MapTile::Edge::LEFT));
	}
	return ret;
}

bool Collision::LineMapIntersect(MapTile* s1, Line A, HitInfo& info) {
	bool ret = false;
	sf::Vector2f p;
	if (s1->IsSolid(MapTile::Edge::UP)) {
		if (LineIntersect(A, s1->GetEdge(MapTile::Edge::UP), p)) {
			ret = true;
			info.point = p;
		}		
	}
	if (s1->IsSolid(MapTile::Edge::RIGHT)) {
		if (LineIntersect(A, s1->GetEdge(MapTile::Edge::RIGHT), p)) {
			ret = true;
			info.point = p;
		}
	}
	if (s1->IsSolid(MapTile::Edge::DOWN)) {
		if (LineIntersect(A, s1->GetEdge(MapTile::Edge::DOWN), p)) {
			ret = true;
			info.point = p;
		}
	}
	if (s1->IsSolid(MapTile::Edge::LEFT)) {
		if (LineIntersect(A, s1->GetEdge(MapTile::Edge::LEFT), p)) {
			ret = true;
			info.point = p;
		}
	}
	info.point = p;

	return ret;
}