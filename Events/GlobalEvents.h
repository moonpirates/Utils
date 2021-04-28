#pragma once
#include <Utils\Events\Dispatcher.h>

namespace Utils
{
	class GlobalEvents : public Dispatcher
	{
	public:
		// Prevent copies
		GlobalEvents(const GlobalEvents&) = delete;
		void operator=(const GlobalEvents&) = delete;

		template<typename T>
		static void Subscribe(const std::function<void(T)> callback, void* context)
		{
			GetInstance().Subscribe<T>(callback, context);
		}

		template<typename T>
		static void Unsubscribe(void* context)
		{
			GetInstance().Unsubscribe<T>(context);
		}

		template<typename T>
		static void Invoke(T e)
		{
			GetInstance().Invoke(e);
		}

	private:
		GlobalEvents() {};
		
		static Dispatcher& GetInstance()
		{
			static GlobalEvents instance;
			return instance;
		}
	};
}