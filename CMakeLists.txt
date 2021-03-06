cmake_minimum_required(VERSION 3.13)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake CACHE STRING "Vcpkg toolchain file")

project(TinySFML)

find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
    execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                    RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
        message(FATAL_ERROR "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg")
    message(FATAL_ERROR "The submodules were not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()


set(RELEASE_PATH "${PROJECT_SOURCE_DIR}/release")

find_package(box2d CONFIG REQUIRED)
find_package(Catch2 CONFIG REQUIRED)
find_package(EnTT CONFIG REQUIRED)
find_package(ImGui-SFML CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(Lua REQUIRED)
find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)

set(PROJECT_PATH ${CMAKE_SOURCE_DIR}/tinysfml)
set(SRC_PATH ${PROJECT_PATH}/src)
set(SHADER_PATH ${PROJECT_PATH}/shaders)
set(RESOURCE_PATH ${PROJECT_PATH}/resources)

file(GLOB_RECURSE PROJECT_SOURCES ${SRC_PATH}/*.cpp)
file(GLOB_RECURSE PROJECT_HEADERS ${SRC_PATH}/*.hpp)
file(GLOB_RECURSE PROJECT_SHADERS ${SHADER_PATH}/*.comp ${SHADER_PATH}/*.frag ${SHADER_PATH}/*.geom ${SHADER_PATH}/*.vert)
file(GLOB_RECURSE PROJECT_RESOURCES ${RESOURCE_PATH}/*.*)
file(GLOB PROJECT_CONFIGS CMakeLists.txt Readme.md .gitattributes .gitignore .gitmodules LICENSE)

#add_subdirectory(tinysfml)

source_group(TREE ${PROJECT_PATH} FILES ${PROJECT_SHADERS})
source_group(TREE ${PROJECT_PATH} FILES ${PROJECT_SOURCES})
source_group(TREE ${PROJECT_PATH} FILES ${PROJECT_HEADERS})
source_group(TREE ${PROJECT_PATH} FILES ${PROJECT_RESOURCES})
source_group(TREE ${PROJECT_SOURCE_DIR} FILES ${PROJECT_CONFIGS})

add_executable(TinySFML ${PROJECT_HEADERS} ${PROJECT_SOURCES} ${PROJECT_SHADERS} ${RESOURCE_PATH})

set_property(TARGET TinySFML PROPERTY CXX_STANDARD 17)



target_include_directories(TinySFML PRIVATE ${LUA_INCLUDE_DIR})

target_link_libraries(TinySFML PRIVATE box2d::box2d 
PRIVATE Catch2::Catch2 
                                        PRIVATE EnTT::EnTT 
                                        PRIVATE nlohmann_json nlohmann_json::nlohmann_json
                                        PRIVATE spdlog::spdlog spdlog::spdlog_header_only 
                                        PRIVATE imgui::imgui 
                                        PRIVATE ${LUA_LIBRARIES} 
                                        PRIVATE ImGui-SFML::ImGui-SFML 
                                        PRIVATE sfml-system sfml-network sfml-graphics sfml-window 
                                        )
                                        
if (MSVC)
   set_target_properties(TinySFML PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${RELEASE_PATH})
                                        
                                        elseif(UNIX AND NOT APPLE)
  target_link_libraries(TinySFML PRIVATE Catch2::Catch2WithMain)
endif()

add_custom_command(TARGET TinySFML POST_BUILD 
                   COMMAND ${CMAKE_COMMAND} -E copy_directory 
                      ${CMAKE_SOURCE_DIR}/tinysfml/resources ${RELEASE_PATH}/resources 
                    COMMAND ${CMAKE_COMMAND} -E copy_directory 
                      ${CMAKE_SOURCE_DIR}/tinysfml/shaders ${RELEASE_PATH}/shaders
)

set_target_properties(TinySFML PROPERTIES 
           ARCHIVE_OUTPUT_DIRECTORY "${RELEASE_PATH}/lib" 
           LIBRARY_OUTPUT_DIRECTORY "${RELEASE_PATH}/lib" 
           RUNTIME_OUTPUT_DIRECTORY "${RELEASE_PATH}" 
           RUNTIME_OUTPUT_DIRECTORY_DEBUG "${RELEASE_PATH}" 
           RUNTIME_OUTPUT_DIRECTORY_RELEASE "${RELEASE_PATH}" 
)