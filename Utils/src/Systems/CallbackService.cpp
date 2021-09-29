#include "CallbackService.h"

Utils::CallbackService::CallbackService() : 
	updatables(std::vector<Updatable*>()),
	renderables(std::vector<Renderable*>()),
	running(false), 
	targetFps(DEFAULT_FPS)
{
}

void Utils::CallbackService::AddUpdatable(Updatable& updatable)
{
	updatables.push_back(&updatable);
}

void Utils::CallbackService::RemoveUpdatable(Updatable& updatable)
{
	static_cast<void>(std::remove(updatables.begin(), updatables.end(), &updatable));
}

void Utils::CallbackService::AddRenderable(Renderable& renderable)
{
	renderables.push_back(&renderable);
}

void Utils::CallbackService::RemoveRenderable(Renderable& renderable)
{
	static_cast<void>(std::remove(renderables.begin(), renderables.end(), &renderable));
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

			// Clone, so this set is determined once per step
			auto updatablesClone = std::vector<Utils::Updatable*>(updatables);
			auto renderablesClone = std::vector<Utils::Renderable*>(renderables);

			OnUpdate(updatablesClone);
			OnPreRender(renderables);
			OnRender(renderables);
			OnPostRender(renderables);
			frameCount++;
		}
	}
}

void Utils::CallbackService::Stop()
{
	running = false;
}

void Utils::CallbackService::OnUpdate(const std::vector<Utils::Updatable*>& updatables)
{
	for (auto updatable : updatables)
	{
		updatable->Update();
	}
}

void Utils::CallbackService::OnPreRender(const std::vector<Utils::Renderable*>& renderables)
{
	for (auto renderable : renderables)
	{
		renderable->PreRender();
	}
}

void Utils::CallbackService::OnRender(const std::vector<Utils::Renderable*>& renderables)
{
	for (auto renderable : renderables)
	{
		renderable->Render();
	}
}

void Utils::CallbackService::OnPostRender(const std::vector<Utils::Renderable*>& renderables)
{
	for (auto renderable : renderables)
	{
		renderable->PostRender();
	}
}
