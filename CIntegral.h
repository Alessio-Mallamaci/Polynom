// FUNCTION OBJECT DELLA CLASSE BASE

//GUARDIA
#ifndef INTEGRAL_H
#define INTEGRAL_H

#include <iostream>      // Libreria standard per input/output (es. cout)
#include <cmath>         // Libreria matematica (es. funzioni come pow, sin, etc.)
#include <cstring>       // Per funzioni C-style sulle stringhe (non usata direttamente qui)

#include "CPolynomial.h" // Inclusione della definizione della classe Polynomial

using namespace std;

// Definizione della classe astratta Integral
class Integral {
protected:
 	Polynomial* poly;    // Puntatore a oggetto Polynomial, il polinomio da integrare

public:
    
	/// @name CONSTRUCTORS and DESTRUCTOR 
	/// @{
    Integral(); 			//Costruttore di default
	Integral(Polynomial* p);//Costruttore con puntatore a Polynomial
    ~Integral();			//Distruttore	
	/// @}

    void SetPolynomial(Polynomial* p); // Metodo per impostare un nuovo polinomio da integrare
	
	//Funzione astratta pura per calcolare l'integrale: deve essere implementato da una classe derivata
	virtual double GetIntegral(double inf, double sup, int intervals = 100)=0;

	/// @name DEBUG and SERIALIZATION 
	/// @{
	void ErrorMessage(const char *string);    // Stampa un messaggio di errore
    void WarningMessage(const char *string);  // Stampa un messaggio di avviso
    void Dump();                              // Stampa lo stato corrente dell’oggetto
    /// @}
};

#endif