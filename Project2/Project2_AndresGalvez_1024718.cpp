#include <iostream>
#include "pch.h"
#include <sstream>
#include <string>
//#include <string.h>
#include <iostream>
//#include <stdlib.h>
//#include <conio.h>
//#include <Windows.h>
#include "ctime"
#define UNIQUE_MOB

//using namespace System;
using namespace std;

//Estructura de los nodos de la cola.
struct Node
{
	int numberGas = 0;
	Node* next;
};

//Estructura de la cola.
struct Linear
{
	Node* front;
	Node* behind;
};

//Este método agrega un nodo a la cola.
void Push(Linear& q, int n)
{
	Node* aux = new Node();

	aux->numberGas = n;
	aux->next = NULL;

	if (q.front == NULL)
	{
		q.front = aux;
	}
	else
	{
		(q.behind)->next = aux;
	}

	q.behind = aux;
}

//Este método permite buscar un número e imprimir si lo encuentra o no.
int Search(Linear q, int numberToSearch)
{
	Node* aux;
	Node* auxant;
	Node* auxsig;
	aux = q.front;
	//int posCounter = 0;
	bool found = false;
	//cout << "Ingrese el número a buscar:\n";
	//cin >> numberToSearch;

	while (aux != NULL && found == false)
	{
		//posCounter++;
		auxsig = aux->next;
		if (aux->numberGas == numberToSearch)
		{
			if (aux == q.front)
			{
				aux->next = q.front;
				found = true;
			}
			else
			{
				auxant->next = auxsig;
				found = true;
			}
			//cout << numberToSearch << " encontrado en la posición " << posCounter << ".\n";
			//return 1;
		}
		if (found == true)
		{
			auxant = aux;
			aux = aux->next;
			delete(aux);
		}
	}

	/*if (found == false)
	{
		//cout << numberToSearch << " no se encuentra en la cola.\n";
		return 0;
	}*/
	return 1;
}


//Este método elimina el primer nodo encolado.
void Pop(Linear& q, int numberGas)
{
	if (Search(q, numberGas) == 1)
	{
		Pop(q, numberGas);
	}
	else
	{

	}
	/*Node* aux;
	aux = q.front;
	q.front = q.front->next;
	delete(aux);*/
}

//Este método permite imprimir la cola.
void Show(Linear q)
{
	Node* aux;
	aux = q.front;
	cout << "Números en la cola:\n";

	while (aux != NULL)
	{
		cout << aux->numberGas << endl;
		aux = aux->next;
	}
}

/*struct Pila
{
	Node* cabeza;

	void Push(Node* nuevo)
	{
		if (cabeza == NULL)
		{
			cabeza = nuevo;
		}
		else
		{
			nuevo->next = cabeza;
			cabeza = nuevo;
		}
	}

	Node* Pop()
	{
		if (cabeza != NULL)
		{
			Node* tmp = cabeza;
			cabeza = tmp->next;
			return tmp;
		}
		else
		{
			return NULL;
		}
	}


};*/



//Método para ingresar un nodo a la pila.
void PushStack(Linear& s, int n)
{
	Node* aux = new Node();
	aux->numberGas = n;
	aux->next = NULL;

	if (s.front == NULL) //Indica si la cola está vacía.
	{
		s.front = aux;
	}
	else
	{
		aux->next = s.front;
		s.front = aux;
	}
}

//Método para mostrar la pila.
void ShowStack(Linear s)
{
	Node* aux = s.front;

	cout << "Números en la pila:" << endl;

	while (aux != NULL)
	{
		cout << aux->numberGas << endl;
		aux = aux->next;
	}
}


void Super(double precio, Linear c1, Linear p1)
{
	int n1 = precio.ToString()[0];
	int n2 = precio.ToString()[1];
	int n3 = precio.ToString()[3];
	int n4 = precio.ToString()[4];
	Pop(c1, n1);
	Pop(c1, n2);
	Pop(c1, n3);
	Pop(c1, n4);
	int ajuste;

	if (n2 == n1)
	{
		Pop(c1, n2);
	}
	else
	{
		Pop(p1, n2);
	}

	if (n3 == n1 || n3 == n2)
	{
		Pop(p1, n3);
	}
	else
	{
		Pop(c1, n3);
	}

	if (n4 == n1 || n4 == n2 || n4 == n3)
	{
		if (n4 == n1 || n4 == n2)
		{
			Pop(c1, n4);
			//ajuste++;
		}
		else if (n4 == n2 || n4 == n3)
		{
			Pop(p1, n4);
			//ajuste++;
		}
		else {
			Pop(p1, n4);
		}

	}
	else
	{
		Pop(c1, n3);
	}
};

void Regular(double precio, Linear c1, Linear c2)
{
	int n1 = precio.ToString()[0];
	int n2 = precio.ToString()[1];
	int n3 = precio.ToString()[3];
	int n4 = precio.ToString()[4];
	Pop(c1, n1);
	Pop(c1, n2);
	Pop(c1, n3);
	Pop(c1, n4);
	int ajuste;

	if (n2 == n1)
	{
		Pop(c1, n2);
	}
	else
	{
		Pop(c2, n2);
	}

	if (n3 == n1 || n3 == n2)
	{
		Pop(c2, n3);
	}
	else
	{
		Pop(c1, n3);
	}

	if (n4 == n1 || n4 == n2 || n4 == n3)
	{
		if (n4 == n1 || n4 == n2)
		{
			Pop(c1, n4);
			ajuste++;
		}
		else if (n4 == n2 || n4 == n3)
		{
			Pop(c2, n4);
			ajuste++;
		}
		else {
			Pop(c2, n4);
		}

	}
	else
	{
		Pop(c1, n3);
	}

};

void Diesel(double precio, Linear p1, Linear p2)
{
	int n1 = precio.ToString()[0];
	int n2 = precio.ToString()[1];
	int n3 = precio.ToString()[3];
	int n4 = precio.ToString()[4];
	Pop(p1, n1);
	Pop(p1, n2);
	Pop(p1, n3);
	Pop(p1, n4);
	int ajuste;

	if (n2 == n1)
	{
		Pop(p1, n2);
	}
	else
	{
		Pop(p2, n2);
	}

	if (n3 == n1 || n3 == n2)
	{
		Pop(p2, n3);
	}
	else
	{
		Pop(p1, n3);
	}

	if (n4 == n1 || n4 == n2 || n4 == n3)
	{
		if (n4 == n1 || n4 == n2)
		{
			Pop(p1, n4);
			ajuste++;
		}
		else if (n4 == n2 || n4 == n3)
		{
			Pop(p2, n4);
			ajuste++;
		}
		else {
			Pop(p2, n4);
		}

	}
	else
	{
		Pop(p1, n3);
	}

};

int main()
{
	setlocale(LC_ALL, "");

	Linear c1;//creacion de cola 1
	c1.front = NULL;
	c1.behind = NULL;
	for (int i = 0; i < 10; i++)
	{
		Push(c1, i);
	}

	Linear c2;//creacion de cola 2
	c2.front = NULL;
	c2.behind = NULL;
	for (int i = 0; i < 10; i++)
	{
		Push(c1, i);
	}

	Linear p1;//creacion de la pila 1
	p1.front = NULL;
	p1.behind = NULL;
	for (int i = 0; i < 10; i++)
	{
		PushStack(p1, i);
	}

	Linear p2;//creacion de la pila 2
	p2.front = NULL;
	p2.behind = NULL;
	for (int i = 0; i < 10; i++)
	{
		PushStack(p1, i);
	}

	string tipo = "";
	double precio;
	bool run = true;

	do
	{
		cout << "---------------------------------------------" << endl;
		cout << "Proyecto Laboratorio Programacion Avanzada 1" << endl;
		cout << "Gaslinera PetrPlus S.A." << endl;
		cout << "1 = Gasolina Super" << endl;
		cout << "2 = Gasolina Regular" << endl;
		cout << "3 = Diesel" << endl;
		cout << "4 = Salir del programa" << endl;
		cout << "---------------------------------------------" << endl;
		cout << "Ingrese tipo de gasolina que desea dar precio" << endl;
		cin >> tipo;


		if (tipo == "1")
		{
			cout << "Precio Gasolina Super" << endl;
			cout << "Ingrese el precio del combustible que desea" << endl;
			cin >> precio;
			Super(precio, c1, p1);
			Show(c1);
			ShowStack(p1);
			Sleep(3000000000);

		}
		else if (tipo == "2")
		{
			cout << "Precio Gasolina Regular" << endl;
			cout << "Ingrese el precio del combustible que desea" << endl;
			cin >> precio;
			Regular(precio, c1, c2);
			Show(c1);
			Show(c2);
			if (true)
			{

			}
			Sleep(3000);
		}
		else if (tipo == "3")
		{
			cout << "Precio Diesel" << endl;
			cout << "Ingrese el precio del combustible que desea" << endl;
			cin >> precio;
			Diesel(precio, p1, p2);
			ShowStack(p1);
			ShowStack(p2);
			if (true)
			{

			}
			Sleep(3000);
		}
		else if (tipo == "4")
		{
			run = false;
		}
		else
		{
			cout << "ERROR, usted ha ingresado una opcion invalida" << endl;
			cout << "Vuelva a ingresar una opcion valida" << endl;
			Sleep(1000); //dormir la consola por 2.5 segundos
		}

		system("cls");//limpiar la consola con cada iteracion.

	} while (run == true);
	cout << "Cerrando programa...";


	return 0;
}



