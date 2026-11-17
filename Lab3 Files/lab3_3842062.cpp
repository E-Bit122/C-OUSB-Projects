/*======== Proforma : EEET2246 Laboratory Code 3 Submission - OUSB Process Control ============
Proforma version number: 2021.001.1

Document history:
	version:	2021.001.1 - 23-04-2021 - original release
	
PURPOSE:
This file is a proforma for the EEET2246 Laboratory Code 3 Submission.
This file defines the assessment task which is worth 15% of the available course grade - 
there is no other documentation.

OUSB USAGE: 
All submissions will be tested using the OUSB Simulator that has been renamed to: ousb.exe
This is so all student can test their code using version of the OUSB interface which everyone has
access too. However, DO NOT use the ousbsim command as part of your pipe code!!!  All pipe code must
use the ousb command. If your code works with a Physical OUSB board and you are only using the PORTB,
PINC or ADC pin 5 (adc 5) commands it should work just as well with the simulator - However it is
recommended that all students check their code with the OUSB Simulator prior to submission.

GOAL:
Laboratory Code 3 task is to write a program that takes up to 2 command line arguments
and makes several decisions based on certain register values on the OUSB Board.

You will be required to read the 'PINC' and 'ADC 5' registers which are connected to
the DIP switches and potentiometer on a physical OUSB Board, respectively. If using the OUSB
Simulator, the values will be stored in the pinc.txt and the p_ADC5.txt files, respectively.
Your program will then perform a comparison (decision) on the input data from the command line
arguments and simulated OUSB Board PINC / ADC 5 registers and write the largest value to be
written to PORTB, as well as display the binary representation of the value to the console window.

The binary representation of the largest value from the comparison must be written to
the console using 8 characters (zero padded as necessary) to either display the binary
representation in reverse or conventional order. You will need to account for the
limitations in the hardware/simulator and appropriately write the correct value to the
OUSB board, as well as perform any necessary error and range checking of input arguments.
The value written to PORTB should always be in the conventional bit-order.

The program decisions will be based on:
	- The first input argument, which must be a valid number between 0 and 255 input as a
	  floating point number. This number will need to be rounded to the nearest integer
	  (i.e. the value 3.4 will be rounded to 3 and 3.5 will rounded to 4).

	- The (optional) second input argument determines the type of comparison operation to
	  undertake and the format of the output on the console window. The only valid arguments
	  for the second command line argument are:
	  
	"c1"  Compare command line argument 1 to the OUSB Board switches (PINC) and display
		  the larger value in binary to the console window in reverse order as well as
		  write the value to PORTB. (Default)
	"c2"  Compare command line argument 1 to the OUSB Board potentiometer (ADC 5) and
		  display the larger value in binary to the console window in reverse order as
		  well as write the value to PORTB.
	"c3"  Compare command line argument 1 to the OUSB Board potentiometer (ADC 5) and 
		  switches (PINC) and display the larger value in binary to the console window
		  in reverse order as well as write the value to PORTB.
	"c4"  Same as option "c3", however display the larger value in binary to the console
		  window in the correct order of bit7 through to bit0 in addition to writing the
		  value to PORTB.

If only one command line argument is provided, then a comparison between the first
command line input argument and the OUSB Board switches should be performed (i.e.
option "c1" by default).

Note: 
	- The value on the switches (PINC) is the value of 8 (DIP) switches on the OUSB Board,
	  or the pinc.txt file if using the simulator. NOTE: Valid values in the pinc.txt file
	  are integer numbers between 0 - 255 (i.e. 8-bits).

	- The value on the potentiometer (ADC 5) is derived from the potentiometer and resistive
	  network connected to pin 5 of PORTA. If using the simulator, this value will come from
	  the p_ADC5.txt file. NOTE: Valid values in the p_ADC5.txt file are integer numbers
	  between 0 - 1023 (i.e. 10-bits).

The program output will be via the OUSB Board LEDs connected to PORTB and the console window.
The output to the console window under normal conditions will display the binary representation
of the value at PORTB in the specified order followed by a new line character. If an error
occurs the only output will be a one character error code followed by a new line character.
The OUSB Board LEDs (PORTB) must not be updated if an error occurs.

The emphasis in this lab is to achieve the basic FUNCTIONAL REQUIREMENTS, however your program
will also need to consider range checking, as well as basic, intermediate and advanced
error level detection and handling to achieve full marks.

Initially it is recommended that you aim for "c1", "c2" and "c3" functionality and if
time permits then attempt to implement "c4" functionality and error checking in priority
order.

RESOURCES:
	1. Lecture and tutorial notes.
	2. Prescribed Text book and the "Teach Yourself C++ in 21 Days" PDF ebook.
	3. The Open-USB-IO Reference manual (PDF file on canvas under the "OUSB Board Resources" page 
	3. The ousbsim.exe file on canvas, which will provide the simulated OUSB Board functionality. 
	   However, you will need to rename the ousbsim.exe file to ousb.exe so that it replaces the
	   real one ousb.exe interface application.

	   Note: If you have a physical board you can do the whole assignment with the real ousb.exe
	   interface file as long as you do not use any other registers arguments are than: PORTB,
	   PINC or ADC pin 5 (adc 5).

SUBMISSION:
You will be required to rename this *.cpp to the following format:
	lab3_1234567.cpp
where the numbers 1234567 are your student number.

The file should then be uploaded via Canvas before the due date and time. You are only required
to upload this submission as a *.cpp file using the correct naming convention. No report is 
required - only the *.cpp file which you have created.

Note: If you re-submit your solution to Canvas, it will be automatically renamed with -1 or -2,
etc. attached to the end of your file. You can submit multiple times, however only your last
submission will count.

Note: 10 marks (i.e. 10% of available marks) per 24-hour period penalty will apply to late submissions
(inclusive of weekends and public holidays). Therefore if you submit 1 minutes late, a 10 mark penalty
will be applied. Your last submission will be the file that is assessed and that submission time will
be used to determine the late penalty.	   
	
MARKING:
Your code will not be modified at all and must compile. Code that fails to compile will score 0%.

Marking has several components-
	1. your code will be checked for functionality.
	2. your code will be tested with erroneous input.

PLAGIARISM:
The submission must be your code solution in its entirety. If your code is found to be similar to
another submission it will be investigated for possible Academic Misconduct. Please respect the
academic process and make sure your submission complies with RMIT's Student Conduct Policy. See:
https://www.rmit.edu.au/about/governance-and-management/policies/student-conduct-policy
*/
/*
___________________________________________________________________________________________
___ GENERAL SPECIFICATIONS (mostly common to all three EEET2246 Laboratory Code Submissions):

G1.	You must rename your file to lab3_1234567.cpp, where 1234567 is your student number.
Your filename MUST NEVER EVER contain any spaces.  _under_score_is_Fine.
You do not need to include the 's' in front of your student number. Canvas will rename you
submission by adding a -1, -2 etc. if you resubmit your solution file - This is acceptable.

G2.	Edit the name/email address string in the main() function to your student number,
student email and student name.	The format of the student ID line is CSV (Comma Separated
Variables) with NO SPACES-
student_id,student_email,student_name
When the program is run without any operands i.e. simply the name of the executable such as:
lab3_1234567.exe
the program MUST print student ID string in Comma Separated Values (CSV) format with no
spaces. For example the following text should be outputted to the console updated with
your student details:
"1234567,s1234567@student.rmit.edu.au,FirstName_LastName"

G3.	All outputs are a binary representation of an integer or a single character error
indicator followed by a linefeed ( endl or \n).

G4.	DO NOT add more than what is specified. Do NOT add additional information, text or
comments to the output console.

G5.	DO NOT use 'cin', system("pause"), getchar(), gets(), etc. type functions. Do NOT ask
for user input from the keyboard. All input MUST be specified on the command line separated
by blank spaces (i.e. use the argv and argc input parameters).

G6. DO NOT use the characters:  * / \  : ^ ? in your command line arguments as your user
input. These are special character and may not be processed as expected, potentially
resulting in undefined behaviour of your program.

G7.	All input and output is case sensitive.

G8.	You should use the Integrated Debugging Environment (IDE) to change input arguments during
the development process.

G9.	When your code exits the 'main()' function using the 'return' command then you MUST use
zero as the return value. This requirement is for exiting the 'main()' function ONLY.

G10. Do NOT put any functions after the 'main()' function - if you write your own functions
then add them BEFORE the 'main()' function. This is a requirement of the Autotester and failure
to do so will result in the Autotester not compiling your code correctly and loss of marks.

G11. You MUST run this file as part of a Project - No other *.cpp or *.h files should be added
to your solution.

G12. The user-defined functions to read and write to the OUSB board must be written before the
'main()' function. This is a requirement of the Autotester and failure to do so will result in your
code scoring 0.

G13. If an error (as per the definition in this specification) occurs, then the value on
the simulated OUSB PORTB (LEDs) must not to be updated.

G14. All numerical values read from / written to the simulated OUSB Board are considered to be
unsigned integers and are between 0 to 255 (inclusive) for PORTB register and 0 to 1023 for
the ADC 5 register.

G15. All binary numbers within this document have the prefix 0b. This notation is not C++
compliant (depending on the C++ version), however is used to avoid confusion between decimal,
hexadecimal and binary number formats within the description and specification provided in
this document. For example the number 10 in decimal could be written as 0xA in hexadecimal
or 0b1010 in binary. It can equally be written with leading zeroes such as: 0x0A or
0b00001010. For output to the console screen you should only ever display the numerical
characters only and omit the 0x or 0b prefixes.

G16. Do not attempt to read/write to any other OUSB Board IO port other than PORTB, PINC
or ADC pin 5 (adc 5).

G17. The conversion to binary must occur in your code, not by using the -b switch as part
of the OUSB.exe application. The '-b' flag will not be supported by the AutoTester.

*/
/*
___________________________________________________________________________________________
___ FUNCTIONAL REQUIREMENTS:

F1.	For situations where NO command line arguments are passed to your program:

F1.1	Your program must display your correct student details in the format:
"1234567,s1234567@student.rmit.edu.au,FirstName_LastName"

F2.	For the situation where ONE command line argument is passed to your program:

F2.1	Your program must compare the rounded value (to the nearest integer) of the
input argument with the value of the DIP switches connected to PINC of the OUSB Board.
Whichever value is larger should then be written to PORTB (LEDs) of the OUSB Board.
The value should also be displayed to the console window using the reverse binary
representation in an 8 character long string (ie. Bit0, Bit1, Bit2, Bit3, Bit4, Bit5,
Bit6, Bit7 with no commas or spaces) followed by a new line character. The code must
return 0 and subsequently exit.

Example 1:
lab3_1234567.exe 40.4
Given a simulated OUSB DIP Switch (PINC) value of 12 (0b00001100), then the argument will
be larger in value, resulting in value 40 be written to PORTB (LEDs) and the binary
representation of 40 should be displayed to the console in reverse order. Hence, the
last (and only) line on the console will be:
00010100
The OUSB PORTB output will be: 40 (0b00101000)

Example 2:
lab3_1234567.exe 39.5
Given a simulated OUSB DIP Switch (PINC) value of 12 (0b00001100), then the argument will
be larger in value, resulting in value 40 be written to PORTB (LEDs) and the binary
representation of 40 should be displayed to the console in reverse order. Hence, the
last (and only) line on the console will be:
00010100
The OUSB PORTB output will be: 40 (0b00101000)

Example 3: 
lab3_1234567.exe 10
Given a simulated OUSB DIP Switch (PINC) value of 12 (0b00001100), then the last
(and only) line on the console will be:
00110000
The OUSB PORTB output will be: 12 (0b00001100)


F3.	For the situation where TWO command line arguments are passed to your program:

F3.1	If the second argument is "c1", your program must compare the rounded value (to the
nearest integer) of the input argument with the value of the DIP switches connected to PINC
of the OUSB Board. Whichever value is larger should then be written to PORTB (LEDs) of the
OUSB Board. The value should also be displayed to the console window using the reverse binary
representation of an 8 character long string (i.e. Bit0, Bit1, Bit2, Bit3, Bit4, Bit5,
Bit6, Bit7 with no commas or spaces) followed by a new line character and return 0;
and exit.

F3.2	If the second argument is "c2", your program must compare the rounded value (to the
nearest integer) of the input argument with the value of the potentiometer connected to
PORTA of the OUSB Board using the 'ADC 5' command. As the ADC value is a 10-bit number
(i.e. 0 to 1023), you are required to convert it to an 8-bit number by dividing it by 4
to scale it within the range of 0 to 255. You must compare the adjusted value of the
potentiometer to the input argument number and whichever value is larger should then be
written to PORTB (LEDs) of the OUSB Board. The value should also be displayed to the console
window using the reverse binary representation of a 8 character long string (ie. Bit0,
Bit1, Bit2, Bit3, Bit4, Bit5, Bit6, Bit7 with no commas or spaces) followed by a new line.
The code must return 0 and subsequently exit.

Example 4: lab3_1234567.exe 22 c2
Given a simulated OUSB potentiometer (ADC 5) value of 163, which when adjusted will be
163/4 = 40.75, the last (and only) line on the console will be:
00010100
The OUSB PORTB output will be: 40 (0b00101000)
NOTE: The division by 4 will result in the truncation of values after the decimal point.

F3.3	If the second argument is "c3", your program must compare the rounded value (to the
nearest integer) of the input argument with the value of the potentiometer connected to
PORTA of the OUSB Board using the 'ADC 5' command and the DIP switches connected to PINC
of the OUSB Board. As the ADC value is a 10-bit number (i.e. 0 to 1023), you are required to
convert it to an 8-bit number by dividing it by 4 to scale it within the range of 0 to 255
prior to making the comparison. You must compare the adjusted potentiometer value to the
other input numbers (PINC switches and command line argument) and whichever value is larger
should then be written to PORTB (LEDs) of the OUSB Board. The value should also be displayed
to the console window using the reverse binary representation of a 8 character long string
(i.e. Bit0, Bit1, Bit2, Bit3, Bit4, Bit5, Bit6, Bit7 with no commas or spaces) followed by
a new line character. The code must return 0 and subsequently exit.

Example 5: lab3_1234567.exe 185 c3
Given a simulated OUSB DIP Switch (PINC) value of 57 (0b00111001) and a simulated OUSB
potentiometer (ADC 5) value of 292, the last (and only) line on the console will be:
10011101
The OUSB PORTB output will be: 185 (0b10111001)

Example 6: lab3_1234567.exe 56.6 c3
Given a simulated OUSB DIP Switch (PINC) value of 57 (0b00111001) and a simulated OUSB
potentiometer (ADC 5) value of 292, the last (and only) line on the console will be:
10010010
The OUSB PORTB output will be: 73 (0b01001001)

Example 7: lab3_1234567.exe 55.664 c3
Given a simulated OUSB DIP Switch (PINC) value of 57 (0b00111001) and a simulated OUSB
potentiometer (ADC 5) value of 80, the last (and only) line on the console will be:
10011100
The OUSB PORTB output will be: 57 (0b00111001)

F3.4	If the second argument is "c4", your program must compare the rounded value (to the
nearest integer) of the input argument with the value of the potentiometer connected to
PORTA of the OUSB Board using the 'ADC 5' command and the DIP switches connected to PINC
of the OUSB Board. As the ADC value is a 10-bit number (i.e. 0 to 1023), you are required
to convert it to an 8-bit number by dividing it by 4 to scale it within the range of 0 to
255 prior to making the comparison. You must compare the adjusted potentiometer value to
the other input numbers (PINC switches and command line argument) and whichever value is
larger should then be written to PORTB (LEDs) of the OUSB Board. The value should also be
displayed to the console window using conventional binary representation in an 8 character
long string (ie. Bit7, Bit6, Bit5, Bit4, Bit3, Bit2, Bit1, Bit0 with no commas or spaces)
followed by a new line character. The code must return 0 and subsequently exit.

Example 8: lab3_1234567.exe  55.664 c4
Given a simulated OUSB DIP Switch (PINC) value of 57 (0b00111001) and a simulated OUSB
potentiometer (ADC 5) value of 80, the last (and only) line on the console will be:
00111001
The OUSB PORTB output will be: 57 (0b00111001)

Example 9: lab3_1234567.exe  55.664 c4
Given a simulated OUSB DIP Switch (PINC) value of 13 (0b00001101) and a simulated OUSB
potentiometer (ADC 5) value of 148, the last (and only) line on the console will be:
00111000
The OUSB PORTB output will be: 56 (0b00111000)


F4.	For situations where more than TWO command line arguments are passed to
your program, your program must display the character 'P' to the console with
a new line character, return 0 and exit. The value of the PORTB register on the
OUSB Board should remain unchanged.

F5.	For specifications F1 to F4 inclusive:

F5.1	Program must return 0 under all situations at exit once it has completed the 
required operations.


F5.2	The first input argument must be a valid number between 0 and 255 input as a
floating point number. This number will need to be rounded to the nearest integer
(i.e. the value 3.4 will be rounded to 3 and 3.5 will rounded to 4) when using the
number to complete comparison and output operations.

F5.3	Program must write only the cast or converted equivalent unsigned 8-bit absolute
integer representation of the result produced by the arithmetic/decision operation to the
PORTB register (LEDs) of the OUSB Board and console output operations.

F5.4	If the result to be written to PORTB of the OUSB Board is above 255 (0xFF), the
value 255 (or 0xFF) should be written to the board instead.

Hint: Consider using a (int) casting operation to truncating the value after the
decimal point.

Hint: Consider using the round() C++ library function to round up input arguments.

Hint: Consider using the strlen() C++ library function to determine the length of a
null terminated string so you can work out how many '0''s to pad your console output with.
*/
/*
___________________________________________________________________________________________
___ ERROR HANDLING:

The following text lists errors you must detect and a priority of testing.
Note: order of testing is important as each test is slightly more difficult than
the previous test (depending on how you structure your code solution).

E1. Error precedence:
Theoretically errors can be checked in any order, however if multiple errors occur during
a program execution event, your program should only display one error code followed by a
newline character and then exit (with a return 0). The displayed error codes to the console
window should occur in this order:
	'P' - Incorrect number of input command line arguments
	'X' - Invalid numerical command line argument
	'R' - command line argument out of range
	'V' - Invalid operation selection
	'H' - Out of range OUSB number returned by 'PINC' or 'ADC 5' command (i.e. an unexpected
          number was returned from the OUSB Board)
	'Y' - MURPHY'S LAW (undefined error)
Therefore if an invalid numerical command line argument and an invalid operation argument
are passed to the program, the first error code should be displayed to the console, which
in this case would be 'X'. Displaying 'V' or 'Y' would be result in a loss of marks.

E2.	Valid operator input:
If the second command line input argument is not a valid operation selection, the output
shall be 'V'. Valid operators are ONLY (case sensitive):
	- "c1"  compare argument to OUSB Board switches (default)
	- "c2"  compare argument to OUSB Board potentiometer
	- "c3"  compare OUSB Board switches, potentiometer and console input arguments.
	- "c4"  compare OUSB Board switches, potentiometer and console arguments.
		    (however display the console binary output in MSB -> LSB order)

E3.	Basic invalid number detection:
Valid numbers are all numbers that the "average Engineering graduate" in Australia
would consider valid. Therefore if the first command line argument is not a valid number,
the output shall be 'X'. For example:	
	013			is valid
	+3			is valid
	.3			is valid
	ABC123		is not valid
	1.3.4		is not valid
	123abc		is not valid

E4.	Intermediate invalid number detection:
If the first command line argument is not a valid number, the output shall be 'X'.
Using comma punctuated numbers and scientific formatted numbers are considered valid.
For example:
	92.000  	is valid
	3,000		is valid	  - NB: atof() will read this as '3' not as 3000
	+1.23e+2	is valid
	2E2			is valid
	1,000.9		is valid
	+1.23e+2.0	is not valid  - NB: value after 'e' or 'E' must be an integer
	e-1			is not valid
	.e3			is not valid

E5.	Advanced invalid number detection:
If the first command line argument cannot be rounded to a valid integer the output shall be 'X'.
	+212+21-2	is not valid - NB: mathematical operation on a group of numbers, not ONE number
	5/2			is not valid - NB: mathematical operation on a number of numbers, not ONE number

HINT:  consider the function atof(), which has the definition:   double atof (const char* str);
Checking the user input for multiple operators (i.e. + or -) is quite a difficult task.
One method may involve writing a 'for' loop which steps through the input argv[] counting
the number of operators. The multiple operator check should be considered an advanced task and
developed once the rest of the code is operational.

E6. Input number range checking:

E6.1 If the value of the first command line argument is greater than 255 or less than 0
the output shall be 'R'. Zero is a valid input.
For example:
	0			is valid
	+1.5e-5		is valid
	85.0		is valid
	1.05e2		is valid
	1.05e3		is not valid
	-45			is not valid
	450			is not valid

E6.2 All 8-bits of the PINC register on the OUSB Board (DIP switches) are valid. Therefore 0 to
255 will be valid inputs. If the hardware returns a value higher than 255 or less than 0 for
some reason then the output shall be 'H'. Similarly, if the 10-bit value reported by the
potentiometer (ADC 5) from the OUSB Board is outside the range of 0 - 1023 (inclusive), then output
shall be 'H'. In both cases PORTB should not be updated. Note: Keep in mind that the ousb.exe
Simulator processes the pinc.txt and p_ADC5.txt file before it passes data to the pipe, so you
need to work within its limitations too.

E7.	ousb.exe or simulated OUSB Board communication error

E7.1	If the pipe code communicating to the OUSB.exe file reports an issue with communication
to the simulated OUSB Board (or the simulator malfunctions), the output shall be 'Y'. This type 
of error is typical when a firmware error, power supply issue or the USB cable between the PC
and the OUSB Board is disconnected. Under one of these conditions, the real OUSB.exe that
communicates to the physical OUSB board (as was the process in 2019) will give a message:
		Fatal Exception!
		USB Error #: 0
		USB Error Text : No USB error
		SRUSB Error # : 1
		SRUSB Error Text: Device not found

This message should NOT be returned by your code. The only output your code should give is
the single character, 'Y' which is the same as the return character as the MURPHY'S LAW TEST
below.

Note: The ousb.exe simulator file provided on the Canvas shell can be used to simulate a
hardware error by passing the -disconnect argument to it. For example the following command:
		ousb -disconnect
	  
Will produce the output:
		Fatal Exception!
		USB Error #: 0
		USB Error Text : No USB error
		SRUSB Error # : 1
		SRUSB Error Text: Device not found

Your code should be able to detect such an error when used in normal operation with a defective
OUSB Board. That is, for example, if your code was executing the following pipe command to a
DEFECTIVE OUSB board:
		ousb -r io portb

The output of your program should be:
Y

This would only be the case if the OUSB Board was defective. To test for this it is recommended
you use -disconnect argument to generate the error and write your program in a way that when
it receives a "Fatal Exception!" return, it handles it as a MURPHY'S output, i.e. output 'Y' and
exit by returning 0. 

E7.2	If the pipe code communicating to the OUSB.exe file reports that the ousb.exe file
is missing the operating system will likely achieve this by returning an error message like:
"'ousb' is not recognized as an internal or external command, operable program or batch file."
In this situation your program should handle this as a MURPHY'S output, i.e. output 'Y' and
exit by returning 0. In this situation only the last character of the output will be tested.

E8.	ANYTHING ELSE THAT CAN GO WRONG (MURPHY'S LAW TEST):
If there are any other kinds of errors not covered here, the output shall be 'Y'.
As an example, the type of error that could be considered here would be:
	- no OUSB Board connection (i.e. Fatal Exception! error),
	- missing ousb.exe file - what happens when you attempt to run the ousb.exe 
	  file and it doesn't exist?
	- disconnection during operation
	- Hardware dead.
	- anything else Murphy can dream up.
	- everything else that has not been covered elsewhere is Murphy's domain.

Rhetorical question: What for example the OUSB board fails to respond, i.e is disconnected?
If this happens then the output	shall be 'Y'.

E9. Errors that will not be considered (and hence no score awarded).
	1,00.0		will not be tested (comma placement). This should be treated as: 100.0
	10,00.1		will not be tested (comma placement). This should be treated as: 1000.1

*/
/*
___________________________________________________________________________________________
___ More HINTS:

- 	If in doubt, check your solutions behaviour against the compiled sample binary (executable)
provided on the EEET2246 Canvas Shell.

-	Use debug mode and a breakpoint at the return statement prior to program
finish in main.

-	What string conversion routines do you know that convert strings to numbers?
Look carefully as they will be needed to convert a command line parameter to a number and
also check for errors.

-	ERROR CHECKING: The basic programming rules are simple (as covered in lectures):
1) check that the input is valid.
2) check that the output is valid.
3) if any library function returns an error code USE IT !!! CHECK FOR IT !!!

-	Most conversion routines do have inbuilt error checking - USE IT !!!
That means: test for the error condition and take some action if the error is true.
If that means more than 70% of your code is error checking, then that's
the way it has to be.

- Tackle the easiest tasks first and build your program up in stages.

- OUSB commands that might be useful for this program:
To read the value at port B:					ousb -r io portb
To write 20 to port B:  						ousb -r io portb 20
To read the value of the DIP switches (pinc):	ousb -r io pinc
To read the potentiometer (ADC 5):				ousb -r adc 5

- Description of _itoa_s() library function - Converts an integer to a string.
Prototype:
           errno_t _itoa_s(int value, char *buffer, int radix);
Parameters: 
[in]  value  - Number to be converted.
[out] buffer - buffer is filled with the result of the conversions a C string.
[in]  radix  - Base of value, which must be in the range of 2-36.
Return Value - Zero if successful; an error code on failure.


- Description of strcpy_s() library function - Copies a C string.
Prototype:
           errno_t strcpy_s(char *strDestination, const char *strSource);
Parameters: 
strDestination - Location of the destination string buffer.
strSource      - Null-terminated source string buffer.
Return Value   - Zero if successful; an error code on failure.


- Description of strcat_s() library function - Appends a C string.
Prototype:
           errno_t strcat_s(char *strDestination, const char *strSource);
Parameters: 
strDestination - Null-terminated destination string buffer.
strSource      - Null-terminated source string buffer.
Return Value   - Zero if successful; an error code on failure.


- The following code is the syntax required to open a pipe to the device.
It may / may not include all of the necessary code to complete the task.

//----Start of template standalone .cpp file--------------------------------------------
	#include <iostream>
	#define Debug 1
	using namespace std;
	int main(int argc, char* argv[])
	{
		char command[256] = {};
		strcpy_s(command, "ousb -r io PORTB 20"); // command to write 20 to OUSB board

		FILE *fpipe;
		char line[250] = {}; // size of Line should be smaller than command

		fpipe = (FILE*)_popen(command,"r");    // attempt to open pipe and execute a command
		if( fpipe != NULL )					   // check that the pipe opened correctly
		{
			while( fgets(line, sizeof(line), fpipe) )
			{   // do nothing here, or print out debug data
				if (Debug) cout << line; // print out OUSB data for debug purposes
			}
			_pclose(fpipe);   // close pipe
		}
		else cout << "Error, problems with pipe!\n";

		// do something with the value returned by the OUSB board, eg:
		int portb = atoi(line); // convert from char array to unsigned short
		cout << "value = " << portb << endl;

		return 0;
	}
//----End of template standalone .cpp file----------------------------------------------
____________________________________________________________________________________________
*/
// These are the libraries you are allowed to use to write your solution. Do not add any
// additional libraries as the auto-tester will be locked down to the following:
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include <errno.h>   
#include <string>
#include <sstream>
// Do NOT Add or remove any #include statements to this project!!
// All library functions required should be covered by the above
// include list. Do not add a *.h file for this project as all your
// code should be included in this file.

using namespace std;

const double MAXRANGE = 255;
const double MINRANGE = 0;

// All functions to be defined below and above main()  - NO exceptions !!!  Do NOT
// define function below main() as your code will fail to compile in the auto-tester.



// WRITE YOUR FUNCTION PROTOTYPES HERE (OPTIONAL, however if you write lots of functions
// having a prototype list will mean that they can be written in any order)



// WRITE ANY USER DEFINED FUNCTIONS HERE (optional)

bool ArgumentCheck(int argc, char* argv[], char* pointer)
{

	bool boolTest = false;
	int dotCount = 0;
	char PreviousChar = 0;
		
		for (int j = 0; argv[1][j] != '\0'; j++)
		{
			for (int k = 0; *(pointer + k) != '\0'; k++)
			{

				if (argv[1][j] == *(pointer + k))
				{
					boolTest = true;
					continue;
				}

			}

			if (argv[1][j] == '.')
			{
				if (dotCount > 0 || j == 0)
				{
					boolTest = false;
				}
				else
				{
					dotCount++;
				}
			}

			if (argv[1][j] == '+')
			{
				if (j == 0 || PreviousChar == 'e' || PreviousChar == 'E')
				{

				}
				else
					boolTest = false;
				
			}

			if (argv[1][j] == 'e')
			{
				if (j == 0 || PreviousChar == 'e' || PreviousChar == 'E' || PreviousChar == '+' || PreviousChar == '-' || PreviousChar == '.')
					boolTest = false;


			}

			if (boolTest == true)
			{
				boolTest = false;
				PreviousChar = argv[1][j];
			}
			else
				return false;

		}
	return true;
}

bool RangeCheck(int Argument)
{

	if (Argument >= 0 && Argument <= 255)
	{
		return true;
	}
	else
		return false;

}

unsigned int ReadPinC()
{
	int pinc = 0;
	char line[255] = {};	// array to hold received data from the OUSB board
	FILE* fpipe;			// file variable, see text book module 11.
	char command[255] = { "ousb -r io PINC" };

	// pipe code that sends out the current Command stored in the command variable
	fpipe = (FILE*)_popen(command, "r");
	if (fpipe != NULL)
	{
		while (fgets(line, sizeof(line), fpipe))
		{
			// do nothing, or print out debug data
			//cout << "Debug line: " << line; // print out OUSB data
		}
		_pclose(fpipe);
	}

	// convert value from char array to int	
	pinc = (unsigned int)atoi(line);
	// Mask pinc value for bottom 8-bit only.
	pinc = pinc & 0x00FF;
	return pinc;
}

unsigned int WritePortB(unsigned int val)
{
	if (val > 255)
	{
		val = 255;
	}
	char line[255] = {};	// array to hold received data from the OUSB board
	FILE* fpipe;			// file variable, see text book module 11.
	char command[255] = { "ousb -r io PORTB " }; // Need to have a extra space after PORTB
	char val_string[4] = {};

	//Convert integer (in base 10) to character
	_itoa_s(val, val_string, 10);
	// append the value to the Command string
	strcat_s(command, val_string);

	// pipe code that sends out the current Command stored in the command variable
	fpipe = (FILE*)_popen(command, "r");
	if (fpipe != NULL)
	{
		while (fgets(line, sizeof(line), fpipe))
		{
			// do nothing, or print out debug data
			//cout << "Debug line: " << line; // print out OUSB data
		}
		_pclose(fpipe);
	}

	// convert value from char array to int	
	unsigned int portb = (unsigned int)atoi(line);
	return portb;
}

int ReadADC()
{

	// Only one of the below command lines can be used. At the moment it is setup for the Physical Board
	   // The command used on both lines requests that the number 20 be written to PORTB of the OUSB board
	char command[255] = "ousb -r adc 5";   	// Use this line if using the Physical OUSB Board
  //char command[255] = "ousbsim -r io PORTB 20";   // Use this line if using the OUSB simulator

	FILE* fpipe;									// Create a File pipe pointer
	char line[1024] = {};							// Declare some memory to hold the reply message

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

	//cout << portb << endl;

	return portb;
}

void ArrayReverse(int Output)
{
	int a[10] = {};
	int n, i, reps;
	n = Output;
	for (i = 0; n > 0; i++)
	{
		a[i] = n % 2;
		n = n / 2;
		reps = i;
	}
	for (i = 0; i < 8; i++)
	{
		cout << a[i];
	}
	cout << endl;
	
}

void ArrayOutput(int Output)
{
	int a[8] = {};
	int n, i, reps;
	n = Output;
	for (i = 0; n > 0; i++)
	{
		a[i] = n % 2;
		n = n / 2;
		reps = i;
	}
	for (i = 7; i >= 0; i--)
	{
		cout << a[i];
	}
	cout << endl;
}

// all function definitions and prototypes to be defined above this line - NO exceptions !!!
int main(int argc, char *argv[])
{ 
	// ALL CODE (excluding variable declarations) MUST come after the following 'if' statement
	if (argc == 1)
	{
		// When run with just the program name (no parameters) your code  MUST print 
		// student ID string in CSV format. i.e.
		// "studentNumber,student_email,student_name"
		// eg: "2345678,s2345678@student.rmit.edu.au,FirstName_LastName"

		// Edit string below: eg: "studentNumber,student_email,student_name"
		cout << "3842062,s3842062@student.rmit.edu.au,Ethan_Haberl" << endl;

		// The convention is to return Zero to signal NO ERRORS (please do not change it).
		return 0;
	}
	//--- START YOUR CODE HERE.
	char ValidCharacters[] = ".+eE0123456789";
	char* pointer = ValidCharacters;

		int s = 0;

		for (int i = 0; i < strlen(argv[1]); i++)
		{
			if (argv[1][i] == ',')
			{
				continue;
			}
			else
			{
				argv[1][s] = argv[1][i];
				s++;
			}
		}
		argv[1][s] = '\0';
				
	if (argc == 2)
	{
		
		if (ArgumentCheck(argc, argv, pointer) != true)
		{
			cout << "X" << endl;
			return 0;
		}
		if (RangeCheck(atof(argv[1])) != true)
		{
			cout << "R" << endl;
			return 0;
		}

		if (round(atof(argv[1])) > ReadPinC())
		{
			WritePortB(round(atof(argv[1])));

			ArrayReverse(round(atof(argv[1])));
		}
		else
		{
			WritePortB(ReadPinC());

			ArrayReverse(ReadPinC());
		}


	}
	else if (argc == 3)
	{
		if (ArgumentCheck(argc, argv, pointer) != true)
		{
			cout << "X" << endl;
			return 0;
		}
		if (RangeCheck(atof(argv[1])) != true)
		{
			cout << "R" << endl;
			return 0;
		}
		
		if (strcmp(argv[2], "c1") == 0)
		{

			if (round(atof(argv[1])) > ReadPinC())
			{
				WritePortB(round(atof(argv[1])));

				ArrayReverse(round(atof(argv[1])));
			}
			else
			{
				WritePortB(ReadPinC());

				ArrayReverse(ReadPinC());
			}

		}
		else if (strcmp(argv[2], "c2") == 0)
		{

			if (round(atof(argv[1])) > (ReadADC()/4))
			{
				WritePortB(round(atof(argv[1])));

				ArrayReverse(round(atof(argv[1])));
			}
			else
			{
				WritePortB(ReadADC()/4);

				ArrayReverse(ReadADC()/4);
			}

		}
		else if (strcmp(argv[2], "c3") == 0)
		{

			if (round(atof(argv[1])) > (ReadADC() / 4) && round(atof(argv[1])) > ReadPinC())
			{
				WritePortB(round(atof(argv[1])));

				ArrayReverse(round(atof(argv[1])));
			}
			else if ((ReadADC()/4) > round(atof(argv[1])) && (ReadADC()/4) > ReadPinC())
			{
				WritePortB(ReadADC() / 4);

				ArrayReverse(ReadADC() / 4);
			}
			else if (ReadPinC() > (round(atof(argv[1]))) && ReadPinC() > (ReadADC() / 4))
			{
				WritePortB(ReadPinC());

				ArrayReverse(ReadPinC());
			}

		}
		else if (strcmp(argv[2], "c4") == 0)
		{

			if (round(atof(argv[1])) > (ReadADC() / 4) && round(atof(argv[1])) > ReadPinC())
			{
				WritePortB(round(atof(argv[1])));

				ArrayOutput(round(atof(argv[1])));
			}
			else if ((ReadADC() / 4) > round(atof(argv[1])) && (ReadADC() / 4) > ReadPinC())
			{
				WritePortB(ReadADC() / 4);

				ArrayOutput(ReadADC() / 4);
			}
			else if (ReadPinC() > (round(atof(argv[1]))) && ReadPinC() > (ReadADC() / 4))
			{
				WritePortB(ReadPinC());

				ArrayOutput(ReadPinC());
			}

		}
		else
			cout << "V" << endl;
	}
	else
		cout << 'P' << endl;

	// The convention is to return Zero to signal NO ERRORS (please do not change it).
	// If you change it the AutoTester will assume you have made some major error. 
	return 0;
}  // No code to be placed below this line - all functions to be defined above main() function.
   // End of file. 

   
   
 

