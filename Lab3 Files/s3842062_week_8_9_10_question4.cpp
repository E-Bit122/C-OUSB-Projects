#include <iostream>
using namespace std;

int main()
{
	//int valuelist[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
	//int valuelist[10] = {4, 7, 98, 46, 453, 8444, 61, 27, 12, 73 };
	int valuelist[10] = {4, 7, 1, 36, 23, 67, 61, 887, 12, 53 };
	int value = 0;
	for (int i = 0; i <= 10; i++)
	{
		
		if (i == 0)
				value = valuelist[0];
		else
		{
			
			if (valuelist[i] > value)
			{
				value = valuelist[i];
			}

		}
		

	}

	cout << "the largest number is " << value << endl;
}
