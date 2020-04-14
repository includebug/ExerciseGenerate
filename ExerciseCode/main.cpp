#include <iostream>
#include <fstream>
#include "Fraction.h"
#include "ExerciseGenerate.h"
#include "calculator.h"
using namespace std;

int main(int argc,char* argv[])
{
	wcout.imbue(locale("chs"));
	if (argc < 3)   //����û�� 4�� 
	{
		cout << "��������������3�����뵽cmd������" << endl;
		system("pause");
		return 1;
	}
	if (strcmp(argv[1], "-n") == 0 && strcmp(argv[3], "-r") == 0)
	{
		wofstream ofs1, ofs2;
		ofs1.open("Exercise.txt", ios::app);
		ofs2.open("Result.txt", ios::app);
		ofs1.imbue(locale("chs"));
		ofs2.imbue(locale("chs"));
		int ExerciseNumber, MaxNum;
		ExerciseNumber = atoi(argv[2]);
		MaxNum = atoi(argv[4]);

		ExerciseGenerate *x = new ExerciseGenerate[ExerciseNumber];
		int j = 0;
		for (int i = 0; i < 20 && j < ExerciseNumber; i++)
		{
			x[j].ExerciseGenerateMaxNum(MaxNum);
			x[j].generateExpress();

			Expression temp = x[j].returnExpression();
			Fraction z = temp.returnResult();
			if (z.isPositive())
			{
				wstring y = temp.returnExpressionWstring();
				ofs1 << j + 1 << L"�� ";
				ofs1 << y << endl;
				y = z.FractionWstring();
				ofs2 << j + 1 << L"�� ";
				ofs2 << y << endl;
				j++;  //��ȡ��һ�����ʽ
				i = 0; //���¼���������20�β��ܴ��ȥ������
			}
		}
		
		delete[]x;
		ofs1.close();
		ofs2.close();
	}
	else if (!strcmp(argv[1], "-e") && !strcmp(argv[3], "-a"))
	{
		string ExerciseFile = argv[2];
		string AnswerFile = argv[4];
		ReadANSI(ExerciseFile, AnswerFile);
	}
	system("pause");
	return 0;
}