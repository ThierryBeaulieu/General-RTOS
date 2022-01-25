//
//  TaskStack.cpp
//  Dev_stack_data_structure
//
//  Created by Thierry Beaulieu on 2022-01-21.
//

#include "TaskQueue.h"

TaskQueue::TaskQueue()
{
    node_ = nullptr;
}

TaskQueue::TaskQueue( const Task& item )
{
    node_ = std::make_shared<Node>(item);
}

const Task* TaskQueue::peekTopTask()
{
    if ( node_ != nullptr ){
        return node_.get()->currentItem_;
    } else {
        return nullptr;
    }
}

const Task* TaskQueue::popTopTask()
{
    try
    {
        if ( node_ != nullptr ){
            
            std::shared_ptr<Node> prevNode = node_->prevNode_;
            const Task& item = *node_.get()->currentItem_;
            node_ = prevNode;
            return &item;
            
        } else {
            throw 1;
        }
    }
    catch(int n) {
        std::cout << "Ending the program. Error " << n << std::endl;
    }
    catch(...) {
        std::cout << "Unknown Error" << std::endl;
    }
    abort();
}

void TaskQueue::addTask( const Task& item )
{
    // Keeps a copy of the address of the node
    std::shared_ptr<Node> iterator_ = node_;
    
    // If it's the first element, we need to
    // create a first element.
    if( node_ == nullptr){
        node_ = std::make_shared<Node>(item);
        return;
    }
    
    // There is already a node and we iterate
    // over the nodes until one is has no address.
    // Complexity O(n)
    
    // TODO: Add the nodes according to the task's priority
    while(node_->prevNode_ != nullptr)
    {
        node_ = node_->prevNode_;
    }
    
    // The node now contains an address that points
    // towards a node that was added.
    node_->prevNode_ = std::make_shared<Node>(item);
    
    // The node's address is now the same as in
    // the beginning.
    node_ = iterator_;
}
