//
//  Task.cpp
//  Dev_stack_data_structure
//
//  Created by Thierry Beaulieu on 2022-01-21.
//

#include "Task.h"

Task::Task(const std::string& name, unsigned char priority): name_(&name), priority_(priority){}

Task::Task(const std::string& name): name_(&name){  priority_ = PRIORITY_MIN;}

unsigned char Task::getPriority() const {
    return priority_;
}
const std::string& Task::getName() const {
    return *name_;
}
