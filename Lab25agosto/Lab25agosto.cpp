// Lab25agosto.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


int main()
{
	string persona[10];
	int dpi[10];
	int nombre[10];
	int sexo[10];

	for (int i = 0; i <= 10; i++)
	{
		cout << "Ingresa el nombre de la persona" + i;
		cin.get >> persona[i];
	}

	cout << persona[0];
    return 0;
}


