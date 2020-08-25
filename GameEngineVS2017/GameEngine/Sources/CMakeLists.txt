# Tell to CMake where our includes are
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/GameEngine/Headers)

# Get all sources (using recursivity)
FILE(GLOB_RECURSE ENGINE_SOURCES *.cpp *.c)

# Get all headers (using recursivity)
FILE(GLOB_RECURSE ENGINE_HEADERS *.hpp *.h *.inl)

# Create exec by giving him all sources and headers
ADD_EXECUTABLE(GameEngine ${ENGINE_SOURCES} ${ENGINE_HEADERS})

# Link the libs we're using
TARGET_LINK_LIBRARIES(GameEngine glfw3 glew32)