//
//  TaskStack.cpp
//  Dev_stack_data_structure
//
//  Created by Thierry Beaulieu on 2022-01-21.
//

#include "TaskQueue.h"

TaskQueue::TaskQueue()
{
    mainQueue_ = nullptr;
    
    for(int i = 0; i < NB_PRIORITIES; i++){
        priorities_[i] = nullptr;
    }
}

const Task* TaskQueue::peekTopTask()
{
    if ( mainQueue_ != nullptr ){
        return mainQueue_.get()->currentItem_;
    } else {
        return nullptr;
    }
}

const Task* TaskQueue::popTopTask()
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

void TaskQueue::addTaskMainQueue( const Task& task )
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


void TaskQueue::addTask(const Task& task){
    
}
