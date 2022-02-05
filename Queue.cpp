//
//  Queue.cpp
//  RTOS
//
//  Created by Thierry Beaulieu on 2022-02-05.
//

#include "Queue.h"


Queue::Queue()
{
    mainQueue_ = nullptr;
}

const Task* Queue::peekTopTask()
{
    if ( mainQueue_ != nullptr ){
        return mainQueue_.get()->currentItem_;
    } else {
        return nullptr;
    }
}

const Task* Queue::popTopTask()
{
    try
    {
        if ( mainQueue_ != nullptr ){
            
            std::shared_ptr<Node> prevNode = mainQueue_->prevNode_;
            const Task& item = *mainQueue_.get()->currentItem_;
            mainQueue_ = prevNode;
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

void Queue::addTask( const Task& task )
{
    // Keeps a copy of the address of the node
    std::shared_ptr<Node> iterator_ = mainQueue_;
    
    // If it's the first element, we need to
    // create a first element.
    if( mainQueue_ == nullptr){
        mainQueue_ = std::make_shared<Node>(task);
        return;
    }
    
    while(mainQueue_->prevNode_ != nullptr)
    {
        mainQueue_ = mainQueue_->prevNode_;
    }
    
    // The node now contains an address that points
    // towards a node that was added.
    mainQueue_->prevNode_ = std::make_shared<Node>(task);
    
    // The node's address is now the same as in
    // the beginning.
    mainQueue_ = iterator_;
}
