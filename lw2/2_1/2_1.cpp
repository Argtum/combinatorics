#include "pch.h"

using namespace std;

const unsigned int ARGUMENT_COUNT = 2;
const int SIZE = 400;

void PrintMatrix(int matrix[][SIZE], int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
}

void ReadEdgeListToMatrix(const string& inputFileName, int matrix[][SIZE])
{
	ifstream input(inputFileName);
	string str;
	vector<string> tops;
	int i, j;

	if (!input.is_open())
	{
		cout << "Failed to open " << inputFileName << " for reading\n";
	}

	getline(input, str);
	int size = stoi(str);

	for (i = 0; i < size; ++i)
	{
		for (j = 0; j < size; ++j)
		{
			matrix[i][j] = 0;
		}
	}

	while (getline(input, str))
	{
		boost::split(tops, str, boost::is_any_of(" "));

		i = stoi(tops[0]);
		j = stoi(tops[1]);

		matrix[i - 1][j - 1] = 1;
		matrix[j - 1][i - 1] = 1;
	}

	PrintMatrix(matrix, size);
}

int main(int argc, char* argv[])
{
	if (argc != ARGUMENT_COUNT)
	{
		cout << "Invalid arguments count\n"
			 << "Usage: 2_1.exe <input file> <output file>\n";
		return 1;
	}

	int matrix[SIZE][SIZE];

	ReadEdgeListToMatrix(argv[1], matrix);

	return 0;
}
