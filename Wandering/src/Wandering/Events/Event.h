#pragma once
#include "../wdpch.h"
namespace Wandering {

	template <typename T>
	class EventHandler {
	public:
		// id wants to index this

		static std::vector<void(*)(T)> eventListeners;
		static std::queue<T> eventQueue;

		static void trigger(T& e) {
			for (size_t i = 0; i < eventListeners.size(); i++)
			{
				eventListeners[i](e);
			}
		}

		static void delayedTrigger(T e) {
			eventQueue.push(e);
		}

		static void processDelayedTriggers() {
			size_t size = eventQueue.size();
			for (size_t i = 0; i < size; i++)
			{
				T e = eventQueue.front();
				eventQueue.pop();
				for (size_t j = 0; j < eventListeners.size(); j++)
				{
					eventListeners[j](e);
				}
			}
		}

		static void addListener(void(*listener)(T)) {
			eventListeners.push_back(listener);
		}
	};

	template <typename T>
	std::vector<void(*)(T)> EventHandler<T>::eventListeners;
	template <typename T>
	std::queue<T> EventHandler<T>::eventQueue;

}