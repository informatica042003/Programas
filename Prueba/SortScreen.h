#pragma once 
#include <iostream>
#include <ctime>
#include<fstream>
#include<vector>
#include <string>
using namespace std;
class SortScreen{
public:
	
	void sortDisplay();
	void compareSortDisplay(int N);
	
	void compareSortDisplay2(int* E, int N, void (*SortMthd)(int*, int), string name);
	
	void setRamdomData(int* A, int N);
	void saveTimeSort(int N, string name, clock_t t0);
	int* getFromFile(int& N);
	void SaveArray(int* E, int n, string name);
};
