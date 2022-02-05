//
//  TaskStack.cpp
//  Dev_stack_data_structure
//
//  Created by Thierry Beaulieu on 2022-01-21.
//

#include "TaskQueue.h"

TaskQueue::TaskQueue()
{
    mainQueue_ = std::make_unique<Queue<Task>>();
    
    for(int i = 0; i < NB_PRIORITIES; i++){
        priorities_[i] = std::make_shared<Queue<Task>>();
    }
}

void TaskQueue::addTask(const Task& task){
    priorities_[task.getPriority()-1]->add(task);
}

const Task* TaskQueue::popTask(){
    // TODO: Add Array elements to the queue.
    // If there are no elements in the array,
    // nullptr is return
    
    // If there is something inside the array, something is returned.
    return mainQueue_->popTop();
}

const Task* TaskQueue::peekTask(){
    // TODO:
    return mainQueue_->peekTop();
}
