#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class BigInt
{
protected:
	string value;
	BigInt removeTrailingZeroes(BigInt);
public:
	BigInt();
	BigInt(string num);
	~BigInt();
	void trim();
	BigInt operator = (string num);
	friend ostream& operator<<(ostream& os, const BigInt& bi);
	BigInt operator + (BigInt rhs);
	BigInt operator * (BigInt rhs);
	BigInt operator < (BigInt rhs);
	BigInt operator > (BigInt rhs);
	BigInt operator == (BigInt rhs);
	BigInt operator >= (BigInt rhs);
	BigInt operator <= (BigInt rhs);
	operator string() const { return value; }
	int length() { return value.length();  }
};


