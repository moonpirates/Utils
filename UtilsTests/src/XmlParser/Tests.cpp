#include <gtest/gtest.h>
#include "XmlParser/Lexer.h"

TEST(XmlParser, Henk)
{
	Lexer lexer;
	XmlDoc xmlDoc = lexer.Parse("test.xml");
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << xmlDoc.GetDebugInfo();
}