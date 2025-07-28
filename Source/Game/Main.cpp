#include "Math/Math.h"
#include "Math/Vector2.h"
#include "Math/Vector3.h"
#include "Math/Transform.h"
#include "Core/Time.h"
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

    //Load Font
	fox::Font* font = new fox::Font();
    font->Load("arcadeclassic.ttf", 20);

    fox::Text* text = new fox::Text(font);
    text->Create(fox::GetEngine().GetRenderer(), "Hello World", fox::vec3{ 1, 1, 1});

    SDL_Event e;
    bool quit = false;

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        fox::GetEngine().Update();
        game->Update();

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

        text->Draw(fox::GetEngine().GetRenderer(), 40.0f, 40.0f);

        game->Draw();
              
       /////////////////////////////////////////////

        fox::GetEngine().GetRenderer().Present();
    }
       
    fox::GetEngine().Shutdown();
    
   
    return 0;
};