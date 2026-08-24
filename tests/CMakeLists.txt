# ==========================================================
# Target
# ==========================================================
add_executable(Mat4Tests
    Math/Mat4Tests.cpp
)

target_include_directories(Mat4Tests
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
)

enable_project_options(Mat4Tests)

add_test(
    NAME Mat4Tests
    COMMAND Mat4Tests
)