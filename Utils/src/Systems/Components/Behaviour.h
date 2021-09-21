#pragma once
#include "Component.h"
#include "Services/GlobalServiceLocator.h"
#include "../CallbackService.h"

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
		}

		~Behaviour()
		{
			callbackService.RemoveUpdatable(*this);
			callbackService.RemoveRenderable(*this);
		}

		virtual void Update() {};
		virtual void OnRender() {};

	private:
		CallbackService& callbackService;
	};
}