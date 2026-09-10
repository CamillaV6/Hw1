
#include <iostream>
#include <string> //std::stoi that converts to int
#include <stdexcept> //catching exceptions
#include <cmath> //inclues log calculation
#include <vector> //includes vectors
//https://www.w3schools.com/cpp/cpp_vectors.asp used for vector functions


using namespace std;

/*
 * The thought about the sum of the digits of an exponent value has 
 * occured to me all the time. I can never stop thinking about the 
 * sum of the digits of an exponent.
*/

unsigned long long int power(unsigned int base, unsigned int exponent) { //calculates the exponent
	
	if (exponent == 0) {
		return 1;
	}
	
	unsigned long long int total = base; //set total as 1 so it will return 1 if exponent is 0
	
	for (int i = 0; i < exponent - 1; i++) { //use loop so number will multiply for exponent amount of times but skip if exonent is 0
		total = total * base;
	}
	
	return total;
} 
	
vector<int> vectorize_digits(unsigned long long n) { //takes digits of number and puts in vector
	
	int num;
	vector<int> digits;
	
	while (n > 0) { //use method of taking digits from previous java program
		num = n % 10;
		digits.insert(digits.begin(), num); //inserts at beginning for consistant num placement: 10s before 1s, 100s before 10s, etc.
		n /= 10;
	}

	return digits;
}

string vec_to_string(vector<int> vec) { //puts vector values into a string, used for debugging
	
	string numbers = "[";
	
	for (int i = 0; i < vec.size(); i++) { //https://www.geeksforgeeks.org/cpp/converting-number-to-string-in-cpp/ used to remember to_string
		numbers = numbers + to_string(vec[i]); //https://stackoverflow.com/questions/48251254/how-can-i-insert-element-into-beginning-of-vector used to insert at beginning of vector
		if (i < vec.size() - 1) { //doesn't add ", " if at end of vector
			numbers = numbers + ", ";
		}
	}
	
	numbers = numbers + "]";
	
	return numbers;
}
	
int sum_vector(vector<int> v) {  //takes numbers from vector and adds them
	
	int sum = 0;
	
	for (int i = 0; i < v.size(); i ++) {
		sum = sum + v[i];		
	}

	return sum;
}

int main(int argc, char* argv[]) { //https://www.geeksforgeeks.org/cpp/command-line-arguments-in-cpp/ used for getting arguments
	
	int base; //initiates variables in scope so doesn't crash
	int exponent;
	
	if (argc != 3) { //makes sure the right amoung of arguments were input
		cout << "please input 2 integers" << endl;
		
		return 1; //return 1 to denote some sort of error
	}
	
	//chacking validity with try catch because I find it easier than converting to string and finding specific characters
	try { //tries convering to int
		
		base = stoi(argv[1]);
		exponent = stoi(argv[2]);
		//Google seach overview helped me converting arguments to int
		//also helped with error types
		if ((to_string(base).size() != string(argv[1]).length()) || (to_string(exponent).size() != string(argv[2]).length())) {
			cout << "please enter integers" << endl;
			return 1;
		}
		
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
	if (base == 0 && exponent == 0) {
		cout << "0 ^ 0 is undefined" << endl;
		return 1;
	}
	if (!((exponent * log(base)) < (64 * log(2)))) {//checks overflow
		cout << "Overflow Error! Please choose smaller numbers!" << endl;
		return 1;
	}

	unsigned long long int pvalue = power(base, exponent);
	cout << argv[1] << "^" << argv[2] << " = " << pvalue << endl;
	
	vector<int> digits = vectorize_digits(pvalue);
	
	//cout << vec_to_string(digits) << endl; //for testing
	
	int sum = sum_vector(digits);
	cout << "sum of digits is " << sum << endl;
		
	return 0; //successfully ran
}
