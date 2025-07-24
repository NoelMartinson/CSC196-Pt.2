#pragma once
#include "../Math/Vector2.h"
#include "../Math/Vector3.h"
#include "../Math/Transform.h"

#include <vector>

namespace fox {
	class Model {
	public:
		Model() = default;
		Model(const std::vector<vec2>& points, const vec3& color = { 1, 1, 1 })
			: points(points),
			color(color) 
		{}
	
		void Draw(class Renderer& renderer, const vec2& position,float rotation, float scale);
		void Draw(class Renderer& renderer, const Transform& transform);

	private:
		std::vector<vec2> points;
		vec3 color{ 1, 1, 1};
	};
}