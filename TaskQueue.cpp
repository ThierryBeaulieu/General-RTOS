//
//  TaskStack.cpp
//  Dev_stack_data_structure
//
//  Created by Thierry Beaulieu on 2022-01-21.
//

#include "TaskQueue.h"

Node::Node( const Task& item ){
    currentItem_ = &item;
}

TaskQueue::TaskQueue()
{
    node_ = nullptr;
}

TaskQueue::TaskQueue( const Task& item )
{
    node_ = std::make_shared<Node>(item);
}

const Task& TaskQueue::peekTopTask()
{
    try
    {
        if ( node_ != nullptr ){
            return *node_.get()->currentItem_;
        } else {
            throw 1;
        }
    }
    catch(int n) {
        std::cout << "Ending the program. Error " << n << std::endl;
    }
    abort();
}

const Task& TaskQueue::popTopTask()
{
    try
    {
        if ( node_ != nullptr ){
            
            std::shared_ptr<Node> prevNode = node_->prevNode_;
            const Task& item = *node_.get()->currentItem_;
            node_ = prevNode;
            return item;
            
        } else {
            throw 1;
        }
    }
    catch(int n) {
        std::cout << "Ending the program. Error " << n << std::endl;
    }
    abort();
}

void TaskQueue::addTask( const Task& item )
{
    
    if ( node_ == nullptr ){
        node_ = std::make_shared<Node>(item);
        return;
    }
    
    node_.get()->prevNode_ = std::make_shared<Node>(item);
}
