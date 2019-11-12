// Lab 5 CXX.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma once;

#include <iostream>
#include <vector>
#include <array>
#include <map>
#include "BigInt.h"
#define matrixVec vector<vector<BigInt> >


using namespace std;

BigInt FibLoop(unsigned);
BigInt FibRecur(unsigned);
BigInt FibRecurDP(unsigned);
BigInt FibRecurDPWorker(unsigned, map<unsigned, BigInt> &);
BigInt FibRecurDPTail(unsigned);
BigInt FibRecurDPTailWorker(unsigned x, BigInt = BigInt("1"), BigInt = BigInt("1"));
BigInt FibMatrix(unsigned);
matrixVec MatrixPower(matrixVec, int);
matrixVec MatrixMultiplication(matrixVec, matrixVec);
void printMatrix(matrixVec);