#include "SpaceGame.h"
#include "Math/Vector2.h"
#include "Renderer/Model.h" 
#include "Renderer/Renderer.h"
#include "Core/Random.h" 
#include "Player.h"
#include "Enemy.h"
#include "Framework/Scene.h"
#include "Engine.h"


#include <vector>
#include <memory>

bool SpaceGame::Initialize() {

    m_scene = std::make_unique<fox::Scene>();

    std::vector<fox::vec2> PlayerPoints = {
        {  5,  0 },
        { -4, -3 },
        { -2,  0 },
        { -4,  3 },
        {  5,  0 }
       
    };

    std::vector<fox::vec2> enemyPoints = {
        { -2, -1 },
        { -1, -2 },
        { 1, -2 },
        { 2, -1 },
        { 6, 0 },
        { 2, 1 },
        { 1, 2 },
        { -1, 2 },
        { -2, 1 },
        { -6, 0 },
        { -2, -1 },
    };

    // Player
    std::shared_ptr<fox::Model>model = std::make_shared < fox::Model>(PlayerPoints, fox::vec3{ 1,1,1 });
    fox::Transform transform{ fox::vec2{ fox::GetEngine().GetRenderer().GetWidth() * 0.5f, fox::GetEngine().GetRenderer().GetHeight() * 0.5f}, 0, 5};
    std::unique_ptr<Player> player = std::make_unique<Player>(transform, model);
    player->speed = 1500.0f;
    player->rotateRate = 180.0f;
    player->dampening = 1.5f;
	player->name = "player";

    m_scene->AddActor(std::move(player));

    //Enemy
    std::shared_ptr<fox::Model>enemyModel = std::make_shared < fox::Model>(enemyPoints, fox::vec3{ 1,1,0 });
    for (int i = 0; i < 10; i++) {
        fox::Transform transform{ fox::vec2{fox::random::getRandomFloat() * 1280, fox::random::getRandomFloat() * 1024 }, 0, 5 };
        std::unique_ptr<Enemy> enemy = std::make_unique<Enemy>(transform, enemyModel);
        enemy->dampening = 1.5f;
		enemy->speed = (fox::random::getRandomFloat() * 800) + 500;
        m_scene->AddActor(std::move(enemy));
    }

    return true;
}

    void SpaceGame::Update() {
        m_scene->Update(fox::GetEngine().GetTime().GetDeltaTime());
    }

    void SpaceGame::Shutdown() {
        
    }

    void SpaceGame::Draw() {
        m_scene->Draw(fox::GetEngine().GetRenderer());
    }
