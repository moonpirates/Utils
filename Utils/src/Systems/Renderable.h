#pragma once

namespace Utils
{
	class Renderable
	{
	public:
		virtual void PreRender() = 0;
		virtual void Render() = 0;
	};
}