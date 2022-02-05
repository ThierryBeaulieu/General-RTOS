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

#define NB_PRIORITIES 15

class Node;

class TaskQueue {
public:
    TaskQueue();
    void addTask(const Task& task);
    
private:
    std::shared_ptr<Node> priorities_[NB_PRIORITIES];
    std::shared_ptr<Node> mainQueue_;
};

#endif /* TaskQueue_h */
