#include "gtest/gtest.h"

#include "SoutSink.hpp"
#include "g3log/g3log.hpp"

class DefaultTest: public testing::Test
{
	public:
	void SetUp() final { utils::initLogger(false); }
	void TearDown() final {}
};

TEST_F(DefaultTest, simpleTest)
{
	LOG(DEBUG) << "running a test " << std::endl;
	EXPECT_TRUE(true);
}
