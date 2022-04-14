#pragma once
#ifndef _TREE_H_
#define _TREE_H_

#include "Math_Expression.h"
#include "Node.h"
#include "Post_Node_Visitor.h"
#include <stdexcept>

class Tree: public Math_Expression 
{
	public:
		Tree();
		~Tree();
		virtual int eval(void);
		Node& get_head();
		void set_head(Node& node);

	private:
		Node* head_;
		Post_Node_Visitor* visitor_;
};
#endif