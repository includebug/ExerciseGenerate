#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "calculator.h"
using namespace std;
class Fraction
{
private:
	int integer;  //���� 
	int molecule;  //����
	int denominator; //��ĸ
	bool isFraction; //�Ƿ�Ϊ����
	wstring fractionWstring;
public:
	Fraction();
	Fraction(wstring fraction);
	void IsFraction();
	void toWstring();
	bool isPositive();
	void print();
	void simplify();
	wstring FractionWstring();
};

