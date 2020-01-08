#include "CmscnProblem.h"
#include <iostream>

using namespace std;

int main()
{
	CMSCN test(2, 3, 3, 5);
	
	test.fillCD();
	
	test.showCD();
	
	cout << "\n";
	
	test.setF(5);
	
	cout << "\n";
	
	test.showCD();
	
	cout << "\n";
	
	test.showCF();
	
	test.setF(-3);
	
	test.fillGivenCD(1, 1, -3);
	
	test.fillGivenCD(-1, 1, 3);
	
	test.fillGivenCD(1, 300, 3);
	
	CMSCN wrong(-2, 3, 6, 7);
	
	CMSCN test2(2, 3, 3, 5);
	
	test2.autofillall();
	
	double* result = new double[30];
	
	for (int i = 0; i < 30; i++) 
	
		result[i] = 100;
	
	double* result2 = new double[30];
	
	for (int i = 0; i < 6; i++)

		result2[i] = 400;
	
	for (int i = 6; i < 15; i++) 
		
		result2[i] = 200;
	
	for (int i = 15; i < 30; i++) 

		result2[i] = 100;
	
	cout << test2.dGetQuality(result, 30) << endl;
	
	cout << test2.dGetQuality(result2, 30) << endl;
	
	test2.save("visualization.txt");
	
	test2.load("visualization.txt");
	
	test2.save("visualization2.txt");
}