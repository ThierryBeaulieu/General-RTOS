//
//  ShowString.h
//  Dev_stack_data_structure
//
//  Created by Thierry Beaulieu on 2022-01-22.
//

#ifndef ShowString_h
#define ShowString_h

#include "Task.h"
#include <iostream>

class ShowString: public Task
{
public:
    ShowString(const std::string& name);
    ~ShowString() = default;
    
    virtual void action();
    
};

#endif /* ShowString_h */
