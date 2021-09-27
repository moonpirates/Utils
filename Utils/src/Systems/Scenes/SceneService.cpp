#include "SceneService.h"

Utils::Scene* Utils::SceneService::LoadScene()
{
	if (currentScene != nullptr)
	{
		UnloadScene(*currentScene);
	}

	currentScene = new Scene();

	return currentScene;
}

void Utils::SceneService::UnloadScene(const Scene& scene)
{
	delete currentScene;
}

Utils::Scene* Utils::SceneService::GetCurrentScene()
{
	return currentScene;
}

