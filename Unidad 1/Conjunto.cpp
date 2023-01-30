#include <iostream>
using namespace std;
class Conjunto{

public:	
string *E;
int Dim; /*Cantidad*/
void copyData(string *acpy, int start, int end, short int paralel);


Conjunto();
~Conjunto();
void Alta(string x);
string Baja();
//overload 1 de baja
string Baja(int posicion);
string Buscar(string x);

};
Conjunto::Conjunto(){
this->Dim = 0;
}
Conjunto::~Conjunto(){
delete E;
}
void Conjunto::Alta(string x){
// por cada alta hay que volver a resim el E
string *acopy = E;
Dim++;
this->E = new string[Dim];
copyData(acopy, 0,Dim-1, 0);
this->E[Dim - 1] = x; // nueva alta en posicion n-1
}
void Conjunto::copyData(string *acpy, int start, int end, short int paralel){
for (int k = start; k < Dim; k++)
this->E[k] = acpy[k+paralel];

}
string Conjunto::Baja(){
// por cada alta hay que volver a resim el E
string *acopy = E;
string bajado = acopy[Dim - 1]; // retira el ultimo
Dim--;
this->E = new string[Dim];
copyData(acopy, 0, Dim,0);
return bajado;
}
string Conjunto::Baja(int posicion){
// por cada alta hay que volver a resim el E
if (posicion < 0 || posicion > Dim - 1)
return NULL;
string *acopy = E;
string bajado = acopy[posicion];
Dim--;
this->E = new string[Dim];
copyData(acopy, 0, posicion, 0);
copyData(acopy, posicion+1, Dim+1, 1);
return bajado;
}
string Conjunto::Buscar(string delta){
// por cada alta hay que volver a resim el E
string buscado = NULL;
for (int k = 0; k < Dim; k++)
if (E[k] == delta)
buscado = E[k];
return buscado;
}

int main(){
	Conjunto con;
	con.Alta("23");
	con.Alta("34");
	con.Alta("567");
	con.Alta("89");
	con.Alta("76");
	con.Baja();
	con.Buscar("23");
	return 0;
}
