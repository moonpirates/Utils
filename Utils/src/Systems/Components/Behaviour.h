#pragma once
#include "Component.h"
#include "Services/GlobalServiceLocator.h"
#include "../CallbackService.h"
#include "../../../MoonUI/src/OpenGL/Renderer.h"
#include "../../../MoonUI/src/OpenGL/RenderService.h"

namespace Utils
{
	class Behaviour : public Component, Updatable, Renderable
	{
	public:
		Behaviour() :
			callbackService(GlobalServiceLocator::Get<CallbackService>())
		{
			callbackService.AddUpdatable(*this);
			callbackService.AddRenderable(*this);

			renderer = GlobalServiceLocator::Get<RenderService>().GetRenderer();
		}

		~Behaviour()
		{
			callbackService.RemoveUpdatable(*this);
			callbackService.RemoveRenderable(*this);
		}

		virtual void Update() {};
		virtual void Render() {};

	protected:
		Renderer* renderer;

	private:
		CallbackService& callbackService;
	};
}