/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadric.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarakho <imarakho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 14:35:57 by imarakho          #+#    #+#             */
/*   Updated: 2018/03/12 12:27:02 by imarakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "quadric.hpp"

Quadric::Quadric(int a, int b, int c)
{
    this->a = a;
    this->b = b;
    this->c = c;
    this->poly = 0;
}

Quadric::Quadric()
{
    this->a = 0;
    this->b = 0;
    this->c = 0;
    this->poly = 0;
}

void    Quadric::Set_poly(double d)
{
    this->poly = d;
}

void    Quadric::Set_a(double d)
{
    this->a = d;
}

void    Quadric::Set_b(double d)
{
    this->b = d;
}

void    Quadric::Set_c(double d)
{
    this->c = d;
}

double   Quadric::Get_a()
{
    return (this->a);
}

double    Quadric::Get_b()
{
    return (this->b);
}

double   Quadric::Get_c()
{
    return (this->c);
}

double   Quadric::Get_poly()
{
    return (this->poly);
}

double    Quadric::abc(double a)
{
    if(a < 0)
        a *= -1;
    return a;
}

double    Quadric::m_sqrt(double a)
{
    double i = 0;
   double x1,x2;
   while((i * i) <= a)
          i += 0.1f;
   x1 = i;
   for(int j = 0;j < 10;j++)
   {
    x2 = a;
      x2 /= x1;
      x2 += x1;
      x2 /= 2;
      x1 = x2;
   }
   return x2;
}

void    Quadric::solve_quadric()
{
    double d, x1, x2;

    if (a == 0)
    {
        cout << "There is no solution, a = 0" << endl;
        return;
    }
    cout << "Founding disriminant:" << endl << "D = " << b * b << " - " << 4 * a * c << endl;
    d = (b * b) - 4 * a * c;
    if (d < 0)
    {
        cout << "Discriminant is negative, there is complex solution!" << endl;
        cout << "X1 = " << -b <<  "/" << (2 * a) << " + i * " << m_sqrt(abc(d)) << endl;
        cout << "X2 = " << -b <<  "/" << (2 * a) << " - i * " << m_sqrt(abc(d)) << endl;
        return ;
    }
    else if (d == 0)
    {
        cout << "Discriminant is 0, there is one solution!" << endl;
        x1 = (-b) / (2 * a);
        cout << "X = " << -b << " / " << 2 * a << endl;
        cout << "X = " << x1 << endl;
        return ;
    }
    cout << "X1 = (" << -b << " + " << m_sqrt(d) << ") / " << 2 * a << endl;
    cout << "X2 = (" << -b << " - " << m_sqrt(d) << ") / " << 2 * a << endl;
    x1 = (-b + m_sqrt(d)) / (2 * a);
    x2 = (-b - m_sqrt(d)) / (2 * a);
    cout << "Discriminant is strictly positive, the two solutions are:\n" << x1 << endl << x2 << endl;
}

void    Quadric::solve_linear()
{
    double x;

    if (b == 0 && c == 0)
        cout << "All real numbrs are solution!" << endl;
    else if(c == 0)
        cout << "The solution is:\n0\n";
    else if (b == 0)
        cout << "There is no solution!" << endl;
    else
        {
            cout << b << "x = " << -c << endl; 
            cout << "The solution is:\n" << c / (-b) << endl;
        }
    
}
