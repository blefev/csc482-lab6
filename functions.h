// Lab 5 CXX.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma once;

#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <cmath>
#include "BigInt.h"
#define matrixVec vector<vector<BigInt> >


using namespace std;

BigInt FibLoop(int);
BigInt FibRecur(int);
BigInt FibRecurDP(int);
BigInt FibRecurDPWorker(int, map<int, BigInt> &);
BigInt FibRecurDPTail(int);
BigInt FibRecurDPTailWorker(int x, BigInt = BigInt("1"), BigInt = BigInt("1"));
BigInt FibMatrix(int);
BigInt FibFormula(int);
matrixVec MatrixPower(matrixVec, int);
matrixVec MatrixMultiplication(matrixVec, matrixVec);
void printMatrix(matrixVec);