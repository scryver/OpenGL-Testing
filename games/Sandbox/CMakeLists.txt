set(EXECUTABLE_NAME "Sandboxing")
add_executable(${EXECUTABLE_NAME}
    src/main.cpp
)

target_link_libraries(${EXECUTABLE_NAME} gcEngine)
