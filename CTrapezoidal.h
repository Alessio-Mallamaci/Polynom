/*! @file CTrapezoidal.h
	@brief A class for numerical integration according to the trapezoidal rule
	@author Paolo Gastaldo

	Details.
*/ 

#ifndef TRAPEZOIDAL_H
#define TRAPEZOIDAL_H

#include "CIntegral.h"

using namespace std;

class Trapezoidal : public Integral {

public:
    
	/// @name CONSTRUCTORS and DESTRUCTOR 
	/// @{
    Trapezoidal();
	Trapezoidal(Polynomial* p);
	Trapezoidal(const Trapezoidal& p);
    ~Trapezoidal();
	/// @}
	
	/// @name OPERATORS 
	/// @{
    Trapezoidal& operator=(const Trapezoidal& p);
	bool operator==(const Trapezoidal& p);
	/// @}

	double GetIntegral(double inf, double sup, int intervals = 100);

	/// @name DEBUG and SERIALIZATION 
	/// @{
	void ErrorMessage(const char *string); 
	void WarningMessage(const char *string);
	void Dump();
	/// @}

    
};

#endif