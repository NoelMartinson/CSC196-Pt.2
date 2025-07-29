#pragma once
#include "Framework/Game.h"

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
};