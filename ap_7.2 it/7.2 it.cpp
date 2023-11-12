#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int n, const int k, const int Low, const int High);
void Print(int** a, const int n, const int k);
void SearchMinEven(int** a, const int n, const int k, int& minEven);
int main()
{
	srand((unsigned)time(NULL));
	int Low = -21;
	int High = 20;
	int n, k;
	cout << "n = "; cin >> n;
	cout << "k = "; cin >> k;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[k];
	Create(a, n, k, Low, High);
	Print(a, n, k);
	int minEven;
	SearchMinEven(a, n, k, minEven);
	return 0;
}
void Create(int** a, const int n, const int k, const int Low, const int High)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int n, const int k)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
void SearchMinEven(int** a, const int n, const int k, int& minEven)
{
	int* ar_max = new int[k], j = 0;
	for (int i = 0; i < k; i++)
	{
		if (i % 2 == 0)
		{
			int max = a[0][i];
			for (int b = 0; b < n; b++)
			{
				if (a[b][i] > max)
				{
					max = a[b][i];
				}
			}
			ar_max[j] = max;
			j++;
		}
	}
	cout << "Max elements: " << endl;
	for (int i = 0; i < j; i++)
	{
		cout << setw(4) << ar_max[i];
		cout << endl;

	}
	int min = ar_max[0];
	for (int i = 0; i < j; i++)
	{
		if (ar_max[i] < min)
		{
			min = ar_max[i];
		}

	}
	cout << "Min = " << min;
	
}