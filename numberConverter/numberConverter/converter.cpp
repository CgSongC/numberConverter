// Create a Converter
#include <iostream>
#include <string>
#include <bitset>

using namespace std;
int main()
{
	int iBinary, iOctal, iDecimal, iHexadecimal, iType, i = 0, iInputType;
	int cArray[100];
	cout << "입력할 진수 타입을 선택하시오 [2:2진수, 8:8진수, 10: 10진수, 16:16진수] :";
	cin >> iInputType;
	// 진수 변환 switch 

	cout << "10 진수를 입력해주세요 : ";
	cin >> iDecimal;
	cout << "변환할 진수 타입를 선택하세요 [2:이진수, 8:8진수, 16:16진수]:";
	cin >> iType;
	cout << "Binary = " << bitset<8>(iDecimal)<< endl;
	cout << "Octal = " << oct << iDecimal << endl;
	cout << "Hexadecimal = " << hex << iDecimal << endl;
	while (iDecimal != 0)
	{
		cArray[i] = (iDecimal % iType);
		iDecimal = iDecimal / iType;
		i++;
	}

	for (int j= i-1; j >= 0; --j)
	{
		cout << cArray[j];
	}
	return 0;
}