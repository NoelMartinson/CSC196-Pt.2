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
#include "Core/File.h"

#include "Game/Player.h"
#include "Game/SpaceGame.h"

#include <iostream>
#include <vector>
#include <fmod.hpp>
#include <memory>

int main(int argc, char* argv[]) {

    std::cout << "Directory Operations:\n";
    std::cout << "Current directory: " << fox::file::GetCurrentDirectory() << "\n";

    // Set current directory path (current path + "Assets")
    std::cout << "Setting directory to 'Assets'...\n";
    fox::file::SetCurrentDirectory("Assets");
    std::cout << "New directory: " << fox::file::GetCurrentDirectory() << "\n\n";

    // Get filenames in the current directory
    std::cout << "Files in Directory:\n";
    auto filenames = fox::file::GetFilesInDirectory(fox::file::GetCurrentDirectory());
    for (const auto& filename : filenames) {
        std::cout << filename << "\n";
    }
    std::cout << "\n";

    // Get filename (filename.extension) only
    if (!filenames.empty()) {
        std::cout << "Path Analysis:\n";
        std::string filename = fox::file::GetFilename(filenames[0]);
        std::cout << "Filename only: " << filename << "\n";

        // Get extension only
        std::string ext = fox::file::GetExtension(filenames[0]);
        std::cout << "Extension: " << ext << "\n\n";
    }

    // Read and display text file
    std::cout << "Text File Reading:\n";
    std::string str;
    bool success = fox::file::ReadTextFile("test.txt", str);
    if (success) {
        std::cout << "Contents of test.txt:\n";
        std::cout << str << "\n";
    }
    else {
        std::cout << "Failed to read test.txt\n";
    }

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
              
       ///////////////////////////////////

        fox::GetEngine().GetRenderer().Present();
    }
       
    game->Shutdown();
    game.release(); 
    fox::GetEngine().Shutdown();
    
   
    return 0;
};