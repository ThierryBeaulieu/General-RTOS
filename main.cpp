//
//  main.cpp
//  Dev_stack_data_structure
//
//  Created by Thierry Beaulieu on 2022-01-21.
//

#include <iostream>
#include <assert.h>
#include <vector>
#include "Queue.h"
#include "OperatingSystem.h"
#include "ShowTaskName.h"

#define OPERATIONS_IN_QUEUE true
#define TASKS_MANIPULATION_WITH_OS true

 
int main() {
    
#if OPERATIONS_IN_QUEUE
    
    std::string taskName1 = "blinking light";
    std::string taskName2 = "write something";
    std::string taskName3 = "write anotherthing";
    
    unsigned char priority1 = 1;
    unsigned char priority2 = 3;
    unsigned char priority3 = 4;

    ShowTaskName task1(taskName1);
    ShowTaskName task2(taskName2);
    ShowTaskName task3(taskName3);

    Queue<Task> queue = Queue<Task>();
    
    queue.add(task1);
    queue.add(task2);
    queue.add(task3);
    
    assert(queue.peekTop()->getName() == taskName1);
    assert(queue.peekTop()->getName() == taskName1);
    assert(queue.peekTop()->getName() == taskName1);
    assert(queue.popTop()->getName() == taskName1);
    
    assert(queue.peekTop()->getName() == taskName2);
    assert(queue.peekTop()->getName() == taskName2);
    assert(queue.peekTop()->getName() == taskName2);
    assert(queue.popTop()->getName() == taskName2);
    
    assert(queue.peekTop()->getName() == taskName3);
    assert(queue.peekTop()->getName() == taskName3);
    assert(queue.peekTop()->getName() == taskName3);
    assert(queue.popTop()->getName() == taskName3);
    
    assert(queue.peekTop() == nullptr);
    
#endif
    
#if TASKS_MANIPULATION_WITH_OS
    OperatingSystem os;
    
    std::string taskNameForOS1 = "task 1";
    std::string taskNameForOS2 = "task 2";
    std::string taskNameForOS3 = "task 3";
    
    ShowTaskName taskAction1 = ShowTaskName( taskNameForOS1, priority1 );
    ShowTaskName taskAction2 = ShowTaskName( taskNameForOS2, priority2 );
    ShowTaskName taskAction3 = ShowTaskName( taskNameForOS3, priority3 );
           
    os.addTask(taskAction1);
    os.addTask(taskAction2);
    os.addTask(taskAction3);
    
    os.addTask(taskAction1);
    os.addTask(taskAction2);
    os.addTask(taskAction3);
    
    taskNameForOS1 = "task 1.1";
    taskNameForOS2 = "task 1.2";
    taskNameForOS3 = "task 1.3";
    
    os.run();
    
#endif
    
    return 0;
}
