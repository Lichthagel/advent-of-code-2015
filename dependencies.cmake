include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.11.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_library(md5 lib/md5/md5.cpp)
target_include_directories(md5 PUBLIC ${PROJECT_SOURCE_DIR}/lib/md5)

add_library(utils lib/utils/input.cpp)
target_include_directories(utils PUBLIC ${PROJECT_SOURCE_DIR}/lib/utils)

find_package(OpenMP)