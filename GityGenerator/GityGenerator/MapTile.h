#pragma once
#include "GSprite.h"

class MapTile : public GSprite
{
public:
	enum class Edge {
		UP		= 0,
		RIGHT	= 1,
		DOWN	= 2,
		LEFT	= 3
	};
	enum class EdgeType {
		OFF,
		SOLID
	};

	MapTile();
	~MapTile();

	void SetEdges(EdgeType u, EdgeType d, EdgeType l, EdgeType r) {
		eU = u;
		eD = d;
		eL = l;
		eR = r;
	};
	
	Line GetEdge(MapTile::Edge edge);

	bool IsSolid(Edge edge) {
		switch (edge) {
			case Edge::UP:
				return eU == EdgeType::SOLID;
				break;
			case Edge::RIGHT:
				return eR == EdgeType::SOLID;
				break;
			case Edge::DOWN:
				return eD == EdgeType::SOLID;
				break;
			case Edge::LEFT:
				return eL == EdgeType::SOLID;
				break;
		}
	};

protected:
	EdgeType eU, eD, eL, eR;

};

