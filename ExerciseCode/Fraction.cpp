#include "Fraction.h"

//using namespace std;

Fraction::Fraction()
{
	integer = 0;  //整数 
	molecule = 0;  //分子
	denominator = 4; //分母
	isFraction = 0; //是否为分数
	fractionWstring = L"";
}

Fraction::Fraction(wstring fraction)
{
	int a[3];
	spiltNum(a,fraction);
	integer = a[0];
	molecule = a[1];
	denominator = a[2];
	if (molecule - denominator >= 0&& denominator!=0)
	{
		integer += molecule / denominator;
		molecule = molecule % denominator;
	}
	simplify();
	IsFraction();
	toWstring();
}

void Fraction::IsFraction()
{
	if (molecule == 0)
		isFraction = false;
	else
		isFraction = true;
}

void Fraction::toWstring()
{
	if (isFraction)
		fractionWstring = to_wstring(integer) + L"\'" + to_wstring(molecule) + L"/" + to_wstring(denominator);
	else
		fractionWstring = to_wstring(integer);
}

bool Fraction::isPositive()
{
	if (denominator == 0)
		return false;
	if (integer + molecule / denominator < 0)
		return false;
	return true;
}

void Fraction::print()
{
	wcout.imbue(locale("chs"));
	wcout << L"宽字符串为：" << fractionWstring << endl;
	cout << "是否为整数（0为整数,1为分数）" << isFraction << endl;
}

void Fraction::simplify()
{
	if (molecule != 0 && denominator != 0)
	{
		int a, b;
		a = molecule;
		b = denominator;
		int c = 0;
		while (c = a % b)   //c==0时 循环结束
		{
			a = b;
			b = c;
		}
		molecule /= b;
		denominator /= b;
	}
}

wstring Fraction::FractionWstring()
{
	return fractionWstring;
}

