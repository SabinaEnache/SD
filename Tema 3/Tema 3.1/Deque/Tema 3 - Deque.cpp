#include <iostream>
#include <fstream>
using namespace std;

ifstream f("deque.in");
ofstream g("deque.out");
int v[5000001], deque[5000001];

int main()
{
	int n, k, stanga, dreapta;
	long long suma = 0;

	f >> n >> k;
	
	for (int i = 1; i <= n; i++)
		f >> v[i];
	stanga = 1;
	dreapta = 0;

	for (int i = 1; i <= n; i++)
	{
		while (stanga <= dreapta && v[i] <= v[deque[dreapta]])
			dreapta--;
		dreapta++;
		deque[dreapta] = i;
		if ( 1 - deque[stanga] > k - i)
			stanga++;
		if (i >= k)
			suma += v[deque[stanga]];
	}
	g << suma;
	f.close();
	g.close();
	return 0;
}