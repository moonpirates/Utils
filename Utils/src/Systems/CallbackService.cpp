#include "CallbackService.h"

Utils::CallbackService::CallbackService() : 
	updatables(std::set<Updatable*>()), 
	renderables(std::set<Renderable*>()),
	running(false), 
	targetFps(DEFAULT_FPS)
{
}

void Utils::CallbackService::AddUpdatable(Updatable& updatable)
{
	updatables.insert(&updatable);
}

void Utils::CallbackService::RemoveUpdatable(Updatable& updatable)
{
	updatables.erase(&updatable);
}

void Utils::CallbackService::AddRenderable(Renderable& renderable)
{
	renderables.insert(&renderable);
}

void Utils::CallbackService::RemoveRenderable(Renderable& renderable)
{
	renderables.erase(&renderable);
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
	time_point previousStep = clock::now();
	duration time = nanoseconds(0);
	unsigned int frameCount = 0;

	while (running)
	{
		time_point now = clock::now();
		duration delta = now - previousNow;
		previousNow = now;
		time += delta;

		// Sleeps to render at desired framerate
		// What do we pass into Update() ?
		while (time >= timestep)
		{
			time -= timestep;

			float deltaTime = std::chrono::duration_cast<std::chrono::nanoseconds>(now - previousStep).count() / 1000000000.0f;
			Utils::TimeUtil::DeltaTime = deltaTime;
			Utils::TimeUtil::TimeSinceStart += deltaTime;

			//LOG("[" << frameCount << "] deltaTime: " << Utils::TimeUtil::DeltaTime <<  " " << Utils::TimeUtil::TimeSinceStart);
			previousStep = now;

			OnUpdate();
			OnPreRender();
			OnRender();
			OnPostRender();
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

void Utils::CallbackService::OnPreRender()
{
	for (auto renderable : renderables)
	{
		renderable->PreRender();
	}
}

void Utils::CallbackService::OnRender()
{
	for (auto renderable : renderables)
	{
		renderable->Render();
	}
}

void Utils::CallbackService::OnPostRender()
{
	for (auto renderable : renderables)
	{
		renderable->PostRender();
	}
}
