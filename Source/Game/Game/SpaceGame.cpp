#include "SpaceGame.h"
#include "Math/Vector2.h"
#include "Renderer/Model.h" 
#include "Core/Random.h" 
#include "Player.h"
#include "Framework/Scene.h"
#include "Engine.h"


#include <vector>
#include <memory>

bool SpaceGame::Initialize() {

    m_scene = std::make_unique<fox::Scene>();

    std::vector<fox::vec2> points = {
        /*{ -5, -5 },
        {  5, -5 },
        {  5,  5 },
        { -5,  5 },
        { -5, -5 }*/

        { -3, 0  },
        {  3, 0  },
        {  0, 2  },
        { -3, 0  },
        { -2,-2  },
        {  0, 0  },
        {  2,-2  },
        {  3, 0  }
    };

    std::shared_ptr<fox::Model>model = std::make_shared < fox::Model>(points, fox::vec3{ 1,1,1, });

    for (int i = 0; i < 1; i++) {
        //fox::Transform transform{ fox::vec2{fox::random::getRandomFloat() * 1280, fox::random::getRandomFloat() * 1024 }, 0, 10 };
        fox::Transform transform{ fox::vec2{1280/2, 1024/2}, 0, 20 };
        std::unique_ptr<Player> player = std::make_unique<Player>(transform, model);
        m_scene->AddActor(std::move(player));
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
