#pragma once
#include "Framework/Actor.h"
#include "Math/Transform.h"

class Player : public fox::Actor {
public:
	Player() = default;
	Player(const fox::Transform& transform, std::shared_ptr<fox::Model> model) :
		Actor{ transform, model }
	{};

	void Update(float dt) override;
private:

};