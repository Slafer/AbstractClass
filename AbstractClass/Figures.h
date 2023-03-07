#pragma once
#include <cmath>
#include <iostream>

using namespace std;

class Figures
{
protected:
	int n;
	double* arr;
public:
	Figures() : arr(nullptr), n(0) {};
	Figures(const Figures& z)
	{
		if (z.n != 0)
		{
			arr = new double[z.n];
			for (int i = 0; i < z.n; i++)
			{
				arr[i] = z.arr[i];
			}
			n = z.n;
		}
	}
	virtual double square() = 0;
	virtual void showFigureType(ostream& ) = 0;
	friend ostream& operator<< (ostream& out, Figures& f)
	{
		f.showFigureType(out);
		return out;
	}
};
class Circle : public Figures
{
/*private:
	double x = 0;
	double y = 0;
	double r = 0;*/
public:
	//Circle(double x1, double y1, double r1) : x(x1), y(y1), r(r1) {};
	Circle(double x1, double y1, double r1)
	{
		n = 3;
		arr = new double[n];
		arr[0] = x1;
		arr[1] = y1;
		arr[2] = r1;
	}
	double square() override 
	{
		return 3.14 * arr[2] * arr[2];
	}
	void showFigureType(std::ostream& out)
	{
		out << "Figures:: Circle" << endl << " O(" << arr[0] << ";"
			<< arr[1] << ")" << endl << " R = " << arr[2] << endl;
	}

};
class Rectangle : public Figures
{
/*private:
	double x;
	double y;*/
public:
	Rectangle(double x, double y, double a, double b)
	{
		n = 4;
		arr = new double[n];
		arr[0] = x;  
		arr[1] = y;  
		arr[2] = a;  
		arr[3] = b;
	}
	double square() override
	{
		return arr[0] * arr[1];
	}
	void showFigureType(std::ostream& out) override
	{
		out << "figure:: Rectangle" << endl << " x1(" << arr[0] << ";"
			<< arr[1] << ") " << " x2(" << arr[0] << ";" << arr[1] + arr[3] << ")"
			<< " x3(" << arr[0] + arr[2] << ";" << arr[1] + arr[3] << ")"
			<< " x4(" << arr[0] + arr[2] << ";" << arr[1] << ")" << endl
			<< " a = " << arr[2] << "   b = " << arr[3] << endl;
	}
};
class Square : public Figures
{
public:
	Square(double x, double y, double a, double b) 
	{
		n = 4;
		arr = new double[n];
		arr[0] = x;
		arr[1] = y;
		arr[2] = a;
		arr[3] = b;
	}
	double square() override
	{
		if (arr[2] == arr[3]) return arr[2] * arr[3];
		else { cout << "ERROR "; return NULL; } 
	}
	void showFigureType(std::ostream& out) override
	{
		out << "Figures:: Square" << std::endl << " x1(" << arr[0] << ";"
			<< arr[1] << ")" << "   x2(" << arr[0] << ";" << arr[1] + arr[3] << ")"
			<< "    x3(" << arr[0] + arr[2] << ";" << arr[1] + arr[3] << ")" << "     x4(" << arr[0] + arr[2] << ";"
			<< arr[1] << ")" << endl << " a = " << arr[2] << "    b = " << arr[3] << endl;
	}
};
class Triangle : public Figures
{
/*private:
	int x;
	int y;
	int z;*/
public:
	Triangle(int x, int y, int a, int b, int c)
	{
		n = 5;
		arr = new double[n];
		arr[0] = x;
		arr[1] = y;
		arr[2] = a;
		arr[3] = b;
		arr[4] = c;
	}
	double square() override
	{
		double p = (arr[0] + arr[1] + arr[2]) / 2;
		return sqrt(p * (p - arr[0]) * (p - arr[1]) * (p - arr[2]));
	}
	void showFigureType(std::ostream& out) override
	{
		out << "Figure:: Triangle" << endl << " x(" << arr[0] << ";"
			<< arr[1] << ")" << endl << "a = " << arr[2] << "   b = "
			<< arr[3] << "   c = " << arr[4] << endl;
	}
};
class IsoscelesTriangle : public Figures
{
/*private:
	int x;
	int y;*/

public:
	IsoscelesTriangle(double x, double y, double a, double b)
	{
		n = 4;
		arr = new double[n];
		arr[0] = x;  
		arr[1] = y;  
		arr[2] = a;  
		arr[3] = b;
	}
	double square() override
	{
		double p = (arr[0] * 2 + arr[2]) / 2;
		return sqrt(p * (p - arr[0]) * (p - arr[0]) * (p - arr[1]));
	}
	void showFigureType(std::ostream& out)
	{
		out << "Figures:: Isosceles Triangle" << endl << " x("<< arr[0] 
			<< ";" << arr[1] << ")" << endl << " a = " << arr[2]
			<< "    b = " << arr[3] << endl;
	}
};
class RightTriangle : public Figures 
{
/*private:
	int x;
	int y;
	int z;*/

public:
	RightTriangle(double x, double y, double a, double b, double c) {
		n = 5;
		arr = new double[n];
		arr[0] = x;  
		arr[1] = y;  
		arr[2] = a;  
		arr[3] = b;  
		arr[4] = c;
	}
	double square() override
	{
		/*cout << "++++++++++++++" << arr[2] * arr[2] + arr[3] * arr[3] <<"=="<< arr[4] * arr[4] << endl;*/
		if (arr[2] * arr[2] + arr[3] * arr[3] == arr[4] * arr[4])
			return 0.5 * arr[2] * arr[3];
		else
		{
			cout << "ERROR ";
			return NULL;
		}
	}
	void showFigureType(std::ostream& out) override
	{
		out << "Figure:: Right Triangle" << endl << " x(" << arr[0] << ";"
			<< arr[1] << ")" << endl << " a = " << arr[2] << "   b = "
			<< arr[3] << "   c = " << arr[4] << endl;
	}

};















