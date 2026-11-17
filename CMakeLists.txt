cmake_minimum_required(VERSION 3.14)

project(main LANGUAGES C)

find_package(cJSON REQUIRED)

add_executable(${PROJECT_NAME}
    src/main.c
)

target_compile_options(${PROJECT_NAME} PRIVATE
    -Wall
    -fsanitize=address
    -g
)
target_link_options(${PROJECT_NAME} PRIVATE
    -Wall
    -fsanitize=address
    -g
)
target_include_directories(${PROJECT_NAME} PRIVATE
    # glad/include
)

target_link_libraries(${PROJECT_NAME} PRIVATE 
    cjson
)

target_compile_definitions(${PROJECT_NAME} PRIVATE 
    SHADER_DIR="${CMAKE_CURRENT_SOURCE_DIR}/shaders/"
)

