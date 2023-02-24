#include <iostream>
#include <string>
using namespace std;
class ColaPrior{
private:
string First;
int Dim;
string *indexQ;
int *Prio;
void copyData(string *acpy, int start, int end, short int paralel,int *copyPrio);
void Ordering();

public:
ColaPrior();
~ColaPrior();
void Alta(string Ocurre, int pPrior);
string Baja();
string GetFirst();
void Vaciar();
void toString();
void DisplayInterfaz();
};
