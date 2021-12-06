#include <iostream>
#include <string>
using namespace std;

string text;
int szyfr, przesuniecie,j,i, dl = text.length();
bool powrot = false;
char znak;
int main() {

poczatek:

	cout << "podaj text ktory chcesz zaszyfrowac " << endl;
	getline(cin, text);
	cout << "wybierz algorytm szyfrują\acy" << endl;
	cout << "1. szyfr podstawieniowy" << endl;
	cout << "2. szyfr pszedstawieniowy" << endl;
	cout << "3. szyfr podstawienowy i przedstawienowy" << endl;
	cout << "4. odszyfruj tekst" << endl;
	cin >> szyfr;

	if (szyfr == 1)
	{
		cout << "ile chesz przesunąć? (MAX. 26)" << endl;
		cin >> przesuniecie;
		for (i = 0; i < dl; i++)
		{
			for (j = 1; j < przesuniecie; j++) {
				if (text[i] == ' ') continue;
				else if (text[i] == 'z') {
					text[i] == 'a';
					przesuniecie--;
					powrot = true;
				}
				else if (text[i] == 'Z') {
					text[i] == 'A';
					przesuniecie--;
					powrot = true;
				}
				else {
					text[i]++;
				}
				if (powrot) {
					przesuniecie++;
					powrot = false;
				}
			}
		}
		cout << text;

	}

	if (szyfr == 2) {
		for (i = 0; i < dl - 1; i += 2)
		{
			char znak;
			znak = text[i];
			text[i] = text[i + 1];
			text[i + 1] = znak;
		}
		cout << "Zaszyfrowany tekst kodem przestawieniowym:" << text << endl;
	}

	if (szyfr == 3) {
		for (i = 0; i < dl; i++) {
			for (int j = 1; j < przesuniecie; j++) {
				if (text[i] == ' ') continue;
				else if (text[i] == 'z') {
					text[i] == 'a';
					przesuniecie--;
					powrot = true;
				}
				else if (text[i] == 'Z') {
					text[i] == 'A';
					przesuniecie--;
					powrot = true;
				}
				else {
					text[i]++;
				}
				if (powrot) {
					przesuniecie++;
					powrot = false;
				}
			}
			for (i = 0; i < dl - 1; i += 2)
			{

				znak = text[i];
				text[i] = text[i + 1];
				text[i + 1] = znak;
			}
		}
		cout << "Zaszyfrowany tekst kodem przestawieniowym" << text << endl;

	}

	if (szyfr == 4)
	{
		cout << "O ile przesunac: ";
		cin >> szyfr;
		if (szyfr <= 0 || szyfr > 26)
		{
			cout << "Niepoprawna liczba\n";
		}
		for (j = 0; j < dl; j++) {
			znak = text[j];
			if (znak >= 'a' && znak <= 'z')
			{
				znak = ((znak - 'a' + (26 - szyfr)) % 26) + 'a';
			}
			text[j] = znak;
		}
		cout << "Odszyfrowany tekst kodem cezara" << text << endl;
	}

	else
	{
		cout << "wybierz od 1 do 4" << endl;
		goto poczatek;
	}

	return 0;
}