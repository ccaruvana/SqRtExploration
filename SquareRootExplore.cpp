#include <iostream>
#include <cmath>

using namespace std;

// Function declarations

double long firstSquareRoot (double long, int);

// The main code

int main () {

long double input, approx;
int precis;

input = 0;

while (input <=0) {
	cout << "Please input a positive number: ";
	cin >> input;
}

cout << "Please input your desired precision: ";
cin >> precis;

int d[precis];

int intpart = 1;

while ((intpart+1)*(intpart+1) <= input) {
	intpart++;
}

approx = intpart;

double long inputMod = input;

for (int j=0; j < precis; j++) {
	int temp = 0;
	while (temp <= 9 && (10*approx+temp+1)*(10*approx+temp+1) <= 100*inputMod) {
		temp++;
	}
	d[j]=temp;
	approx = 10*approx + temp;
	inputMod *= 100;
}

cout << "Calculation 1: " << firstSquareRoot(input,precis) << endl;
cout << "Calculation 2: " << intpart << ".";
for (int j=0; j < precis; j++) {
	cout << d[j];
}
cout << endl << "The standard sqrt function: " << sqrt(input) << endl;

return 0;
}

// Function definitions

double long firstSquareRoot (double long x, int y) {
	long double approx;

	int intpart = 1;

	while ((intpart+1)*(intpart+1) <= x) {
		intpart++;
	}

	approx = intpart;

	for (int j=1; j <= y; j++) {
		int temp = 0;
		while (temp <= 9 && (approx+((temp+1)/(pow(10,j))))*(approx+((temp+1)/(pow(10,j)))) <= x) {
			temp++;
		}
		approx = approx + (temp/pow(10,j));
	}

	return approx;
}
