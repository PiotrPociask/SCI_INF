#include<iostream>
#include<stdlib.h>
#include<cstring>
using namespace std;
char text[100];

class szyfry																	
{
public:
	int dlugosc;
	int przesuniecie;
	int r1, r2, r3;
	void SzyfrCezar()														
	{
		cezar1:
		char znak;
		cout << "zakres przesuniecia od 0 do 26" << endl;
		cout << "O ile przesunac: " << endl;
		cin >> przesuniecie;
		if (przesuniecie <= 0 || przesuniecie > 26)
		{
			cout << "Niepoprawna liczba" <<endl;
			goto cezar1;
		}

		for (int i = 0; i < dlugosc; i++)								
		{
			znak = text[i];
			if (znak >= 'a' && znak <= 'z')
			{
				znak = ((znak - 'a' + przesuniecie) % 26) + 'a';
			}

			text[i] = znak;
		}
	}

	void OdszyfrCezar()														
	{
		char znak;
		cezar2:
		cout << "O ile przesunac: ";
		cin >> przesuniecie;
		if (przesuniecie <= 0 || przesuniecie > 26)
		{
			cout << "Niepoprawna liczba" << endl;
			goto cezar2;
		}

		for (int i = 0; i < dlugosc; i++)
		{
			znak = text[i];
			if (znak >= 'a' && znak <= 'z')
			{
				znak = ((znak - 'a' + (26 - przesuniecie)) % 26) + 'a';
			}

			text[i] = znak;
		}
	}

	void Przestawienie()													
	{
		for (int i = 0; i < dlugosc - 1; i += 2)
		{
			char znak;
			znak = text[i];
			text[i] = text[i + 1];
			text[i + 1] = znak;

		}
	}

	int S(int a, int b)
	{
		while (a != b)
		{
			if (a < b)
				b -= a;
			else
				a -= b;
		}
		return a;
	}

	void RSA()
	{
		int lpierwsze[25] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97 };
			srand(time(NULL));
				int x = rand() % 17;

		int p = lpierwsze[x];
		int q = lpierwsze[x + 1];
		int r1 = p * q;
		int r4 = (p - 1) * (q - 1);
		int r2 = 2;
		int r3 = 2;

		while (r2 < r4)
		{
			if (S(r2, r4) == 1)
				break;
			else
				r2++;
		}
		while (r3 * r2 % r4 != 1)
		{
			r3++;
		}
		cout << "klucz publiczny: " << "wartosc 1: " << r1 << " wartosc 2: " << r2 << endl;
		cout << "klucz prywatny: "  << "wartosc 1: " << r1 << " wartosc 2: " << r3 << endl;
	};
};

int main()
{


	cout << "Podaj wiadomosc do zaszyfrowania: (maks 100 znakow)" << endl;
		cin >> text;
	wybor:
	cout << "Jaka operacje wykonac " << endl;
	cout << "1 - Zaszyfruj kodem cezara " << endl;
	cout << "2 - Zaszyfruj lub odszyfruj kodem przestawieniowym " << endl;
	cout << "3 - Zaszyfruj kodem cezara i przestawieniowym " << endl;
	cout << "4 - Odszyfruj kodem cezara " << endl;
	cout << "5 - Wygeneruj klucz RSA " << endl;

	szyfry l1;
	int wyboropcji;
		cin >> wyboropcji;
	switch (wyboropcji) {
		cout << "wybrano szyfr cezara" << endl;
		l1.SzyfrCezar();
		break;
	case 2:
		cout << "wybrano kod przestawieniowy" << endl;
		l1.Przestawienie();
		break;
	case 3:
		cout << "wybrano kod przestawieniowy i szyfr cezara" << endl;
		l1.SzyfrCezar();
		l1.Przestawienie();
		break;
	case 4:
		cout << "wybrano odszyfrowywanie cezara" << endl;
		l1.OdszyfrCezar();
		break;
	case 5:
		cout << "wybrano generacje klucza RSA" << endl;
		l1.RSA();
		break;
	default:
		cout << "Niepoprawna opcja!  wybierz od 1 do 5" << endl;
		goto wybor;
	}
}
