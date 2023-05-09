#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

ifstream f("alibaba.in");
ofstream g("alibaba.out");

int main()
{
	int n, k;
	string cifre;
	
	f >> n >> k;
	f >> cifre;
	int nr = 0;
	while (nr < cifre.length() - 1 && k > 0)
	{
		if (cifre[nr] < cifre[nr + 1])
		{
			cifre.erase(nr, 1);
			nr = max(0, nr - 1);
			k--;
		}
		else nr++;
	}

	while (cifre.length() > 0 && k > 0)
	{
		cifre.erase(cifre.length() - 1, 1);
		k = k - 1;
	}

	g << cifre;
	return 0;
}