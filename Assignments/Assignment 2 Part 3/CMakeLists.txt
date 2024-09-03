cmake_minimum_required(3.11)

project{BagTest}

set{CMake_CXX_STANDARD 11}
set{CMake_CXX_STANDARD_REQUIRED True}

include_directories(../../include
	${PROJEST_source_DIR}/include
	${PROJEST_source_DIR}/source 
)

file(GLOB all_SRCS
	"../../include/*.h"
	"${PROJEST_source_DIR}/include/*.h"
	"${PROJEST_source_DIR}/source/*.cpp"
	"${PROJEST_source_DIR}/source/*.cpp"
)

include(FetchContent)
FetchContent_Declare(
	googletest
	URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" fORCE)
FETCHCONTENT_MAKEAVAILABLE(googletest)

add_executable(listtest BagTest.cpp receiptbag.hpp)
target_link_libraries(listtest GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(listtest)
