//
//  Node.h
//  RTOS
//
//  Created by Thierry Beaulieu on 2022-02-05.
//

#ifndef Node_h
#define Node_h

#include "Task.h"

class Node {
public:
    Node( const Task& item );
    const Task* currentItem_ = nullptr;
    
    std::shared_ptr<Node> nextNode_;
    std::shared_ptr<Node> prevNode_;
};

#endif /* Node_h */
