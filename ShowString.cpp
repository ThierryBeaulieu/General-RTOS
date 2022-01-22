//
//  ShowString.cpp
//  Dev_stack_data_structure
//
//  Created by Thierry Beaulieu on 2022-01-22.
//

#include "ShowString.h"


ShowString::ShowString(const std::string& name): Task(name){}

void ShowString::action(){
    std::cout << this->Task::getName() << std::endl;
}
