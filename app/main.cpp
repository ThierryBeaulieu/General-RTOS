#include <iostream>
#include <assert.h>
#include <vector>

#include <grtos/Queue.h>
#include <grtos/OperatingSystem.h>
#include <grtos/ShowTaskName.h>

#define OPERATIONS_IN_QUEUE true
#define TASKS_MANIPULATION_WITH_OS true

int main()
{

#if OPERATIONS_IN_QUEUE

    std::string taskName1 = "blinking light";
    std::string taskName2 = "write something";
    std::string taskName3 = "write anotherthing";

    unsigned char priority1 = 1;
    unsigned char priority2 = 2;
    unsigned char priority3 = 3;
    unsigned char priority6 = 6;

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

    std::string taskNameForOS1 = "task priority 1.";
    std::string taskNameForOS3 = "task priority 3.";
    std::string taskNameForOS21 = "task priority 2.1";
    std::string taskNameForOS22 = "task priority 2.2";
    std::string taskNameForOS6 = "task priority 6.";

    ShowTaskName taskAction1 = ShowTaskName(taskNameForOS1, priority1);
    ShowTaskName taskAction3 = ShowTaskName(taskNameForOS3, priority3);
    ShowTaskName taskAction21 = ShowTaskName(taskNameForOS21, priority2);
    ShowTaskName taskAction22 = ShowTaskName(taskNameForOS22, priority2);
    ShowTaskName taskAction6 = ShowTaskName(taskNameForOS6, priority6);

    // The order in which the tasks are
    // added doesn't matter, the result
    // will be the same.
    os.addTask(taskAction6);
    os.addTask(taskAction3);
    os.addTask(taskAction21);
    os.addTask(taskAction1);
    os.addTask(taskAction22);

    taskNameForOS1 = "task priority 1.0";
    taskNameForOS3 = "task priority 3.0";
    taskNameForOS21 = "task priority 2.1";
    taskNameForOS22 = "task priority 2.2";
    taskNameForOS6 = "task priority 6.0";

    // It executes the tasks
    os.run();

#endif

    return 0;
}
