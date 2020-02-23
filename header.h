#include <iostream>
#include <stack>
#include <string>
#include <fstream>

using namespace std;

class Calculator
{
	void ErroCheck(string str);
public:
	string ReadFile(string road);
	string Transfer(string str);
	double Result(string str);
};