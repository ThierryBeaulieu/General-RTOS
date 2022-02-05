//
//  Node.cpp
//  RTOS
//
//  Created by Thierry Beaulieu on 2022-02-05.
//

#include "Node.h"


Node::Node( const Task& item ){
    currentItem_ = &item;
}
