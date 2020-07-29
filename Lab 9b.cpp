/* Programmer: Drew Welbourn
Lab: 9b
Purpose: Calculate MPG for the fleet
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

double milesD(double, double, double);


int main()
{
	int car = 0, miles = 0, gas = 0;
	double mpg = 0;
	ifstream inFile;

	inFile.open("C:\\Users\\Drew\\Desktop\\Cars.txt");

	// Test if file opens correctly; if not EXTERMINATE

	if (inFile.fail())
	{
		cout << "File Read Error";
		exit(1);
	}

	cout << fixed << showpoint << setprecision(2);
	cout << setw(15) << "Car Number" <<
		setw(15) << "Miles Driven" <<
		setw(15) << "Gallons Used" <<
		setw(20) << "Miles Per Gallon" << endl;

	//Read from the file until it reaches end of the file

	while (!inFile.eof())
	{
		inFile >> car >> miles >> gas;
		mpg = milesD(gas, miles, mpg);

		cout << setw(11) << car <<
			setw(15) << miles <<
			setw(15) << gas <<
			setw(17) << mpg << endl;
	}

	inFile.close();

	return 0;

}

double milesD(double gas, double miles, double mpg) // Calculates Miles Per Gallon
{

	mpg = miles / gas;


	return mpg;
}