#include "CallbackService.h"

Utils::CallbackService::CallbackService() : updatables(std::set<Updatable*>()), running(false), targetFps(DEFAULT_FPS), timestep()
{
	std::cout << "Started" << std::endl;
	Start();
}

void Utils::CallbackService::AddUpdatable(Updatable& updatable)
{
	updatables.insert(&updatable);
}

void Utils::CallbackService::RemoveUpdatable(Updatable& updatable)
{
	updatables.erase(&updatable);
}

int Utils::CallbackService::GetTargetFps()
{
	return targetFps;
}

void Utils::CallbackService::SetTargetFps(int targetFps)
{
	this->targetFps = targetFps;
}

void Utils::CallbackService::Start()
{
	if (running)
	{
		return;
	}

	running = true;
	timestep = std::chrono::nanoseconds(1 / targetFps);

	Time previousTime = Clock::now();

	Duration lag;

	while (running)
	{
		Duration deltaTime = Clock::now() - previousTime;
		previousTime = Clock::now();

		lag += deltaTime;

		if (lag > timestep)
		{
			std::cout << "Update!" << std::endl;
			lag = Duration();
		}

	}
}

void Utils::CallbackService::Stop()
{
	running = false;
}

void Utils::CallbackService::OnUpdate()
{
	for (auto updatable : updatables)
	{
		updatable->Update();
	}
}
