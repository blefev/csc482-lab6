// Lab 5 CXX.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <array>
#include <map>
#define matrixVec vector<vector<uint64_t> >

#pragma once;

using namespace std;

uint64_t FibLoop(size_t);
uint64_t FibRecur(uint64_t);
uint64_t FibRecurDP(size_t);
uint64_t FibRecurDPWorker(size_t, map<uint64_t, uint64_t> &);
uint64_t FibRecurDPTail(uint64_t);
uint64_t FibRecurDPTailWorker(int x, int = 1, int = 1);
uint64_t FibMatrix(uint64_t);
matrixVec MatrixPower(matrixVec, int);
matrixVec MatrixMultiplication(matrixVec, matrixVec);
void printMatrix(matrixVec);