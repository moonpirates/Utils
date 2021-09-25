#pragma once

namespace Utils
{
	class Renderable
	{
	public:
		virtual void PreRender() {};
		virtual void Render() {};
		virtual void PostRender() {};
	};
}