#include <iostream>
#include<vector>
#include <algorithm>
#include <iomanip>

void print(const std::vector<std::vector<int>>& matrix)
{

	for (size_t i = 0; i < matrix.size(); i++)
	{
		for (size_t j = 0; j < matrix.size(); j++)
		{
			std::cout << " " << matrix[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void CPM(std::vector<std::vector<int>>& matrix) 
{
	for (int k = 0; k < matrix.size(); k++) 
	{
		for (int i = 0; i < matrix.size(); i++) 
		{
			for (int j = 0; j < matrix.size(); j++) 
			{
				if (i != j && matrix[i][k] != -10 && matrix[k][j] != -10) 
				{
					if (matrix[i][j] == -10) 
						matrix[i][j] = matrix[i][k] + matrix[k][j];
					else matrix[i][j] = std::max(matrix[i][j], matrix[i][k] + matrix[k][j]);
				}
			}
		}
		std::cout << "operations" << k << std::endl;
		print(matrix);
	}
}



int main()
{
	std::vector<std::vector<int>> Matrix =
	{
		{  0,     3,   -10,   -10,   -10,     5,   -10},
		{-10,     0,     2,     3,   -10,   -10,   -10},
		{-10,   -10,     0,     4,     4,     2,   -10},
		{-10,   -10,   -10,     0,   -10,     1,   -10},
		{-10,   -10,   -10,   -10,     0,     3,     5},
		{-10,   -10,   -10,   -10,   -10,     0,     3},
		{-10,   -10,   -10,   -10,   -10,   -10,     0},
	};
	print(Matrix);
	CPM(Matrix);
	print(Matrix);
	std::cout << "critical path length=  " << Matrix[0][6];
}


