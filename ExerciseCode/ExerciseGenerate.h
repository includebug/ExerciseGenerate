#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <time.h>
#include <list>
#include "Expression.h"
#include "Fraction.h"
#include "calculator.h"

using namespace std;
class ExerciseGenerate
{
private:
	int a[4][3];
	Expression NewExpression;
	int numSize;  //�����������ֵ
public:
	bool ExerciseGenerateMaxNum(int i);

    wstring generateExpress();
	//���ɱ��ʽ
	Expression returnExpression();
};
