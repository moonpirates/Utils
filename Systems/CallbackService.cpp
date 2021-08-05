#include "CallbackService.h"

Utils::CallbackService::CallbackService() : updatables(std::set<Updatable*>()), running(false), targetFps(DEFAULT_FPS)
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

	nanoseconds timestep = nanoseconds(1000000000 / targetFps);
	time_point previousNow = clock::now();
	duration time = nanoseconds(0);
	unsigned int frameCount = 0;

	while (true)
	{
		time_point now = clock::now();
		duration deltaTime = now - previousNow;
		previousNow = now;
		time += deltaTime;
		
		while (time >= timestep)
		{
			std::cout << "[" << frameCount << "] step at time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(time).count() << std::endl;
			time -= timestep;
			frameCount++;
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
