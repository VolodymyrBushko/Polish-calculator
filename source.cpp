#include "Header.h"



void Calculator::ErroCheck(string str)
{
	int counter = 0, i = 0; stack<char> stackChar;
	try {
		while (str.size() > i)
		{
			if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
				counter++;
			if (str[i] == ' ')
				throw exception("Error through space.");
			i++;
		}
		if (counter == 0)
			throw exception("There are no mathematical operations or file is clean.");
		i = 0;
		while (str.size() > i)
		{
			if (str[i] == ')'&&stackChar.empty())
				exit(0);
			else if (str[i] == '(')
				stackChar.push(str[i]);
			else if (str[i] == ')')
				stackChar.pop();
			i++;
		}
		if (!stackChar.empty())
			throw exception("The brackets do not match.");
	}
	catch (exception& ex)
	{
		cout << ex.what() << "\n";
		system("pause");
		exit(0);
	}
}



string Calculator::ReadFile(string road)
{
	ifstream file; string str; char tmp;
	file.open(road);
	if (!file.is_open())
		cout << "\n Error file. ";
	else
	{
		while (file.get(tmp))
			str += tmp;
	}
	file.close();
	ErroCheck(str);
	return str;
}



string Calculator::Transfer(string str)
{
	int i = 0; stack<char> stackChar; string tmp;
	while (i < str.size())
	{
		if (isdigit(str[i]) || str[i] == '.')
			tmp += str[i];
		else if (str[i] == '(')
			stackChar.push(str[i]);
		else if (str[i] == ')')
		{
			tmp += ' ';
			while (stackChar.top() != '(')
			{
				tmp += stackChar.top();
				tmp += ' ';
				stackChar.pop();
			}
			stackChar.pop();
		}
		else if (!isdigit(str[i]))
		{
			tmp += ' ';
			if (!stackChar.empty() && str[i] == '+' || str[i] == '-')
			{
				while (!stackChar.empty() && stackChar.top() != '(')
				{
					tmp += stackChar.top();
					tmp += ' ';
					stackChar.pop();
				}
			}
			else if (!stackChar.empty() && str[i] == '*' || str[i] == '/')
			{
				while (!stackChar.empty() && stackChar.top() != '(' && stackChar.top() != '+' && stackChar.top() != '-')
				{
					tmp += stackChar.top();
					tmp += ' ';
					stackChar.pop();
				}
			}
			stackChar.push(str[i]);
		}
		i++;
	}
	tmp += ' ';
	while (!stackChar.empty())
	{
		tmp += stackChar.top();
		tmp += ' ';
		stackChar.pop();
	}
	return tmp;
}



double Calculator::Result(string str)
{
	string tmp = ""; stack<double> stackDouble;
	int i = 0; double a, b;
	while (i < str.size())
	{
		if (isdigit(str[i]) || str[i] == '.')
			tmp += str[i];
		else if (str[i] == ' ' && i != (str.size() - 1))
		{
			if (i != 0 && isdigit(str[i - 1]))
				stackDouble.push(strtod(tmp.c_str(), 0));
			tmp = "";
		}
		else if (!isdigit(str[i]) && str[i] != ' '&&str[i] != '.')
		{
			a = stackDouble.top();
			stackDouble.pop();
			b = stackDouble.top();
			stackDouble.pop();
			if (str[i] == '+')
				stackDouble.push(a + b);
			else if (str[i] == '-')
				stackDouble.push(b - a);
			else if (str[i] == '*')
				stackDouble.push(a*b);
			else if (str[i] == '/')
				stackDouble.push(b / a);
		}
		i++;
	}
	return stackDouble.top();
}