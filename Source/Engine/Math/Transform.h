#pragma once
#include "Vector2.h"

namespace fox {
	struct Transform {
		vec2 position{ 0, 0 };
		float roatation = 0;
		float scale = 1;

		Transform() = default;
		Transform(const vec2& position, float rotation = 0, float scale = 1) :
			position(position),
			roatation(rotation),
			scale(scale)
		{}
	};
}