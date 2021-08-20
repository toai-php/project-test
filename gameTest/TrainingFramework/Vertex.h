#pragma once
#include "../Utilities/Math.h"

struct Vertex
{
	Vertex();
	Vertex(const Vertex &v);
	Vector3 pos;
	Vector2 uv;

};