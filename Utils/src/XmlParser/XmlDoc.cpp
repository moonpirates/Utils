#include "XmlDoc.h"

XmlDoc::XmlDoc() :
	Root(new XmlElement())
{
}

XmlDoc::~XmlDoc()
{
	delete Root;
}

std::string XmlDoc::GetDebugInfo()
{
	std::string debugInfo = "";
	RecursiveLogElement(Root, 0, debugInfo);

	return debugInfo;
}

void XmlDoc::RecursiveLogElement(XmlElement* element, int depth, std::string& debugInfo)
{
	std::string tabs = std::string(depth, '\t');
	debugInfo += tabs + element->GetDebugInfo() + "\n";

	if (element->GetNumChildren() > 0)
	{
		depth++;
		XmlElement::ElementsContainer::iterator it;
		for (it = element->Children.begin(); it != element->Children.end(); it++)
		{
			RecursiveLogElement(*it, depth, debugInfo);
		}
		depth--;
	}
}
