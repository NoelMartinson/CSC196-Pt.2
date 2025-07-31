#include "Math/Math.h"
#include "Math/Vector2.h"
#include "Math/Vector3.h"
#include "Math/Transform.h"
#include "Core/Time.h"
#include "Core/Random.h"
#include "Renderer/Renderer.h"
#include "Renderer/Model.h"
#include "Input/InputSystem.h"
#include "Audio/AudioSystem.h"
#include "Framework/Actor.h"
#include "Framework/Scene.h"
#include "Engine.h"
#include "Renderer/Text.h"
#include "Renderer/Font.h"

#include "Game/Player.h"
#include "Game/SpaceGame.h"

#include <iostream>
#include <vector>
#include <fmod.hpp>
#include <memory>

int main(int argc, char* argv[]) {

	// Initize Engine   
    fox::GetEngine().Initialize();

    // Initialize Game
	std::unique_ptr<fox::Game> game = std::make_unique<SpaceGame>();
	game->Initialize();

	// Load a sound file
	fox::GetEngine().GetAudio().AddSound("bass.wav", "bass");
    fox::GetEngine().GetAudio().AddSound("snare.wav", "snare");
    fox::GetEngine().GetAudio().AddSound("open-hat.wav", "hihat");

    // Create stars
	std::vector<fox::vec2> stars;
    for (int i = 0; i < 100; i++) {
        stars.push_back(fox::vec2{ fox::random::getReal() * 1280, fox::random::getReal() * 1024 });
    }

    //Load Font
	fox::Font* font = new fox::Font();
    font->Load("arcadeclassic.ttf", 20);

    SDL_Event e;
    bool quit = false;

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        fox::GetEngine().Update();
        game->Update(fox::GetEngine().GetTime().GetDeltaTime());

        if(fox::GetEngine().GetInput().GetKeyPressed(SDL_SCANCODE_ESCAPE)) {
            quit = true;
        }

        fox::GetEngine().GetInput().Update();
        fox::GetEngine().GetAudio().Update();

        /////////////////////////////////
        
        //Escape Key

        // draw
        fox::vec3 color{ 0,0,0 };
        fox::GetEngine().GetRenderer().SetColor(color.r, color.g, color.b);
        fox::GetEngine().GetRenderer().Clear();

        game->Draw();

        // Test getInt() variants
        std::cout << "Integer Functions:\n";
        std::cout << "getInt(): " << fox::random::getInt() << "\n";
        std::cout << "getInt(): " << fox::random::getInt() << "\n";
        std::cout << "getInt(10): " << fox::random::getInt(10) << "\n";
        std::cout << "getInt(10): " << fox::random::getInt(10) << "\n";
        std::cout << "getInt(5, 15): " << fox::random::getInt(5, 15) << "\n";
        std::cout << "getInt(5, 15): " << fox::random::getInt(5, 15) << "\n";
        std::cout << "getInt(-10, 10): " << fox::random::getInt(-10, 10) << "\n\n";

        // Test getReal() variants with float
        std::cout << "Float Functions:\n";
        std::cout << std::fixed << std::setprecision(6);
        std::cout << "getReal<float>(): " << fox::random::getReal<float>() << "\n";
        std::cout << "getReal<float>(): " << fox::random::getReal<float>() << "\n";
        std::cout << "getReal<float>(5.0f): " << fox::random::getReal<float>(5.0f) << "\n";
        std::cout << "getReal<float>(2.5f, 7.5f): " << fox::random::getReal<float>(2.5f, 7.5f) << "\n";
        std::cout << "getReal<float>(-1.0f, 1.0f): " << fox::random::getReal<float>(-1.0f, 1.0f) << "\n\n";

        // Test getReal() variants with double
        std::cout << "Double Functions:\n";
        std::cout << std::setprecision(10);
        std::cout << "getReal<double>(): " << fox::random::getReal<double>() << "\n";
        std::cout << "getReal<double>(100.0): " << fox::random::getReal<double>(100.0) << "\n";
        std::cout << "getReal<double>(0.0, 2.0): " << fox::random::getReal<double>(0.0, 2.0) << "\n\n";

        // Test getBool()
        std::cout << "Boolean Functions:\n";
        for (int i = 0; i < 10; ++i) {
            std::cout << "getBool(): " << std::boolalpha << fox::random::getBool() << "\n";
        }
        std::cout << "\n";

              
       ///////////////////////////////////

        fox::GetEngine().GetRenderer().Present();
    }
       
    game->Shutdown();
    game.release(); 
    fox::GetEngine().Shutdown();
    
   
    return 0;
};