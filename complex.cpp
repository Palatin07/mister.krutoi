#define _USE_MATH_DEFINES
#include "Complex.h"
#include <cmath>
TComplex::TComplex()
{
	double re = 0;
	double im = 0;
}

TComplex::TComplex(double _re, double _im)
{
	re = _re;
	im = _im;
}

TComplex::TComplex(const TComplex& p)
{
	re = p.re;
	im = p.im;
}

double TComplex::GetRe()
{
	return re;
}

double TComplex::GetIm()
{
	return im;
}

void TComplex::SetRe(double _re)
{
	re = _re;
}

void TComplex::SetIm(double _im)
{
	im = _im;
}

TComplex TComplex::operator+(TComplex& p)
{
	TComplex A;
	A.re = re + p.re;
	A.im = im + p.im;
	return A;
}

TComplex TComplex::operator-(TComplex& p)
{
	TComplex A;
	A.re = re - p.re;
	A.im = im - p.im;
	return A;
}

TComplex TComplex::operator*(TComplex& p)
{
	TComplex A;
	A.re = (re * p.re) - (im * p.im);
	A.im = (re * p.im) + (im * p.re);
	return A;
}

TComplex TComplex::operator/(TComplex& p)
{
	TComplex A;
	A.re = (re * p.re + im * p.im) * 1.0 / (p.re * p.re + p.im * p.im);
	A.im = (im * p.re - re * p.im) * 1.0 / (p.re * p.re + p.im * p.im);
	return A;
}

TComplex TComplex::operator=(const TComplex& p)
{
	re = p.re;
	im = p.im;
	return*this;
}

bool TComplex::operator==(TComplex& p)
{
	if ((p.re == re) && (p.im == im))
	{
		return true;
	}
	return false;
}

double TComplex::Abs()
{
	return sqrt(pow(re,2)+pow(im,2));
}

TComplex TComplex::VozvedenieVStepen(double n)
{
	TComplex res;
	double r = pow(sqrt(pow(re, 2) + pow(im, 2)),n);
	if (re > 0 and im >= 0)
	{
		double fi = atan(abs(im / re));
		res.re = r * cos(fi * n);
		res.im = r * sin(fi * n);
		if (abs(res.im) < 0.000000001) res.im = 0;
		if (abs(res.re) < 0.000000001) res.re = 0;
		std::cout << r << "(cos(" << fi << "*" << n << ") + i*sin(" << fi << "*" << n << ") = (" << res.re << ") + (" << res.im << "*i)";
	}
	double fi = atan(abs(im / re));
	if (re < 0 and im >= 0)
	{
		double fi = M_PI - atan(abs(im / re));
		res.re = r * cos(fi * n);
		res.im = r * sin(fi * n);
		if (abs(res.im) < 0.000000001) res.im = 0;
		if (abs(res.re) < 0.000000001) res.re = 0;
		std::cout << r << "(cos(" << fi << "*" << n << ") + i*sin(" << fi << "*" << n << ") = (" << res.re << ") + (" << res.im << "*i)";
	}
	if (re < 0 and im < 0)
	{
		double fi = M_PI + atan(abs(im / re));
		res.re = r * cos(fi * n);
		res.im = r * sin(fi * n);
		if (abs(res.im) < 0.000000001) res.im = 0;
		if (abs(res.re) < 0.000000001) res.re = 0;
		std::cout << r << "(cos(" << fi << "*" << n << ") + i*sin(" << fi << "*" << n << ") = (" << res.re << ") + (" << res.im << "*i)";
	}
	if (re > 0 and im < 0)
	{
		double fi = 2* M_PI - atan(abs(im /re));
		res.re = r * cos(fi * n);
		res.im = r * sin(fi * n); 
		if (abs(res.im) < 0.000000001) res.im = 0;
		if (abs(res.re) < 0.000000001) res.re = 0;
		std::cout << r << "(cos(" << fi <<"*"<< n << ") + i*sin(" << fi <<"*" << n << ") = (" << res.re << ") + (" << res.im << "*i)";
	}
	return res;
}

TComplex TComplex::TrigForm()
{
	TComplex res;
	double r = sqrt(pow(re, 2) + pow(im, 2));
	if (re > 0 and im >= 0)
	{
		double fi = atan(abs(im / re));
		std::cout << r << "(cos" << fi << "+ i*sin" << fi << ")";
	}
	if (re < 0 and im >= 0)
	{
		double fi = M_PI - atan(abs(im / re));
		std::cout << r << "(cos" << fi << "+ i*sin" << fi << ")";
	}
	if (re < 0 and im < 0)
	{
		double fi = M_PI + atan(abs(im / re));
		std::cout << r << "(cos" << fi << "+ i*sin" << fi << ")";
	}
	if (re > 0 and im < 0)
	{
		double fi = 2* M_PI - atan(abs(im / re));
		std::cout << r << "(cos" << fi << "+ i*sin" << fi << ")";
	}
	return res;
}

std::istream& operator>>(std::istream& B, TComplex& A)
{
	B >> A.re;
	B >> A.im;
	return B;
}

std::ostream& operator<<(std::ostream& B, TComplex& A)
{
	B << A.re << " + i" << A.im;
	return B;
}

