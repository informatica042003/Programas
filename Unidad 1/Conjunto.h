#include <iostream>
#include <string>
using namespace std;
class Conjunto{

private:	
string *E;
int Dim; /*Cantidad*/
void copyData(string *acpy, int start, int end, short int paralel);

public:
Conjunto();
~Conjunto();
void Alta(string x);
string* GetE();
int GetDim();
string Baja();
//overload 1 de baja
string Baja(int posicion);
string Buscar(string delta);
void toString();
void Union(string *acpy1,string *acpy2,int Dim, int Dim2);//Union normal
void Union(string *acpy1,string *acpy2,int Dim, int Dim2, bool distintiva);//Union Distintiva
void Intercesion(string *acpy1,string *acpy2,int Dim, int Dim2);
void Diferencia(string *acpy1,string *acpy2,int Dim, int Dim2);//Diferencia Conjunto 1 de Conjunto 2
void Diferencia(string *acpy1,string *acpy2,int Dim, int Dim2, bool distintiva);//Diferencia Conjunto 2 de Conjunto 1
void ProductoCarteciano(string *acpy1,string *acpy2,int Dim, int Dim2);//Conjunto 1 X Conjunto2
void ProductoCarteciano(string *acpy1,string *acpy2,int Dim, int Dim2, bool distintiva);//Conjunto 1 X Conjunto2
};
