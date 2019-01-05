message("COMPILING UTILS")
ADD_LIBRARY(utils src/SoutSink.cpp)
TARGET_LINK_LIBRARIES(utils PRIVATE g3logger)
TARGET_INCLUDE_DIRECTORIES(utils PRIVATE src PUBLIC include)
TARGET_COMPILE_FEATURES(utils PUBLIC cxx_std_17)
TARGET_SOURCES(utils PRIVATE src/ConsumerThread.cpp)

compile_options(utils)

message("END COMPILING UTILS")
