#pragma once

/**
 *	Include Header
 */
#include "Entity.h"



/**
 *	Include ECS Component System
 */
#include <ING/ECS/Component/System/System.h>



/**
 *	Define Class Members,...
 */
namespace ING {

	namespace ECS {

		/**
		 *	Constructors And Destructor
		 */
		Entity::Entity	(Repository* repository) {

			this->repository = repository;

		}

		Entity::~Entity	() {



		}



		/**
		 *	Release Methods
		 */
		void Entity::Release() {

			

			delete this;
		}



		/**
		 *	Methods
		 */
		template<typename T, class TComponentSystem>
		void								Entity::AddComponent(ComponentPtr<T, TComponentSystem> componentPtr) {

			componentMap[typeid(T).name()] = componentPtr;

		}

		template<typename T, class TComponentSystem>
		ComponentPtr<T, TComponentSystem>	Entity::GetComponent() {

			return ComponentPtr<T, TComponentSystem>(componentMap[typeid(T).name()]);

		}

		template<typename T>
		void								Entity::RemoveComponent() {

			componentMap.erase(typeid(T).name());

		}

	}

}