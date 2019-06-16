/**
*@file AppEjemplo/calculadora.hpp
*@author Francisco Magdaleno <francisco.magdalenog@gmail.com>
*@brief Definición de la clase calculadora.
**/
#pragma once
using namespace std;

class Calculadora
{
public:
	Calculadora();
	~Calculadora();

	bool leerNumero(int iter);
	bool leerOperacion();
	float getNum1();
	float getNum2();
	char getOp();
	void setNum1(float num);
	void setNum2(float num);
	void setOp(char op);
	float calcula();

private:
	float m_num1;
	float m_num2;
	char m_op;
	float suma();
	float resta();
	float multiplica();
	float divide();
	float modulo();
};
