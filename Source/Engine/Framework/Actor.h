#pragma once  
#include "../Math/Transform.h"  
#include "../Renderer/Model.h"  
#include <memory>  

namespace fox {  
	class Actor {  
	public:  
		Actor() = default;  
		Actor(const fox::Transform& transform, std::shared_ptr<class Model> model) :
			transform(transform),  
			model{ model }  
		{}  

		virtual void Update(float dt);  
		virtual void Draw(class Renderer& renderer);  

		Transform& GetTransform() { return transform; }  

	protected:  
		Transform transform;  
		std::shared_ptr<Model> model;
	};  
}