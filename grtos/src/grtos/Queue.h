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
    
    const T* peekTop();
    const T* popTop();
    
    void add(const T& task);
    
    int getnbItem(){
        return nbItem_;
    }
    
private:
    
    int nbItem_;
    std::shared_ptr<Node> queue_;
    std::shared_ptr<Node> lastItem_;
};


template<typename T>
Queue<T>::Queue()
{
    queue_ = nullptr;
    lastItem_ = nullptr;
    nbItem_ = 0;
}

template<typename T>
const T* Queue<T>::peekTop()
{
    if ( queue_ != nullptr ){
        return queue_.get()->currentItem_;
    } else {
        return nullptr;
    }
}

template<typename T>
const T* Queue<T>::popTop()
{
    try
    {
        if ( queue_ != nullptr ){
            
            std::shared_ptr<Node> prevNode = queue_->prevNode_;
            const T& item = *queue_.get()->currentItem_;
            queue_ = prevNode;
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
void Queue<T>::add( const T& task )
{
    
    // If it's the first element, we need to
    // create a first element.
    if( queue_ == nullptr){
        queue_ = std::make_shared<Node>(task);
        nbItem_++;
        lastItem_ = queue_;
        return;
    }
    
    // The node now contains an address that points
    // towards a node that was added.
    lastItem_->prevNode_ = std::make_shared<Node>(task);
    
    // Increment the number of items in the queue.
    nbItem_++;
    
    lastItem_ = lastItem_->prevNode_;
}


#endif /* Queue_h */
