//
//  OperatingSystem.cpp
//  Dev_stack_data_structure
//
//  Created by Thierry Beaulieu on 2022-01-21.
//

#include "OperatingSystem.h"

OperatingSystem::OperatingSystem()
{
    taskQueue_ = std::make_unique<TaskQueue>();
}

void OperatingSystem::addTask(const Task& task){
    taskQueue_->addTask(task);
}

void OperatingSystem::run() const {
    
    taskQueue_->generateQueue();
    
    while(taskQueue_->peekTask() != nullptr){
        taskQueue_->popTask()->action();
    }
}
