/**
*@file AppEjemplo/main.cpp
*@author Francisco Magdaleno <francisco.magdalenog@gmail.com>
*@brief Archivo con la funcion main de la calculadora
**/

#include "calculadora.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    std::cout << "Hello World!\n";
	Calculadora calcu;
	float res;
	bool ctrl=false;

	while (ctrl == false)
	{
		ctrl=calcu.llegeixNumero(1);
		if (ctrl == true)
		{
			ctrl=calcu.llegeixOperacio();
			if (ctrl == true)
			{
				ctrl=calcu.llegeixNumero(2);
			}
		}

		if (ctrl == false)
			std::cout << "Invalid characters. Try again!\n";
	}	

	res = calcu.calcula();
	std::cout << res ;
	std::cout << "\n";

	return 0;
}


