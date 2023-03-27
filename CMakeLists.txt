cmake_minimum_required(VERSION 3.24)
project(MyTrace)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -fsanitize=address,undefined")

add_subdirectory(deps/Algebra3D)
include_directories(deps/Algebra3D/include)
add_subdirectory(deps/PAMImage)
include_directories(deps/PAMImage/include)
add_subdirectory(deps/SLib)
include_directories(deps/SLib/include)

file(GLOB SRC src/*)
add_executable(MyTrace ${SRC})
target_link_libraries(MyTrace Algebra3D PAMImage)
