#include "CPolynomial.h"
#include "CTrapezoidal.h"

int main() {

    // Inizializzazione di due array di coefficienti per due polinomi
    double cf1[7] = {2.0, 1.5, 0, 0, 0, 0, -1.0};  // -x^6 + 1.5x + 2
    double cf2[4] = {-2.0, 1.5, 2.5, -3.5};        // 3.5x^3 + 2.5x^2 + 1.5x - 2

    // Creazione di vari oggetti Polynomial
    Polynomial p0;
    Polynomial p1(cf1, 7);
    Polynomial p2(cf2, 4);
    Polynomial p3 = p1;

    // Dump dei polinomi
    p0.Dump();
    p1.Dump();
    p2.Dump();
    p3.Dump();
	cout << endl << endl;

    // Assegnazione e somma
    p0 = p2;
    p0.Dump();
    p3 = p0 + p2;
    p3.Dump();

    // Confronto tra p0 e p1 (NON funziona perchè non ho implementato la funzione)
    if (p0 == p1)
        cout << "uguali" << endl;

    // Reset del polinomio
    p1.Reset();
    p1.Dump();

    // ------------------------------
    // TEST DELLA CLASSE TRAPEZOIDAL
    // ------------------------------

    // Creazione di un oggetto Trapezoidal passando p2 (polinomio da integrare)
    Trapezoidal trap(&p2);

    // Dump del contenuto di Trapezoidal
    trap.Dump();

    // Calcolo dell'integrale di p2 tra 0 e 1 con 100 intervalli
    double result = trap.GetIntegral(0.0, 1.0, 100);
    cout << "Integrale del polinomio p2 in [0,1] con 100 intervalli: " << result << endl;

    // Test del costruttore di copia
    Trapezoidal trapCopy (trap);
    trapCopy.Dump();

    // Test dell'operatore di assegnazione
    Trapezoidal trapAssigned;
    trapAssigned = trap;
    trapAssigned.Dump();

    // Test del metodo SetPolynomial con un nuovo polinomio
    trapAssigned.SetPolynomial(&p1);
    trapAssigned.Dump();

    // Calcolo dell'integrale dopo aver cambiato il polinomio
    double result2 = trapAssigned.GetIntegral(0.0, 1.0, 100);
    cout << "Integrale del nuovo polinomio (p1) in [0,1]: " << result2 << endl;

    return 0;
}
