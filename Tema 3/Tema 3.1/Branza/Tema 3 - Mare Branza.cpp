#include <iostream>
#include <fstream>
#include <deque>

using namespace std;

ifstream f("branza.in");
ofstream g("branza.out");

long long  c[100001], p[100001];

int main()
{
	long long n, s, t, cost_min=0;
	deque<long long> deq;

	f >> n >> s >> t;

	for (int i = 0; i < n;i++)
	{
		f >> c[i] >> p[i];
		if (!deq.empty() && i - deq.front() > t)
			deq.pop_front();
		while (!deq.empty() && c[i] <= c[deq.back()] + s * (i - deq.back()))
			deq.pop_back();
		deq.push_back(i);
		cost_min += p[i] * (c[deq.front()] + s * (i - deq.front()));
	}
	g << cost_min;
	return 0;
}