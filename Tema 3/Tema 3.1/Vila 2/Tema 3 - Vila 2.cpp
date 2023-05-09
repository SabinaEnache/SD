#include <iostream>
#include <fstream>
#include <deque>
#include <vector>

using namespace std;

ifstream f("vila2.in");
ofstream g("vila2.out");

int main()
{
	int n, k, dif, difmax = 0;
	f >> n >> k;
	vector<int> varste(n);
	deque<int> minim, maxim;
	for (int i = 0; i < n; i++) 
	{
		f >> varste[i];
		while (!maxim.empty() && varste[maxim.back()] < varste[i])
			maxim.pop_back();
		while (!minim.empty() && varste[minim.back()] > varste[i])
			minim.pop_back();

		minim.push_back(i);
		maxim.push_back(i);
		
		if (i >= k && maxim.front() < i - k)
			maxim.pop_front();
		if (i >= k && minim.front() < i - k)
			minim.pop_front();
		if (i >= k)
		{
			dif = varste[maxim.front()] - varste[minim.front()];
			if (dif > difmax) difmax = dif;
		}
	}
	g << difmax;

	f.close();
	g.close();

	return 0;
}