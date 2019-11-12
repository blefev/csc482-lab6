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
	string removeLeadingZeroes(string);
public:
	BigInt();
	BigInt(string num);
	BigInt(char chars[]);
	BigInt(const char chars[]);
	~BigInt();
	BigInt trim();
	BigInt& operator = (string num);
	BigInt& operator = (char num[]);
	BigInt& operator = (const char num[]);
	string Add(string lhs, string rhs);
	friend ostream& operator<<(ostream& os, const BigInt& bi);
	BigInt operator + (BigInt rhs);
	BigInt& operator += (BigInt rhs);
	BigInt operator * (BigInt rhs);
	bool operator < (BigInt rhs);
	bool operator > (BigInt rhs);
	bool operator == (BigInt rhs);
	bool operator >= (BigInt rhs);
	bool operator <= (BigInt rhs);
	operator string() const { return value; }
	int length() { return value.length();  }
};


