#include <gtest/gtest.h>
#include "Math/Math.h"

using namespace Utils;

TEST(Math, LerpsForward)
{
	EXPECT_EQ(Math::Lerp(5.0f, 10.0f, 0.5f), 7.5f);
}

TEST(Math, LerpsReversed)
{
	EXPECT_EQ(Math::Lerp(10.0f, 5.0f, 0.5f), 7.5f);
}

TEST(Math, LerpClamps)
{
	EXPECT_EQ(Math::Lerp(5.0f, 10.0f, 500.0f), 10.0f);
	EXPECT_EQ(Math::Lerp(5.0f, 10.0f, -500.0f), 5.0f);
}

TEST(Math, InverseLerpsForward)
{
	EXPECT_EQ(Math::InverseLerp(5.0f, 10.0f, 7.5f), 0.5f);
}

TEST(Math, InverseLerpsReversed)
{
	EXPECT_EQ(Math::InverseLerp(10.0f, 5.0f, 7.5f), 0.5f);
}

TEST(Math, InverseLerpsClamps)
{
	EXPECT_EQ(Math::InverseLerp(5.0f, 10.0f, 500.0f), 1.0f);
	EXPECT_EQ(Math::InverseLerp(5.0f, 10.0f, -500.0f), 0.0f);
}