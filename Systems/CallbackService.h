#pragma once

#include <iostream>
#include <set>
#include <chrono>
#include "../Services/BaseService.h"
#include "Updatable.h"

namespace Utils
{
	class CallbackService : public BaseService
	{
		using Clock = std::chrono::high_resolution_clock;
		using Time = std::chrono::steady_clock::time_point;
		using Duration = std::chrono::steady_clock::duration;

	public:
		CallbackService();
		void AddUpdatable(Updatable& updatable);
		void RemoveUpdatable(Updatable& updatable);
		int GetTargetFps();
		void SetTargetFps(int targetFps);
		void Start();
		void Stop();

	private:
		const int DEFAULT_FPS = 60;

		std::set<Updatable*> updatables;
		bool running;
		int targetFps;
		std::chrono::nanoseconds timestep;

		void OnUpdate();
	};
}

