#include "Scene.h"
#include "Actor.h"
#include "../Renderer/Renderer.h"
#include "../Core/StringHelper.h"

namespace fox {
	void Scene::Update(float dt){
		for (auto& actor : actors) {
			actor->Update(dt);
		}
	};

	void Scene::Draw(Renderer& renderer) {
		for (auto& actor : actors) {
			actor->Draw(renderer);
		}
	}
	void Scene::AddActor(std::unique_ptr<class Actor> actor)
	{
		actor->scene = this;
		actors.push_back(std::move(actor));
	}
	void Scene::RemoveAllActors(){
		actors.clear();
	}
}