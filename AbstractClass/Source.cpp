#include <iostream>
#include "Figures.h"

using namespace std;

int main() 
{
    setlocale(LC_ALL, "ru");
    Figures* circle = new Circle(1, 1, 4);
    
    Figures* rectangle = new Rectangle(1, 1, 4, 8);
    
    Figures* square = new Square(1, 1, 4, 4);
    
    Figures* triangle = new Triangle(1, 1, 4, 3, 5);
    
    Figures* isosceles_triangle = new IsoscelesTriangle(1, 4, 10, 10);

    Figures* right_triangle = new RightTriangle(3, 4, 4, 3, 5);
  
    Figures* mas_figures[6] = { circle, rectangle, square, triangle, isosceles_triangle, right_triangle };
    int max = 0, k;
    for (int i = 0; i < 6; i++)
    {
        cout << *mas_figures[i];
        if (mas_figures[i]->square() > max)
        {
            max = mas_figures[i]->square();
            k = i;
        }
    }
    cout << "figure number ¹ " << k + 1 << " have max square = " << max << endl;
    cout << *mas_figures[k + 1];
}