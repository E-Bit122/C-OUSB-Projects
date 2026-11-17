#include <iostream>
using namespace std;


bool ArgumentCheck(int argc, char* argv[], char* pointer)
{
	
	bool boolTest;

	for (int i = 1; i != argc; i++)
	{
		for (int j = 0; argv[i][j] != '\0'; j++)
		{
			for (int k = 0; *(pointer + k) != '\0'; k++)
			{

				if (argv[i][j] == *(pointer + k))
				{
					boolTest = true;
					continue;
				}

			}

			if (boolTest == true)
			{
				boolTest = false;
			}
			else
				return false;

		}
		cout << argv[i] << " ";
	}
	return true;
}

int main(int argc, char* argv[])
{
	char ValidCharacters[] = ".,-+eE0123456789";
	char* pointer = ValidCharacters;
	bool ReturnValue = ArgumentCheck(argc, argv, pointer);

	if (ReturnValue == true)
	{
		cout << endl << "Arguments are valid" << endl;
	}
	else
	{
		cout << "X" << endl;
	}

}
