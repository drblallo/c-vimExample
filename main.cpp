#include <g3log/g3log.hpp>

#include "SoutSink.hpp"

int main()
{
	utils::initLogger(true);
	LOG(DEBUG) << "Starting program\n";
	LOG(DEBUG) << "Ending program" << std::endl;
}
