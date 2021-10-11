#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cmath>
using namespace std;

ifstream in;
ofstream out;

class zadanie
{
	public:
		double dlugosc(double a, double b, double n);
		double f(double x);
		double g(double x);
};

double zadanie::f(double x)
{
   return (pow(x, 4) / 500 - pow(x, 2) / 200 - 0.012);
}

double zadanie::g(double x)
{
   return (-x * x * x / 30 + x / 20 + 1.0 / 6);
}

double zadanie::dlugosc(double a, double b, double n)
{
	double d = 0; //ca³a d³ugoœæ
	int podstawy = 8; //podstawa dolna i górna
	d = d + (2 * podstawy) + f(b) - g(b); // d³ugoœæ = 2 podstawy + dwie funkcje
	double h = 1.0 * (b - a) / n; // h = wysokosc?
	int i;
	double x = a;
	double tmp;
	//dlugosc luku f
	
	for (i=0; i<=n - 1; i++)
	{
	       tmp = sqrt(h * h + (f(x + h) - f(x)) * (f(x + h) - f(x)) ); //fragment luku
	       d = d + tmp;//nowa dlugosc
	       x = x + h; //zmiana x_i
	}
	
	//dlugosc luku g
	x = a;
	for (i = 0; i <= n - 1; i++)
	{
	       tmp = sqrt(h * h + (g(x + h) - g(x)) * (g(x + h) - g(x)) ); //fragment luku
	       d = d + tmp;//nowa dlugosc
	       x = x + h; //zmiana x_i
	}
	
	return d;
}


int main()
{
	zadanie x;
	
	double a,b,n;
	n = 1000;
	cout << "Podaj a, b:\n"; cin >> a >> b;
	
	cout << "\nDlugosc tasmy ktora musi kupic pani binarna: " << ceil(x.dlugosc(a,b,n))<< "m";
}
