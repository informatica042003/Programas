#include <iostream>
#include <string>
#include "ColaPrior.h"
using namespace std;
ColaPrior::ColaPrior(){
indexQ = NULL;
Prio = NULL;
this->Dim = 0;
}
ColaPrior::~ColaPrior(){
delete indexQ;
delete Prio;
}
void ColaPrior::Alta(string Ocurre, int pPrior){
// por cada alta hay que volver a resim el IndexQ
string *acopy = indexQ;
int *copyPrio = Prio;
Dim++;
this->indexQ=new string[Dim];
this->Prio=new int[Dim];
copyData(acopy, 0,Dim-1, 0,copyPrio);
this->indexQ[Dim - 1]= Ocurre;	
this->Prio[Dim - 1]= pPrior;
Ordering();	
}

string ColaPrior::Baja(){
// por cada alta hay que volver a resim el E
string *acopy = indexQ;
int *copyPrio = Prio;
string bajado = acopy[0]; // retira el primero
Dim--;
this->indexQ=new string[Dim];
this->Prio=new int[Dim];
copyData(acopy, 0, Dim,1,copyPrio);
return bajado;
}

void ColaPrior::copyData(string *acpy, int start, int end, short int paralel,int *copyPrio){
for (int k = start; k < end; k++){
this->indexQ[k] = acpy[k+paralel];
this->Prio[k] = copyPrio[k+paralel];
}
}

void ColaPrior::Ordering(){
    int auxPrio;
    string auxIndex;
    for(int i = 0;i < Dim;i++){
    	for(int k = 0; k < Dim - 1;k++){
    	 if(Prio[k]>Prio[k+1]){
    	 	auxPrio = Prio[k];
    	 	Prio[k] = Prio[k+1];
    	 	Prio[k+1] = auxPrio;
    	 	auxIndex = indexQ[k];
    	 	indexQ[k] = indexQ[k+1];
    	 	indexQ[k+1] = auxIndex;
		 }
		}
	}
}
 
void ColaPrior::toString(){
	 cout<<"[";
    
	for (int i = 0; i < Dim; i++)

	{
		cout << indexQ[i] <<" ";
	}
	cout<<"]";
}

string ColaPrior::GetFirst(){
	First = indexQ[0];
	return First;
}

void ColaPrior::Vaciar(){
	for(int i = 0;i<=Dim+1;i++){
		Baja();
	}
}
void ColaPrior::DisplayInterfaz(){//Interfaz
	string elemento = "1";
	int prioridad = 0;
	ColaPrior col1;
	cout<<"Conjunto 1"<<endl;
	while(elemento!="#"){
		cout<<"\nIntroduzca elemento(Para salir introduzca #): ";
	cin>>elemento;
	if(elemento=="#"){
		break;
	}
	else;
	cout<<"\nIntroduzca prioridad del elemento: ";
	cin>>prioridad;
	Alta(elemento,prioridad);
	}
	
	cout<<"\nConjunto Creado y ordenado: ";toString();
	cout<<"\n";
	cout<<"\nEl elemento bajado es :"<<Baja()<<endl;
	cout<<"\n";
	toString();
	cout<<"\n";
	cout<<"\nEl primer valor ahora es:"<<GetFirst();
	cout<<"\n";
	Vaciar();
	cout<<"\nEl conjunto vaciado: ";toString();
}

int main(){//Unit Testing
	ColaPrior col1;
    col1.DisplayInterfaz();
	return 0;
}


