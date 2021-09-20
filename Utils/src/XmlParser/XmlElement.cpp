#include "XmlElement.h"

XmlElement::XmlElement() : XmlElement(nullptr)
{
}

XmlElement::XmlElement(XmlElement* parent) :
	Parent(parent), ID(nextID++), Children(std::list<XmlElement*>())
{
}

XmlElement::~XmlElement()
{
	for (XmlElement* child : Children)
	{
		delete child;	
	}
}

XmlElement* XmlElement::operator[](int index)
{
	return GetChildAt(index);
}

XmlElement* XmlElement::AddChild()
{
	return Children.emplace_back(new XmlElement(this));
}

void XmlElement::RemoveChild(XmlElement* child)
{
	Children.remove(child);
}

size_t XmlElement::GetNumChildren() const
{
	return Children.size();
}

XmlElement* XmlElement::GetChildAt(unsigned int index)
{
	if (Children.size() == 0)
	{
		return nullptr;
	}

	if (index > Children.size() - 1)
	{
		throw std::out_of_range("Out of range on Children: " + index);
	}

	XmlElement* el = *std::next(Children.begin(), index);
	return el;
}

size_t XmlElement::GetNumAttributes() const
{
	return Attributes.size();
}

std::optional<const std::string> XmlElement::TryGetAttribute(const std::string& name) const
{
	const AttributesContainer::const_iterator it = Attributes.find(name);

	if (it == Attributes.end())
	{
		return std::nullopt;
	}

	return it->second;
}

std::string XmlElement::GetDebugInfo()
{
	std::string info = "Tag: '" + Tag + "'";

	if (Content != "")
	{
		info += " | Content: '" + Content + "'";
	}

	if (Parent != nullptr)
	{
		info += " | Parent '" + Parent->Tag + "'";
	}

	info += " | Children: " + std::to_string(Children.size()) + " | ID: " + std::to_string(ID);

	if (Attributes.size() > 0)
	{
		info += " | ";

		std::map<std::string, std::string>::iterator it;

		for (it = Attributes.begin(); it != Attributes.end(); it++)
		{
			info += it->first;

			if (!it->second.empty())
			{
				info += ": " + it->second;
			}

			if (std::next(it) != Attributes.end())
			{
				info += ", ";
			}
		}
	}

	return info;
}
