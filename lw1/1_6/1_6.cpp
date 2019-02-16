#include "pch.h"
#include <algorithm>
#include <boost/timer.hpp>
#include <iostream>
#include <iterator>
#include <vector>

const int N = 20;

void printSubset(std::vector<size_t> a, std::vector<size_t> b)
{
	for (int i = 0; i < N; i++)
	{
		if (a[i] == 1)
		{
			std::cout << b[i];
		}
	}
	std::cout << std::endl;
}

int main()
{
	boost::timer t;
	std::vector<size_t> a(N), b(N);
	for (int i = 1; i < N; i++)
	{
		a[i] = 0;
		b[i] = i;
	}

	t.restart();
	while (a[N - 1] != 1)
	{		
		//printSubset(a, b);
		int i = 0;
		while (a[i] == 1)
		{
			a[i] = 0;
			i++;
		}
		a[i] = 1;
	}

	double duration = t.elapsed();
	std::cout << duration << std::endl;

	return 0;
}
