#include <iostream>
#include <ctime>
#include<fstream>
#include<vector>
#include <string>
#include "SortMethod.h"
using namespace std;
void SortMethod::sortShell(int* E, int N) {
	int pivot = 0, j;
	///string S = "";
	//printArray(E, N, "original");
	for (int Gap = N / 2; Gap > 0; Gap /= 2) {
		for (int k = Gap; k < N; k++) {
			pivot = E[k];
			for (j = k; j >= Gap && E[j - Gap] > pivot; j -= Gap) {
				E[j] = E[j - Gap];
				//S += "," + to_string(j);
			}
			E[j] = pivot;
			/* if (S != ""){
			S = to_string(Gap) + "_" + to_string(k) + S;
			printArray(E, N, S);
			}
			S = "";*/
		}// EN FOR K
	}// END FOR Gap
} // end function
void SortMethod::printArray(int* E, int N, string label) {
	int pivot = 0;
	cout << endl << "Iter:" << label << ":";
	for (int k = 0; k < N; k++) {
		cout << E[k] << " ";
	}
}
void SortMethod::SaveLogArray(int* E, int a, int b, string label) {
	int pivot = 0;
	ofstream outfile = ofstream();
	outfile.open("C:\\Users\\User\\Documents\\Semestre 2023-1\\Estructura de Datos\\Programas\\Unidad 4\\Prueba\\sortlogs.txt", ios::out | ios::app);
	outfile << endl << "Iter:" << label << ": ";
	for (int k = a; k <= b; k++) {
		outfile << E[k] << " ";
	}
	outfile.close();
}
void SortMethod::insertionSort(int* E, int N) {
	int key, j;
	//string S = "";
	for (int i = 1; i < N; i++) {
		key = E[i];//take value
		j = i;
		while (j > 0 && E[j - 1] > key) {
			E[j] = E[j - 1];
			j--;
			//S += "," + to_string(j);
		}
		E[j] = key; //insert into left
		/*if (S != ""){
		S = to_string(i) + "_" + S;
		printArray(E, N, S);
		}
		S = "";*/
	}
}
void SortMethod::mergeSort(int* E, int n)
{
	if (n == 1) { return; }
	int pm = n / 2;
	int* izq = new int[pm];
	int* der = new int[n - pm];
	//printArray(E, n, to_string(n));
	for (int i = 0; i < pm; i++)
		izq[i] = E[i];
	for (int i = pm; i < n; i++)
		der[i - pm] = E[i];
	mergeSort(izq, pm); // no lineal
	mergeSort(der, n - pm); // no lineal
	merge(izq, pm, der, n - pm, E);
}
void SortMethod::merge(int* izq, int nIzq, int* der, int nDer, int* A)
{
	int i = 0, j = 0, k = 0;
	while ((i < nIzq) && (j < nDer)) {
		if (izq[i] <= der[j]) {
			A[k] = izq[i];
			i++;
		}
		else {
			A[k] = der[j];
			j++;
		}
		k++;
	}
	while (i < nIzq) {
		A[k] = izq[i];
		i++; k++;
	}
	while (j < nDer) {
		A[k] = der[j];
		j++; k++;
	}
}// end merge action\
\
//string S = "";
void SortMethod::BurbbleSort(int* E, int n)
{
	int top = 0; int aux = 0; bool indchn = false;
	int nx = 0;
	for (int k = 0; k < n - 1; k++) {
		indchn = false; top = n - k - 1;
		for (int j = 0; j < top; j++) {
			nx = j + 1;
			if (E[j] > E[nx]) {
				aux = E[j];
				E[j] = E[nx];
				E[nx] = aux; indchn = true;
			} /*fin de if e iteracion doble*/
		}
		if (!indchn) break;
	}
} // fin function
void SortMethod::BurbbleSortOrigen(int* E, int n)
{
	int aux = 0; bool indchn = false;
	for (int k = 0; k < n - 1; k++) {
		indchn = false;
		for (int j = 0; j < n - k - 1; j++) {
			if (E[j] > E[j + 1]) {
				aux = E[j];
				E[j] = E[j + 1];
				E[j + 1] = aux; indchn = true;
			} /*fin de if e iteracion doble*/
		}
		if (!indchn) break;
	}
} // fin function
void SortMethod::swapping(int& a, int& b) { //swap the content of a and b
	int aux;
	aux = a;
	a = b;
	b = aux;
}
//string S = ""; //swapping(E[k], E[idx]);
/* S = to_string(k) + "_" + to_string(idx);
printArray(E, n, S);
*/
void SortMethod::SelectionSort(int* E, int n)
{
	//string S = "";
	int aux = 0; int idx_min = 0;
	for (int k = 0; k < n - 1; k++) {
		idx_min = k;
		for (int j = k + 1; j < n; j++) {
			if (E[j] < E[idx_min]) {
				idx_min = j;
				//S = to_string(k) + "_" + to_string(idx);
				//printArray(E, n, S);
			}
		}
		if (idx_min > k) {
			swapping(E[k], E[idx_min]);
			/*E[k] = E[idx];
			E[idx] = aux;*/
		}
	} /*fin de if e iteracion doble*/
} // fin function
// Función para dividir el array y hacer los intercambios
//string SS = ""; // Mientras no se cruzen los índices
// SS = to_string(i) + "_" + to_string(L);
// printArray(E, b + 1, SS);
int SortMethod::divideQuick(int* E, int a, int b) {
	int L; int R; int pivot; int aux;
	pivot = E[a]; L = a; R = b;
	//string SS = "";
	for (int i = a + 1; i <= b; i++)
	{
		if (E[i] < pivot) {
			L++;
			//swap(a[i], a[p]);
			aux = E[i];
			E[i] = E[L];
			E[L] = aux;
			/*if (a == 0){
			SS = to_string(a) + "_" + to_string(L);
			printArray(E, b + 1, SS);
			}*/
		}
	}
	//swap(a[p], a[first]);
	aux = E[L];
	E[L] = pivot;
	E[a] = aux;
	//SS = to_string(a) + "_" + to_string(b);
	//printArray(E, b + 1, SS);
	return L;
}
/* Función recursiva para hacer el ordenamiento*/
void SortMethod::quicksort(int* E, int a, int b)
{
	int pivot;
	if (a < b) {
		pivot = divideQuick(E, a, b);
		//printArray(E, 9, to_string(a) + "-" + to_string(b));
		/*Ordeno lista de los menores*/
		quicksort(E, a, pivot - 1);
		/*Ordeno lista de los mayores*/
		quicksort(E, pivot + 1, b);
	}// end if
}// end method
void SortMethod::quicksortBegin(int* E, int n)
{
	quicksort(E, 0, n - 1);
}
