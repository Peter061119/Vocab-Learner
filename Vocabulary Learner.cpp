#include <iostream>
#include <cstdio>
#include <Windows.h>
using namespace std;

string Eng[1000];
string Chn[1000];
string filename;
char fnptr[10000] = { 0 };

void WriteIn();
void Test();

int main()
{
	while (true)
	{
		//初始化变量
		for (int i = 0; i < 1000; i++)
		{
			Eng[i] = "";
			Chn[i] = "";
		}
		filename = "";
		memset(fnptr, 0, sizeof(fnptr));


		//--------------提示语--------------------
		cout << "VocabLearner0.3(C++ver)  by 失智のZP" << endl << endl;

		char mode = 0;
		cout << "Which mode do you want to choose?" << endl;
		cout << "W - Write Mode" << endl;
		cout << "T - Test Mode" << endl;

		//----------------输入模式-----------------
		while (true)
		{
			cin >> mode;
			if (mode >= 'a' and mode <= 'z')
			{
				mode -= 'a';
				mode += 'A';
			}

			if (mode != 'W' and mode != 'T')
			{
				cout << "error. Please try again" << endl;
			}
			else
			{
				break;
			}
		}
		cout << endl;

		//---------------输入文件名-----------------
		cout << "Please enter filename:";
		cin >> filename;
		cout << endl;
		for (size_t i = 0; i < filename.size(); i++)
		{
			fnptr[i] = filename[i];
		}


		//------------程序主体--------------
		if (mode == 'W')
		{
			WriteIn();
		}
		else
		{
			Test();
		}
		cout << "Do you wanna quit? (Y / N)" << endl;
		while (true)
		{
			char tmp;
			cin >> tmp;
			if (tmp >= 'a' and tmp <= 'z')tmp = tmp - 'a' + 'A';

			if (tmp != 'Y' and tmp != 'N')cout << "error. Please enter again." << endl;

			if (tmp == 'Y')
			{
				cout << "Thanks for using. " << endl;
				system("pause");
				return 0;
			}

			if (tmp == 'N')
			{
				system("cls");
				break;
			}
		} 
	}
	return 0;
}

void WriteIn()
{
	int gs;

	cout << "How many do you wanna insert?" << endl;
	cin >> gs;

	cout << endl;

	for (int i = 0; i < gs; i++)
	{
		cout << "Input English of this word: ";
		cin >> Eng[i];
		cout << "Input Chinese of this word: ";
		cin >> Chn[i];
		cout << endl;
	}
	FILE* pfile;
	pfile = fopen(fnptr, "w");
	
	fprintf(pfile, "%d\n", gs);

	for (int i = 0; i < gs; i++)
	{
		for (size_t j = 0; j < Eng[i].size(); j++)fprintf(pfile, "%c", Eng[i][j]);
		fprintf(pfile, "\n");

		for (size_t j = 0; j < Chn[i].size(); j++)fprintf(pfile, "%c", Chn[i][j]);
		fprintf(pfile, "\n");
	}
	fclose(pfile);
	cout << "WriteFinished" << endl;
	return;
}

void Test()
{
	FILE* pf;
	pf = fopen(fnptr, "r");

	if (pf == NULL)
	{
		cout << "You haven't write yet. Please write first.";
		return;
	}

	int gs;
	char tool;

	fscanf(pf, "%d", &gs);
	fscanf(pf, "%c", &tool);

	for (int i = 0; i < gs; i++)
	{
		while (true)
		{
			char tmp;
			fscanf(pf, "%c", &tmp);
			if (tmp == '\n')break;
			Eng[i].push_back(tmp);
		}

		while (true)
		{
			char tmp;
			fscanf(pf, "%c", &tmp);
			if (tmp == '\n')break;
			Chn[i].push_back(tmp);
		}
	}
	fclose(pf);

	int correct = 0;
	for (int i = 0; i < gs; i++)
	{
		string tmp;
		cout << Chn[i] << endl;
		cout << "Input English of this word: ";
		cin >> tmp;
		if (tmp != Eng[i])
		{
			cout << "wrong" << endl;
		}
		if (tmp == Eng[i])
		{
			cout << "correct!" << endl;
			correct++;
		}
		cout << endl;
	}
	cout << endl;
	cout << "----------------------------------------" << endl;
	cout << "Total: " << gs << endl;
	cout << "Correct: " << correct << endl;
	cout << "Wrong: " << gs - correct << endl << endl;
	cout << "TestFinished" << endl;
	return;
}
