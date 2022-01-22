//
//  ShowTaskName.cpp
//  Dev_stack_data_structure
//
//  Created by Thierry Beaulieu on 2022-01-22.
//

#include "ShowTaskName.h"

ShowTaskName::ShowTaskName(const std::string& name): Task(name){}

void ShowTaskName::action(){
    std::cout << this->Task::getName() << std::endl;
}
