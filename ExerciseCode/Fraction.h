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
	int integer;  //整数 
	int molecule;  //分子
	int denominator; //分母
	bool isFraction; //是否为分数
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

