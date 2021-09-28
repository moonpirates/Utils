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

void Utils::Scene::PrintHierarchy()
{
	PrintHierarchy(rootGameObject, 0);
}

void Utils::Scene::PrintHierarchy(GameObject* gameObject, size_t depth)
{
	const unsigned short INDENT_SPACES = 3;
	std::string indentation = depth == 0 ? "" : std::string(INDENT_SPACES * (depth - 1), ' ') + "|--";

	std::string components = "";
	const std::vector<Utils::Component*> allComponents = gameObject->GetAllComponents();
	
	for (size_t i = 0; i < allComponents.size(); i++)
	{
		components += TypeToClassName(typeid(*allComponents[i]));

		if (i < allComponents.size() - 1)
		{
			components += ", ";
		}
	}

	std::cout << indentation << gameObject->Name << " (" << components << ")" << std::endl;

	depth++;

	for (size_t i = 0; i < gameObject->GetNumChildren(); i++)
	{
		PrintHierarchy(gameObject->GetChildAtIndex(i), depth);
	}
}
