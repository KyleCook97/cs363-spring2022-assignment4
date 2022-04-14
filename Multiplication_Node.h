#pragma once
#ifndef _MULTIPLICATION_NODE_H_
#define _MULTIPLICATION_NODE_H_

#include "Binary_Node.h"
class Node_Visitor;

class Multiplication_Node : public Binary_Node
{
	public:
		Multiplication_Node();  
		virtual void accept(Node_Visitor& visitor); 
};
#endif