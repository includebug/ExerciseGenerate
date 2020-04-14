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

int simplify(int a, int b); //�����Լ��

bool isNo(wchar_t c); //is Number

bool isSyb(wstring c);//is Symbol

bool isSyb(wchar_t c);//is Symbol


bool isIlg(wchar_t c); //is illegal


wstring GetSubtext(wstring S, size_t bgn, size_t end);//follow "left-inclusive interval"


vector<wstring> split(const std::wstring &s, wchar_t delim);  //�и�wstring����delim����Ϊ�ֽ�


bool spiltNum(int a[3], wstring x);//�ѷ�����wstring����ȥ������������������������a��


wstring calculatorFractionAndInt(wstring x, wstring y, char z);  //�������������


wstring calculatorIntAndFraction(wstring x, wstring y, char z); //���������ͷ���


wstring calculatorFraction(wstring x, wstring y, char z);  //������������


wstring calculatorInt(wstring x, wstring y, char z);  //������������


wstring BasicCalculation(wstring x, wstring y, char z); //�����������Ľ��


wstring calc(wstring S, size_t len);  //����S����ֵ����wstring����Ľ��


void ReadANSI(string expressionFilename, string resultFilename); //ANSI�����txt��ȡ


void ReadUTF8(string expressionFilename, string resultFilename);  //����BOM��utf8�Ķ�ȡ
