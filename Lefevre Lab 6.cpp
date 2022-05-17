#include <iostream>
#include "BigInt.h"
#include "test_numbers.h" // first 94 fibonacci numbers
#include "functions.h"
#include <functional>
#include <chrono>
#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include <bitset>

using namespace std;

long double timeFunction(string funcName, int param);
bool testAllFuncs();
bool testFibFunc(string funcName, int X);
void measureAllFuncs();
void measureAndRecordFunc(string funcName, int X, int nTrials = 1);

map<string, function<BigInt(int)>> namesToFuncs{
	{"FibLoop", FibLoop},
	{"FibRecur", FibRecur},
	{"FibRecurDP", FibRecurDP},
	{"FibMatrix", FibMatrix},
	{"FibRecurDPTail", FibRecurDPTail},
	{"FibFormula", FibFormula}
};

map<string, int> funcMaxXs{
	{"FibLoop", 100},
	{"FibRecur", 28},
	{"FibRecurDP", 1000},
	{"FibMatrix", 1000},
	{"FibRecurDPTail", 92},
	{"FibFormula", 45}
};

int main(int argc, char** argv) {
	BigInt a = "";
	a.test();
	if (argc > 1 && string(argv[1]) == "test") {
		return testAllFuncs();
	}
	//return testAllFuncs();
	measureAllFuncs();

	return 0;
}

void measureAllFuncs() {
	// iterate through each function and call measureAndRecordFunc
	for (auto& it : namesToFuncs) {
		string funcName = it.first; // this is the value in the namesToFuncs map
		int maxX = funcMaxXs[funcName]; // get maximum N
		cout << "Testing " << funcName << "\n";
		measureAndRecordFunc(funcName, maxX);
	}
}

// times function and writes results to file
void measureAndRecordFunc(string funcName, int X, int nTrials) {
	ofstream fout("output\\" + funcName, ios::trunc);
	fout << "N\tX\tT\n";
	long double sum = 0;
	long double avg = 0;

	for (int i = 0; i <= X; i++) {
		cout << i << " ";
		for (int trial = 0; trial < nTrials; trial++) {
			long double time = timeFunction(funcName, i);
			sum += time;

			//cout << "Trial " << trial << ", time: " << time << "\n";
			//cout << "Sum: " << sum << "\n";	
		}
		avg = sum / nTrials;

		unsigned long bits = round(floor(log2(i)) + 1);

		fout << bits << "\t" << i << "\t" << avg << endl;

	}
	cout << "\n";
	fout.close();
}

bool testAllFuncs() {
	// test each function by name
	for (auto& it : namesToFuncs) {
		string funcName = it.first; // map value is function name
		uint64_t maxX = funcMaxXs[funcName]; // max X
		if (!testFibFunc(funcName, maxX)) {
			return false; // return if failed
		}
	}
	return true;
}

bool testFibFunc(string funcName, int X) {
	// First 94 fibonaccis (including zero)
	// fibonacci(93) is the max uint64_t can handle
	cout << "Testing " << funcName << "\n";

	for (int i = 1; i < X; i++) {
		// grab function object from map
		function<BigInt(int)> func = namesToFuncs[funcName];
		// call function with i and store result
		BigInt result = func(i);

		// check if it matches known fibonacci number
		if (!(result == FIBS[i])) {
			cout << funcName << "(" << i << "): failed\n";
			cout << "Expected: " << FIBS[i] << ".Got : " << result << "\n";
			return false;
		}
		cout << funcName << "(" << i << "): passed\n";
	}
	return true;
}

// time function passed in, called with param
long double timeFunction(string funcName, int param) {
	using namespace chrono; // temporarily use namespace for ease
	function<BigInt(int)> func = namesToFuncs[funcName];

	high_resolution_clock::time_point start = high_resolution_clock::now();
	func(param); // call fibonacci function
	high_resolution_clock::time_point end = high_resolution_clock::now();

	// calculate timeTaken
	duration<long double> timeTaken = duration_cast<duration<long double>>(end - start);

	return timeTaken.count() * 1000;
}
