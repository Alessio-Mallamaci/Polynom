
#include "CPolynomial.h" 

int main() {
	
	double cf1[7]={2.0,1.5,0,0,0,0,-1.0};
	double cf2[4]={-2.0,1.5,2.5,3.5};
	
	
	Polynomial p0;
	Polynomial p1(cf1,7);
	Polynomial p2(cf2,4);
	Polynomial p3=p1;
		
	p0.Dump();
	p1.Dump();
	p2.Dump();
	p3.Dump();
	
	p0=p2;
	p0.Dump();
	
	p3 = p0 + p2;
	p3.Dump();
	
	if (p0==p1)
		cout << "uguali" << endl;
	
	p1.Reset(); 
	p1.Dump();
	
}