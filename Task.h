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
    Task(const std::string& name, unsigned char priority);
    Task(const std::string& name);
    
    ~Task() = default;
    
    const std::string& getName() const;
    unsigned char getPriority() const;
    
    virtual void action() = 0;
    
private:
    Task();
    const std::string* name_ = nullptr;
    unsigned char priority_;
    const unsigned char PRIORITY_MIN = 15;
    const unsigned char PRIORITY_MAX = 1;
};

#endif /* Task_h */
