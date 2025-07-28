#include "Actor.h"
#include "../Renderer/Model.h"

namespace fox {
	void fox::Actor::Update(float dt) {
		transform.position += velocity * dt;
	}

	void fox::Actor::Draw(Renderer& renderer) {
		model->Draw(renderer, transform);
	}
}