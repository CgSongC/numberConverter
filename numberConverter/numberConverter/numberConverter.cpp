// Number Converter
// Choice type of input number
// binary | octal |decimal |hexadecimal
// Input Number
// Choice type of number to convert

#include <iostream>
using namespace std;

#define ARR_MAX 10000
class NumberConverter
{
private:
	int iInput;
	int iConvert1;
	int iConvert2;
	int iConverted;
	int iArray[ARR_MAX];
	int iCnt = 0;
	int iDiv10;
	int iTenPosition = 1;
	int iTen = 0;
public:
	NumberConverter()
	{
		iInput = 0;
		iConvert1 = 0;
		iConvert2 = 0;
		iConverted = 0;
	}
	NumberConverter(int iInput)
	{
		this->iInput = iInput;
		iConvert1 = 0;
		iConvert2 = 0;
	}
	NumberConverter(int iInput, int iConvert1)
	{
		this->iInput = iInput;
		this->iConvert1 = iConvert1;
	}
	NumberConverter(int iInput, int iConvert1, int iConvert2)
	{
		(*this).iInput = iInput;
		this->iDiv10 = iInput;
		this->iConvert1 = iConvert1;
		this->iConvert2 = iConvert2;
		this->iCnt = GetCount(this->iDiv10, this->iCnt);
		this->iTenPosition = MakeTenPosition(this->iCnt, this->iTenPosition);
		PositionNum(this->iInput, this->iConvert1, this->iTenPosition);
		this->iTen = SquareNum(this->iCnt, this->iConvert1);
		ConvertComplete(this->iTen, this->iConvert2);

		cout << "iCnt =  " << this->iCnt << endl;
		cout << "iTenPosition = " << this->iTenPosition << endl;
		cout << "this-> iArray = ";
		for (int i = 0; i < this->iCnt; ++i)
		{
			cout << this->iArray[i];
		}
		cout << endl;

	}

	int GetCount(int gDiv, int gCnt)
	{
		while (gDiv != 0)
		{
			gDiv /= 10;
			gCnt++;
		}
		return gCnt;
	}
	int MakeTenPosition(int mCnt, int mTenPosition)
	{
		for (int i = 1; i < mCnt; ++i)
		{
			mTenPosition *= 10;
		}
		return mTenPosition;
	}

	void PositionNum(int pInput, int pCinvert1, int pTenPosition)
	{
		int p = 0;
		int pTenTotal = 0;

		while (pInput != 0)
		{
			this->iArray[p] = pInput / pTenPosition;
			pTenTotal += pCinvert1;
			pInput %= pTenPosition;
			pTenPosition /= 10;
			p++;
		}
	}
	// Convert input type of number to decimal
	int SquareNum(int sCnt, int sConvert1)
	{
		int sTen = 0;
		// Create dynamic array
		int *sSquareArray = new int[sCnt];
		fill_n(sSquareArray, sCnt, 1);

		// Calculation weight of input type of number
		for (int i = 0; i < sCnt; ++i)
		{

			for (int j = sCnt - i - 1; j > 0; --j)
			{
				sSquareArray[i] *= sConvert1;
			}

		}
		// Create dynamic array & sum value of each position.
		int *sValueArray = new int[sCnt];
		fill_n(sValueArray, sCnt, 0);
		for (int i = 0; i < sCnt; ++i)
		{
			sValueArray[i] = this->iArray[i] * sSquareArray[i];
			sTen += sValueArray[i];
		}

		// Print value by position
		for (int i = 0; i < sCnt; ++i)
		{
			cout << "sValueArray = " << sValueArray[i] << endl;
		}
		return sTen;
	}

	// Convert decimal to other type of number
	void ConvertComplete(int cTen, int cConvert2)
	{
		int cCnt = 0, i = 0, jTen = cTen;
		int resultCnt = 0;
		while (jTen != 0)
		{
			jTen /= cConvert2;
			++cCnt;
		}
		resultCnt = cCnt;
		int *cConverted = new int[cCnt];
		fill_n(cConverted, cCnt, 0);
		while (cTen != 0)
		{
			cConverted[i] = cTen % cConvert2;
			cTen /= cConvert2;
			i++;
		}
		GetNumber(cConverted, resultCnt);
	}

	// Print result massage
	void GetNumber(int *makeNumber, int resultCnt)
	{
		cout << "A ";
		switch (iConvert1)
		{
		case 2:
			cout << "binary";
			break;
		case 8:
			cout << "octal";
			break;
		case 10:
			cout << "decimal";
			break;
		case 16:
			cout << "hexadecimal";
			break;
		}
		cout << " number " << iInput << " is converted to an ";
		switch (iConvert2)
		{
		case 2:
			cout << "binary";
			break;
		case 8:
			cout << "octal";
			break;
		case 10:
			cout << "decimal";
			break;
		case 16:
			cout << "hexadecimal";
			break;
		}
		cout << " number ";
		for (int i = resultCnt; i > 0; --i)
		{
			cout << makeNumber[i - 1];
		}
		cout << ".\n";
	}

};

int main() {
	int iInput, iConvert1, iConvert2;
	cout << "Choice a starting notation type \n[2:Binary, 8:Octal, 10:Decimal, 16:Hexadecimal] :";
	cin >> iConvert1;
	cout << "Enter a number what you convert :";
	cin >> iInput;
	cout << "Choice a converting notation type \n[2:Binary, 8:Octal, 10:Decimal, 16:Hexadecimal] :";
	cin >> iConvert2;

	NumberConverter nCr(iInput, iConvert1, iConvert2);
	return 0;
}