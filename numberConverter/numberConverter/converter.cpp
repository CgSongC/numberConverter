// Create a Converter
#include <iostream>
#include <string>
#include <bitset>

using namespace std;
int main()
{
	int iBinary, iOctal, iDecimal, iHexadecimal, iType, i = 0, iInputType;
	int cArray[100];
	cout << "�Է��� ���� Ÿ���� �����Ͻÿ� [2:2����, 8:8����, 10: 10����, 16:16����] :";
	cin >> iInputType;
	// ���� ��ȯ switch 

	cout << "10 ������ �Է����ּ��� : ";
	cin >> iDecimal;
	cout << "��ȯ�� ���� Ÿ�Ը� �����ϼ��� [2:������, 8:8����, 16:16����]:";
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