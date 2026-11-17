

#include <iostream>
#include <windows.h>
using namespace std;
int ReadPinC();
void WritePortB(int val);

int ReadPinC()
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
	int portb = (int)atoi(line);		// do something with the value that was returned by the pipe

	cout << portb << endl;

	return portb;
}

void WritePortB(int val)
{

	int portb = val;

	char val_string[255];
	_itoa_s(portb, val_string, 10);
	FILE* fpipe;
	char line[256] = {};
	char command2[255] = "ousb -r io PORTB ";   	// Use this line if using the Physical OUSB Board
  //char command[255] = "ousbsim -r io PORTB 20";   // Use this line if using the OUSB simulator
	strcat_s(command2, val_string);

	// Declare some memory to hold the reply message

	fpipe = (FILE*)_popen(command2, "r");			// Open the pipe so the command can be executed
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
	portb = (int)atoi(line);					// do something with the value that was returned by the pipe
	cout << "value = " << portb << endl;

	return;
}


int main(int argc, char* argv[])
{
    
	while (int k = 1)
	{

		
		
		int portb = ReadPinC();
		

		//////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////

		WritePortB(portb);

		Sleep(1000);
		
	}
	
	return 0;

}


