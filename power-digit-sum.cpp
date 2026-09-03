
#include <iostream>
#include <string> //std::stoi that converts to int
#include <stdexcept> //catching exceptions
#include <cmath> //allows for exponent calculation for testing

/*
 
 The thought about the sum of the digits of an exponent value has 
 occured to me all the time. I can never stop thinking about the 
 sum of the digits of an exponent.

*/

unsigned int power(unsigned int base, unsigned int exponent) { //calculates the exponent
	
	if (exponent == 0) { //exponents of 0 always equal 1
	return 1;
	}
	
	unsigned int total = base;
	
	for (int i = 0; i < exponent - 1; i++) { //use loop so number will multiply by the base for exponent amount of times
		total = total * base;
		}
	
	return total;
	} 
	
int sumDigits (int num) { //calculates sum of the digits
	int sum = 0;
	
	//looped it like this because it's how I did it in Java	
	while (num > 0) { //lops until there are no digits in the number
		sum += num % 10; //takes ones place and adds it to sum
		num /= 10; //takes off digit in ones place
		}
	
	return sum;
	}

int main(int argc, char* argv[]) { //https://www.geeksforgeeks.org/cpp/command-line-arguments-in-cpp/
	
	int base; //initiates variables in scope
	int exponent;
	
	if (argc != 3) { //makes sure the right amoung of arguments were input
		std::cout << "please input 2 integers" << std::endl;
		
		return 0;
	}
	
	//chacking validity
	try { //tries convering to int
		base = std::stoi(argv[1]);
		exponent = std::stoi(argv[2]);
		//Google seach overview helped me converting arguments to int
		//also helped with error types
	}
	catch (const std::invalid_argument& e) { //if invalid, catches and asks for int inputs
		std::cout << "please enter integers" << std::endl;
		return 0;
	}
	catch (const std::out_of_range& e) { //if too large of a number, catches
		std::cout << "number is too large" << std::endl;
		return 0;
	}
	if (base < 0 || exponent < 0) {
		std::cout << "positive integers only" << std::endl;
		return 0;
	}

	int pvalue = power(base, exponent);
	std::cout << argv[1] << "^" << argv[2] << " = " << pvalue << std::endl;
	
	int sum = sumDigits(pvalue);
	std::cout << "sum of digits is " << sum << std::endl;
	
	return 0;
}
