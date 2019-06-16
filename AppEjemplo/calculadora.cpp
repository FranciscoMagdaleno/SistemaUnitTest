/**
*@file AppEjemplo/calculadora.cpp
*@author Francisco Magdaleno <francisco.magdalenog@gmail.com>
*@brief Implementacion de los metodos de la clase calculadora
**/
#include "calculadora.hpp"
#include <iostream>
#include <string>

/**
 * @brief Este método crea y inicia la calculadora
 **/
Calculadora::Calculadora()
{
	m_num1 = 0;
	m_num2 = 0;
}

/**
 * @brief Este método es el destructor de la calculadora
 **/
Calculadora::~Calculadora()
{
}

/**
 * @brief Este método realiza la operación introducida.
 * @returns Devuelve el valor de la operación ejecutada
 **/
float Calculadora::calcula()
{
	float resultat;

	switch (m_op) {
	case '+': resultat = suma();
		break;
	case '-': resultat = resta();
		break;
	case '*': resultat = multiplica();
		break;
	case '/': resultat = divide();
		break;
	case '%': resultat = modulo();
		break;
	default:
		break;
	}
	return resultat;
}
/**
 * @brief Este método lee un valor de operando por teclado
 * @param iter Define que operando se va a leer, iter igual a 1 para leer operando 1, si no, lee el operando 2
 * @returns Devuelve true cuando ha leido el valor con exito
 **/
bool Calculadora::leerNumero(int iter)
{
	bool ctr=true;
	float num;
	std::string cad;
	std::cout << "Introdueix un numero: ";
	if (iter == 1) {
		std::cin >> num;
		if (std::cin.fail()){
			std::cin.clear();
			ctr = false;
		}else {
			setNum1(num);
		}
	}
	else {
		std::cin >> num;
		if (std::cin.fail()) {
			std::cin.clear();
			ctr = false;
		}
		else {
			setNum2(num);
		}
	}
	return ctr;
}

/**
 * @brief Este método lee la operación deseada por teclado
 * @returns Devuelve true si ha leido una operacion valida ('+','*','/','-','%'), false si no es valido
 **/
bool Calculadora::leerOperacion()
{
	bool ctr=true;
	char op;
	std::cout << "Introdueix operacio: ";
	std::cin >> op;
	//std::cin.clear();
	//std::cin.get(op);
	if (op == '+' || op == '*' || op == '/' || op == '-' || op == '%')
		setOp(op);
	else
		ctr = false;
	return ctr;
}
/**
 * @brief Este método suma dos valores
 * @returns Resultado de la suma
 **/
float Calculadora::suma()
{
	return m_num1 + m_num2;
}
/**
 * @brief Este método resta dos valores
 * @returns Resultado de la resta
 **/
float Calculadora::resta()
{
	return m_num1 - m_num2;
}
/**
 * @brief Este método multiplica dos valores
 * @returns Resultado de la multiplicación
 **/
float Calculadora::multiplica()
{
	return m_num1 * m_num2;
}
/**
 * @brief Este método divide dos valores
 * @returns Resultado de la división
 **/
float Calculadora::divide()
{
	return (float)m_num1 / m_num2;
}
/**
 * @brief Este método realiza el modulo
 * @returns Resultado del modulo
 **/
float Calculadora::modulo()
{
	int result =(int)m_num1 % (int)m_num2;
	if (result >= 0) {
		return result;
	}
	else {
		return result + (int)m_num2;
	}
}
/**
 * @brief Este método devuelve el primer operando de dos valores
 * @returns operando numero 1
 **/
float Calculadora::getNum1()
{
	return m_num1;
}
/**
 * @brief Este método devuelve el segundo operando de dos valores
 * @returns operando numero 2
 **/
float Calculadora::getNum2()
{
	return m_num2;
}
/**
 * @brief Este método devuelve el operador
 * @returns operador
 **/
char Calculadora::getOp()
{
	return m_op;
}
/**
 * @brief Este método setea el primer operando
 * @param num Valor del operando 1
 **/
void Calculadora::setNum1(float num)
{
	m_num1 = num;
}
/**
 * @brief Este método setea el segundo operando
 * @param num Valor del operando 2
 **/
void Calculadora::setNum2(float num)
{
	m_num2 = num;
}
/**
 * @brief Este método setea el operador
 * @param op Valor del operando
 **/
void Calculadora::setOp(char op)
{
	m_op = op;
}
