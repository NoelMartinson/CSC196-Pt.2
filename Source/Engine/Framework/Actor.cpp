#include "Actor.h"
#include "../Renderer/Model.h"

namespace fox {
	void fox::Actor::Update(float dt) {
		transform.position += velocity * dt;
		velocity *= (1.0f / (1.0f + dampening * dt));
	}

	void fox::Actor::Draw(Renderer& renderer) {
		model->Draw(renderer, transform);
	}
}