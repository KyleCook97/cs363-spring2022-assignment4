#pragma once
#ifndef _TREE_BUILDER_H_
#define _TREE_BUILDER_H_

#include "Builder.h"
#include "Math_Expression.h"
#include "Number_Node.h"
#include "Addition_Node.h"
#include "Subtraction_Node.h"
#include "Multiplication_Node.h"
#include "Division_Node.h"
#include "Modulus_Node.h"
#include "Tree.h"
#include "Calculator.h"
#include <stdexcept>

class Tree_Builder: public Builder
{
	public:
		Tree_Builder();  
		~Tree_Builder();  
		virtual void start_expression(void);  // create a new tree.
		virtual void build_number(int number);  // add a number to the tree
		virtual void build_addition_operator(void);  // add addition to the tree
		virtual void build_subtraction_operator(void);  // add subtraction to the tree
		virtual void build_multiplication_operator(void);  // add multiplication to the tree
		virtual void build_division_operator(void);  // add division to the tree
		virtual void build_modulus_operator(void); // add modulus to the tree
		virtual void build_open_parenthesis(void);  // build the tree with respect to parenthesis.
		virtual void build_close_parenthesis(void);  // finish a parenthesis.
		virtual Math_Expression& get_expression(void);  // get the abstract math expression (concrete Tree).s

		/*
		* If the current builder has its own calculator for a sub expression
		* @returns	boolean		If builder has a calculator
		*/
		virtual bool has_calculator(void);
	private:
		void insert_binary_node(Binary_Node& node); 

        // Returns true if there is a tree head
		bool ensure_head();  

        // This instance of a calculator is only used when evaluating the contents within a set of parenthesis
		Calculator* calc_;
		Tree* tree_;

        // Binary node that needs to be completed
		Binary_Node* incomplete_node_;  
};
#endif