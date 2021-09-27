#pragma once

#include "Services/BaseService.h"
#include "Scene.h"

namespace Utils
{
	class SceneService : public BaseService
	{
	public:
		Scene* LoadScene();
		void UnloadScene(const Scene& scene);
		Scene* GetCurrentScene();
	private:
		Scene* currentScene;
	};
}