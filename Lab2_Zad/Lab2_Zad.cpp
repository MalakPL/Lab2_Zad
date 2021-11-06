#include <iostream>

using namespace std;

const char* IntCastExceptionMessage = "Podana wartosc nie mogla zostac zrzutowana do typu int.";

/*
	Napisz program do obliczania szeregu wg podanego wzoru: (1)+ (1+2) + (1+2+3) + (1+2+3+4) + (1+2+3+4) + ... + (1+2+3+4+...+n).
*/
auto Zadanie1() -> void
{
	int N;
	cout << "Podaj N: ";
	cin >> N;

	if (cin.fail())
	{
		throw exception{ IntCastExceptionMessage };
	}

	/* Spos�b naiwny */
	int Suma = 0;
	for (int i = 1; i <= N; i++)
	{
		int SumaPomocnicza = 0;
		for (int j = 1; j <= i; j++)
		{
			SumaPomocnicza += j;

			cout << j;
			if (j < i)
			{
				cout << " + ";
			}
		}
		Suma += SumaPomocnicza;

		cout << " = " << SumaPomocnicza << endl;
	}

	cout << "Suma szeregu (naiwna): " << Suma << endl;

	/* Spos�b preferowany */
	cout << "Suma szeregu (preferowana): " << (N * (N + 1) * (N + 2)) / 6 << endl << endl;
}


/*
	Napisz program, kt�ry:
	A) Pobierze od U�ytkownika liczb "a" oraz "b" oraz wypisze je na ekran.
	B) Wypisze wiersz gwiazdek o d�ugo�ci "a".
	C) Wypisze kolumn� gwiazdek o d�ugo�ci "b".
	D) Wypisze wype�niony prostok�t gwiazdek o wymiarach "a" na "b".
	E) Wypisze obw�d (obramowanie) prostok�tugwiazdek o wymiarach "a" na "b".  (Wskaz�wka: warto skorzysta� z operatora logicznego || -OR).

	=== Podpunkty bonusowe ===
	F*) Wypisze tr�jk�t prostok�tny r�wnoramienny:
	�o pionowej przyprostok�tnej o d�ugo�ci "a" oraz poziomej przyprostok�tnej o d�ugo�ci TAK�E "a".
	�liczba gwiazdek w kolejnych wierszach: 1, 2, 3, ..., a-1, a.
	�k�t prosty w tr�jk�cie: lewy dolny r�g.

	G*) Jak w podpunkcie F, ale:
	�liczba gwiazdek w kolejnych wierszach NA ODWR�T: a, a-1, ..., 3, 2, 1;
	�k�t prosty w tr�jk�cie: prawy g�rny r�g.
*/
auto Zadanie2() -> void
{
	int A, B;

#pragma region A) Pobierze od U�ytkownika liczb "a" oraz "b" oraz wypisze je na ekran.
	cout << "Podaj A: ";
	cin >> A;

	if (cin.fail())
	{
		throw exception{ IntCastExceptionMessage };
	}

	cout << "Podaj B: ";
	cin >> B;

	if (cin.fail())
	{
		throw exception{ IntCastExceptionMessage };
	}

	cout << "Podano liczby a == " << A << " oraz b == " << B << endl << endl;
#pragma endregion

#pragma region B) Wypisze wiersz gwiazdek o d�ugo�ci "a".
	char* WierszGwiazdek = new char[A + 1]; /* +1 jest zarezerwowane dla zanku null na ko�cu string'a */
	memset(WierszGwiazdek, (int)'*', A); /* Wype�niamy pami�� zmiennej znakami gwiazdek, mo�na te� u�yc std::fill_n(WierszGwiazdek, A, '*'); */
	WierszGwiazdek[A] = 0x00; //NULL na ko�cu string'a

	cout << "Wiersz o dlugosci 'a':" << endl;
	cout << WierszGwiazdek << endl << endl;
#pragma endregion

#pragma region C) Wypisze kolumn� gwiazdek o d�ugo�ci "b".
	cout << "Kolumna o dlugosci 'b':" << endl;

	for (int y = 0; y < B; y++)
	{
		cout << '*' << endl;
	}

	cout << endl;
#pragma endregion

#pragma region 	D) Wypisze wype�niony prostok�t gwiazdek o wymiarach "a" na "b".
	cout << "Prostokat gwiazdek o wymiarch 'a' na 'b':" << endl;

	for (int y = 0; y < A; y++)
	{
		for (int x = 0; x < B; x++)
		{
			cout << '*';
		}
		cout << endl;
	}

	cout << endl;
#pragma endregion

#pragma region E) Wypisze obw�d (obramowanie) prostok�tugwiazdek o wymiarach "a" na "b".  (Wskaz�wka: warto skorzysta� z operatora logicznego || -OR).
	cout << "Obwod prostokatu o wymiarch 'a' na 'b':" << endl;

	for (int y = 0; y < A; y++)
	{
		for (int x = 0; x < B; x++)
		{
			/* (Wskaz�wka: warto skorzysta� z operatora logicznego || -OR). */
			if (x == 0 || y == 0 || x == B - 1 || y == A - 1)
			{
				cout << '*';
			}
			else {
				cout << ' ';
			}
		}

		cout << endl;
	}

	cout << endl;
#pragma endregion


	//=== Podpunkty bonusowe ===

#pragma region 	F*)
	cout << "Trojkat prostokatny rownoramienny z katem prostem w lewym dolnm rogu:" << endl;

	for (int y = 0; y < A; y++)
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
#pragma endregion

#pragma region G*)
	cout << "Trojkat prostokatny rownoramienny z katem prostem w prwym gornm rogu:" << endl;

	for (int y = 0; y < A; y++)
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

	cout << endl;
#pragma endregion
}

/*
	U�yj instrukcji switch i napisz program, kt�ry:
	a) Pobierze od U�ytkownika liczb� z przedzia�u [1,12], reprezentuj�c� wybrany miesi�c w roku.
	b) Je�li podana przez u�ytkownika liczba b�dzie spoza przedzia�u, program poinformuje o tym u�ytkownika i zako�czy si�.
	c) Wypisze polsk� nazw� miesi�ca (ale bez polskich znak�w).
	d) Wypisze ile dni ma wybrany miesi�c w roku nieprzest�pnym.
	e) Wypisze czy w tym miesi�cu jest s�onecznie, czy pochmurno. S�onecznie jest od kwietnia w��cznie do wrze�nia w��cznie.
*/

auto IleDniMaMiesiac(const int N) -> int;
auto JakaPogoda(int N) -> string;

enum Miesiac
{
	Styczen = 1, /* Zaczynamy numeracje od 1 */
	Luty,
	Marzec,
	Kwiecien,
	Maj,
	Czerwiec,
	Lipiec,
	Sierpien,
	Wrzesien,
	Pazdziernik,
	Listopad,
	Grudzien
};

auto Zadanie3() -> void
{
#pragma region a) Pobierze od U�ytkownika liczb� z przedzia�u [1,12], reprezentuj�c� wybrany miesi�c w roku.
	int N;

	cout << "Podaj numer miesiaca: ";
	cin >> N;

	if (cin.fail())
	{
		throw exception{ IntCastExceptionMessage };
	}
#pragma endregion

#pragma region b) c) d) oraz e)
	switch (N)
	{
	case Miesiac::Styczen:
		cout << "Styczen ma " << IleDniMaMiesiac(N) << " dni i jest w nim " << JakaPogoda(N) << endl;
		break;

	case Miesiac::Luty:
		cout << "Luty ma " << IleDniMaMiesiac(N) << " dni i jest w nim " << JakaPogoda(N) << endl;
		break;

	case Miesiac::Marzec:
		cout << "Marzec ma " << IleDniMaMiesiac(N) << " dni i jest w nim " << JakaPogoda(N) << endl;
		break;

	case Miesiac::Kwiecien:
		cout << "Kwiecien ma " << IleDniMaMiesiac(N) << " dni i jest w nim " << JakaPogoda(N) << endl;
		break;

	case Miesiac::Maj:
		cout << "Maj ma " << IleDniMaMiesiac(N) << " dni i jest w nim " << JakaPogoda(N) << endl;
		break;

	case Miesiac::Czerwiec:
		cout << "Czerwiec ma " << IleDniMaMiesiac(N) << " dni i jest w nim " << JakaPogoda(N) << endl;
		break;

	case Miesiac::Lipiec:
		cout << "Lipiec ma " << IleDniMaMiesiac(N) << " dni i jest w nim " << JakaPogoda(N) << endl;
		break;

	case Miesiac::Sierpien:
		cout << "Sierpien ma " << IleDniMaMiesiac(N) << " dni i jest w nim " << JakaPogoda(N) << endl;
		break;

	case Miesiac::Wrzesien:
		cout << "Wrzesien ma " << IleDniMaMiesiac(N) << " dni i jest w nim " << JakaPogoda(N) << endl;
		break;

	case Miesiac::Pazdziernik:
		cout << "Pazdziernik ma " << IleDniMaMiesiac(N) << " dni i jest w nim " << JakaPogoda(N) << endl;
		break;

	case Miesiac::Listopad:
		cout << "Listopad ma " << IleDniMaMiesiac(N) << " dni i jest w nim " << JakaPogoda(N) << endl;
		break;

	case Miesiac::Grudzien:
		cout << "Grudzien ma " << IleDniMaMiesiac(N) << " dni i jest w nim " << JakaPogoda(N) << endl;
		break;

	default:
		throw exception{ "Numer miesiaca jest spoza dozwolonego zakresu" };
	}
#pragma endregion
}

auto IleDniMaMiesiac(const int N) -> int
{
	/* Liczone na kostkach https://www.wykop.pl/cdn/c3201142/comment_xHiLpUQ14GtmgbvWF94B0nyAi6uRfOCI.jpg */

	if (N == 2)
	{
		return 28; //FIX dla lutego
	}

	if (N >= 1 && N <= 7)
	{
		return (N % 2 == 1) ? 31 : 30; //Kostki lewej d�oni
	}
	else {
		return (N % 2 == 1) ? 30 : 31; //Kostki prawej d�oni
	}
}

auto JakaPogoda(int N) -> string
{
	return (N >= 4 && N <= 9) ? "slonecznie" : "pochmurno";
}

auto main() -> int
{
	/* Obs�uga wyj�tk�w */
	try
	{
		Zadanie1();
		Zadanie2();
		Zadanie3();
	}
	catch (exception ex)
	{
		cout << "Wyj�tek: " << ex.what() << endl;

		return 1; /* Zwracamy b��d */
	}

	return 0;
}
