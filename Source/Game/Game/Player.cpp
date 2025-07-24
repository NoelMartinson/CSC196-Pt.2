#include "Player.h"
#include "Engine.h"
#include "Input/InputSystem.h"

#include <iostream>

void Player::Update(float dt){
    float speed = 200;

    fox::vec2 direction{ 0, 0 };
    if (fox::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_W)) direction.y = -1;
    if (fox::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_A)) direction.x = -1; //speed * time.GetDeltaTime();
    if (fox::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_S)) direction.y = 1; //speed * time.GetDeltaTime();
    if (fox::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_D)) direction.x = 1; //speed * time.GetDeltaTime();

    if (direction.LengthSquare() > 0) {
        direction = direction.Normalized();  
        transform.position += (direction * speed) * dt;
    }
}
