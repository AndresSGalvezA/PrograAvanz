// PrimerTrabajo.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void expo(int base, int exp)
{
	int resultado = 1;
	int chejo = 0;
	while (chejo < exp)
	{
		chejo++;
		resultado = resultado * base;
	}
	cout << resultado;
}

int main()
{
	int x = 0;
	expo(2, 4);
	cin >> x;
}


