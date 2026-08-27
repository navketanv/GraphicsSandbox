include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.17.0
)

FetchContent_MakeAvailable(googletest)

# ==========================================================
# Target
# ==========================================================
add_executable(MathTests
    Math/Mat4Tests.cpp
    Math/Vec4Tests.cpp
    Math/Vec3Tests.cpp
)

target_include_directories(MathTests
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(MathTests
    PRIVATE
        GTest::gtest_main
)

enable_project_options(MathTests)

include(GoogleTest)

gtest_discover_tests(MathTests)
