#include "Player.h"
#include "Engine.h"
#include "Renderer/Renderer.h" 
#include "Input/InputSystem.h"

#include <iostream>

void Player::Update(float dt){
   
    float rotate = 0;
    if (fox::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_A)) rotate = -1;
    if (fox::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_D)) rotate = +1;
    
	transform.rotation += (rotate * rotateRate) * dt;

    float thrust = 0;
	if (fox::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_W)) thrust = +1;

    fox::vec2 direction{ 1, 0 };
	fox::vec2 force = direction.Rotate(fox::math::degToRad(transform.rotation)) * thrust * speed;
    velocity += force * dt;

	transform.position.x = fox::math::wrap(transform.position.x, 0.0f, (float)fox::GetEngine().GetRenderer().GetWidth());
    transform.position.y = fox::math::wrap(transform.position.y, 0.0f, (float)fox::GetEngine().GetRenderer().GetHeight());

    if (fox::GetEngine().GetInput().GetKeyPressed(SDL_SCANCODE_SPACE)) {

    }

	Actor::Update(dt);
}
