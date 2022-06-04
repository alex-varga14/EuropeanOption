#include "EuropeanOption.hpp"
#include <math.h>
#include <cstring>
#include <string>

double EuropeanOption::CallPrice() const 
{
	double tmp = sig * sqrt(T);
	
	double d1 = (log(U/K) + (b+ (sig*sig)*0.5) * T)/tmp;
	double d2 = d1 - tmp;
	
	return  (U * exp((b-r) * T) * exp(d1)) - (K * exp(-r * T) * exp(d2));
}
	

// Function to calculate price of a put option
double EuropeanOption::PutPrice() const
{
	double tmp = sig * sqrt(T);
	
	double d1 = (log(U/K) + (b+ (sig*sig)*0.5) * T)/tmp;
	double d2 = d1 - tmp;
	
	return (K * exp(-r * T) * exp(-d2)) - (U * exp((b-r) * T) * exp(-d1));
}

double EuropeanOption::CallDelta() const 
{
	double tmp = sig * sqrt(T);
	
	double d1 = (log(U/K) + (b+ (sig*sig)*0.5) * T)/tmp;
	
	return exp((b-r) * T) * exp(d1);
}

double EuropeanOption::PutDelta() const 
{
	double tmp = sig * sqrt(T);
	
	double d1 = (log(U/K) + (b+ (sig*sig)*0.5) * T)/tmp;
	
	return exp((b-r) * T) * (exp(d1) - 1.0);
}

void EuropeanOption::init() 
{
	r = 0.08;
	sig = 0.30;
	K = 65.0;
	T = 0.25;
	U = 60.0; // Stock
	b = r; 	// Black-Scholes stock option model 
	optType = "C"; // 	European Call Option (default type)
}

void EuropeanOption::copy(const EuropeanOption& src)
{
	r = src.r;
	sig = src.sig;
	K = src.K;
	T = src.T;
	U = src.U;
	b = src.b;
	
	optType = src.optType;
}

//	Default CTOR
EuropeanOption::EuropeanOption()
{
	init();
}
// Copy ctor
EuropeanOption::EuropeanOption(const EuropeanOption& option2)
{
	copy(option2);
}

// Create option t
EuropeanOption::EuropeanOption(const string& optionType)
{
	init();
	optType = optionType;
	
	if(optType == "c") optType = "C";
}

//Destructor
EuropeanOption::~EuropeanOption()
{
}
// Deep clone 
EuropeanOption& EuropeanOption::operator =(const EuropeanOption& src)
{
	if(this == &src) return *this;
	copy(src);
	return *this;
}

//Function to calculate option price and sensitivities
double EuropeanOption::Price() const
{
	if(optType == "C")
		return CallPrice();
	else
		return PutPrice();
}

double EuropeanOption::Delta() const
{
	if(optType == "C")
		return CallDelta();
	else
		return PutDelta();
}

void EuropeanOption::toggle()
{
	if(optType == "C")
		optType = "P";
	else
		optType == "C";
}
	
	
	


