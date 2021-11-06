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

	/* Sposób naiwny */
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

	/* Sposób preferowany */
	cout << "Suma szeregu (preferowana): " << (N * (N + 1) * (N + 2)) / 6 << endl << endl;
}


/*
	Napisz program, który:
	A) Pobierze od U¿ytkownika liczb "a" oraz "b" oraz wypisze je na ekran.
	B) Wypisze wiersz gwiazdek o d³ugoœci "a".
	C) Wypisze kolumnê gwiazdek o d³ugoœci "b".
	D) Wypisze wype³niony prostok¹t gwiazdek o wymiarach "a" na "b".
	E) Wypisze obwód (obramowanie) prostok¹tugwiazdek o wymiarach "a" na "b".  (Wskazówka: warto skorzystaæ z operatora logicznego || -OR).

	=== Podpunkty bonusowe ===
	F*) Wypisze trójk¹t prostok¹tny równoramienny:
	•o pionowej przyprostok¹tnej o d³ugoœci "a" oraz poziomej przyprostok¹tnej o d³ugoœci TAK¯E "a".
	•liczba gwiazdek w kolejnych wierszach: 1, 2, 3, ..., a-1, a.
	•k¹t prosty w trójk¹cie: lewy dolny róg.

	G*) Jak w podpunkcie F, ale:
	•liczba gwiazdek w kolejnych wierszach NA ODWRÓT: a, a-1, ..., 3, 2, 1;
	•k¹t prosty w trójk¹cie: prawy górny róg.
*/
auto Zadanie2() -> void
{
	int A, B;

#pragma region A) Pobierze od U¿ytkownika liczb "a" oraz "b" oraz wypisze je na ekran.
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

#pragma region B) Wypisze wiersz gwiazdek o d³ugoœci "a".
	char* WierszGwiazdek = new char[A + 1]; /* +1 jest zarezerwowane dla zanku null na koñcu string'a */
	memset(WierszGwiazdek, (int)'*', A); /* Wype³niamy pamiêæ zmiennej znakami gwiazdek, mo¿na te¿ u¿yc std::fill_n(WierszGwiazdek, A, '*'); */
	WierszGwiazdek[A] = 0x00; //NULL na koñcu string'a

	cout << "Wiersz o dlugosci 'a':" << endl;
	cout << WierszGwiazdek << endl << endl;
#pragma endregion

#pragma region C) Wypisze kolumnê gwiazdek o d³ugoœci "b".
	cout << "Kolumna o dlugosci 'b':" << endl;

	for (int y = 0; y < B; y++)
	{
		cout << '*' << endl;
	}

	cout << endl;
#pragma endregion

#pragma region 	D) Wypisze wype³niony prostok¹t gwiazdek o wymiarach "a" na "b".
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

#pragma region E) Wypisze obwód (obramowanie) prostok¹tugwiazdek o wymiarach "a" na "b".  (Wskazówka: warto skorzystaæ z operatora logicznego || -OR).
	cout << "Obwod prostokatu o wymiarch 'a' na 'b':" << endl;

	for (int y = 0; y < A; y++)
	{
		for (int x = 0; x < B; x++)
		{
			/* (Wskazówka: warto skorzystaæ z operatora logicznego || -OR). */
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
	U¿yj instrukcji switch i napisz program, który:
	a) Pobierze od U¿ytkownika liczbê z przedzia³u [1,12], reprezentuj¹c¹ wybrany miesi¹c w roku.
	b) Jeœli podana przez u¿ytkownika liczba bêdzie spoza przedzia³u, program poinformuje o tym u¿ytkownika i zakoñczy siê.
	c) Wypisze polsk¹ nazwê miesi¹ca (ale bez polskich znaków).
	d) Wypisze ile dni ma wybrany miesi¹c w roku nieprzestêpnym.
	e) Wypisze czy w tym miesi¹cu jest s³onecznie, czy pochmurno. S³onecznie jest od kwietnia w³¹cznie do wrzeœnia w³¹cznie.
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
#pragma region a) Pobierze od U¿ytkownika liczbê z przedzia³u [1,12], reprezentuj¹c¹ wybrany miesi¹c w roku.
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
		return (N % 2 == 1) ? 31 : 30; //Kostki lewej d³oni
	}
	else {
		return (N % 2 == 1) ? 30 : 31; //Kostki prawej d³oni
	}
}

auto JakaPogoda(int N) -> string
{
	return (N >= 4 && N <= 9) ? "slonecznie" : "pochmurno";
}

auto main() -> int
{
	/* Obs³uga wyj¹tków */
	try
	{
		Zadanie1();
		Zadanie2();
		Zadanie3();
	}
	catch (exception ex)
	{
		cout << "Wyj¹tek: " << ex.what() << endl;

		return 1; /* Zwracamy b³¹d */
	}

	return 0;
}
