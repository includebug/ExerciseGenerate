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
	int numSize;  //操作数的最大值
public:
	bool ExerciseGenerateMaxNum(int i);

    wstring generateExpress();
	//生成表达式
	Expression returnExpression();
};
