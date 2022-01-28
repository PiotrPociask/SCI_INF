#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

class sort {
public:
	int y;
	vector<int>liczby;
	vector<int>::iterator it;

	void losowe() {
		cout << "wprowadzanie losowych liczb do vektora" << endl;
		srand(time(NULL));
		for (int i = 0; i < 101; i++)
		{
			liczby.push_back(rand() % 1000);
		}
	}


	void szukanie() {
		cout << "wprowadz szukana wartosc";
		int szukana;
		cin >> szukana;

		for (int i = 0; i < liczby.size() - 1; i++)
		{
			if (szukana == liczby[i])
			{
				cout << "towja liczba znanjduje sie w wektorze nr" << i << endl;
				y++;
			}
		
		}
		if (y==0)
		{
			cout << " - 1" << endl;
		}
	}

	void bubble() {
		bool swapp = true;
		while (swapp)
		{
			swapp = false;
			for (int i = 0; i < liczby.size() - 1; i++)
			{
				if (liczby[i] > liczby[i + 1])
				{
					liczby[i] += liczby[i + 1];
					liczby[i + 1] = liczby[i] - liczby[i + 1];
					liczby[i] -= liczby[i + 1];
					swapp = true;
				}
			}
		}
	}
	void stawianie() {
		int i, key, j;
		for (i = 1; i < liczby.size() - 1; i++)
		{
			key = liczby[i];
			j = i - 1;


			while (j >= 0 && liczby[j] > key)
			{
				liczby[j + 1] = liczby[j];
				j = j - 1;
			}
			liczby[j + 1] = key;
		}
	}

	void wypisywanie() {
		for (int i = 0; i < liczby.size() - 1; i++)
		{
			cout << i << ". = " << liczby[i] << endl;
		}
	}

};

int main()
{
	sort s1;
	cout << "1 = bubble sort" << endl;
	cout << "2 = wstawianie" << endl;
	cout << "3 = szukanie liczby " << endl;
	int wybor;
	cin >> wybor;
	switch (wybor)
	{
	case 1:
		cout << "przed sortowaniem" << endl;
		s1.losowe();
		s1.wypisywanie();
		cout << "po sortowaniu" << endl;
		s1.bubble();
		s1.wypisywanie();
		break;
	case 2:
		cout << "przed sortowaniem" << endl;
		s1.losowe();
		s1.wypisywanie();
		cout << "po sortowaniu" << endl;
		s1.stawianie();
		s1.wypisywanie();
		break;
	case 3:

		s1.losowe();
		s1.wypisywanie();
		s1.szukanie();
		s1.bubble();
		s1.wypisywanie();
		s1.szukanie();
		break;
	default:
		cout << "niepoprawna opcja" << endl;
		break;
	};
}
