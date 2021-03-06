#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include "XmlElement.h"

namespace Utils
{
	class XmlDoc
	{
	public:
		XmlElement* Root;

		XmlDoc();
		~XmlDoc();
		std::string GetDebugInfo();

	private:

		void RecursiveLogElement(XmlElement* element, int depth, std::string& debugInfo);
	};
}