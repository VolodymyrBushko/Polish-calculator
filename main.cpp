#include "Header.h"
int main()
{
	//need create file "math.txt" in local folder with expression
	const string road = "math.txt";
	Calculator calculator;
	cout << "\n Transfer : " << calculator.Transfer(calculator.ReadFile(road)) << "\n\n\n";
	cout << "\n Result : " << calculator.Result(calculator.Transfer(calculator.ReadFile(road))) << "\n\n\n";
	
	system("pause");
	return 0;
}