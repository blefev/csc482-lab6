#include "BigInt.h"


BigInt::BigInt()
{
	value = "";
}

BigInt::BigInt(string num)
{
	value = num;
}


BigInt::~BigInt()
{
}

BigInt BigInt::operator=(string num)
{
	value = num;
	return *(this);
}

BigInt BigInt::operator+(BigInt operand)
{
	string lhs = value;
	string rhs = string(operand);
	string result = "";

	// perform multiplication
	if (lhs.length() > rhs.length()) {
		lhs.swap(rhs);
	}

	int carry = 0;
	for (auto i = lhs.length()-1; i--;) {
		// calculate sum for current positions
		int sum = ((lhs[i] - '0') + (rhs[i] - '0') + carry);

		// add to result
		result.push_back(sum % 10 + '0');

		carry = sum / 10;
	}

	// add what's left of the longer BigInteger string
	for (auto i = rhs.length() - 1; i >= lhs.length(); i--) {
		int sum = (rhs[i] - '0') + carry;
		result.push_back(sum % 10 + '0');

		carry = sum / 10;
	}

	if (carry > 0) {
		result.push_back(carry + '0');
	}

	return BigInt(result);
}

BigInt BigInt::operator*(BigInt rhs)
{
	return BigInt();
}

ostream& operator<<(ostream& os, const BigInt& bi)
{
	os << bi.value;
	return os;
}
