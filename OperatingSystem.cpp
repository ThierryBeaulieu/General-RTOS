//
//  OperatingSystem.cpp
//  Dev_stack_data_structure
//
//  Created by Thierry Beaulieu on 2022-01-21.
//

#include "OperatingSystem.h"

OperatingSystem* OperatingSystem::instance_ = nullptr;

OperatingSystem* OperatingSystem::createInstance(){
    if(instance_ == nullptr)
    {
        OperatingSystem os;
        instance_ = &os;
    }
    return instance_;
}

OperatingSystem::OperatingSystem()
{
    taskQueue_ = std::make_unique<TaskQueue>();
}

void OperatingSystem::addTask(const Task& task){
    taskQueue_->addTask(task);
}

void OperatingSystem::run(){
    // TODO: Use the tasks in the TaskQueue and execute them
}
