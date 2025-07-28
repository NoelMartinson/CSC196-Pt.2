#include "SpaceGame.h"
#include "Math/Vector2.h"
#include "Renderer/Model.h" 
#include "Renderer/Renderer.h"
#include "Core/Random.h" 
#include "Player.h"
#include "Framework/Scene.h"
#include "Engine.h"


#include <vector>
#include <memory>

bool SpaceGame::Initialize() {

    m_scene = std::make_unique<fox::Scene>();

    std::vector<fox::vec2> points = {
        {  5,  0 },
        { -4, -3 },
        { -2,  0 },
        { -4,  3 },
        {  5,  0 }

       /* { -3, 0  },
        {  3, 0  },
        {  0, 2  },
        { -3, 0  },
        { -2,-2  },
        {  0, 0  },
        {  2,-2  },
        {  3, 0  }*/
    };

    std::shared_ptr<fox::Model>model = std::make_shared < fox::Model>(points, fox::vec3{ 0.0f,0.4f,1.0f });

    fox::Transform transform{ fox::vec2{ fox::GetEngine().GetRenderer().GetWidth() * 0.5f, fox::GetEngine().GetRenderer().GetHeight() * 0.5f}, 0, 5};
    std::unique_ptr<Player> player = std::make_unique<Player>(transform, model);
    m_scene->AddActor(std::move(player));

    //for (int i = 0; i < 10; i++) {
    //    fox::Transform transform{ fox::vec2{fox::random::getRandomFloat() * 1280, fox::random::getRandomFloat() * 1024 }, 0, 10 };
    //    std::unique_ptr<Player> player = std::make_unique<Player>(transform, model);
    //    m_scene->AddActor(std::move(player));
    //}

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
