#pragma once 
#include <iostream>
#include <ctime>
#include<fstream>
#include<vector>
#include <string>
using namespace std;

class SortMethod
{
public:
	static void sortShell(int* E, int N);
	static void printArray(int* E, int N, string label);
	static void insertionSort(int* E, int N);
	static void mergeSort(int* A, int n);
	static void merge(int* izq, int nIzq, int* der, int nDer, int* A);
	static void BurbbleSort(int* E, int n);
	static int divideQuick(int* E, int a, int b);
	static void quicksort(int* E, int a, int b);
	static void SelectionSort(int* E, int n);
	static void swapping(int& a, int& b);
	static void BurbbleSortOrigen(int* E, int n);
	static void quicksortBegin(int* E, int n);
	void SaveLogArray(int* E, int a, int b, string label);
};
