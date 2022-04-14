#pragma once
#ifndef _POST_NODE_VISITOR_H_
#define _POST_NODE_VISITOR_H_

#include "Node_Visitor.h"
#include "Stack.h"

class Addition_Node;
class Subtraction_Node;
class Multiplication_Node;
class Division_Node;
class Modulus_Node;
class Number_Node;
class Node;
class Binary_Node;

// visit nodes in post order (left -> right -> operator)
class Post_Node_Visitor: public Node_Visitor 
{
	public:
		Post_Node_Visitor();
		~Post_Node_Visitor();

		virtual void visit_addition_node(Addition_Node& node);
		virtual void visit_subtraction_node(Subtraction_Node& node);
		virtual void visit_multiplication_node(Multiplication_Node& node);
		virtual void visit_division_node(Division_Node& node);
		virtual void visit_modulus_node(Modulus_Node& node);
		virtual void visit_number_node(Number_Node& node);
		int get_result(void);  
	private:
		void eval_children(Binary_Node& bin_node);  

        // final result after evaluating the left and right nodes
		int result_;

        // stores left node value
		int num1_;

        // stores right node value
		int num2_;

        // stack that holds the values of the expression while traversing the tree
		Stack<int>* stack_;
};
#endif