#include "BigInt.h"


string BigInt::removeLeadingZeroes(string str)
{
	// remove trailing zeroes up to n-2
	if (str.length() < 2) {
		return str;
	}

	str.erase(0, min(str.find_first_not_of('0'), str.size() - 2));
	return str;
}

BigInt::BigInt()
{
	value = "0";
}

BigInt::BigInt(string num)
{
	if (num.length() == 0) {
		value = "0";
	} else {
		value = removeLeadingZeroes(num);
	}
}

BigInt::BigInt(char chars[])
{
	value = removeLeadingZeroes(string(chars));
}

BigInt::BigInt(const char chars[])
{
	value = removeLeadingZeroes(string(chars));
}

BigInt::~BigInt()
{
}

BigInt BigInt::trim()
{
	value = removeLeadingZeroes(value);
	return *(this);
}

BigInt& BigInt::operator=(string num)
{
	value = removeLeadingZeroes(num);
	return *(this);
}

BigInt& BigInt::operator=(char chars[])
{
	value = removeLeadingZeroes(string(chars));
	return *this;
}

BigInt& BigInt::operator=(const char chars[])
{
	value = removeLeadingZeroes(string(chars));
	return *this;
}

string BigInt::Add(string lhs, string rhs) {
	string result = "";

	// perform multiplication
	if (lhs.length() > rhs.length()) {
		swap(lhs, rhs);
	}

	lhs.insert(lhs.begin(), rhs.length() - lhs.length(), '0');

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
	for (int i = rhs.length() - 1; i >= lhs.length(); i--) {
		int sum = (rhs[i] - '0') + carry;
		result.push_back(sum % 10 + '0');

		carry = sum / 10;
	}

	if (carry > 0) {
		result.push_back(carry + '0');
	}
	reverse(result.begin(), result.end());

	return result;
}

BigInt BigInt::operator+(BigInt operand)
{
	string lhs = value;
	string rhs = string(operand);

	return Add(lhs, rhs);
}

BigInt& BigInt::operator+=(BigInt rhs)
{
	value = Add(value, rhs);
	return *(this);
}

bool BigInt::test() {
	cout << "Testing\n";
	for (int i = 0; i < 100; i++) {
		for (size_t j = 0; j < 100; j++) {
			BigInt a = BigInt(to_string(i));
			BigInt b = BigInt(to_string(j));
			BigInt result = a * b;
			cout << i << "*" << j << ": " << result;

			if (string(result) != to_string(i * j)) {
				cout << " FAILURE!\n";
				return false;
			} else {
				cout << " PASSED\n";
			}
		}
	}
	for (int i = 0; i < 100; i++) {
		for (size_t j = 0; j < 100; j++) {
			BigInt a = BigInt(to_string(i));
			BigInt b = BigInt(to_string(j));
			BigInt result = a + b;
			cout << i << "+" << j << ": " << result;

			if (string(result) != to_string(i * j)) {
				cout << " FAILURE!\n";
				return false;
			} else {
				cout << " PASSED\n";
			}
		}
	}
	return true;
}

BigInt BigInt::operator*(BigInt operand)
{
	string lhs = value;
	string rhs = string(operand);
	if (lhs.length() == 0 || rhs.length() == 0) {
		return BigInt("0");
	}

	vector<int> result(lhs.length() + rhs.length(), 0);

	int index1 = 0, index2 = 0;

	for (int i = lhs.length() - 1; i >= 0; i--) {
		int carry = 0;
		int num1 = lhs[i] - '0';
		index2 = 0;

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

bool BigInt::operator<(BigInt rhs)
{
	return value < string(rhs);
}

bool BigInt::operator>(BigInt rhs)
{
	return value > string(rhs);
}

bool BigInt::operator==(BigInt rhs)
{
	return value == string(rhs);
}

bool BigInt::operator>=(BigInt rhs)
{
	return value >= string(rhs);
}

bool BigInt::operator<=(BigInt rhs)
{
	return value <= string(rhs);
}

ostream& operator<<(ostream& os, const BigInt& bi)
{
	os << bi.value;
	return os;
}
