#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

ifstream f("paranteze.in");
ofstream g("paranteze.out");

int main()
{
	int n, lmax=0;
	string paranteze;
	f >> n;
	f >> paranteze;
	stack<int> stck;
	stck.push(-1);
	for (int i = 0;i < n;i++) 
	{
		if (paranteze[i] == '(' || paranteze[i] == '[' || paranteze[i] == '{')
		{
			stck.push(i);
		}
		else 
		{
			if (paranteze[i] == ')' || paranteze[i] == ']' || paranteze[i] == '}')
			{
				if (!stck.empty() && ((paranteze[i] == ')' && paranteze[stck.top()] == '(') || (paranteze[i] == ']' && paranteze[stck.top()] == '[') || (paranteze[i] == '}' && paranteze[stck.top()] == '{')))
				{
					stck.pop();
					if (!stck.empty() && i - stck.top() > lmax)
						lmax = i - stck.top();
				}
				else stck.push(i);
			}
		}
	}
	g << lmax;
	f.close();
	g.close();
	return 0;
}