//
//  Queue.h
//  RTOS
//
//  Created by Thierry Beaulieu on 2022-02-05.
//

#ifndef Queue_h
#define Queue_h

#include "Task.h"
#include "Node.h"

class Queue {
    
public:
    
    Queue();
    
    const Task* peekTopTask();
    const Task* popTopTask();
    
    void addTask(const Task& task);
    
private:
    std::shared_ptr<Node> mainQueue_;
    std::shared_ptr<Node> lastItemMainQueue_;
};


#endif /* Queue_h */
