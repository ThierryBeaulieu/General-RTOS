//
//  main.cpp
//  Dev_stack_data_structure
//
//  Created by Thierry Beaulieu on 2022-01-21.
//

#include <iostream>
#include "TaskQueue.h"
#include "OperatingSystem.h"
#include "ShowString.h"

/* TODO:
 * Make the node class only accessible via TaskStack
 */

int main() {
    
    OperatingSystem* os = OperatingSystem::createInstance();
    
    ShowString something = ShowString("First string");
    ShowString something2 = ShowString("Second string");
    something.action();
    something2.action();
            
    os->addTask(something);
    os->addTask(something2);
    
    return 0;
}
