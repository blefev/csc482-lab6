#include "BigInt.h"


BigInt::BigInt()
{
	value = "0";
}

BigInt::BigInt(string num)
{
	if (num.length() == 0) {
		value = "0";
	}
	else {
		value = num;
	}
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

	if (lhs.length() == 0) {
		return rhs;
	}

	int carry = 0;
	for (int i = lhs.length() - 1; i >= 0; i--) {
		// calculate sum for current positions
		int sum = ((lhs[i] - '0') + (rhs[i] - '0') + carry);

		// add to result
		result.push_back(sum % 10 + '0');

		carry = sum / 10;
	}

	// add what's left of the longer BigInteger string
	for (int i = rhs.length()-1; i >= lhs.length(); i--) {
		int sum = (rhs[i] - '0') + carry;
		result.push_back(sum % 10 + '0');

		carry = sum / 10;
	}

	if (carry > 0) {
		result.push_back(carry + '0');
	}
	reverse(result.begin(), result.end());
	return BigInt(result);
}

BigInt BigInt::operator*(BigInt operand)
{
	string rhs = string(operand);
	if (value.length() == 0 || rhs.length() == 0) {
		return BigInt("0");
	}

	vector<int> result(value.length() + rhs.length(), 0);

	int index1 = 0, index2 = 0;

	for (int i = value.length() - 1; i >= 0; i--) {

		int carry = 0;

		int num1 = value[i] - '0';

		for (int j = rhs.length() - 1; j >= 0; j--) {
			int num2 = rhs[j] - '0';

			int sum = num1 * num2 + result[index1 + index2] + carry;
			
			carry = sum / 10;

			result[index1 + index2] = sum % 10;

			index2++;
		}

		if (carry > 0) {
			result[index1 + index2] += carry;
		}

		index1++;
	}

	int i = result.size() - 1;

	while (i >= 0 && result[i] == 0) {
		i--;
	}

	if (i == -1) return BigInt("0");

	string stringResult = "";

	while (i >= 0) {
		stringResult += to_string(result[i--]);
	}

	return BigInt(stringResult);
}

ostream& operator<<(ostream& os, const BigInt& bi)
{
	os << bi.value;
	return os;
}
