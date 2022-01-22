//
//  main.cpp
//  Dev_stack_data_structure
//
//  Created by Thierry Beaulieu on 2022-01-21.
//

/* TODO:
 * Make the node class only accessible via TaskStack
 */

#include <iostream>
#include <assert.h>
#include <vector>
#include "TaskQueue.h"
#include "OperatingSystem.h"
#include "ShowTaskName.h"

#define OPERATIONS_IN_TASKQUEUE true
#define TASKS_MANIPULATION_WITH_OS true


int main() {
    
#if OPERATIONS_IN_TASKQUEUE
    
    std::string taskName1 = "blinking light";
    std::string taskName2 = "write something";
    std::string taskName3 = "write anotherthing";

    ShowTaskName task1(taskName1);
    ShowTaskName task2(taskName2);
    ShowTaskName task3(taskName3);

    TaskQueue queue = TaskQueue();
    
    queue.addTask(task1);
    queue.addTask(task2);
    queue.addTask(task3);
    
    assert(queue.peekTopTask().getName() == taskName1);
    assert(queue.peekTopTask().getName() == taskName1);
    assert(queue.peekTopTask().getName() == taskName1);
    assert(queue.popTopTask().getName() == taskName1);
    
    assert(queue.peekTopTask().getName() == taskName2);
    assert(queue.peekTopTask().getName() == taskName2);
    assert(queue.peekTopTask().getName() == taskName2);
    assert(queue.popTopTask().getName() == taskName2);
    
    assert(queue.peekTopTask().getName() == taskName3);
    assert(queue.peekTopTask().getName() == taskName3);
    assert(queue.peekTopTask().getName() == taskName3);
    assert(queue.popTopTask().getName() == taskName3);
    
#endif
    
#if TASKS_MANIPULATION_WITH_OS
    OperatingSystem os;
    
    std::string taskNameForOS1 = "green light";
    std::string taskNameForOS2 = "red light";
    
    ShowTaskName taskAction1 = ShowTaskName(taskNameForOS1);
    ShowTaskName taskAction2 = ShowTaskName(taskNameForOS2);
    
    taskAction1.action();
    taskAction2.action();
            
    os.addTask(taskAction1);
    os.addTask(taskAction2);
    
#endif
    
    return 0;
}
