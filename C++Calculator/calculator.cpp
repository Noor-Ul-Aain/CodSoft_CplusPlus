#include"calculator.h"
#include<iostream>
using namespace std;

calculator::calculator()
{
	number1 = 0;
	number2 = 0;
}

calculator::~calculator()
{}

void calculator::input()
{
	cout << "Enter any two Numbers for calculation: ";
	cin >> number1 >> number2;
}

void calculator::menuDisplay(void)
{
	cout << "_______________________Features of the C++ Calculator_______________________" << endl;
	cout << "Press '+' for addition\nPress '-' for subtraction\nPress '*' for multiplication\nPress '/' for division" << endl;
}

void calculator::selectOperation()
{
	char operation = ' ';

	while (1)
	{
		cin >> operation;

		if (operation == '+')
		{
			cout << "Sum of " << number1 << " and " << number2 << " is: " << sum(number1, number2) << endl;
			break;
		}

		else if (operation == '-')
		{
			cout << "Difference of " << number1 << " and " << number2 << " is: " << diff(number1, number2) << endl;
			break;
		}

		else if (operation == '*')
		{
			cout << "Product of " << number1 << " and " << number2 << " is: " << product(number1, number2) << endl;;
			break;
		}

		else if (operation == '/')
		{
			cout << "Divison of " << number1 << " and " << number2 << " is: " << div(number1, number2) << endl;
			break;
		}

		else
			cout << "Wrong selection!!!\nChoose the functionality again!!!" << endl;
	}
}

float calculator::sum(float num1, float num2)
{
	return (num1 + num2);
}

float calculator::diff(float num1, float num2)
{
	return (num1 - num2);
}

float calculator::product(float num1, float num2)
{
	return (num1 * num2);
}

float calculator::div(float num1, float num2)
{
	if (num2 == 0)
	{
		cout << "Can not Divide by Zero!!!" << endl;
		return -99999; //returns the error value when dividing by zero
	}
	else
		return (num1 / num2);
}
