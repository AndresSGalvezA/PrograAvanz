#include "pch.h"
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

//Variables globales
bool aux = true; //Flujo de do-while en try-catch.
string tmp; //Función getline de try catch.
string eProgram; //Toma de decisiones Sí y No.
string itemBroken; //Objetos del inventario;
int nonCounter = 0; //Contador para revisar cuartos.
int numObjBroken; //Total de objetos de cuarto.
int priceBroken; //Valor unitario de cada objeto de cuarto.

class objRooms
{
public:
	int nTowel = 0, nMirror = 0, nSodas = 0, nSnacks = 0, nSoap = 0, nCloset = 0, nTable = 0, nTV = 0, nLamp = 0;

	void inventory(int nRoom, int inventoryOption, string itemBroken, int numObjBroken);
};

//Método que registra y detalla el inventario de cada cuarto.
void objRooms::inventory(int nRoom, int inventoryOption, string itemBroken, int numObjBroken)
{
	if (inventoryOption == 1)
	{
		if (itemBroken == "toalla")
		{
			nTowel = numObjBroken;
		}

		if (itemBroken == "espejo")
		{
			nMirror = numObjBroken;
		}

		if (itemBroken == "gaseosa")
		{
			nSodas = numObjBroken;
		}

		if (itemBroken == "golosina")
		{
			nSnacks = numObjBroken;
		}

		if (itemBroken == "jabón" || itemBroken == "jabon")
		{
			nSoap = numObjBroken;
		}

		if (itemBroken == "ropero")
		{
			nCloset = numObjBroken;
		}

		if (itemBroken == "mesa")
		{
			nTable = numObjBroken;
		}

		if (itemBroken == "televisor" || itemBroken == "television" || itemBroken == "televisión")
		{
			nTV = numObjBroken;
		}

		if (itemBroken == "lámpara" || itemBroken == "lampara")
		{
			nLamp = numObjBroken;
		}

		cout << itemBroken << "s(es) de la habitación " << nRoom << " completos(as)\n";
	}
	else
	{
		cout << "La habitación número " << nRoom << "está equipada con " << endl;
		cout << "\nToallas: " << nTowel;
		cout << "\nEspejos: " << nMirror;
		cout << "\nGaseosas: " << nSodas;
		cout << "\nGolosinas: " << nSnacks;
		cout << "\nJabón: " << nSoap;
		cout << "\nRopero: " << nCloset;
		cout << "\nMesas: " << nTable;
		cout << "\nTelevisiones: " << nTV;
		cout << "\nLámparas: " << nLamp << endl;
	}

}

class rooms
{
public:
	string Roomer, idRoomer, nameCC, numCC, securityCC, expDateCC, numbRoom, petF, airC;
	int beds, pricePerDay, numDays, numBroken;

	//Métodos.
	void setConfig(int nRoom);
	void searchRoomer(string alreadyRoomer, int nRoom);
	void outUnavailableRoom(int nRoom);
	void outAvailableRoom(int nRoom);
	void checkIn(int nRoom);
	void checkOut(int nRoom);
};

//Método que inicializa los atributos de cada habitación.
void rooms::setConfig(int nRoom)
{
	cin.exceptions(istream::failbit);
	cout << "\n--Ingrese el número de camas de la habitación " << to_string(nRoom) << endl;
	do {
		try {
			cin >> beds;
			aux = true;
		}
		catch (ios_base::failure &fail)
		{
			aux = false;
			cout << "\nPor favor ingrese una cantidad válida\n";
			cin.clear();
			getline(cin, tmp);
		}
	} while (aux == false);

	cout << "\n--¿Habitación pet friendly?\nSí[s] - No[n]\n";
	do
	{
		cin >> petF;

		if (petF != "s" && petF != "n")
		{
			cout << "Por favor ingrese una opción válida\n";
		}
	} while (petF != "s" && petF != "n");

	cout << "\n--¿Habitación con aire acondicionado?\nSí[s] - No[n]\n";
	do
	{
		cin >> airC;

		if (airC != "s" && airC != "n")
		{
			cout << "Por favor ingrese una opción válida\n";
		}
	} while (airC != "s" && airC != "n");

	cout << "\n--Ingrese el precio por día de la habitación " << to_string(nRoom) << endl;
	do {
		try {
			cin >> pricePerDay;
			aux = true;
		}
		catch (ios_base::failure &fail)
		{
			aux = false;
			cout << "\nPor favor ingrese una cantidad válida\n";
			cin.clear();
			getline(cin, tmp);
		}
	} while (aux == false);
}

//Método que permite buscar huéspedes alojados.
void rooms::searchRoomer(string alreadyRoomer, int nRoom)
{
	if (alreadyRoomer != Roomer)
	{
		nonCounter++;
	}
	else
	{
		cout << alreadyRoomer << " (" << idRoomer << ") se encuentra en la habitación número " << to_string(nRoom) << ".\n\n";
		nonCounter = 0;
	}

	if (nonCounter == 25)
	{
		cout << endl << alreadyRoomer << " no se encuentra hospedado(a) en el hotel.\n\n";
		nonCounter = 0;
	}
}

//Método que muestra habitaciones ocupadas y sus huéspedes.
void rooms::outUnavailableRoom(int nRoom)
{
	if (Roomer == "")
	{
		nonCounter++;
	}
	else
	{
		cout << "\nLa habitación número " << to_string(nRoom) << " se encuentra ocupada por el(la) huésped " << Roomer << " (" << idRoomer << ").\n";
		nonCounter = 0;
	}

	if (nonCounter == 25)
	{
		cout << "\n(No hay habitaciones ocupadas actualmente).\n\n";
		nonCounter = 0;
	}
}

//Método que muestra habitaciones disponibles.
void rooms::outAvailableRoom(int nRoom)
{
	if (Roomer != "")
	{
		nonCounter++;
	}
	else
	{
		cout << "La habitación número " << to_string(nRoom) << " está disponible.\n";
		nonCounter = 0;
	}

	if (nonCounter == 25)
	{
		cout << "No hay habitaciones disponibles actualmente).\n\n";
		nonCounter = 0;
	}
}

//Método que realiza un check in.
void rooms::checkIn(int nRoom)
{
	cout << "\nIngrese el nombre del huésped encargado\n";
	cin >> Roomer;
	cout << "\nIngrese el número de DPI/Pasaporte del húesped\n";
	cin >> idRoomer;
	cout << "\nIngrese el número de días que el huésped se hospedará\n";
	cin.exceptions(istream::failbit);
	do {
		try {
			cin >> numDays;
			aux = true;
		}
		catch (ios_base::failure &fail)
		{
			aux = false;
			cout << "\nPor favor ingrese una cantidad válida\n";
			cin.clear();
			getline(cin, tmp);
		}
	} while (aux == false);
	cout << "\nIngrese el nombre en la tarjeta de crédito del huésped (sin espacios)\n";
	cin >> nameCC;
	cout << "\nIngrese el número de la tarjeta de crédito (sin espacios)\n";
	cin >> numCC;
	cout << "\nIngrese el código de seguridad de la tarjeta de crédito\n";
	cin >> securityCC;
	cout << "\nIngrese el formato de fecha de expiración de la tarjeta de crédito\n";
	cin >> expDateCC;
}

//Método que realiza un check out.
void rooms::checkOut(int nRoom)
{
	double fPrice; //Precio final que se cargará a la tarjeta de crédito del huésped.

	cout << "\nSe va a realizar el check out del(la) huésped " << Roomer << " (" << idRoomer << ")\n";
	cout << "\n¿La habitación " << nRoom << " se encuentra completa?\nSí[s] - No[n]\n";

	do
	{
		cin >> eProgram;

		if (eProgram != "s" && eProgram != "n")
		{
			cout << "\n\nPor favor, ingrese una opción válida\n";
		}
	} while (eProgram != "s" && eProgram != "n");

	if (eProgram == "n")
	{
		priceBroken = 0;
		cout << "\n¿Cuántos tipos de objetos faltan/están dañados?\n";

		cin.exceptions(istream::failbit);
		do {
			try
			{
				cin >> numObjBroken;
				if (numObjBroken < 1 || numObjBroken > 10)
				{
					cout << "\nPor favor ingrese una cantidad válida\n";
				}
				aux = true;
			}
			catch (ios_base::failure &fail)
			{
				aux = false;
				cout << "\nPor favor ingrese un número válido\n";
				cin.clear();
				getline(cin, tmp);
			}
		} while (aux == false || numObjBroken < 1 || numObjBroken > 10);

		for (int i = 0; i < numObjBroken; i++)
		{
			cout << "\nIngrese el nombre del tipo de objeto faltante/dañado número " << i + 1 << endl;
		validateObject:
			cin >> itemBroken;



			if (itemBroken == "toalla")
			{
				cout << "\nIngrese el número de toallas que faltan/están dañadas\n";

				cin.exceptions(istream::failbit);
				do {
					try {
						cin >> numBroken;
						aux = true;
					}
					catch (ios_base::failure &fail)
					{
						aux = false;
						cout << "\n\nPor favor ingrese un número válido\n";
						cin.clear();
						getline(cin, tmp);
					}
				} while (aux == false);

				priceBroken += (50 * numBroken);
			}
			else if (itemBroken == "espejo")
			{
				cout << "\nIngrese el número de espejos que faltan/están dañados\n";

				cin.exceptions(istream::failbit);
				do {
					try {
						cin >> numBroken;
						aux = true;
					}
					catch (ios_base::failure &fail)
					{
						aux = false;
						cout << "\n\nPor favor ingrese un número válido\n";
						cin.clear();
						getline(cin, tmp);
					}
				} while (aux == false);

				priceBroken += (40 * numBroken);
			}
			else if (itemBroken == "cama")
			{
				cout << "\nIngrese el número de camas que faltan/están dañadas\n";

				cin.exceptions(istream::failbit);
				do {
					try {
						cin >> numBroken;
						aux = true;
					}
					catch (ios_base::failure &fail)
					{
						aux = false;
						cout << "\n\nPor favor ingrese un número válido\n";
						cin.clear();
						getline(cin, tmp);
					}
				} while (aux == false);

				priceBroken += (1700 * numBroken);
			}
			else if (itemBroken == "gaseosa" || itemBroken == "soda")
			{
				cout << "\nIngrese el número de gaseosas que faltan/están dañadas\n";

				cin.exceptions(istream::failbit);
				do {
					try {
						cin >> numBroken;
						aux = true;
					}
					catch (ios_base::failure &fail)
					{
						aux = false;
						cout << "\n\nPor favor ingrese un número válido\n";
						cin.clear();
						getline(cin, tmp);
					}
				} while (aux == false);

				priceBroken += (20 * numBroken);
			}
			else if (itemBroken == "golosina" || itemBroken == "snack")
			{
				cout << "\nIngrese el número de golosinas que faltan/están dañadas\n";

				cin.exceptions(istream::failbit);
				do {
					try {
						cin >> numBroken;
						aux = true;
					}
					catch (ios_base::failure &fail)
					{
						aux = false;
						cout << "\n\nPor favor ingrese un número válido\n";
						cin.clear();
						getline(cin, tmp);
					}
				} while (aux == false);

				priceBroken += (15 * numBroken);
			}
			else if (itemBroken == "jabón" || itemBroken == "jabon")
			{
				cout << "\nIngrese el número de jabones que faltan/están dañadas\n";

				cin.exceptions(istream::failbit);
				do {
					try {
						cin >> numBroken;
						aux = true;
					}
					catch (ios_base::failure &fail)
					{
						aux = false;
						cout << "\n\nPor favor ingrese un número válido\n";
						cin.clear();
						getline(cin, tmp);
					}
				} while (aux == false);

				priceBroken += (30 * numBroken);
			}
			else if (itemBroken == "ropero")
			{
				cout << "\nIngrese el número de roperos que faltan/están dañados\n";

				cin.exceptions(istream::failbit);
				do {
					try {
						cin >> numBroken;
						aux = true;
					}
					catch (ios_base::failure &fail)
					{
						aux = false;
						cout << "\n\nPor favor ingrese un número válido\n";
						cin.clear();
						getline(cin, tmp);
					}
				} while (aux == false);

				priceBroken += (1000 * numBroken);
			}
			else if (itemBroken == "mesa")
			{
				cout << "\nIngrese el número de mesas que faltan/están dañadas\n";

				cin.exceptions(istream::failbit);
				do {
					try {
						cin >> numBroken;
						aux = true;
					}
					catch (ios_base::failure &fail)
					{
						aux = false;
						cout << "\n\nPor favor ingrese un número válido\n";
						cin.clear();
						getline(cin, tmp);
					}
				} while (aux == false);

				priceBroken += (650 * numBroken);
			}
			else if (itemBroken == "television" || itemBroken == "televisor")
			{
				cout << "\nIngrese el número de televisiones que faltan/están dañadas\n";

				cin.exceptions(istream::failbit);
				do {
					try {
						cin >> numBroken;
						aux = true;
					}
					catch (ios_base::failure &fail)
					{
						aux = false;
						cout << "\n\nPor favor ingrese un número válido\n";
						cin.clear();
						getline(cin, tmp);
					}
				} while (aux == false);

				priceBroken += (3000 * numBroken);
			}
			else if (itemBroken == "lampara")
			{
				cout << "\nIngrese el número de lámparas que faltan/están dañadas\n";

				cin.exceptions(istream::failbit);
				do {
					try {
						cin >> numBroken;
						aux = true;
					}
					catch (ios_base::failure &fail)
					{
						aux = false;
						cout << "\n\nPor favor ingrese un número válido\n";
						cin.clear();
						getline(cin, tmp);
					}
				} while (aux == false);

				priceBroken += (100 * numBroken);
			}
			else
			{
				cout << "Por favor, ingrese un objeto válido\n";
				goto validateObject;
			}
		}

		fPrice = (pricePerDay * numDays) + priceBroken;
		cout << "\nSe cargarán Q" << fPrice << " a la tarjeta " << numCC << " de " << nameCC << endl;
	}
	else
	{
		fPrice = pricePerDay * numDays;
		cout << "\nSe cargarán Q" << fPrice << " a la tarjeta " << numCC << " de " << nameCC << endl;
	}

	Roomer = ""; //Vacía la habitación.
	numCC = ""; //Vacía el número de tarjeta de crédito para prevenir fraude.
	securityCC = ""; //Vacía el código de seguridad de la tarjeta de crédito para prevenir fraude.
}

int main()
{
	setlocale(LC_ALL, ""); //Permite imprimir caracteres fuera del estándar.

	//Conjunto de variables.
	string roomer, numbRoom;
	int option, nRoom, inventoryOption;
	rooms theRooms[25]; //Vector de objetos rooms.
	objRooms theObjRooms[25]; //Vector de objetos de inventario.

start:
	cout << "Sistema hotelero de control de cuartos\n\nMenú principal\n";
	cout << "1. Ingresar configuración de cuarto\n2. Buscar huésped\n3. Mostrar cuartos ocupados\n4. Mostrar cuartos libres\n";
	cout << "5. Hacer check in\n6. Hacer check out\n7. Inventario por cuarto\n8. Salir\n\n";
validateOption:

	//Control de excepciones de entrada.
	cin.exceptions(istream::failbit);
	do {
		try {
			cout << "Seleccione una opción\n";
			cin >> option;
			aux = true;
		}
		catch (ios_base::failure &fail)
		{
			aux = false;
			cout << "\nPor favor seleccione una opción válida\n";
			cin.clear();
			getline(cin, tmp);
		}
	} while (aux == false);

	//Determina la opción seleccionada.
	switch (option)
	{
	case 1: //Ingresar configuración de cuarto.
	  /*for (int i = 0; i < 25; i++)
		{
			system("cls"); //Borra el contenido de la consola.
			cout << "Sistema hotelero de control de cuartos\n\n1. Ingresar configuración de cuarto\n";
			theRooms[i].setConfig(i + 1);
		}
	  Este conjunto de instrucciones permite configurar cada uno de los cuartos, pero es un proceso bastante largo, así
	  que para efectos de demostración se ejecutará el siguiente código que permite configurar un cuarto en específico*/

		system("cls");
		cout << "Sistema hotelero de control de cuartos\n\n1. Ingresar configuración de cuarto\nIngrese el número de habitación que desea configurar\n";

		cin.exceptions(istream::failbit);
		do {
			try {
				cin >> nRoom;
				aux = true;
			}
			catch (ios_base::failure &fail)
			{
				aux = false;
				cout << "\nPor favor ingrese un número válido\n";
				cin.clear();
				getline(cin, tmp);
			}
		} while (aux == false);

		theRooms[nRoom - 1].setConfig(nRoom);
		cout << "\n\nConfiguración lista.\n";
		system("pause");
		system("cls");
		goto start;
		break;

	case 2: //Buscar huésped.
		system("cls");
		cout << "Sistema hotelero de control de cuartos\n\n2. Buscar huésped\nIngrese el nombre del huésped\n";
		cin.ignore();
		getline(cin, roomer);

		for (int i = 0; i < 25; i++)
		{
			theRooms[i].searchRoomer(roomer, i + 1);
		}

		system("pause");
		system("cls");
		goto start;
		break;

	case 3: //Mostrar cuartos ocupados.
		system("cls");
		cout << "Sistema hotelero de control de cuartos\n\n3. Mostrar cuartos ocupados\nLas habitaciones actualmente ocupadas son:\n";

		for (int i = 0; i < 25; i++)
		{
			theRooms[i].outUnavailableRoom(i + 1);
		}

		system("pause");
		system("cls");
		goto start;
		break;

	case 4: //Mostrar cuartos libres.
		system("cls");
		cout << "Sistema hotelero de control de cuartos\n\n4. Mostrar cuartos libres\n¿Desea buscar por categorías?\nSí[s] - No[n]\n";

		do
		{
			cin >> eProgram;

			if (eProgram != "s" && eProgram != "n")
			{
				cout << "\nPor favor, ingrese una opción válida\n";
			}
		} while (eProgram != "s" && eProgram != "n");

		if (eProgram == "s") //Si el usuario desea buscar por categorías.
		{
			cout << "\n¿Desea buscar habitaciones pet friendly?\nSí[s] - No[n]\n";

			do
			{
				cin >> eProgram;

				if (eProgram != "s" && eProgram != "n")
				{
					cout << "\nPor favor, ingrese una opción válida\n";
				}
			} while (eProgram != "s" && eProgram != "n");

			if (eProgram == "s")
			{
				cout << "\n¿Desea buscar habitaciones con aire acondicionado?\nSí[s] - No[n]\n";

				do
				{
					cin >> eProgram;

					if (eProgram != "s" && eProgram != "n")
					{
						cout << "\nPor favor, ingrese una opción válida\n";
					}
				} while (eProgram != "s" && eProgram != "n");

				if (eProgram == "s")
				{
					for (int i = 0; i < 25; i++)
					{
						if (theRooms[i].petF == "s" && theRooms[i].airC == "s")
						{
							theRooms[i].outAvailableRoom(i + 1);
						}
					}
				}
				else
				{
					for (int i = 0; i < 25; i++)
					{
						if (theRooms[i].petF == "s" && theRooms[i].airC == "n")
						{
							theRooms[i].outAvailableRoom(i + 1);
						}
					}
				}
			}
			else
			{
				cout << "\n¿Desea buscar habitaciones con aire acondicionado?\n";
				cin >> eProgram;

				if (eProgram == "s")
				{
					for (int i = 0; i < 25; i++)
					{
						if (theRooms[i].petF == "n" && theRooms[i].airC == "s")
						{
							theRooms[i].outAvailableRoom(i + 1);
						}
					}

				}
				else if (eProgram == "n")
				{
					for (int i = 0; i < 25; i++)
					{
						if (theRooms[i].petF == "n" && theRooms[i].airC == "n")
						{
							theRooms[i].outAvailableRoom(i + 1);
						}
					}

				}
			}
		}
		else
		{
			system("cls");
			cout << "Sistema hotelero de control de cuartos\n\n4. Mostrar cuartos libres\nLas habitaciones actualmente libres son:\n";

			for (int i = 0; i < 25; i++)
			{
				theRooms[i].outAvailableRoom(i + 1);
			}
		}

		system("pause");
		system("cls");
		goto start;
		break;

	case 5: //Hacer check in.
		system("cls");
		cout << "Sistema hotelero de control de cuartos\n\n5. Hacer check in\n\nIngrese el número de habitación que desea\n";

		cin.exceptions(istream::failbit);
		do {
			try
			{
				cin >> nRoom;
				if (nRoom < 1 || nRoom > 25)
				{
					cout << "\nPor favor ingrese un número de habitación válido\n";
				}
				aux = true;
			}
			catch (ios_base::failure &fail)
			{
				aux = false;
				cout << "\nPor favor ingrese un número válido\n";
				cin.clear();
				getline(cin, tmp);
			}
		} while (aux == false || nRoom < 1 || nRoom > 25);

		if (theRooms[nRoom - 1].Roomer != "")
		{
			cout << "\nEl número de habitación ingresado ya está en uso. Por favor verificar.\n\n";
		}
		else
		{
			theRooms[nRoom - 1].checkIn(nRoom);
		}

		system("pause");
		system("cls");
		goto start;
		break;

	case 6: //Hacer check out.
		system("cls");
		cout << "Sistema hotelero de control de cuartos\n\n6. Hacer check out\n\nIngrese el número de habitación del huésped que se retira\n";

		cin.exceptions(istream::failbit);
		do {
			try
			{
				cin >> nRoom;
				if (nRoom < 1 || nRoom > 25)
				{
					cout << "\nPor favor ingrese un número de habitación válido\n";
				}
				aux = true;
			}
			catch (ios_base::failure &fail)
			{
				aux = false;
				cout << "\nPor favor ingrese un número válido\n";
				cin.clear();
				getline(cin, tmp);
			}
		} while (aux == false || nRoom < 1 || nRoom > 25);

		if (theRooms[nRoom - 1].Roomer == "")
		{
			cout << "\nLa habitación que ingresó está desocupada. Por favor verificar.\n";
		}
		else
		{
			theRooms[nRoom - 1].checkOut(nRoom);
		}

		system("pause");
		system("cls");
		goto start;
		break;

	case 7: //Inventario por cuarto.
		system("cls");
		cout << "Sistema hotelero de control de cuartos\n\n7. Inventario por cuarto\n\n1. Configurar habitación\n2. Revisar habitación\n\nSeleccione una opción\n";

		cin.exceptions(istream::failbit);
		do {
			try
			{
				cin >> inventoryOption;
				if (inventoryOption < 1 || inventoryOption > 2)
				{
					cout << "\nPor favor ingrese una opción válida\n";
				}
				aux = true;
			}
			catch (ios_base::failure &fail)
			{
				aux = false;
				cout << "\nPor favor ingrese una opción válida\n";
				cin.clear();
				getline(cin, tmp);
			}
		} while (aux == false || inventoryOption < 1 || inventoryOption > 2);

		if (inventoryOption == 1)
		{
			cout << "\nIngrese el número de habitación que desea configurar\n";

			cin.exceptions(istream::failbit);
			do {
				try
				{
					cin >> nRoom;
					if (nRoom < 1 || nRoom > 25)
					{
						cout << "\nPor favor ingrese una habitación válida\n";
					}
					aux = true;
				}
				catch (ios_base::failure &fail)
				{
					aux = false;
					cout << "\nPor favor ingrese una habitación válida\n";
					cin.clear();
					getline(cin, tmp);
				}
			} while (aux == false || nRoom < 1 || nRoom > 25);

			cout << "\n\nIngrese el nombre del objeto de la habitación " << nRoom << endl;
			cin >> itemBroken;

			cout << "\n\nIngrese el número de " << itemBroken << "s(es) disponibles en la habitación " << nRoom << endl;

			cin.exceptions(istream::failbit);
			do {
				try {
					cin >> numObjBroken;
					aux = true;
				}
				catch (ios_base::failure &fail)
				{
					aux = false;
					cout << "\nPor favor ingrese una cantidad válida\n";
					cin.clear();
					getline(cin, tmp);
				}
			} while (aux == false);

		}
		else
		{
			cout << "\nIngrese el número de habitación que desea revisar\n";

			cin.exceptions(istream::failbit);
			do {
				try
				{
					cin >> nRoom;
					if (nRoom < 1 || nRoom > 25)
					{
						cout << "\nPor favor ingrese una habitación válida\n";
					}
					aux = true;
				}
				catch (ios_base::failure &fail)
				{
					aux = false;
					cout << "\nPor favor ingrese una habitación válida\n";
					cin.clear();
					getline(cin, tmp);
				}
			} while (aux == false || nRoom < 1 || nRoom > 25);
		}

		theObjRooms[nRoom - 1].inventory(nRoom, inventoryOption, itemBroken, numObjBroken);

		system("pause");
		system("cls");
		goto start;
		break;

	case 8: //Salir.
		system("cls");
		cout << "¿Salir del sistema?\nSí[s] - No[n]\n";
		validateExit:
		cin >> eProgram;

		if (eProgram == "n")
		{
			system("cls");
			goto start;
		}
		else if (eProgram != "n" && eProgram != "s")
		{
			cout << "\nIngrese una opción válida\n";
			goto validateExit;
		}

		system("cls");
		cout << "Sistema hotelero de control de cuartos\n\nAndres Gálvez - Universidad Rafael Landívar\n\nCerrando programa...";
		Sleep(3000); //Mantiene la consola abierta por 3 segundos.
		break;

	default:
		cout << "\nPor favor seleccione una opción válida\n";
		goto validateOption;
		break;
	}
}