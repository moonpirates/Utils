#pragma once

#include <iostream>
#include <memory>
#include <map>
#include <list>
#include <string>
#include <optional>

namespace Utils
{
	class XmlElement
	{
	public:
		using ElementsContainer = std::list<XmlElement*>;
		using AttributesContainer = std::map<std::string, std::string>;

		std::string Markup;
		std::string Tag;
		std::string Content;
		XmlElement* Parent;
		AttributesContainer Attributes;
		ElementsContainer Children;
		int ID = 0;

		XmlElement();
		XmlElement(XmlElement* parent);
		~XmlElement();
		XmlElement* operator[](int);
		std::string GetDebugInfo();
		XmlElement* AddChild();
		void RemoveChild(XmlElement* child);
		size_t GetNumChildren() const;
		XmlElement* GetChildAt(unsigned int);
		size_t GetNumAttributes() const;
		std::optional<const std::string> TryGetAttribute(const std::string& name) const;

	private:
		inline static int nextID = 0;
	};
}