#include "pch.h"
#include <algorithm>
#include <boost/timer.hpp>
#include <iostream>
#include <iterator>
#include <vector>

const int N = 100; // ����� ���-�� ���������
const int K = 5;  // ���������� ������������ ��������� 

int main()
{
	boost::timer t;
	std::vector<size_t> a(K + 1);
	a[0] = -1;
	int m = 1;
	for (int i = 1; i <= K; i++)
	{
		a[i] = i;
	}

	t.restart();
	while (m != 0)
	{
		//copy(a.begin() + 1, a.end(), std::ostream_iterator<size_t>(std::cout, " "));
		//std::cout << std::endl;
		m = K;
		
		while (a[m] == N - K + m)
		{
			m--;
		}
		a[m]++;
		for (int i = m + 1; i <= K; i++)
		{
			a[i] = a[i - 1] + 1;
		}
	}

	double duration = t.elapsed();
	std::cout << duration << std::endl;

	return 0;
}
