/*  
  internetBill.cpp
  Programmer: Ronald Baasland
  Created on: October 11, 2010
  Modified on: October 18, 2010
*/

#include <iostream> //for console input and output
#include <iomanip> // For manipulating the input/output such as setting numbers to two decimal places
#include <fstream> //For input and output to files
#include <string> //For using the string
#include <cctype> //Used to check things on a string, like isDigit
using namespace std;

//All the protocols for the functions
void validInput(string &,string &, char &, int &);
float optionA(int); 
float optionB(int);
float optionC(int);
void printBillConsole(string, string, char, int, float, float, float); 
void printToFile(string, string, char, int, float, float, float); 

int main()
{
	string month;
	string custNumber;
	char package;
	int hours;
	float optATotal;
	float optBTotal;
	float optCTotal;
	
	//Displays the months for the user to decide

    cout << "Select the month:" << endl;
    cout << "January" << endl;
    cout << "February" << endl;
    cout << "March" << endl;
    cout << "April" << endl;
    cout << "May" << endl;
    cout << "June" << endl;
    cout << "July" << endl;
    cout << "August" << endl;
    cout << "September" << endl;
    cout << "October" << endl;
    cout << "November" << endl;
    cout << "December" << endl;

    validInput(month, custNumber,package, hours); // Calls the validInput function and validates the input

	optATotal = optionA(hours); //Computes option A and saves it to the variable
	optBTotal = optionB(hours); //Computes option B and saves it to the variable
	optCTotal = optionC(hours); //Computes option C and saves it to the variable

	printBillConsole(month, custNumber, package, hours, optATotal, optBTotal, optCTotal); //Calls printBillConsole function and displays the bill in the console
	printToFile(month, custNumber, package, hours, optATotal, optBTotal, optCTotal); //Calls printToFile function and displays in a file

	system("pause");
	return 0;

} // End of Main

/* validInput
This function asks the user for its input, and then validadates the information.
*/


void validInput(string & month, string & custNumber, char & package, int & hours)
{

	bool valCustNumber;
	bool valInp = false;
	bool valMonth = false;
	char isLeapYear;
	int monthHours;
	
	//Validates the month to make sure it is correct. The first letter has to be capitalized. 
	do
	{
		cout <<"Enter the month of your bill (Enter the number corresponding to the month)" << endl;
		cin >> month;
		cout << endl;

		if (month == "January")
		{
			valMonth = true;
			monthHours = 1;
		}
		else if (month == "February")
		{
			valMonth = true;
			monthHours = 2;
		}
		else if (month == "March")
		{
			valMonth = true;
			monthHours = 3;
		}
		else if (month == "April")
		{
			valMonth = true;
			monthHours = 4;
		}
		else if (month == "May")
		{
			valMonth = true;
			monthHours = 5;
		}
		else if (month == "June")
		{
			valMonth = true;
			monthHours = 6;
		}
		else if (month == "July")
		{
			valMonth = true;
			monthHours = 7;
		}
		else if (month == "August")
		{
			valMonth = true;
			monthHours = 8;
		}
		else if (month == "September")
		{
			valMonth = true;
			monthHours = 9;
		}
		else if (month == "October")
		{
			valMonth = true;
			monthHours = 10;
		}
		else if (month == "November")
		{
			valMonth = true;
			monthHours = 11;
		}
		else if (month == "December")
		{
			valMonth = true;
			monthHours = 12;
		}
		else
		{
			valMonth = false;
		}

	}
	while(valMonth == false);
	
	// Checks to make sure the customer number is 8 digits
	do
	{
		valCustNumber = false;
		cout << "Enter your customer number and press return: " << endl;
		cin >> custNumber;
		cout << endl;

		if (custNumber.length() == 8)
		{
			for(int i = 0; i < custNumber.length(); i++)
			{
				if(isdigit(custNumber[i]))
					valCustNumber = true;
				else
					valCustNumber = false;
			}
		}
		else
			valCustNumber = false;
	}
	while (valCustNumber == false);

	bool valPackage = false;

	//Checks to make sure the service package is correct, case doesn't matter.
	do
	{
		cout << "Enter Service package (Select A, B, or C): ";
		cin >> package;
		cout << endl;

		switch(package)
		{
		case 'a':
		case 'A':
			valPackage = true;
			break;
		case 'b':
		case 'B':
			valPackage = true;
			break;
		case 'c':
		case 'C':
			valPackage = true;
			break;
		default:
			valPackage = false;
		}
	}
	while (valPackage == false);

	bool valHours = false;

	//Checks to make sure that the hours are valid for the month inputted
	do
	{
		cout << "Enter number of hours used: ";
		cin >> hours;
		cout << endl;

		switch(monthHours)
		{
		case 1:
			if (hours > 744)
			{
				valHours = false;
				cout << "Invalid Hours!" << endl;
			}
			 if (hours <= 744 && hours > 0)
				valHours = true;
			else
			{
				valHours = false;
				cout << "Invalid Hours!" << endl;
			 }
			 break;
		case 2:

			do
			{
				cout << "Is this a leap year? ( y or n) "<< endl;
				cin >> isLeapYear;
				
				if (isLeapYear == 'y' || isLeapYear == 'n')
					valInp = true;
				else
					valInp = false;
			}
			while(valInp == false);

			if (isLeapYear == 'y')
			{
				if (hours > 696)
				{
					valHours = false;
					cout << "Invalid Hours!" << endl;
				}
				if (hours <= 696 && hours > 0)
					valHours = true;
				else
				{
					valHours = false;
					cout << "Invalid Hours!" << endl;
				}
			}

			if (isLeapYear == 'n')
			{
				if (hours > 672)
				{
					valHours = false;
					cout << "Invalid Hours!" << endl;
				}
				if (hours <= 672 && hours > 0)
					valHours = true;
				else
				{
					valHours = false;
					cout << "Invalid Hours!" << endl;
				}
			}
			break;

		case 3:
			if (hours > 744)
			{
				valHours = false;
				cout << "Invalid Hours!" << endl;
			}
			 if (hours <= 744 && hours > 0)
				valHours = true;
			else
			{
				valHours = false;
				cout << "Invalid Hours!" << endl;
			 }
			break;
		case 4:
			if (hours > 720)
			{
				valHours = false;
				cout << "Invalid Hours!" << endl;
			}
			 if (hours <= 720 && hours > 0)
				valHours = true;
			else
			{
				valHours = false;
				cout << "Invalid Hours!" << endl;
			 }
			break;
		case 5:
			if (hours > 744)
			{
				valHours = false;
				cout << "Invalid Hours!" << endl;
			}
			 if (hours <= 744 && hours > 0)
				valHours = true;
			else
			{
				valHours = false;
				cout << "Invalid Hours!" << endl;
			 }
			 break;
		case 6:
			if (hours > 720)
			{
				valHours = false;
				cout << "Invalid Hours!" << endl;
			}
			 if (hours <= 720 && hours > 0)
				valHours = true;
			else
			{
				valHours = false;
				cout << "Invalid Hours!" << endl;
			 }
			 break;
		case 7:
			if (hours > 744)
			{
				valHours = false;
				cout << "Invalid Hours!" << endl;
			}
			 if (hours <= 744 && hours > 0)
				valHours = true;
			else
			{
				valHours = false;
				cout << "Invalid Hours!" << endl;
			 }
			 break;
		case 8:
			if (hours > 744)
			{
				valHours = false;
				cout << "Invalid Hours!" << endl;
			}
			 if (hours <= 744 && hours > 0)
				valHours = true;
			else
			{
				valHours = false;
				cout << "Invalid Hours!" << endl;
			 }
			 break;
		case 9:
			if (hours > 720)
			{
				valHours = false;
				cout << "Invalid Hours!" << endl;
			}
			 if (hours <= 720 && hours > 0)
				valHours = true;
			else
			{
				valHours = false;
				cout << "Invalid Hours!" << endl;
			 }
			 break;
		case 10:
			if (hours > 744)
			{
				valHours = false;
				cout << "Invalid Hours!" << endl;
			}
			 if (hours <= 744 && hours > 0)
				valHours = true;
			else
			{
				valHours = false;
				cout << "Invalid Hours!" << endl;
			 }
			 break;
		case 11:
			if (hours > 720)
			{
				valHours = false;
				cout << "Invalid Hours!" << endl;
			}
			 if (hours <= 720 && hours > 0)
				valHours = true;
			else
			{
				valHours = false;
				cout << "Invalid Hours!" << endl;
			 }
			 break;
		case 12:
			if (hours > 744)
			{
				valHours = false;
				cout << "Invalid Hours!" << endl;
			}
			 if (hours <= 744 && hours > 0)
				valHours = true;
			else
			{
				valHours = false;
				cout << "Invalid Hours!" << endl;
			 }
			 break;
		default:
			valHours = false;
		}

	}
	while (valHours == false);
} // End of validInput


// Computes the total for option A
float optionA(int hours)
{
	if (hours < 10)
		return 9.95;
	else
	{
		float total = 9.95;
		hours = hours - 10;
		total += hours * 2.00;
		return total;

	}
	
} //End of optionA function

//Computes the total for option B
float optionB(int hours)
{
	if (hours < 20)
		return 14.95;
	else
	{
		float total = 14.95;
		hours = hours - 20;
		total += hours * 1.00;
		return total;

	}
	
} //End of optionB function

//Computes the total for option C
float optionC(int hours)
{
	return 19.95;
} //End of optionC function

//Takes the validated input, and computes the bill and displays it in the console.
void printBillConsole(string month, string custNumber, char package, int hours, float optionATotal, float optionBTotal, float optionCTotal)
{
	string monthName;
	cout << "=============================================================" << endl;
	cout << "Monthly Internet Service Bill" << endl << endl;

	cout << "Month" << setw(56) << month << endl;
	cout << "Customer Account Number" << setw(38) << custNumber << endl;
	cout << "Service Package" << setw(46) << package << endl;
	cout << "Hours Used" << setw(51) << hours << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << fixed << showpoint << setprecision(2);

	//The if statements check to see if there are any savings if another package would be chosen. Then it displays the total and savings if there are any
	if(package == 'a' || package == 'A')
	{
		cout << "Total Bill:" << setw(44) << "$" << optionATotal << endl << endl;
		if(optionATotal > optionBTotal)
			cout << "Your monthly savings if your choose Package B is: " << setw(5) << "$" <<optionATotal - optionBTotal << endl;
		if(optionATotal > optionCTotal)
			cout << "Your monthly savings if your choose Package C is: " << setw(5) << "$" << optionATotal - optionCTotal << endl;

	}
	if(package == 'b' || package == 'B')
	{
		cout << "Total Bill:" << setw(44) << "$" << optionBTotal << endl << endl;
		if(optionBTotal > optionCTotal)
			cout << "Your monthly savings if your choose Package C is: " << setw(5) << "$" <<  optionBTotal - optionCTotal << endl;

	}
	if(package == 'c' || package == 'C')
		cout << "Total Bill:" << setw(44) << "$" << optionCTotal << endl << endl;


	
	cout << "=============================================================" << endl;


}

//Takes the validated input, and computes it to a file.
void printToFile(string month, string custNumber, char package, int hours, float optionATotal, float optionBTotal, float optionCTotal)
{
	ofstream dataOut;
	string filename;
	string monthName;

	//Sets the filename that the bill will be saved too
		if (month == "January")
			filename = "Jan" + custNumber;
		else if (month == "February")
			filename = "Feb" + custNumber;
		else if (month == "March")
			filename = "Mar" + custNumber;
		else if (month == "April")
			filename = "Apr" + custNumber;
		else if (month == "May")
			filename = "May" + custNumber;
		else if (month == "June")
			filename = "Jun" + custNumber;
		else if (month == "July")
			filename = "Jul" + custNumber;
		else if (month == "August")
			filename = "Aug" + custNumber;
		else if (month == "September")
			filename = "Sep" + custNumber;
		else if (month == "October")
			filename = "Oct" + custNumber;
		else if (month == "November")
			filename = "Nov" + custNumber;
		else if (month == "December")
			filename = "Dec" + custNumber;


	dataOut.open(filename); // opens a file naming it whatever "filename" is

	dataOut << "=============================================================" << endl;
	dataOut << "Monthly Internet Service Bill" << endl << endl;

	dataOut << "Month" << setw(56) << month << endl;
	dataOut << "Customer Account Number" << setw(38) << custNumber << endl;
	dataOut << "Service Package" << setw(46) << package << endl;
	dataOut << "Hours Used" << setw(51) << hours << endl;
	dataOut << "-------------------------------------------------------------" << endl;
	dataOut << fixed << showpoint << setprecision(2);


	//The if statements check to see if there are any savings, and then it prints the total bill, and any savings if there are any
	if(package == 'a' || package == 'A')
	{
		dataOut << "Total Bill:" << setw(44) << "$" << optionATotal << endl << endl;
		if(optionATotal > optionBTotal)
			dataOut << "Your monthly savings if your choose Package B is: " << setw(5) << "$" <<optionATotal - optionBTotal << endl;
		if(optionATotal > optionCTotal)
			dataOut << "Your monthly savings if your choose Package C is: " << setw(5) << "$" << optionATotal - optionCTotal << endl;

	}
	if(package == 'b' || package == 'B')
	{
		dataOut << "Total Bill:" << setw(44) << "$" << optionBTotal << endl << endl;
		if(optionBTotal > optionCTotal)
			dataOut << "Your monthly savings if your choose Package C is: " << setw(5) << "$" <<  optionBTotal - optionCTotal << endl;

	}
	if(package == 'c' || package == 'C')
		dataOut << "Total Bill:" << setw(44) << "$" << optionCTotal << endl << endl;


	dataOut << "=============================================================" << endl;

	dataOut.close(); // Closes the file

}
