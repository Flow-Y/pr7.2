#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int n, const int Low, const int High);
void Print(int** a, const int n);
int searchMinMax(int** a, int max, int min, int n, int k);

int main()
{
	srand((unsigned)time(NULL));
	int Low = 7;
	int High = 65;
	int n;
	cout << "n = "; cin >> n;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
	Create(a, n, Low, High);
	Print(a, n);
	int min, max;
	int k = -1;
	if (searchMinMax(a, max, min, n, k))
		swap(min, max);
	else
		cout << "There are nothing to swap" << endl;
		for (int i = 0; i < n; i++)
			delete[] a[i];
	delete[] a;
	return 0;
}

void Create(int** a, const int n, const int Low, const int High)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

int searchMinMax(int** a, int* max, int* min, int n, int k)
{
	*max = a[n][0], * min = a[n][0];
	for (int i = 0; i < k; i++) {
		if (a[n][i] > *max) { *max = a[n][i]; }
		if (a[n][i] < *min) { *min = a[n][i]; }
	}
	cout << min << max;
}