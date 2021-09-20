#include <gtest/gtest.h>
#include <filesystem>
#include "XmlParser/Lexer.h"

class XmlParserTest : public ::testing::Test
{
protected:
	const std::string TEST_PATH = "..\\..\\..\\..\\Utils\\UtilsTests\\src\\XmlParser\\test.xml";
	XmlDoc* Doc;
	XmlElement* FirstElement;
	XmlElement* FirstChild;
	XmlElement* FirstGrandchild;

	void SetUp() override
	{
		::testing::GTEST_FLAG(catch_exceptions) = false;

		ASSERT_TRUE(std::filesystem::exists(TEST_PATH));
		Lexer lexer;
		Doc = lexer.Parse(TEST_PATH);
		FirstElement = (*Doc->Root)[0];
		FirstChild = (*FirstElement)[0];
		FirstGrandchild = (*FirstChild)[0];
	}
};

class XmlElementTest : public ::testing::Test
{
protected:
	XmlElement* Root;
	XmlElement* Child;

	void SetUp() override
	{
		Root = new XmlElement();
		Child = Root->AddChild();
	}

	void TearDown() override
	{
		delete Root;
	}
};

TEST_F(XmlParserTest, NumChildrenCorrect)
{
	EXPECT_EQ(FirstElement->GetNumChildren(), 4);
}
 
 TEST_F(XmlParserTest, TagIsCorrect)
 {
 	EXPECT_EQ(FirstElement->Tag, "root");
 }
 
 TEST_F(XmlParserTest, HasCorrectNumAttributes)
 {
 	EXPECT_EQ(FirstElement->GetNumAttributes(), 1);
 }
 
 TEST_F(XmlParserTest, FindsAttribute)
 {
 	EXPECT_NE(FirstElement->TryGetAttribute("toot"), std::nullopt);
 }
 
 TEST_F(XmlParserTest, AttributeHasCorrectValue)
 {
 	EXPECT_EQ(FirstElement->TryGetAttribute("toot"), "honk");
 }
 
 TEST_F(XmlParserTest, FindsChild)
 {
 	EXPECT_EQ(FirstChild->Tag, "childA");
 }
 
 TEST_F(XmlParserTest, FindsGrandChild)
 {
 	EXPECT_EQ(FirstGrandchild->Tag, "grandchild");
 }

 TEST_F(XmlParserTest, CanReadContent)
 {
	 EXPECT_EQ(FirstGrandchild->Content, "grandchildcontent");
 }

 TEST_F(XmlParserTest, ParsesEmptyElementTag)
 {
	 XmlElement* emptyElementElement = FirstElement->GetChildAt(2);
	 EXPECT_EQ(emptyElementElement->Tag, "childC");
 }

 TEST_F(XmlElementTest, CanAddChild)
 {
	 EXPECT_EQ(Root->GetNumChildren(), 1);
 }

 TEST_F(XmlElementTest, CanRemoveChild)
 {
	 Root->RemoveChild(Child);
	 EXPECT_EQ(Root->GetNumChildren(), 0);
 }