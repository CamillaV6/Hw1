
#include <iostream>
#include <string> //std::stoi that converts to int
#include <stdexcept> //catching exceptions
#include <vector> //includes vectors
#include <cmath> //inclues log calculation

using namespace std;

/*
 * The thought about the sum of the digits of an exponent value has 
 * occured to me all the time. I can never stop thinking about the 
 * sum of the digits of an exponent.
*/

unsigned long long int power(unsigned int base, unsigned int exponent) { //calculates the exponent
	
	unsigned long long int total = 1;
	
	for (int i = 0; i < exponent; i++) { //use loop so number will multiply by the base for exponent amount of times
		total = total * base;
	}
	
	return total;
} 
	
vector<int> vectorize_digits(unsigned long long n) { //takes digits of number and puts in vector
	
	int num;
	vector<int> digits;
	
	while (n > 0) { 
		num = n % 10;
		digits.insert(digits.begin(), num); //inserts at beginning for consistant num placement: 10s before 1s, 100s before 10s, etc.
		n /= 10;
	}
		
		/* 
		 * used method from a previous java program:
		 * loops until there are no digits in number
		 * takes one place and adds it to sum
		 * inserts digit
		 * takes off one place
		*/

	return digits;
}

string vec_to_string(vector<int> vec) { //puts vector values into a string, used for debugging
	
	string numbers = "[";
	
	for (int i = 0; i < vec.size(); i++) {
		numbers = numbers + to_string(vec[i]);
		if (i < vec.size() - 1) { //doesn't add ", " if at end of vector
			numbers = numbers + ", ";
		}
	}
	
	numbers = numbers + "]";
	
	return numbers;
}
	
int sum_vector(vector<int> v) {  //takes numbers from vector and adds them
	
	int sum = 0;
	
	for (int i = 0; i < v.size(); i ++) { //loops through each number in vector
		sum = sum + v[i];		
	}

	return sum;
}

int main(int argc, char* argv[]) { //https://www.geeksforgeeks.org/cpp/command-line-arguments-in-cpp/
	
	int base; //initiates variables in scope
	int exponent;
	
	if (argc != 3) { //makes sure the right amoung of arguments were input
		cout << "please input 2 integers" << endl;
		
		return 1;
	}
	
	//chacking validity
	try { //tries convering to int
		base = stoi(argv[1]);
		exponent = stoi(argv[2]);
		//Google seach overview helped me converting arguments to int
		//also helped with error types
	}
	catch (const invalid_argument& e) { //if invalid, catches and asks for int inputs
		cout << "please enter integers" << endl;
		return 1;
	}
	catch (const out_of_range& e) { //if too large of a number, catches
		cout << "number is too large" << endl;
		return 1;
	}
	if (base < 0 || exponent < 0) { //checks positive int
		cout << "positive integers only" << endl;
		return 1;
	}
	if (!((exponent * log(base)) < (64 * log(2)))) {//checks overflow
		cout << "Overflow Error! Please choose smaller numbers!" << endl;
		return 1;
	}

	unsigned long long int pvalue = power(base, exponent);
	cout << argv[1] << "^" << argv[2] << " = " << pvalue << endl;
	
	vector<int> digits = vectorize_digits(pvalue);
	
	cout << vec_to_string(digits) << endl; //for testing
	
	int sum = sum_vector(digits);
	cout << "sum of digits is " << sum << endl;
		
	return 0; //successfully ran
}
