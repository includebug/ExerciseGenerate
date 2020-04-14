#pragma once
#include "Fraction.h"
#include "calculator.h"
using namespace std;
class Expression
{
private:
	int OperationNum;  //操作数个数
	int bracketsNum[2];    //0存括号个数，1存括号模式，OperationNum     ， OperationNum==4时下面的1234为操作数
						//bracketsNum[0]为0，无括号，bracketsNum[0]为1，五种模式，bracketsNum[0]为2，三种
						//bracketsNum[0]为1，bracketsNum[5]{“（12）34”，“1（23）4”，“12（34）”，“（123）4”，“1（234）”}
						//bracketsNum[0]为2，bracketsNum[3]{“（（12）3）4”，“（1（23））4”，“1（（23）4）”}
	Fraction t[4];     //存放操作数
	wchar_t wOPERATER[3]; //存放wchar_t类型的运算符
	Fraction result;  //存运算结果
	wstring ExpressionWstring;
public:
	Expression();
	Expression(Fraction x[4], wchar_t OPERATER[3], int i, int brackets[2]);
	void toWstring();
	void print();  //打印表达式
	void CalculateFraction();  //计算表达式的值，用result存起来
	Fraction returnResult();
	wstring returnExpressionWstring();
};

