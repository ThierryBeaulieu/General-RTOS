//
//  Task.h
//  Dev_stack_data_structure
//
//  Created by Thierry Beaulieu on 2022-01-21.
//

#ifndef Task_h
#define Task_h

#include <iostream>
#include <string>

class Task{
public:
    Task(const std::string& name);
    ~Task() = default;
    
    const std::string& getName() const;
    
    virtual void action() = 0;
    
private:
    const std::string* name_ = nullptr;
};

#endif /* Task_h */
