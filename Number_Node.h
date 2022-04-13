#pragma once
#ifndef _NUMBER_NODE_H_
#define _NUMBER_NODE_H_

#include "Node.h"
class Node_Visitor;

class Number_Node : public Node 
{
    public:
        Number_Node();

        // constructor that takes in the value of the number node
        Number_Node(int num);  

        // visit the number node
        virtual void accept(Node_Visitor& visitor);  

        int get_value();  
        virtual bool is_leaf();

    private:
        int value_;  // value of the node.
};
#endif