#pragma once
#include "Framework/Game.h"
#include "Renderer/Font.h"
#include "Renderer/Text.h"

class SpaceGame : public fox::Game {
public:
	enum class GameState {
		Initalize,
		Title,
		StartGame,
		StartRound,
		Game,
		PlayerDead,
		GameOver,
	};

public:
	SpaceGame() = default;

	bool Initialize() override;
	void Update(float dt) override;
	void Shutdown() override;
	void Draw() override;


private:
	GameState gameState = GameState::Initalize;
	float enemySpawnTimer{ 0 };

	std::shared_ptr<class fox::Font> titleFont;
	std::shared_ptr<class fox::Font> uiFont;

	std::unique_ptr<class fox::Text> titleText;
	std::unique_ptr<class fox::Text> scoreText;
	std::unique_ptr<class fox::Text> livesText;
};