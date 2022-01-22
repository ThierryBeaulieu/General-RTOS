//
//  OperatingSystem.cpp
//  Dev_stack_data_structure
//
//  Created by Thierry Beaulieu on 2022-01-21.
//

#include "OperatingSystem.h"

OperatingSystem::OperatingSystem()
{
    OperatingSystem::taskQueue_ = std::make_shared<TaskQueue>();
}

void OperatingSystem::addTask(const Task& task){
    OperatingSystem::taskQueue_->addTask(task);
}

void OperatingSystem::run(){
    // TODO: Use the tasks in the TaskQueue and execute them
}
