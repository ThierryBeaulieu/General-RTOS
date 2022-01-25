//
//  ShowTaskName.h
//  Dev_stack_data_structure
//
//  Created by Thierry Beaulieu on 2022-01-22.
//

#ifndef ShowTaskName_h
#define ShowTaskName_h

#include "Task.h"
#include <iostream>

class ShowTaskName: public Task
{
public:
    ShowTaskName(const std::string& name, unsigned char priority);
    ShowTaskName(const std::string& name);
    
    ~ShowTaskName() = default;
    
    virtual void action();
    
};

#endif /* ShowTaskName_h */
