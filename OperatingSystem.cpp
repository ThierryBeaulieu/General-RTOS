//
//  OperatingSystem.cpp
//  Dev_stack_data_structure
//
//  Created by Thierry Beaulieu on 2022-01-21.
//

#include "OperatingSystem.h"

OperatingSystem::OperatingSystem()
{
    taskQueue_ = std::make_shared<TaskQueue>();
}

void OperatingSystem::addTask(const Task& task){
    taskQueue_->addTaskMainQueue(task);
}

void OperatingSystem::run() const {
    while(taskQueue_->peekTopTask() != nullptr)
    {
        taskQueue_->popTopTask()->action();
    }
}
