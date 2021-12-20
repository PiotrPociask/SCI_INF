#include<iostream>
#include<stdlib.h>
#include<cstring>
using namespace std;

class Szyfr																	
{
public:
	char text[100];
	int dlugosc, klucz;
	int lpierwsze[25] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,};
	int r1, r2, r3;

	void wartoscszyfrowana()															
	{
		cout << "Podaj wiadomosc do zaszyfrowania: (maks 100)" << endl;
		cin.getline(text, 100);
		dlugosc = strlen(text);
	}

	void SzyfrCezar()														
	{
		char znak;
		oile:
		cout << "O ile przesunac: ";
		cin >> klucz;
		if (klucz <= 0 || klucz > 26)
		{
			cout << "Niepoprawna liczba " << endl;
			goto oile;

		}

		for (int i = 0; i < dlugosc; i++)									
		{
			znak = text[i];
			if (znak >= 'a' && znak <= 'z')
			{
				znak = ((znak - 'a' + klucz) % 26) + 'a';
			}

			text[i] = znak;
		}
		printf("Zaszyfrowany tekst kodem cezara: %s \n", text);
	}

	void OdszyfrCezar()														
	{
		char znak;
		przesuniecie:
		cout << "O ile przesunac: ";
		cin >> klucz;
		if (klucz <= 0 || klucz > 26)
		{
			cout << "Niepoprawna liczba  (od 0 do 26)"<< endl;
			goto przesuniecie;
		}

		for (int i = 0; i < dlugosc; i++)
		{
			znak = text[i];
			if (znak >= 'a' && znak <= 'z')
			{
				znak = ((znak - 'a' + (26 - klucz)) % 26) + 'a';
			}

			text[i] = znak;
		}
		printf("Odszyfrowany tekst kodem cezara: %s \n", text);
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
		printf("Zaszyfrowany tekst kodem przestawieniowym: %s \n", text);
	}

	int wartosc(int a, int b)
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
		srand(time(NULL));
		int x = rand() % 24;
		int p = lpierwsze[x];
		int q = lpierwsze[x + 1];
		int r1 = p * q;
		int r = (p - 1) * (q - 1);
		int e = 2;
		int d = 2;
		while (e < r)
		{
			if (wartosc(e, r) == 1)
				break;
			else
				e++;
		}
		while (d * e % r != 1)
		{
			d++;
		}--
		this->r1 = r1;
		this->r3 = r3;
		this->r2 = r2;
		cout << "Publiczny RSA: " << "pierwsza wrtosc " << r1 << " " << "druga wartosc " << r2 << endl;
		cout << "Prywatny RSA: " << "pierwsza wrtosc " << r1 << " " << "druga wartosc " << r3 << endl;
	}



};

int main()
{

	Szyfr S1;
	S1.wartoscszyfrowana();

		wybor:
	cout << "Jaka operacje wykonac " << endl;
	cout << "1 - Zaszyfruj kodem cezara  " << endl;
	cout << "2 - Zaszyfruj lub odszyfruj kodem przestawieniowym  " << endl;
	cout << "3 - Zaszyfruj oboma kodami  " << endl;
	cout << "4 - Odszyfruj kodem cezara  " << endl;
	cout << "5 - Wygeneruj klucz RSA  " << endl;
	cout << "6 - wylacz program" << endl;
	int wybor;
		cin >> wybor;
	switch (wybor) {															
	case 1:
		S1.SzyfrCezar();
		break;
	case 2:
		S1.Przestawienie();
		break;
	case 3:
		S1.SzyfrCezar();
		S1.Przestawienie();
		break;
	case 4:
		S1.OdszyfrCezar();
		break;
	case 5:
		S1.RSA();
		break;
	case 6:
		return 0;
	break;
	default:
		cout << "Niepoprawna liczba " << endl;
		cout << "wybierz od 1 do 5" << endl;
		goto wybor;
		return 0;
	}
}
