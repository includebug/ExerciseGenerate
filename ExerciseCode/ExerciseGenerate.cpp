#include "ExerciseGenerate.h"

bool ExerciseGenerate::ExerciseGenerateMaxNum(int i)
{
	numSize = i;
	return true;
}

wstring ExerciseGenerate::generateExpress()
{
	srand(clock()+rand());
	int i = rand() % 3 + 2;

	for (int k = 0; k < i; k++)          //4*3的二维数组存数据，一行为一个数据
	{
		int isFraction = rand() % 2;     //是否为整数，若为整数a[k][1]=0，即分子置为0
		if (isFraction == 0)
		{
			for (int j = 0; j < 3; j++)
			{
				if (j == 2)  //保证分母不为0
					a[k][j] = (rand() % (numSize - 1)) + 1;
				else
					a[k][j] = rand() % numSize;
			}
				
		}
		else
		{
			for (int j = 0; j < 3 ; j++)
			{
				if (j == 2)
					a[k][j] = (rand() % (numSize - 1)) + 1;
				else
					a[k][j] = rand() % numSize;
			}
			a[k][1] = 0;
		}
	}

	wchar_t oprtr[3];

	for (int p = 0; p < i-1; p++)
	{
		int u = rand() % 4;
		if (u == 0)
			oprtr[p] = L'+';
		else if(u==1)
			oprtr[p] = L'-';
		else if (u == 2)
			oprtr[p] = L'×';
		else 
			oprtr[p] = L'÷';
	}

	int bracketsNum[2];
	if (i == 2)
	{
		bracketsNum[0] = 0;
		bracketsNum[1] = 0;
	}
	else if (i == 3)
	{
		bracketsNum[0] = rand() % 2;
		if (bracketsNum[0] == 0)
			bracketsNum[1] = 0;
		else
			bracketsNum[1] = rand() % 2;
	}
	else
	{
		bracketsNum[0] = rand() % 3;
		if (bracketsNum[0] == 0)
			bracketsNum[1] = 0;
		else if(bracketsNum[0] == 1)
			bracketsNum[1] = rand() % 5;
		else
			bracketsNum[1] = rand() % 4;
	}

	Fraction fraction[4];

	for (int z = 0; z < i; z++)
	{
		wstring ex = to_wstring(a[z][0]) + L"\'" + to_wstring(a[z][1]) + L"/" + to_wstring(a[z][2]);
		Fraction k(ex);
		fraction[z] = k;
	}

	Expression t(fraction, oprtr, i, bracketsNum);
	t.toWstring();
	t.CalculateFraction();
	NewExpression = t;

	return t.returnExpressionWstring();
}

Expression ExerciseGenerate::returnExpression()
{
	return NewExpression;
}
