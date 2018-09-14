#include "SoutSink.hpp"

#include <iostream>

#include "g3log/loglevels.hpp"
#include "g3log/logworker.hpp"

struct ActualSink
{
	void ReceiveLogMessage(g3::LogMessageMover logEntry)
	{
		std::cout << "> " << logEntry.get().function()
							<< " at: " << logEntry.get().file_path() << "\n\t"
							<< logEntry.get().level() << ": " << logEntry.get().message()
							<< "\n";
	}
};

namespace utils
{
	std::unique_ptr<g3::LogWorker> logWorker;
	void initLogger(bool enbled)
	{
		if (logWorker.get())
			return;

		if (!enbled)
		{
			g3::log_levels::disableAll();
			return;
		}

		logWorker		= g3::LogWorker::createLogWorker();
		auto handle = logWorker->addSink(
				std::make_unique<ActualSink>(), &ActualSink::ReceiveLogMessage);
		g3::initializeLogging(logWorker.get());
	}
}	// namespace utils
