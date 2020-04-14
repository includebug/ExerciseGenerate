#include "Expression.h"

Expression::Expression()
{
	;
}

Expression::Expression(Fraction x[4], wchar_t Operator[3],int i,int brackets[2])
{
	OperationNum = i;
	for (int k = 0; k < OperationNum; k++)
		t[k] = x[k];
	for (int j = 0; j < OperationNum - 1; j++)
		wOPERATER[j] = Operator[j];
	for (int n = 0; n< 2; n++)
		bracketsNum[n] = brackets[n];
}

void Expression::toWstring()
{
	if (OperationNum == 4)
	{
		if (bracketsNum[0] == 1 && OperationNum == 4)
		{
			if (bracketsNum[1] == 0)
			{
				ExpressionWstring = L"(" + t[0].FractionWstring() + L' ' + wOPERATER[0] + L' ' + t[1].FractionWstring() + L")"
					+ L' ' + wOPERATER[1] + L' ' + t[2].FractionWstring() + wOPERATER[2] + L' ' + t[3].FractionWstring();
			}
			else if (bracketsNum[1] == 1)
			{
				ExpressionWstring = t[0].FractionWstring() + L' ' + wOPERATER[0] + L"(" + L' ' + t[1].FractionWstring() + L' ' +
					wOPERATER[1] + L' ' + t[2].FractionWstring() + L")" + wOPERATER[2] + L' ' + t[3].FractionWstring();
			}
			else if (bracketsNum[1] == 2)
			{
				ExpressionWstring = t[0].FractionWstring() + L' ' + wOPERATER[0] + L' ' + t[1].FractionWstring() + L' ' +
					wOPERATER[1] + L' ' + L"(" + t[2].FractionWstring() + wOPERATER[2] + L' ' + t[3].FractionWstring() + L")";
			}
			else if (bracketsNum[1] == 3)
			{
				ExpressionWstring = L"(" + t[0].FractionWstring() + L' ' + wOPERATER[0] + L' ' + t[1].FractionWstring() + L' ' +
					wOPERATER[1] + L' ' + t[2].FractionWstring() + L")" + wOPERATER[2] + L' ' + t[3].FractionWstring();
			}
			else
			{
				ExpressionWstring = t[0].FractionWstring() + L' ' + wOPERATER[0] + L' ' + L"(" + t[1].FractionWstring() + L' ' +
					wOPERATER[1] + L' ' + t[2].FractionWstring() + wOPERATER[2] + L' ' + t[3].FractionWstring() + L")";
			}
		}
		else if (bracketsNum[0] == 2 && OperationNum == 4)
		{
			if (bracketsNum[1] == 0)
			{
				ExpressionWstring = L"((" + t[0].FractionWstring() + L' ' + wOPERATER[0] + L' ' + t[1].FractionWstring() + L")"
					+ L' ' + wOPERATER[1] + L' ' + t[2].FractionWstring() + L")" + wOPERATER[2] + L' ' + t[3].FractionWstring();
			}
			else if (bracketsNum[1] == 1)
			{
				ExpressionWstring = t[0].FractionWstring() + L' ' + wOPERATER[0] + L' ' + L"((" + t[1].FractionWstring() + L' ' +
					wOPERATER[1] + L' ' + t[2].FractionWstring() + L")" + wOPERATER[2] + L' ' + t[3].FractionWstring() + L")";
			}
			else
			{
				ExpressionWstring = t[0].FractionWstring() + L' ' + wOPERATER[0] + L' ' + L"(" + t[1].FractionWstring() + L' ' +
					wOPERATER[1] + L' ' + L"(" + t[2].FractionWstring() + wOPERATER[2] + L' ' + t[3].FractionWstring() + L"))";
			}
		}
		else
		{
			ExpressionWstring = t[0].FractionWstring() + L' ' + wOPERATER[0] + L' ' + t[1].FractionWstring() + L' ' +
				wOPERATER[1] + L' ' + t[2].FractionWstring() + wOPERATER[2] + L' ' + t[3].FractionWstring();
		}	
	}		
	else if (OperationNum == 3)
	{
		if (bracketsNum[1] == 0)
		{
			ExpressionWstring = L"("+t[0].FractionWstring() + L' ' + wOPERATER[0] + L' '
				+ t[1].FractionWstring()+L")" + L' ' + wOPERATER[1] + L' ' + t[2].FractionWstring();
		}
		else if(bracketsNum[1] == 1)
		{
			ExpressionWstring = t[0].FractionWstring() + L' ' + wOPERATER[0] + L' ' + L"("
				+ t[1].FractionWstring() + L' ' + wOPERATER[1] + L' ' + t[2].FractionWstring() + L")";
		}
		else
		{
			ExpressionWstring = t[0].FractionWstring() + L' ' + wOPERATER[0] + L' '
				+ t[1].FractionWstring() + L' ' + wOPERATER[1] + L' ' + t[2].FractionWstring();
		}
	}	
	else
		ExpressionWstring = t[0].FractionWstring() + L' ' + wOPERATER[0] + L' ' + t[1].FractionWstring();
}

void Expression::print()
{
	wcout.imbue(locale("chs"));
	wcout << L"表达式宽字符串为：" << ExpressionWstring << endl;
	result.print();
}

Fraction Expression::returnResult()
{
	return result;
}


wstring Expression::returnExpressionWstring()
{
	return ExpressionWstring;
}

void Expression::CalculateFraction()
{
	wstring result1 = calc(ExpressionWstring, ExpressionWstring.size());
	if (string::npos == result1.find(L"\'"))
		result1 = result1 + L"\'0/1";
	Fraction result2(result1);
	result = result2;
}

