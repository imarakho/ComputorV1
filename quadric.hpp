/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadric.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarakho <imarakho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 14:31:55 by imarakho          #+#    #+#             */
/*   Updated: 2018/03/06 16:29:58 by imarakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUADRIC_HPP
# define QUADRIC_HPP

#include <iostream>
#include <cstring>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

class   Quadric
{
    public:
            Quadric();
            Quadric(int a, int b, int c);
    void    solve_quadric();
    void    solve_linear();
    void    Set_poly(double d);
    void    Set_a(double d);
    void    Set_b(double d);
    void    Set_c(double d);
    double  Get_poly();
    double  Get_a();
    double  Get_b();
    double  Get_c();
    double a;
    double b;
    double c;
    private:
    double    m_sqrt(double a);
    double      abc(double a);
       /* double a;
        double b;
        double c;*/
        int    poly;
};
#endif