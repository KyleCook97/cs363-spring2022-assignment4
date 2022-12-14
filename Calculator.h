#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include <string>        
#include <iostream>         
#include <sstream>			
#include <stdexcept>
#include "Builder.h"

class Calculator 
{
	public:
		// default constructor
		Calculator(void);  
		Calculator(Builder& builder);
		~Calculator();

		/*
		* Evaluates an infix string
		* @param[in]      infix		   String for the infix
		* @return			result		   Answer of expression
		*/
		int evaluate(const std::string& infix);

		/*
		* Evaluates a value/operator from an infix string
		* @param[in]      val		   String that holds a stream value from an infix string
		*/
		void evaluate_val(const std::string& val);

		/*
		* Gets the result of an expression
		* Useful when evaluating value by value instead of an entire string
		* @return			result		   Answer of expression
		*/
		int get_result(void);

		/*
		* Lets the calculator know to start an expression with the builder
		* Useful when evaluating value by value instead of an entire string
		*/
		void start_manual_expression(void);

		/*
		* Retrieves the current builder of the calculator
		* @throws		std::exception		when a builder does not exist
		* @return		Builder				The builder of the calculator
		*/
		Builder& get_builder(void);

	private:
		Builder* builder_;

};
#endif