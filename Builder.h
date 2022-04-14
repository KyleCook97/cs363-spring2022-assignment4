#pragma once
#ifndef _BUILDER_H_
#define _BUILDER_H_

#include "Math_Expression.h"

class Builder 
{
	public:
		Builder();
		virtual ~Builder() = 0;
		virtual void start_expression(void) = 0;

		// build the nodes into a concrete Math_Expression.
		virtual void build_number(int number) = 0;
		virtual void build_addition_operator(void) = 0;
		virtual void build_subtraction_operator(void) = 0;
		virtual void build_multiplication_operator(void) = 0;
		virtual void build_division_operator(void) = 0;
		virtual void build_modulus_operator(void) = 0;
		virtual void build_open_parenthesis(void) = 0;
		virtual void build_close_parenthesis(void) = 0;

		/*
		* This checks if the builder already has a calculator (evaluating a sub-expression)
        * allowing the concrete builder to go down branches
		* @returns	boolean		If builder has a calculator
		*/
		virtual bool has_calculator(void);
		virtual Math_Expression& get_expression(void) = 0;
};
#endif