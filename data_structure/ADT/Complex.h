/****************************Complex Implement*****************/

#ifndef _complex_
#define _complex_

typedef struct complex *Complex;
struct complex { float Re; float Im; };

Complex initComplex(float a, float b)
{
	Complex t = new complex();
	t->Im = a;
	t->Re = b;
	return t;
}

float Re(Complex a)
{
	return a->Re;
}

float Im(Complex a)
{
	return a->Im;
}

Complex mulitComplex(Complex a, Complex b)
{
	return initComplex(Re(a)*Re(b) - Im(a)*Im(b), Re(a)*Im(b) + Im(a)*Re(b));
}

#endif
