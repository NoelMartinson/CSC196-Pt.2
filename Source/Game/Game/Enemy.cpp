#include "Enemy.h"
#include "Engine.h"
#include "Framework/Scene.h"
#include "Renderer/Renderer.h"

void Enemy::Update(float dt){
	
	Actor* player = scene->GetActorByName("player");
	if (player) {
		fox::vec2 direction{ 0, 0 };
		direction = player->transform.position - transform.position;
		direction = direction.Normalized();
		transform.roatation = fox::math::radToDeg(direction.Angle());
	}


	fox::vec2 force = fox::vec2{1,0}.Rotate(fox::math::degToRad(transform.roatation)) * speed;
	velocity += force * dt;

	transform.position.x = fox::math::wrap(transform.position.x, 0.0f, (float)fox::GetEngine().GetRenderer().GetWidth());
	transform.position.y = fox::math::wrap(transform.position.y, 0.0f, (float)fox::GetEngine().GetRenderer().GetHeight());

	Actor::Update(dt);
}
