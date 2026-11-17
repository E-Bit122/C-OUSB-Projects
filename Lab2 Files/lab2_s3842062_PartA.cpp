
#include <iostream>
using namespace std;

int main()
{

	// Only one of the below command lines can be used. At the moment it is setup for the Physical Board
   // The command used on both lines requests that the number 20 be written to PORTB of the OUSB board
	char command[255] = "ousb -r io PINC";   	// Use this line if using the Physical OUSB Board
  //char command[255] = "ousbsim -r io PORTB 20";   // Use this line if using the OUSB simulator

	FILE* fpipe;									// Create a File pipe pointer
	char line[256] = {};							// Declare some memory to hold the reply message

	fpipe = (FILE*)_popen(command, "r");			// Open the pipe so the command can be executed
	if (fpipe != NULL)								// Confirm pipe was successfully opened
	{
		while (fgets(line, sizeof(line), fpipe))	// Read in the reply message line by line
		{   //do nothing, or print out debug data
			//cout << "Debug:" << line; // print out OUSB data
		}
		_pclose(fpipe);								// Close the pipe
	}
	else cout << "Error, problems with pipe!\n";	// print and error message if the pipe failed to open

	//convert value from char array to int	
	int pinc = (int)atoi(line);		// do something with the value that was returned by the pipe
	pinc = pinc + 12;
	cout << pinc << endl;

	return 0;
}
