/*
EEET2246 OUSB IO Board example code 

This file is for demonstration purposes ONLY (and will work with the ousbsim.exe simulator
as well as the Physical OUSB board if the correct command line argument is use and the
correct ousb.exe/ousbsim.exe file/s and drivers are installed)  Note: the OUSB Simulator
does not require any specific drivers to be installed.

NOTE: If using this example with the simulator, the value of PORTB will be written and
read from the PORTB text file: portb.txt 

    Version Date:	27/03/2021

*/
#include <iostream>  	// used for cout statements

using namespace std;

int main(int argc, char * argv[])
{
    // Only one of the below command lines can be used. At the moment it is setup for the Physical Board
	// The command used on both lines requests that the number 20 be written to PORTB of the OUSB board
	char command[255] = "ousb -r io PORTB 20";   	// Use this line if using the Physical OUSB Board
  //char command[255] = "ousbsim -r io PORTB 20";   // Use this line if using the OUSB simulator

	FILE *fpipe;									// Create a File pipe pointer
	char line[256] = {};							// Declare some memory to hold the reply message

	fpipe = (FILE*)_popen(command, "r");			// Open the pipe so the command can be executed
	if (fpipe != NULL)								// Confirm pipe was successfully opened
	{
		while (fgets(line, sizeof(line), fpipe))	// Read in the reply message line by line
		{   //do nothing, or print out debug data
			cout << "Debug:" << line; // print out OUSB data
		}
		_pclose(fpipe);								// Close the pipe
	}
	else cout << "Error, problems with pipe!\n";	// print and error message if the pipe failed to open

	//convert value from char array to int	
	int portb = (int)atoi(line);					// do something with the value that was returned by the pipe
	cout << "value = " << portb << endl;

	return 0;
}