#pragma once

#include <iostream>
#include <set>
#include <chrono>
#include "../Macros/Macros.h"
#include "../TimeUtil.h"
#include "../Services/BaseService.h"
#include "Updatable.h"
#include "Renderable.h"

namespace Utils
{
	class CallbackService : public BaseService
	{
		using duration = std::chrono::high_resolution_clock::duration;
		using nanoseconds = std::chrono::nanoseconds;
		using clock = std::chrono::high_resolution_clock;
		using time_point = std::chrono::high_resolution_clock::time_point;

	public:
		CallbackService();
		void AddUpdatable(Updatable& updatable);
		void RemoveUpdatable(Updatable& updatable);
		void AddRenderable(Renderable& updatable);
		void RemoveRenderable(Renderable& updatable);
		int GetTargetFps();
		void SetTargetFps(int targetFps);
		void Start();
		void Stop();

	private:
		const int DEFAULT_FPS = 60;

		std::set<Updatable*> updatables;
		std::set<Renderable*> renderables;
		bool running;
		int targetFps;

		void OnUpdate(const std::set<Utils::Updatable*>& updatables);
		void OnPreRender(const std::set<Utils::Renderable*>& renderables);
		void OnRender(const std::set<Utils::Renderable*>& renderables);
		void OnPostRender(const std::set<Utils::Renderable*>& renderables);
	};
}

