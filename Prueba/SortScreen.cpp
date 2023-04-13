#include "SortScreen.h"
#include "SortMethod.h"
using namespace std;

void SortScreen::sortDisplay() {
	int step = 10000;
	int multiplo = 1;
	for (int k = 1; k <= 20; k++) {
		compareSortDisplay(step * multiplo);
		if (k > 10)
			multiplo = (k - 9) * 10;
		else
			multiplo++;
		//system("pause");
		////system("pause");
	}
}
/*Montar todos los delegados en un vector*/
void SortScreen::compareSortDisplay(int N) {
	int* A = new int[N];
	string Names[] = { "buble", "selsort", "quick", "merge", "shell", "insertion", "TinajaSort", "OrdenReturn" };
	vector<void(*)(int*, int)> Methods;
	Methods.push_back(&SortMethod::BurbbleSort);
	Methods.push_back(&SortMethod::SelectionSort);
	Methods.push_back(&SortMethod::quicksortBegin);
	Methods.push_back(&SortMethod::mergeSort);
	Methods.push_back(&SortMethod::sortShell);
	Methods.push_back(&SortMethod::insertionSort);

	for (int m = 0; m <= 5; m++) {
		setRamdomData(A, N);
		SaveArray(A, N, Names[m] + "_ORIGEN_" + to_string(N));
		compareSortDisplay2(A, N, Methods[m], Names[m]);
		SaveArray(A, N, Names[m] + to_string(N));
	}
}
/*Gestion de Reloj, por cada delegado coriendo*/
void SortScreen::compareSortDisplay2(int* E, int N, void (*SortMthd)(int*, int), string name) {
	clock_t t0;
	t0 = clock();
	SortMthd(E, N);
	t0 = clock() - t0;
	//cout << N << "|"<<name << "|" << t0;
	saveTimeSort(N, name, t0);
}
void SortScreen::setRamdomData(int* A, int N) {
	for (int k = 0; k < N; k++)
		A[k] = rand() % (2 * N) + (k + 1);
}

void SortScreen::SaveArray(int* E, int n, string name) {
	ofstream outfile = ofstream();
	outfile.open("C:\\Users\\User\\Documents\\Semestre 2023-1\\Estructura de Datos\\Programas\\Unidad 4\\Prueba\\" + name + ".txt", ios::out);
	int k = 0;
	while (k < n) {
		outfile << " " << E[k];
		//if (k % 100 == 0)
		outfile << endl;
		k++;
	}
	outfile.close();
}
void SortScreen::saveTimeSort(int N, string name, clock_t t0) {
	ofstream outfile = ofstream();
	outfile.open("C:\\Users\\User\\Documents\\Semestre 2023-1\\Estructura de Datos\\Programas\\Unidad 4\\Prueba\\sortstat.txt", ios::out | ios::app);
	outfile << N << "|" << name << "|" << t0 << endl;
	outfile.close();
}
/*
1000000|TinajaSort|832 ---20mil
300000|TinajaSort|168 -- 20mil div
1000000|TinajaSort|829 -- 30mil
1000000|TinajaSort|892 --40mil
1000000|TinajaSort|816
*/
int* SortScreen::getFromFile(int& N) {
	vector<int> putData;
	ifstream infile = ifstream();
	string S = "";
	/*c:\\Apps\\Data\\*/
	infile.open("C:\\Users\\User\\Documents\\Semestre 2023-1\\Estructura de Datos\\Programas\\Unidad 4\\Prueba\\DataError.txt");
	while (infile.good()) {
		infile >> S;
		putData.push_back(stoi(S));
	}
	N = putData.size();
	int* E = new int[N];
	for (int i = 0; i < N; i++) {
		E[i] = putData.at(i);
	}
	infile.close();
	return E;
}

int main(int argc, char *argv[]) {
	SortScreen obj1;
	obj1.sortDisplay();	
	return 0;
}


	
