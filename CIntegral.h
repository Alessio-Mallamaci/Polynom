#ifndef INTEGRAL_H
#define INTEGRAL_H

#include <iostream>
#include <cmath>
#include <cstring>

#include "CPolynomial.h"

using namespace std;

class Integral {
protected:
	Polynomial* poly;

public:
    
	/// @name CONSTRUCTORS and DESTRUCTOR 
	/// @{
    Integral();
	Integral(Polynomial* p);
    ~Integral();
	/// @}

    void SetPolynomial(Polynomial* p);
	
	virtual double GetIntegral(double inf, double sup, int intervals = 100)=0;

	/// @name DEBUG and SERIALIZATION 
	/// @{
	void ErrorMessage(const char *string); 
	void WarningMessage(const char *string);
	void Dump();
	/// @}

    
};

#endif