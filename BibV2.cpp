#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

class Kniga {
	char Nazv[256];
	char Ganr[256];
	char Izdatel[256];
	int Seriya;
	int God;
	int Str;
	bool Pereplet;
	char Format[256];
	char Avtor[256];
	int Tiraj;

public:
	void INCONS(void)
	{
		//string buf;

		cout << endl << "Название книги: ";
		cin >> Kn.Nazv;
		
		cout << endl << "Жанр книги: ";
		cin >> Kn.Ganr;

		cout << endl << "Издатель книги: ";
		cin >> Kn.Izdatel;

		cout << endl << "Серия выпуска книги: ";
		cin >> Kn.Seriya;
		
		cout << endl << "Год выпуска книги: ";
		cin >> Kn.God;
		
		cout << endl << "Количество страниц в книге: ";
		cin >> Kn.Str;

		cout << endl << "Переплёт книги: ";
		cin >> Kn.Pereplet;

		cout << endl << "Формат книги: ";
		cin >> Kn.Format;

		cout << endl << "Автор книги: ";
		cin >> Kn.Avtor;

		cout << endl << "Тираж: ";
		cin >> Kn.Tiraj;	

		fstream fin;
		ofstream fout;
		fin.open("Katalog.txt", ios::in);
		fout.open("Work.txt", ios::out);

		string line;
		string buf = Kn.Ganr;

		while (getline(fin, line))			//  Пока мы получили строку - тело цикла исполняется ||  когда файл закончился (все строки считались) - цикл false
		{
			if ((line == "Fantasy")&&(buf == "Fantasy"))
			{
				fout << "Fantasy" << "\n";
				fout << Kn.Nazv << "\n";
				//fout << Kn.Ganr << "\n";
				fout << Kn.Izdatel << "\n";
				fout << Kn.Seriya << "\n";
				fout << Kn.God << "\n";
				fout << Kn.Str << "\n";
				fout << Kn.Pereplet << "\n";
				fout << Kn.Format << "\n";
				fout << Kn.Avtor << "\n";
				fout << Kn.Tiraj << "\n";
			}
			if ((line == "Classic") && (buf == "Classic"))
			{
					fout << "Classic" << "\n";
					fout << Kn.Nazv << "\n"; 
					//fout << Kn.Ganr << "\n";
					fout << Kn.Izdatel << "\n";
					fout << Kn.Seriya << "\n";
					fout << Kn.God << "\n";
					fout << Kn.Str << "\n";
					fout << Kn.Pereplet << "\n";
					fout << Kn.Format << "\n";
					fout << Kn.Avtor << "\n";
					fout << Kn.Tiraj << "\n";
			}
			else 
			{
				fout << line << "\n";
			}
		}

		fin.close();
		fout.close();

		fin.open("Work.txt", ios::in);
		fout.open("Katalog.txt", ios::out);

		while (getline(fin, line))
		{
			fout << line << "\n";
		}

		fin.close();
		fout.close();
	};

	void INFILE(void)
	{
		fstream fin;
		ofstream fout;
		fstream fadd;
		string buf;

		fadd.open("Add.txt", ios::in);
		for (int i=0; i<2; i++) 
		{
			getline(fadd, buf);
		}
		fadd.close();

		fin.open("Katalog.txt", ios::in);
		fout.open("Work.txt", ios::out);
		fadd.open("Add.txt", ios::in);	

		string line;

		while (getline(fin, line))			//  Пока мы получили строку - тело цикла исполняется ||  когда файл закончился (все строки считались) - цикл false
		{
			if ((line == "Fantasy") && (buf == "Fantasy"))
			{
				fout << "Fantasy" << "\n";
				if (fadd)					
				{
					string buf2;	
					int a = 0;
					while (getline(fadd, buf2))		
					{
						if(a!=1)fout << buf2 << "\n";
						a++;
					}
				}
			}
			if ((line == "Classic") && (buf == "Classic"))
			{
				fout << "Classic" << "\n";
				if (fadd)
				{
					string buf2;
					int a = 0;
					while (getline(fadd, buf2))
					{
						if (a != 1)fout << buf2 << "\n";
						a++;
					}
				}
			}
			else
			{
				fout << line << "\n";
			}
		}

		fin.close();
		fout.close();
		fadd.close();

		fin.open("Work.txt", ios::in);
		fout.open("Katalog.txt", ios::out);

		while (getline(fin, line))
		{
			fout << line << "\n";
		}

		fin.close();
		fout.close();
	};

	void FOUND(void) 
	{

	};
}Kn;

int main()
{
	setlocale(LC_ALL, "Russian");
	int deistvie;

	cout << "ПРИЛОЖЕНИЕ БИБЛИОТЕКА" << endl << endl;
	cout << "Выбирите операцию:" << endl <<
		"0) Закрыть" << endl <<
		"1) Добавление книги в библиотеку из консоли" << endl <<
		"2) Добавление книги в библиотеку из файла" << endl <<
		"3) Поиск по жанру" << endl <<endl;

	cin >> deistvie;

	if (deistvie == 0) return 0;
	if (deistvie == 1) Kn.INCONS();
	if (deistvie == 2) Kn.INFILE();
	if (deistvie == 3) Kn.FOUND();

	system("pause"); 
	return 0;
}