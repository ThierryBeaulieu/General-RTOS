//
//  OperatingSystem.h
//  Dev_stack_data_structure
//
//  Created by Thierry Beaulieu on 2022-01-21.
//

#ifndef OperatingSystem_h
#define OperatingSystem_h

#include <iostream>
#include "TaskQueue.h"

class OperatingSystem
{
public:
    OperatingSystem();
    void addTask(const Task& task);
    void run() const;

private:
    std::unique_ptr<TaskQueue> taskQueue_;
};

#endif /* OperatingSystem_h */
