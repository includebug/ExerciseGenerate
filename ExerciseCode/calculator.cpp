#include "calculator.h"
#include "Fraction.h"

int simplify(int a, int b)  //求最大公约数
{
	int c = 0;
	while (c = a % b)   //c==0时 循环结束
	{
		a = b;
		b = c;
	}
	return b;
}

bool isNo(wchar_t c) //is Number
{
	return c >= L'0' && c <= L'9' || c == L'\'' || c == L'/';
}
bool isSyb(wstring c)//is Symbol
{
	return (c[0] == L'+' || c[0] == L'-' || c[0] == L'×' || c[0] == L'÷') && c.size() == 1; //ver1.2
}
bool isSyb(wchar_t c)//is Symbol
{
	return c == L'+' || c == L'-' || c == L'×' || c == L'÷';
}

bool isIlg(wchar_t c) //is illegal
{
	return !isNo(c) && !isSyb(c) && !(c == L'(' || c == L')' || c == L' ');
}

wstring GetSubtext(wstring S, size_t bgn, size_t end) //follow "left-inclusive interval"
{
	wstring subtext(end - bgn, L' ');
	for (size_t i = bgn; i != end; i++)
		subtext[i - bgn] = S[i];
	return subtext;
}

vector<wstring> split(const std::wstring &s, wchar_t delim)  //切割wstring，以delim符号为分界
{
	if (!s.find(delim))
	{
		cout << "没有这个字符，该数不是分数" << endl;
	}
	vector<wstring> elems;
	wstringstream ss;
	ss.str(s);
	std::wstring item;
	while (getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}

bool spiltNum(int a[3], wstring x)  //把分数的wstring传进去，返回三个整数，存在数组a里
{
	vector<wstring> k, k1;
	k = split(x, L'\'');
	if (k.at(0) == x)    //判断是否切割成功
		return false;
	k1 = split(k.at(1), L'/');
	if (k1.at(0) == k.at(1))
		return false;
	a[0] = stoi(k.at(0));
	a[1] = stoi(k1.at(0));
	a[2] = stoi(k1.at(1));
	return true;
}

wstring calculatorFractionAndInt(wstring x, wstring y, char z)
{
	int b = stoi(y);
	int a[3];
	spiltNum(a, x);
	int c[3];
	wstring TempResult;
	if (z == '+')
	{
		c[0] = a[0] + b;
		c[1] = a[1];
		c[2] = a[2];
	}
	else if (z == '-')
	{
		c[0] = a[0] - b;
		c[1] = a[1];
		c[2] = a[2];
	}
	else if (z == '*')
	{
		c[0] = a[0] * b;
		c[1] = a[1] * b;
		c[2] = a[2];
	}
	else
	{
		c[0] = 0;
		c[1] = a[0] * a[2] + a[1];
		c[2] = a[2] * b;
	}
	if (c[2] != 0 && c[1] != 0)
	{
		int d = simplify(c[1], c[2]);
		c[1] /= d;
		c[2] /= d;
	}
	if (c[1] > c[2] && c[2] != 0)
	{
		c[0] += c[1] / c[2];
		c[1] = c[1] % c[2];
	}
		
	TempResult = to_wstring(c[0]) + L'\'' + to_wstring(c[1]) + L'/' + to_wstring(c[2]);
	return TempResult;
}

wstring calculatorIntAndFraction(wstring x, wstring y, char z)
{
	int a = stoi(x);
	int b[3];
	spiltNum(b, y);
	int c[3];
	wstring TempResult;
	if (z == '+')
	{
		c[0] = a + b[0];
		c[1] = b[1];
		c[2] = b[2];
	}
	else if (z == '-')
	{
		c[0] = a - b[0] - 1;
		c[1] = b[2] - b[1];
		c[2] = b[2];
	}
	else if (z == '*')
	{
		c[0] = b[0] * a;
		c[1] = b[1] * a;
		c[2] = b[2];
	}
	else
	{
		c[0] = 0;
		c[1] = b[0] * b[2] + b[1];
		c[2] = b[2] * a;
	}
	if (c[2] != 0 && c[1] != 0)
	{
		int d = simplify(c[1], c[2]);
		c[1] /= d;
		c[2] /= d;
	}
	if (c[1] > c[2] && c[2] != 0)
	{
		c[0] += c[1] / c[2];
		c[1] = c[1] % c[2];
	}
	TempResult = to_wstring(c[0]) + L'\'' + to_wstring(c[1]) + L'/' + to_wstring(c[2]);
	return TempResult;
}

wstring calculatorFraction(wstring x, wstring y, char z)
{
	int a[3], b[3];
	spiltNum(a, x);
	spiltNum(b, y);
	int c[3];
	wstring TempResult;
	if (z == '+')
	{
		c[0] = a[0] + b[0];
		c[1] = a[1] * b[2] + a[2] * b[1];
		c[2] = a[2] * b[2];
	}
	else if (z == '-')
	{
		c[0] = a[0] - b[0];
		c[1] = a[1] * b[2] - a[2] * b[1];
		c[2] = a[2] * b[2];
		if (c[1] < 0)
		{
			c[0]--;
			c[1] = c[2] - c[1];
		}
	}
	else if (z == '*')
	{
		c[0] = 0;
		c[1] = (a[0] * a[2] + a[1])*(b[0] * b[2] + b[1]);
		c[2] = a[2] * b[2];
	}
	else
	{
		c[0] = 0;
		c[1] = (a[0] * a[2] + a[1])*b[2];
		c[2] = a[2] * (b[0] * b[2] + b[1]);
	}
	if (c[2] != 0 && c[1] != 0)
	{
		int d = simplify(c[1], c[2]);
		c[1] /= d;
		c[2] /= d;
	}
	if (c[1] > c[2] && c[2] != 0)
	{
		c[0] += c[1] / c[2];
		c[1] = c[1] % c[2];
	}
	TempResult = to_wstring(c[0]) + L'\'' + to_wstring(c[1]) + L'/' + to_wstring(c[2]);
	return TempResult;
}

wstring calculatorInt(wstring x, wstring y, char z)
{
	int a[3];
	wstring CtmpResult;
	int tempResult;
	if (z == '+')
	{
		tempResult = stoi(x) + stoi(y);
	}
	if (z == '-')
	{
		tempResult = stoi(x) - stoi(y);
	}
	if (z == '*')
	{
		tempResult = stoi(x) * stoi(y);
	}
	if (z == '/')
	{
		if (stoi(y) == 0)
		{
			CtmpResult = L"0\'0/0";
			return CtmpResult;
		}
		else if (stoi(x) % stoi(y) == 0)
			tempResult = stoi(x) / stoi(y);
		else
		{
			int num1 = stoi(x), num2 = stoi(y);
			a[0] = num1 / num2;
			a[1] = num1 % num2;
			a[2] = num2;
			CtmpResult = to_wstring(a[0]) + L'\'' + to_wstring(a[1]) + L'/' + to_wstring(a[2]);
			return CtmpResult;
		}
	}
	CtmpResult = to_wstring(tempResult); // int to wstring
	return CtmpResult;
}

wstring BasicCalculation(wstring x, wstring y, char z)
{
	wstring CtmpResult;
	if (string::npos != x.find(L"\'") && string::npos != y.find(L"\'"))  //两个分数计算
		CtmpResult = calculatorFraction(x, y, z);
	else if (string::npos == x.find(L"\'") && string::npos != y.find(L"\'"))  //左边整数，右边分数
		CtmpResult = calculatorIntAndFraction(x, y, z);
	else if (string::npos != x.find(L"\'") && string::npos == y.find(L"\'"))  //左边分数，右边整数
		CtmpResult = calculatorFractionAndInt(x, y, z);
	else                                                                           //两个整数
		CtmpResult = calculatorInt(x, y, z); // int to wstring
	return CtmpResult;
}

wstring calc(wstring S, size_t len)
{
	deque<wstring> words;
	bool inNo = false; //door for isNo
	//bool inSyb = false; //door for isSyb
	size_t NoPos = 0;
	//size_t SybPos = 0;
	size_t ParPos = 0, ParDep = 0;
	size_t begin = 0, end = len;
	for (size_t temp = 0; temp < len; temp++)
	{
		if (S[temp] == L'、')
			begin = temp + 1;
		if (S[temp] == L'=')
			end = temp;
	}
	for (size_t i = begin; i <= end; i++) //build standard formula
	{

		if (isIlg(S[i]) && i != end) //formula illegal checking
			return L"The formula is illegal1!";

		if (isNo(S[i]) && !inNo) //Number postion begin
		{
			inNo = true;
			NoPos = i;
		}
		if (!isNo(S[i]) && inNo) //Number postion end
		{
			inNo = false;
			words.push_back(GetSubtext(S, NoPos, i));
		}

		if (isSyb(S[i])/* && !inSyb*/)
		{
			words.push_back(GetSubtext(S, i, i + 1));
		}

		if (S[i] == L')')
			return L"RightParentheses is not match!";

		if (S[i] == L'(')
		{
			//inPar = true;
			ParDep++;
			ParPos = i + 1; //left-inclusive interval
			size_t j;
			for (j = i + 1; ParDep && j <= end; j++)
			{
				if (S[j] == L'(') ParDep++;
				if (S[j] == L')') ParDep--;
			}
			if (j <= end)
			{
				wstring recResult(calc(GetSubtext(S, ParPos, j - 1), GetSubtext(S, ParPos, j - 1).size()));
				if (recResult == L"The formula is illegal!")
					return L"The formula is illegal2!";

				else if (recResult == L"Parentheses is not match!")
					return L"LeftParentheses is not match!";

				else
					words.push_back(recResult);
			}
			else
			{
				//parentheses is not match
				return L"LeftParentheses is not match!";
			}
			i = j - 1; //jump over subtext
		}

	} //end for

	int tempResult = 0;
	wstring CtmpResult;

	//check formula
	if (words.size() == 0) return L"0"; // 0 element
	if (words.size() == 1) //1 element
		if (!isSyb(words.front()))
		{
			//strcpy_s(CtmpResult, words.front().c_str());
			CtmpResult = words.front();
			return CtmpResult;
		}
		else
		{
			wstring s(L"The formula is illegal3!");
			return s;
		}
	if (words.front() == L"×" || words.front() == L"÷")  //front is symble
		return L"The formula is illegal4!";
	if (words.front() == L"+" || words.front() == L"-")
	{
		if (!isSyb(*(words.begin() + 1)))
		{
			words.front() += *(words.begin() + 1);
			words.erase(words.begin() + 1); //erase second one
		}
		else
			return L"The formula is illegal5!";
	}
	if (isSyb(words.back()))
	{
		wcout.imbue(locale("chs"));
		wcout << words.back() << endl;
		return L"The formula is illegal6!";
	}

	for (deque<wstring>::iterator i = words.begin() + 1; i < words.end(); i++)
	{
		if ((*i == L"×" || *i == L"÷") && (isSyb(*(i - 1))) && (*(i - 1)).size())
			return L"The formula is illegal7!";
		if ((*i == L"+" || *i == L"-") && (isSyb(*(i - 1))) && (*(i - 1)).size())
			if (!isSyb(*(i + 1)))
			{
				*(i + 1) = *i + *(i + 1);
				i = words.erase(i);
			}
			else
				return L"The formula is illegal8!";
	}

	//start calculate
	for (deque<wstring>::iterator i = words.begin(); i != words.end(); i++)
	{
		//calculate * and /
		if (*i == L"×")
		{
			CtmpResult = BasicCalculation(*(i - 1), *(i + 1), '*');
			i = words.erase(i - 1);
			i = words.erase(i);
			*i = CtmpResult;
		}
		if (*i == L"÷")
		{
			CtmpResult = BasicCalculation(*(i - 1), *(i + 1), '/');
			i = words.erase(i - 1);   //erase函数返回下一个的对象，相当于数组的i++
			i = words.erase(i);
			*i = CtmpResult;
		}
	}
	for (deque<wstring>::iterator i = words.begin(); i != words.end(); i++)
	{
		//calculate + and -
		if (*i == L"+")
		{
			CtmpResult = BasicCalculation(*(i - 1), *(i + 1), '+');
			i = words.erase(i - 1);
			i = words.erase(i);
			*i = CtmpResult;
		}
		if (*i == L"-")
		{
			CtmpResult = BasicCalculation(*(i - 1), *(i + 1), '-');
			i = words.erase(i - 1);
			i = words.erase(i);
			*i = CtmpResult;
		}
	}

	CtmpResult = words.front();
	return CtmpResult;
}

void ReadANSI(string expressionFilename, string resultFilename)  //ANSI编码的txt读取
{
	wstring b;
	wstring c;
	wifstream infile;
	wifstream infile1;
	infile.imbue(locale("chs"));
	infile1.imbue(locale("chs"));
	wcout.imbue(locale("chs"));
	//ANSI型保存的txt才能用
	infile.open(expressionFilename);
	infile1.open(resultFilename);
	if (!infile.is_open())
	{
		exit(EXIT_FAILURE);
	}
	int i = 0;
	int errorNumber = 0;
	int rightNumber = 0;
	string right;
	string error;
	while (!infile.eof())
	{
		i++;
		getline(infile, b);
		getline(infile1, c);
		if (b.size() == 0 && c.size() == 0)
			continue;
		wstring result1 = calc(b, b.size());
		if (string::npos == result1.find(L"\'"))
			result1 = result1 + L"\'0/1";
		Fraction temp(result1);
		if (string::npos == c.find(temp.FractionWstring()))
		{
			error = error + to_string(i) + ',';
			errorNumber++;
		}
		else
		{
			right = right + to_string(i) + ',';
			rightNumber++;
		}
	}
	
	ofstream GradeFile;
	GradeFile.open("Grade.txt", ios::app);
	if (!GradeFile.is_open())
	{
		exit(EXIT_FAILURE);
	}
	string Correct = "Correct:" + to_string(rightNumber) + '(' + right + ')';
	string Wrong = "Wrong:" + to_string(errorNumber) + '(' + error + ')';
	GradeFile << Correct << endl << Wrong << endl;
	GradeFile.close();
	infile.close();
}
