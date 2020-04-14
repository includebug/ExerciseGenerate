#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <deque>
#include <vector>
#include <fstream>
#include <codecvt>
#include <sstream>

using namespace std;

int simplify(int a, int b); //求最大公约数

bool isNo(wchar_t c); //is Number

bool isSyb(wstring c);//is Symbol

bool isSyb(wchar_t c);//is Symbol


bool isIlg(wchar_t c); //is illegal


wstring GetSubtext(wstring S, size_t bgn, size_t end);//follow "left-inclusive interval"


vector<wstring> split(const std::wstring &s, wchar_t delim);  //切割wstring，以delim符号为分界


bool spiltNum(int a[3], wstring x);//把分数的wstring传进去，返回三个整数，存在数组a里


wstring calculatorFractionAndInt(wstring x, wstring y, char z);  //计算分数和整数


wstring calculatorIntAndFraction(wstring x, wstring y, char z); //计算整数和分数


wstring calculatorFraction(wstring x, wstring y, char z);  //计算两个分数


wstring calculatorInt(wstring x, wstring y, char z);  //计算两个整数


wstring BasicCalculation(wstring x, wstring y, char z); //计算两个数的结果


wstring calc(wstring S, size_t len);  //计算S的数值返回wstring保存的结果


void ReadANSI(string expressionFilename, string resultFilename); //ANSI编码的txt读取


void ReadUTF8(string expressionFilename, string resultFilename);  //不带BOM的utf8的读取
