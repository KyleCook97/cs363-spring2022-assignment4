#include "Post_Node_Visitor.h"
#include "Addition_Node.h"
#include "Subtraction_Node.h"
#include "Multiplication_Node.h"
#include "Division_Node.h"
#include "Modulus_Node.h"
#include "Number_Node.h"
#include "Binary_Node.h"

Post_Node_Visitor::Post_Node_Visitor()
	:result_(0),
	num1_(0),
	num2_(0),
	stack_(new Stack<int>())
{
    
}

Post_Node_Visitor::~Post_Node_Visitor()
{
	if (stack_ != nullptr) 
    {
		delete stack_;
	}
}

void Post_Node_Visitor::visit_addition_node(Addition_Node& node)
{
	eval_children(node);
	stack_->push(num1_ + num2_);
}

void Post_Node_Visitor::visit_subtraction_node(Subtraction_Node& node)
{
	eval_children(node);
	stack_->push(num1_ - num2_);
}

void Post_Node_Visitor::visit_multiplication_node(Multiplication_Node& node)
{
	eval_children(node);
	stack_->push(num1_ * num2_);
}

void Post_Node_Visitor::visit_division_node(Division_Node& node)
{
	eval_children(node);
}