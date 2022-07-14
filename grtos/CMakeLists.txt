add_library(
    grtos
    src/grtos/Node.h
    src/grtos/Node.cpp
    src/grtos/TaskQueue.h
    src/grtos/TaskQueue.cpp
    src/grtos/OperatingSystem.h
    src/grtos/OperatingSystem.cpp
    src/grtos/Queue.h
    src/grtos/ShowTaskName.h
    src/grtos/ShowTaskName.cpp
    src/grtos/Task.h
    src/grtos/Task.cpp

)

target_include_directories(grtos PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)