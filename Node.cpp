//
//  Node.cpp
//  RTOS
//
//  Created by Thierry Beaulieu on 2022-01-22.
//

#include "Node.h"

Node::Node( const Task& item ){
    currentItem_ = &item;
}
