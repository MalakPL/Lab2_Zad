#include <iostream>
using namespace std;

void Zadanie1()
{
	int N;
	cout << "Podaj N: ";
	cin >> N;

	int Sum = 0;
	for (int i = 1; i <= N; i++)
	{
		Sum += (i * i + i) / 2;
	}
	cout << "Wynik: " << Sum << endl;
}

void Zadanie2()
{
	int A, B;

	cout << "Podaj A: ";
	cin >> A;

	cout << "Podaj B: ";
	cin >> B;

	char* WierszGwiazdek = new char[A];
	memset(WierszGwiazdek, (int)'*', A);
	WierszGwiazdek[A] = 0x00; //NULL do stringa

	cout << "Wiersz o dlugosci 'a'" << endl;
	cout << WierszGwiazdek << endl << endl;

	cout << "Kolumna o dlugosci 'b'" << endl;
	for (int y = 0; y < B; y++)
	{
		cout << '*' << endl;
	}

	cout << endl;
	cout << "Prostokat gwiazdek o wymiarch 'a' na 'b'" << endl;

	for (int y = 0; y < B; y++)
	{
		cout << WierszGwiazdek << endl;
	}

	cout << endl;

	cout << "Obwod prostokatu o wymiarch 'a' na 'b'" << endl;
	for (int y = 0; y < B; y++)
	{
		for (int x = 0; x < A; x++)
		{
			if ((x > 0 && y > 0) && (x < A-1 && y < B-1))
			{
				cout << ' ';
			}
			else {
				cout << '*';
			}

		}

		cout << endl;
	}



	cout << endl;

	cout << "Trojkat prostokatny rownoramienny z katem prostem w lewym dolnm rogu" << endl;
	for (int y = 0; y < B; y++)
	{
		for (int x = 0; x < A; x++)
		{
			if (x > y)
			{
				cout << ' ';
			}
			else {
				cout << '*';
			}

		}

		cout << endl;
	}

	cout << endl;

	cout << "Trojkat prostokatny rownoramienny z katem prostem w prwym gornm rogu" << endl;
	for (int y = 0; y < B; y++)
	{
		for (int x = 0; x < A; x++)
		{
			if (x < y)
			{
				cout << ' ';
			}
			else {
				cout << '*';
			}

		}

		cout << endl;
	}
}

int IleDniMaMiesiac(int N)
{
	/*Na kostkach dloni liczone */

	if (N == 2)
	{
		return 28; //FIX
	}

	if (N >= 1 && N <= 7)
	{
		return (N % 2 == 1) ? 31 : 30;
	}
	else {
		return (N % 2 == 1) ? 30 : 31;
	}
}

string JakaPogoda(int N)
{
	return (N >= 4 && N <= 9) ? "Slonecznie" : "Pochmurno";
}

void Zadanie3()
{
	int N;

	cout << "Podaj numer miesiaca: ";
	cin >> N;

	switch (N)
	{
	case 1:
		cout << "Styczen ma " << IleDniMaMiesiac(N) << " dni i jest " << JakaPogoda(N) << endl;
		break;

	case 2:
		cout << "Luty ma " << IleDniMaMiesiac(N) << " dni i jest " << JakaPogoda(N) << endl;
		break;

	case 3:
		cout << "Marzec ma " << IleDniMaMiesiac(N) << " dni i jest " << JakaPogoda(N) << endl;
		break;

	case 4:
		cout << "Kwiecien ma " << IleDniMaMiesiac(N) << " dni i jest " << JakaPogoda(N) << endl;
		break;

	case 5:
		cout << "Maj ma " << IleDniMaMiesiac(N) << " dni i jest " << JakaPogoda(N) << endl;
		break;

	case 6:
		cout << "Czerwiec ma " << IleDniMaMiesiac(N) << " dni i jest " << JakaPogoda(N) << endl;
		break;

	case 7:
		cout << "Lipiec ma " << IleDniMaMiesiac(N) << " dni i jest " << JakaPogoda(N) << endl;
		break;

	case 8:
		cout << "Sierpien ma " << IleDniMaMiesiac(N) << " dni i jest " << JakaPogoda(N) << endl;
		break;

	case 9:
		cout << "Wrzesien ma " << IleDniMaMiesiac(N) << " dni i jest " << JakaPogoda(N) << endl;
		break;

	case 10:
		cout << "Pazdziernik ma " << IleDniMaMiesiac(N) << " dni i jest " << JakaPogoda(N) << endl;
		break;

	case 11:
		cout << "Listopad ma " << IleDniMaMiesiac(N) << " dni i jest " << JakaPogoda(N) << endl;
		break;

	case 12:
		cout << "Grudzien ma " << IleDniMaMiesiac(N) << " dni i jest " << JakaPogoda(N) << endl;
		break;

	default:
		cout << "Podales liczbe poza dozwolonego zakresu" << endl;
		break;
	}
}

int main()
{
	Zadanie1();
	Zadanie2();
	Zadanie3();

	return 0;
}
