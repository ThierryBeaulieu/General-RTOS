//
//  TaskStack.cpp
//  Dev_stack_data_structure
//
//  Created by Thierry Beaulieu on 2022-01-21.
//

#include "TaskQueue.h"

TaskQueue::TaskQueue()
{
    mainQueue_ = std::make_unique<Node>();
    
    for(int i = 0; i < NB_PRIORITIES; i++){
        priorities_[i] = nullptr;
    }
}
