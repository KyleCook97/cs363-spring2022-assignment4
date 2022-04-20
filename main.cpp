#include "Calculator.h"
#include <string>
#include "Tree_Builder.h"
#include "Builder.h"

// COMMENT Correct use of the patterns. Clean up your code.


int main(int argc, char* argv[])
{
	Builder* builder = new Tree_Builder();
	Calculator* calc = new Calculator(*builder);

	std::string infix_input;  // User input
	bool keep_going = true;

    // Loops until 'QUIT' is called
	while (keep_going) 
    {
		try 
        {
			infix_input.clear();

			std::cout << "\nPlease enter a math expression or type QUIT to exit.\n";
			std::getline(std::cin, infix_input);

            // Exit
			if (infix_input == "QUIT") 
            {
				keep_going = false;
				break;
			}

			// Evalulate the expression
			std::cout << calc->evaluate(infix_input);
		}
		catch (std::runtime_error & err) 
        {
			std::cout << "An error has occurred -> " << err.what() << "\n";
		}
		catch (std::exception & err) 
        {
			std::cout << "An error has occurred -> " << err.what() << "\n";
		}
		catch (...) 
        {
			std::cout << "An unknown error has occurred.";
		}
	}
	delete calc;
    return 0;
}
