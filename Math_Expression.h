#pragma once
#ifndef _MATH_EXPRESSION_H_
#define _MATH_EXPRESSION_H_

class Math_Expression
{
	public:
		Math_Expression();  
		virtual ~Math_Expression();  

        // evaluate the expression return the result
		virtual int eval(void) = 0;  
};
#endif