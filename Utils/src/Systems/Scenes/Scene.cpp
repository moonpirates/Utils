#include "Scene.h"

Utils::Scene::Scene() : 
	rootGameObject(new GameObject("Root"))
{

}

Utils::GameObject* Utils::Scene::AddGameObject(const std::string& name)
{
	return rootGameObject->AddChild(name);
}

void Utils::Scene::RemoveGameObject(GameObject* gameObject)
{
	rootGameObject->RemoveChild(gameObject);
}

Utils::GameObject* Utils::Scene::GetRoot()
{
	return rootGameObject;
}
