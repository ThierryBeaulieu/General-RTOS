//
//  TaskStack.cpp
//  Dev_stack_data_structure
//
//  Created by Thierry Beaulieu on 2022-01-21.
//

#include "TaskQueue.h"

TaskQueue::TaskQueue(){
    mainQueue_ = std::make_unique<Queue<Task>>();
    
    for(int i = 0; i < NB_PRIORITIES; i++){
        priorities_[i] = std::make_shared<Queue<Task>>();
    }
}

void TaskQueue::addTask(const Task& task){
    
    // TODO: Fix this bug. The items aren't
    // added to the different queues.
    
    priorities_[task.getPriority()-1]->add(task);
}

const Task* TaskQueue::popTask(){
    
    // Iterates over the array of tasks
    // to add them, form the most to the least
    // important
    
    // The algorithm could be improved
    for ( int i = 0; i < NB_PRIORITIES; i++ ){
        while ( priorities_[i] != nullptr){
            while(priorities_[i]->peekTop() != nullptr){
                mainQueue_->add(*(priorities_[i]->popTop()));
            }
        }
    }
    
    // If there is something inside the array, something is returned.
    return mainQueue_->popTop();
}

const Task* TaskQueue::peekTask(){
    return mainQueue_->peekTop();
}
