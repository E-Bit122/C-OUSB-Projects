
#include <iostream>
using namespace std;

void ArrayReverse(char* InputPointer, int stringlength)
{
	
	for (int i = 0; i <= stringlength ; i++)
	{

		cout << *(InputPointer - i);

	}
	cout << endl;
}


int main()
{
	char InputArray[] = "Ethan Haberl";
	//char InputArray[] = "Hello World!";
	//char InputArray[] = "s3842062";
	char* EndArray = InputArray + strlen(InputArray);

	ArrayReverse(EndArray, strlen(InputArray));
	
}

