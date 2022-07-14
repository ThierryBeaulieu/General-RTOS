//
//  Node.cpp
//  RTOS
//
//  Created by Thierry Beaulieu on 2022-02-05.
//

#include "Node.h"

Node::Node(){
    currentItem_ = nullptr;
}

Node::Node( const Task& item ){
    currentItem_ = &item;
}
