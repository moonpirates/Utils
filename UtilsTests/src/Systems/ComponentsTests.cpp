
#include <gtest/gtest.h>
#include "Systems/Components/Component.h"
#include "Systems/Components/Components.h"


class TestComponent : public Utils::Component
{
};

class AlternativeTestComponent : public Utils::Component
{
};

class ComponentTest : public ::testing::Test
{
protected:
	Utils::Components Components;
	TestComponent* FirstComponent;
	TestComponent* SecondComponent;
	AlternativeTestComponent* AlternativeComponent;

	void SetUp() override
	{
		FirstComponent = Components.AddComponent<TestComponent>();
		SecondComponent = Components.AddComponent<TestComponent>();
		AlternativeComponent = Components.AddComponent<AlternativeTestComponent>();
	}
};

TEST_F(ComponentTest, CanGetComponent)
{
	EXPECT_EQ(FirstComponent, Components.GetComponent<TestComponent>());
}

TEST_F(ComponentTest, CanAddAndGetMultipleComponents)
{
	std::vector<TestComponent*> components = Components.GetComponents<TestComponent>();
	 
	EXPECT_EQ(components.size(), 2);
	EXPECT_EQ(components[0], FirstComponent);
	EXPECT_EQ(components[1], SecondComponent);
}

TEST_F(ComponentTest, CanRemoveComponent)
{
	EXPECT_EQ(Components.GetComponents<Utils::Component>().size(), 3);
	
	Components.RemoveComponent(AlternativeComponent);
	
	EXPECT_EQ(Components.GetComponents<Utils::Component>().size(), 2);
	
	AlternativeTestComponent* alternativeComponent = Components.GetComponent<AlternativeTestComponent>();

	EXPECT_EQ(alternativeComponent, nullptr);
}