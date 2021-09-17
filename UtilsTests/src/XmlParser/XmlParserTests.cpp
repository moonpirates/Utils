#include <gtest/gtest.h>
#include <filesystem>
#include "XmlParser/Lexer.h"

class XmlParserTest : public ::testing::Test
{
protected:
	const std::string TEST_PATH = "..\\..\\..\\..\\Utils\\UtilsTests\\src\\XmlParser\\test.xml";
	XmlDoc Doc;
	std::shared_ptr<XmlElement> FirstElement;

	void SetUp() override
	{
		ASSERT_TRUE(std::filesystem::exists(TEST_PATH));
		Lexer lexer;
		Doc = lexer.Parse(TEST_PATH);
		FirstElement = Doc.Root->Children.front();
	}
};

TEST_F(XmlParserTest, NumChildrenCorrect)
{
	EXPECT_EQ(FirstElement->Children.size(), 4);
}

TEST_F(XmlParserTest, TagIsCorrect)
{
	EXPECT_EQ(FirstElement->Tag, "root");
}

TEST_F(XmlParserTest, HasCorrectNumAttributes)
{
	EXPECT_EQ(FirstElement->Attributes.size(), 1);
}

TEST_F(XmlParserTest, FindsAttribute)
{
	EXPECT_NE(FirstElement->TryGetAttribute("toot"), std::nullopt);
}

TEST_F(XmlParserTest, AttributeHasCorrectValue)
{
	EXPECT_EQ(FirstElement->TryGetAttribute("toot"), "honk");
}