// CLASSE BASE

/*! @file CPolynomial.h 
	@brief A class for polynomial functions 
	@author Paolo Gastaldo

	Details.
*/ 

//GUARDIA --> per non definirlo + volte all'interno del programma
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>   // Per operazioni di input/output (es. cout)
#include <cmath>      // Per operazioni matematiche (anche se non usata qui direttamente)
#include <cstring>    // Per funzioni C-style su stringhe (non usata direttamente)

using namespace std;

// Dichiarazione della classe Polynomial
class Polynomial { 

// Variabili e funzioni membro private --> accessibili e modificabili solo dalla classe stessa
private:
    double* coeff; 	//puntatore all'array dei coefficienti
    int degree; 	//grado del polinomio

// Variabili e funzioni membro pubbliche --> interfacciabili da tutti
public:
    
	/// @name CONSTRUCTORs and DESTRUCTOR 
	/// @{

    Polynomial(); 										//Costruttore di default
	Polynomial(const double* coefficients, int size); 	//Costruttore parametrico (array di coefficienti e dimensione dell'array) --> istanzio oggetto con parametri che gli fornisco io
    Polynomial(const Polynomial& p); 					//Costruttore di copia (passaggio dell'oggetto by reference)
    ~Polynomial(); 										//Distruttore (distrugge tutto una volta uscito dallo scope)
	/// @}

	/// @name OPERATORS 
	/// @{
    Polynomial& operator=(const Polynomial& p); //Operatore di assegnazione
	Polynomial operator+(const Polynomial& p);  //Operatore di somma
	bool operator==(const Polynomial& p); 		//Operatore di comparazione
	/// @}

	//Metodi principali
	void SetPolynomial(const double* coefficients, int size); 	// Setter dei coefficienti del polinomio
	
    double GetValue(double in) const;							// Calcola il valore del polinomio per un certo input
																// ( Scrivere "const" dopo la dichiarazione dei parametri significa che il metodo non modifica l'oggetto su cui viene chiamato. In altre parole, la funzione promette di non cambiare alcun membro della classe )				
	
	void Reset(); // Resetta il polinomio (ai valori di default)

	/// @name DEBUG and SERIALIZATION 
	/// @{
	void ErrorMessage(const char *string);     // Mostra un messaggio di errore
    void WarningMessage(const char *string);   // Mostra un messaggio di avviso
    void Dump();                               // Stampa il contenuto del polinomio
	/// @}    
};

#endif