cmake_minimum_required(VERSION 3.14)

project(romanov LANGUAGES C)

set(CMAKE_INSTALL_PREFIX "$ENV{HOME}/.local" CACHE PATH "..." FORCE)

include(GNUInstallDirs)
find_package(PkgConfig REQUIRED)
pkg_check_modules(CJSON REQUIRED IMPORTED_TARGET libcjson)

add_executable(${PROJECT_NAME}
    src/main.c
)

target_compile_options(${PROJECT_NAME} PRIVATE
    -Wall
)

target_compile_definitions(${PROJECT_NAME} PRIVATE
    QUOTES_PATH="${CMAKE_INSTALL_FULL_DATADIR}/romanov/quotes.json"
)

target_link_libraries(${PROJECT_NAME} PRIVATE 
    PkgConfig::CJSON
)

install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_BINDIR})
install(FILES data/quotes.json DESTINATION ${CMAKE_INSTALL_DATADIR}/romanov)


