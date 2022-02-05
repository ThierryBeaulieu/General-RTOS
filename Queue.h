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

template<typename T>
class Queue {
    
public:
    
    Queue();
    
    const T* peekTopTask();
    const T* popTopTask();
    
    void addTask(const T& task);
    
private:
    std::shared_ptr<Node> mainQueue_;
    std::shared_ptr<Node> lastItemMainQueue_;
};


template<typename T>
Queue<T>::Queue()
{
    mainQueue_ = nullptr;
}

template<typename T>
const T* Queue<T>::peekTopTask()
{
    if ( mainQueue_ != nullptr ){
        return mainQueue_.get()->currentItem_;
    } else {
        return nullptr;
    }
}

template<typename T>
const T* Queue<T>::popTopTask()
{
    try
    {
        if ( mainQueue_ != nullptr ){
            
            std::shared_ptr<Node> prevNode = mainQueue_->prevNode_;
            const T& item = *mainQueue_.get()->currentItem_;
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

template<typename T>
void Queue<T>::addTask( const T& task )
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


#endif /* Queue_h */
