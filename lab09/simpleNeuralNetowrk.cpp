// ref: https://medium.com/technology-invention-and-more/how-to-build-a-simple-neural-network-in-9-lines-of-python-code-cc8f23647ca1

#include <iostream>
#include <cmath>

using namespace std;
double weights[3] = { -0.16595599, 0.44064899, -0.99977125 };
double input[4][3] = {
	{0, 0, 1},
	{1, 1, 1},
	{1, 0, 1},
	{0, 1, 1}
};
double output[4] = { 0,1,1,0 };
double errors[4];
double guess[4];
double problem[3] = {1, 0, 0};
double adjust[3];


void printWeights(void) {
	cout << "weights : ";
	for (int i = 0; i < 3; i++)
	{
		cout << weights[i] << ",";
	}
	cout << endl;
}

void printAdjust(void) {
	cout << "adjust : ";
	for (int i = 0; i < 3; i++)
	{
		cout << adjust[i] << ",";
	}
	cout << endl;
}

void printErrors(void) {
	cout << "errors : ";
	for (int i = 0; i < 4; i++)
	{
		cout << errors[i] << ",";
	}
	cout << endl;
}


void printGuess(void) {
	cout << "guess : ";
	for (int i = 0; i < 4; i++)
	{
		cout << guess[i] << ",";
	}
	cout << endl;
}

double weight_sum(double x[], double y[], int n) {
    double sum = 0.0;
	for (int i = 0; i < n; i++)
	{
		sum += x[i] * y[i];
	}
	return sum;
}


int main() {
	

	for (long int k=0; k < 1; k++) {
		//printWeights();

		for (int i = 0; i < 4; i++) {
			double x;
			x = weight_sum(input[i], weights, 3);
			cout << x << ",";
			guess[i] = 1 / (1 + exp(-x));
		}
		cout << endl;
		printGuess();
		// cal errors
		for (int i = 0; i < 4; i++)
		{
			errors[i] = output[i] - guess[i];
		}
		printErrors();

		for (int j = 0; j < 3; j++) {
			adjust[j] = 0;
			for (int i = 0; i < 4; i++)
			{
				adjust[j] += input[i][j] * errors[i] * guess[i] * (1 - guess[i]);
			}
		}
		printAdjust();
		for (int j = 0; j < 3; j++) {
			weights[j] += adjust[j];
		}


	} // end of iteration of k
	printWeights();
	printGuess();

	double y;
	for (int i = 0; i < 4; i++) {
		double x;
		x = weight_sum(problem, weights, 3);
		cout << x << endl;
		y = 1 / (1 + exp(-x));

	}
	cout << "guess [1,0,0] is " << y << endl;

	return 0;
}
