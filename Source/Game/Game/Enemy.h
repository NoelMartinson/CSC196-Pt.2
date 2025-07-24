#pragma once
#include "Framework/Actor.h"
#include "Math/Transform.h"

class Enemy : public fox::Actor {
public:
	Enemy() = default;
	Enemy(const fox::Transform& transform, std::shared_ptr<fox::Model> model) :
		Actor{ transform, model }
	{
	};

	void Update(float dt) override;
private:
};