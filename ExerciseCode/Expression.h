#pragma once
#include "Fraction.h"
#include "calculator.h"
using namespace std;
class Expression
{
private:
	int OperationNum;  //����������
	int bracketsNum[2];    //0�����Ÿ�����1������ģʽ��OperationNum     �� OperationNum==4ʱ�����1234Ϊ������
						//bracketsNum[0]Ϊ0�������ţ�bracketsNum[0]Ϊ1������ģʽ��bracketsNum[0]Ϊ2������
						//bracketsNum[0]Ϊ1��bracketsNum[5]{����12��34������1��23��4������12��34����������123��4������1��234����}
						//bracketsNum[0]Ϊ2��bracketsNum[3]{������12��3��4��������1��23����4������1����23��4����}
	Fraction t[4];     //��Ų�����
	wchar_t wOPERATER[3]; //���wchar_t���͵������
	Fraction result;  //��������
	wstring ExpressionWstring;
public:
	Expression();
	Expression(Fraction x[4], wchar_t OPERATER[3], int i, int brackets[2]);
	void toWstring();
	void print();  //��ӡ���ʽ
	void CalculateFraction();  //������ʽ��ֵ����result������
	Fraction returnResult();
	wstring returnExpressionWstring();
};

