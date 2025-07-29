#pragma once
#include <memory>

namespace fox {
	class Game {
	public:
		Game() = default;

		virtual bool Initialize() = 0;

		virtual void Update() = 0;

		virtual void Shutdown() = 0;

		virtual void Draw() = 0;
	protected:
		int score{ 0 };
		int lives{ 0 };

		std::unique_ptr<class Scene> m_scene;
	};
}