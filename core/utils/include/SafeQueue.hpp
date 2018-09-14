//
// Created by massimo on 29/07/18.
//

#ifndef CULT_LOCKFREEQUEUE_HPP
#define CULT_LOCKFREEQUEUE_HPP

#include <mutex>
#include <queue>

namespace utils
{
	template<typename T>
	class SafeQueue
	{
		private:
		std::queue<T> queue;
		std::mutex mutex;

		public:
		SafeQueue(): queue(), mutex() {}

		/***
		 *  Copy constructor is not thread safe
		 */
		SafeQueue(const SafeQueue &other): queue(), mutex() { queue = other.queue; }

		/***
		 * Move constructor is not thread safe
		 */
		SafeQueue(SafeQueue &&other) noexcept
				: queue(std::move(other.queue)), mutex()
		{
		}

		SafeQueue &operator=(const SafeQueue &other)
		{
			queue = other.queue;
			return *this;
		}

		bool empty()
		{
			std::lock_guard<std::mutex> g(mutex);
			return queue.empty();
		}

		unsigned long size()
		{
			std::lock_guard<std::mutex> g(mutex);
			return queue.size();
		}

		T front()
		{
			std::lock_guard<std::mutex> g(mutex);
			return queue.front();
		}

		void offer(T value)
		{
			std::lock_guard<std::mutex> g(mutex);
			queue.push(value);
		}

		T poll()
		{
			std::lock_guard<std::mutex> g(mutex);
			T toRet(queue.front());
			queue.pop();
			return toRet;
		}
	};
}	// namespace utils

#endif	// CULT_LOCKFREEQUEUE_HPP
