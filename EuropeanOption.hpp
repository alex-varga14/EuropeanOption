#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class EuropeanOption 
{
 private:
	// Initialize all default values
	void init(); 
	void copy(const EuropeanOption& src);
	
	// Kernel functions for option calc
	double CallPrice() const;
	double PutPrice() const;
	double CallDelta() const;
	double PutDelta() const;
	
 public:
	// Member data 
	double r;	// Interest Rate
	double sig;	// Volatility
	double K;	// Strike Price
	double T; 	// Expiry Date
	double U; 	// Current Underlying Price
	double b; 	// Cost of carry
	double N = 1;
	
	string optType; 	// Option name - call or put
	
	// Rule of Big 3
	
	// Constructors
	EuropeanOption();
	EuropeanOption(const EuropeanOption& option2); // Cpy CTOR
	EuropeanOption(const string& optionType); 	// Create option
	
	// Destructor
	virtual ~EuropeanOption();
	
	// Assignment Operator
	EuropeanOption& operator =(const EuropeanOption& src);
	
	// Func to calc option price and Delta
	double Price() const;
	double Delta() const;
	
	// Modifier
	void toggle(); // Change opt type 
 
 
};
	
	
	
	