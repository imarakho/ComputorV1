/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarakho <imarakho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 14:18:18 by imarakho          #+#    #+#             */
/*   Updated: 2018/03/12 13:18:51 by imarakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quadric.hpp"

inline bool space(char c){
    return isspace(c);
}
 
inline bool notspace(char c){
    return !isspace(c);
}

vector<string> split(const string& s){
    typedef string::const_iterator iter;
    vector<string> ret;
    iter i = s.begin();
    while(i!=s.end()){
        i = find_if(i, s.end(), notspace);
        iter j= find_if(i, s.end(), space);
        if(i!=s.end()){
            ret.push_back(string(i, j));
            i = j; 
        }
    }
    return ret;
}

int ifloor(double x)
{
    if (x >= 0)
    {
        return (int)x;
    }
    else
    {
        int y = (int)x;
        return ((float)y == x) ? y : y - 1;
    }
}

int     main(int argc, char **argv)
{
    char *pch = NULL;
    double tmp_data = 0;
    double tmp_poly = 0;
    bool    minus = 0;
    bool    equal = 0;
    vector<string> pol;
    vector<double> coefs;
   Quadric q;

    if (argc != 2)
    {
        cout << "Wrong number of arguments." << endl;
        return (0);
    }
    for(int i = 0;argv[1][i] != '\0';i++)
    {
        if(argv[1][i] != ' ' && argv[1][i] != 'X' 
        && argv[1][i] != '^' && argv[1][i] != '*' && 
        argv[1][i] != '+' && argv[1][i] != '-' 
        && !isnumber(argv[1][i]) && argv[1][i] != '=' && argv[1][i] != '.')
        {
            cout << "Wrong input!" << endl;
            return 0;
        }
        if(argv[1][i] == '=')
            equal = 1;
    }
    if(!equal)
    {
        cout << "Wrong input!" << endl;
            return 0;
    }
    equal = 0;
    pol = split(argv[1]);
    for(int i = 0;i < pol.size();i++)
    {
        if ((!isnumber(pol[i][1]) && (pol[i].find("-") != -1 && !equal)) || equal)
            minus = 1;
        if(pol[i].find("=") != -1)
            equal = 1;
        if(isnumber(pol[i][0]) || (pol[i][0] == '-' && isnumber(pol[i][1])))
        {
            tmp_data = stof(pol[i]);
            if(minus)
            {
                tmp_data *= -1;
                minus = 0;
            }
            if (pol[i + 2].find("X^0") != -1 && !isnumber(pol[i + 2][3]) && pol[i + 2][3] != '.')
            {
                q.c += tmp_data;
            }
            else if (pol[i + 2].find("X^1") != -1 && !isnumber(pol[i + 2][3]) && pol[i + 2][3] != '.')
            {
                tmp_poly = 1;
                q.b += tmp_data;
            }
            else if (pol[i + 2].find("X^2") != -1 && !isnumber(pol[i + 2][3]) && pol[i + 2][3] != '.')
            {
                tmp_poly = 2;
                q.a += tmp_data;
            }
            else if(pol[i + 2].find("X^") != -1)
                {
                    coefs.push_back(tmp_data);
                    tmp_poly = stof(&pol[i + 2][2]);
                    if(!isnumber(pol[i + 2][2]))
                    {
                        cout << "Error!\nWrong power!" << endl;
                        return (0);
                    }
                    if(tmp_poly < 0)
                    {
                        cout << "Error!\nPower is less then 0!" << endl;
                        return (0);
                    }
                    else if (ifloor(tmp_poly) != tmp_poly)
                    {
                        cout << "Error!\nPower is not integer!" << endl;
                        return(0);
                    }
                }
            else if(equal != 1 /*&& pol[i + 2].find("0") != - 1*/) 
            {
                 cout << "Wrong input!" << endl;
                return 0;
            }
             if (tmp_poly > q.Get_poly())
                q.Set_poly(tmp_poly);
        }
    }
    pch = strtok(argv[1], "+-");
    if(q.Get_poly() == 0)
    {
        cout << "Reduced form: " << q.c << " * X^0 = 0" << endl;
        cout << "Polynomial degree: " << q.Get_poly() << endl;
        if(q.c == 0)
            cout << "All real numbers are solution!" << endl;
        else
             cout << "There is no solution!" << endl;
    }
    if(q.Get_poly() == 1)
    {
        cout << "Reduced form: " << q.c << " * X^0";
        if(q.b < 0)
        cout << " - " << q.b * (-1) << " * X^1 = 0" << endl;
        else
            cout << " + " << q.b << " * X^1 = 0" << endl;
        cout << "Polynomial degree: " << q.Get_poly() << endl;
        q.solve_linear();
    }
    if(q.Get_poly() == 2)
    {
        cout << "Reduced form: " << q.c << " * X^0";
        if(q.b < 0)
        cout << " - " << q.b * (-1) << " * X^1";
        else
            cout << " + " << q.b << " * X^1";
        if(q.a < 0)
        cout << " - " << q.a * (-1) << " * X^2 = 0" << endl;
        else
            cout << " + " << q.a << " * X^2 = 0" << endl;
        cout << "Polynomial degree: " << q.Get_poly() << endl;
        q.solve_quadric();
    }
    else if(q.Get_poly() > 2)
    {
         cout << "Reduced form: " << q.c << " * X^0";
        if(q.b < 0)
        cout << " - " << q.b * (-1) << " * X^1";
        else
            cout << " + " << q.b << " * X^1";
        if(q.a < 0)
        cout << " - " << q.a * (-1) << " * X^2";
        else
            cout << " + " << q.a << " * X^2";
        for(int i = 2;i < q.Get_poly();++i)
        {
            if(coefs.back() < 0)
            cout << " - " << coefs.back() * (-1) << " * X^" << i + 1;
            else
            cout << " + " << coefs.back() << " * X^" << i + 1;
            coefs.pop_back();
        }
        cout << " = 0" << endl;
         cout << "Polynomial degree: " << q.Get_poly() << endl;
         cout << "The polynomial degree is stricly greater than 2, I can't solve." << endl;
         exit(1);
    }
    return (0);
}