/*
EEET2246 OUSB Board example code (Can be used with simulator if it is renamed ousb.exe)

This file is for demonstration purposes ONLY, which uses OUSB write portb and
OUSB read portb functions

This file demonstrated the use of _popen(), with some peripheral code to clarify
how this provide pipe code functions. The code reads the current state of the OUSB board
PORTB register and displays it to the console. It then increments the state of PORTB
and displays the new state and repeats the process again. (i.e. Read, Write, Read, Write). 

No guarantee given. Use at own risk. Feel free to change, or disregard. Suggestion only.
There are many other ways to achieve the same purpose.

NOTE: If using this example with the simulator, the value of PORTB will be written and
read from the PORTB text file: portb.txt 

Version Date:	26/03/2021

*/
#include <iostream>

const int numToAdd = 11; // add 11 to the current state of PORTB for demo purposes.

using namespace std;


int main(int argc, char *argv[])
{
	// Declare common variables
	char command[255] = {};	// array that will hold the OUSB commands
	char line[255] = {};	// array to hold received data from the OUSB board
	FILE *fpipe;			// file variable, see text book module 11.

	char ReadCommand[] = "ousb -r io PORTB";   		// String containing the OUSB read command
	char BaseWriteCommand[] = "ousb -r io PORTB "; 	// String containing the OUSB base write command (It is missing the actual value to write which we append later)
	char val_string[4] = {}; 						// String that will contain the PORTB value to be written to the OUSB Board (as a char array)
	int portb = 0;           						// Place to save the value of PORTB value (as an int)

							 //  Read value of PORTB -------------------------------------------------
	cout << "First part of the program reads the current value of PORTB from the OUSB Board\n";

	// construct the read command
	strcpy_s(command, ReadCommand); // copy the ReadCommand into the Command array
									// Display OUSB command that will be used to communicate to the OUSB Board
	cout << "OUSB Board command is: " << command << endl;

	// pipe code that sends out the current Command stored in the command variable
	fpipe = (FILE*)_popen(command, "r");
	if (fpipe != NULL)
	{
		while (fgets(line, sizeof(line), fpipe))
		{   //do nothing, or print out debug data
			cout << "Debug line:" << line; // print out OUSB data
		}
		_pclose(fpipe);
	}
	else cout << "Error, problems with pipe!\n";

	//convert value from char array to int	
	portb = (int)atoi(line);  // this is the value on PORTB at this time as an integer. 

							  // do something with it
	cout << "This was read from PORTB  = " << portb << endl;

	// write to PORTB--------------------------------------------------------------
	cout << endl;
	cout << "Second part of the program adds 11 the current value of PORTB from the OUSB Board\n";

	//  Updated value of PORTB -------------------------------------------------
	portb = portb + numToAdd; // add 11 to the current state of PORTB for demo purposes.

							  // construct the write command with the correct value to write to PORTB
	_itoa_s(portb, val_string, 10);		 // Convert PORTB integer to character array (in base 10)
	strcpy_s(command, BaseWriteCommand); // reset the command array with the BaseWriteCommand string
	strcat_s(command, val_string);		 // append the value to write to PORTB to the Command string

										 // Display OUSB command that will be used to communicate to the OUSB Board
	cout << "OUSB Board command is: " << command << endl;

	// pipe code that sends out the current Command stored in the command variable
	fpipe = (FILE*)_popen(command, "r");
	if (fpipe != NULL)
	{
		while (fgets(line, sizeof(line), fpipe))
		{   //do nothing, or print out debug data
			cout << "Debug line:" << line; // print out OUSB data
		}
		_pclose(fpipe);
	}
	else cout << "Error, problems with pipe!\n";

	//convert value from char array to int	
	portb = (int)atoi(line);  // this is the value on PORTB at this time as an integer. 

							  // do something with it
	cout << "This was written to PORTB  = " << portb << endl;


	// read PORTB again ------------------------------------------------------------------
	cout << endl;
	cout << "Third part of the program reads the current value of PORTB from the OUSB Board\n";

	// construct the read command
	strcpy_s(command, ReadCommand); // copy the ReadCommand into the Command array

									// Display OUSB command that will be used to communicate to the OUSB Board
	cout << "OUSB Board command is: " << command << endl;

	// pipe code that sends out the current Command stored in the command variable
	fpipe = (FILE*)_popen(command, "r");
	if (fpipe != NULL)
	{
		while (fgets(line, sizeof(line), fpipe))
		{   //do nothing, or print out debug data
			cout << "Debug line:" << line; // print out OUSB data
		}
		_pclose(fpipe);
	}
	else cout << "Error, problems with pipe!\n";

	//convert value from char array to int	
	portb = (int)atoi(line);  // this is the value on PORTB at this time as an integer. 

							  // do something with it
	cout << "This was read from PORTB  = " << portb << endl;


	// write to PORTB--------------------------------------------------------------
	cout << endl;
	cout << "Fourth part of the program adds 11 the current value of PORTB from the OUSB Board\n";

	//  Updated value of PORTB -------------------------------------------------
	portb = portb + numToAdd; // add 11 to the current state of PORTB for demo purposes.

							  // construct the write command with the correct value to write to PORTB
	_itoa_s(portb, val_string, 10);		 // Convert PORTB integer to character array (in base 10)
	strcpy_s(command, BaseWriteCommand); // reset the command array with the BaseWriteCommand string
	strcat_s(command, val_string);		 // append the value to write to PORTB to the Command string

										 // Display OUSB command that will be used to communicate to the OUSB Board
	cout << "OUSB Board command is: " << command << endl;

	// pipe code that sends out the current Command stored in the command variable
	fpipe = (FILE*)_popen(command, "r");
	if (fpipe != NULL)
	{
		while (fgets(line, sizeof(line), fpipe))
		{   //do nothing, or print out debug data
			cout << "Debug line:" << line; // print out OUSB data
		}
		_pclose(fpipe);
	}
	else cout << "Error, problems with pipe!\n";

	//convert value from char array to int	
	portb = (int)atoi(line);  // this is the value on PORTB at this time as an integer. 

							  // do something with it
	cout << "This was written to PORTB  = " << portb << endl;

	cout << endl;
	return 0;
}