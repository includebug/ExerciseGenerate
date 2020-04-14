#include "Fraction.h"

//using namespace std;

Fraction::Fraction()
{
	integer = 0;  //���� 
	molecule = 0;  //����
	denominator = 4; //��ĸ
	isFraction = 0; //�Ƿ�Ϊ����
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
	wcout << L"���ַ���Ϊ��" << fractionWstring << endl;
	cout << "�Ƿ�Ϊ������0Ϊ����,1Ϊ������" << isFraction << endl;
}

void Fraction::simplify()
{
	if (molecule != 0 && denominator != 0)
	{
		int a, b;
		a = molecule;
		b = denominator;
		int c = 0;
		while (c = a % b)   //c==0ʱ ѭ������
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

