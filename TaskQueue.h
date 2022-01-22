//
//  TaskStack.h
//  Dev_stack_data_structure
//
//  Created by Thierry Beaulieu on 2022-01-21.
//

#ifndef TaskQueue_h
#define TaskQueue_h

#include <iostream>
#include <memory>
#include <exception>

#include "Task.h"
#include "Node.h"

class Node;

class TaskQueue {
public:
    TaskQueue();
    TaskQueue( const Task& item );
    
    const Task& peekTopTask();
    const Task& popTopTask();
    
    void addTask(const Task& item);
    
private:
    std::shared_ptr<Node> node_;
};

#endif /* TaskQueue_h */
