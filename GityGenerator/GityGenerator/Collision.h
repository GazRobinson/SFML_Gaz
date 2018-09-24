#pragma once
#include "MapTile.h"
#include "structs.h"
#include <iostream>

// Static class provide collision detection functions.


class Collision
{
public:
	//AABB
	static bool CheckBoundingBox(GSprite* sp1, GSprite* sp2);
	//AABB w/ Overlap
	static sf::Vector2f CheckBoundingBoxOverlap(GSprite* s1, GSprite* s2);
	// Bounding circle
	static bool CheckBoundingSphere(GSprite* sp1, GSprite* sp2);

	static bool Contains( GSprite* s1, const sf::Vector2f point);

	static bool LineIntersect(Line a, Line b);
	static bool LineIntersect(Line a, Line b, sf::Vector2f& point);

	static bool LineSpriteIntersect(GSprite* s1, Line A);

	static bool LineMapIntersect(MapTile* s1, Line A);
	static bool LineMapIntersect(MapTile* s1, Line A, HitInfo& info);
};