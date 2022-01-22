//
//  Node.h
//  RTOS
//
//  Created by Thierry Beaulieu on 2022-01-22.
//

#ifndef Node_h
#define Node_h

#include <iostream>
#include "Task.h"
#include "TaskQueue.h"

class Node {
public:
    Node( const Task& item );
    
    const Task* currentItem_ = nullptr;
    
    std::shared_ptr<Node> nextNode_;
    std::shared_ptr<Node> prevNode_;
};


#endif /* Node_h */
