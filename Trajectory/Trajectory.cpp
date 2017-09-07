/*
 * Formula obtained at https://en.wikipedia.org/wiki/Trajectory_of_a_projectile*/
#include <clocale>
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <fstream>

using namespace std;

#define thetaAngle 233
#define square 253

char theta = thetaAngle;
char superScriptTwo = square; //ascii value of super script two
int mainMenu;

//Function prototype
void notation();
void finalPosition();
void distanceTraveled(double velocity, double angle, double acceleration, double y0);
void timeOfFlight(double distance, double veolocity, double angle);
void fileWriting(string fileName, double answer);

void menu() {
	
	cout << "Menu: " << endl;
	cout << "Press 0 for debugging mode" << endl;
	cout << "Press 1 for Notation"<< endl;
	cout << "Press 2 for Conditions at the final position of the projectile" << endl;
	cout << "Press 3 for Conditions at an arbitrary distance x" << endl;
	cout << "Press 4 for Angle " << theta << " required to hit coordinate (x,y)" << endl;
	
}


int main() {
	
	menu();
	cin >> mainMenu;
	cout << " " << endl;
	switch (mainMenu) {
		case 0:
			cout << "debugging mode" << endl;
			break;
		case 1:
			notation();
			break;
		
		case 2:
			finalPosition();
			break;
	}
	return 0;
}
void notation() {
	
	cout << "Notation" << endl;
	cout << "g: the gravitational acceleration - usually taken to be 9.81 m/s" << superScriptTwo << " near the Earth's surface" << endl;
	cout << theta << ": the angle at which the projectile is launched" << endl;
	cout << "v: the speed at which the projectile is launched" << endl;
	cout << "y0:  the initial height of the projectile" << endl;
	cout << "d: the total horizontal distance traveled by the projectile" << endl;
	cout << "Press 77 to return to the main menu" << endl;
	cout << "Press q to exit the program" << endl;
	cin >> mainMenu;
	switch (mainMenu) {
		case 77:
			cout << "Returning to the main menu" << endl;
			main();
			break;
		case 'q':
			exit(EXIT_SUCCESS);
			break;
			
	}

}

void finalPosition() {
	int choice;
	double velocity;
	double angle;
	double acceleration;
	double y0;
	double distance;
	
	cout << "Press 1 for distance traveled" << endl;
	cout << "Press 2 for time of flight" << endl;
	cout << "Press 3 for Angle of reach" << endl;
	cin >> choice;
	switch (choice) {
		case 1:
			cout << "The formula is :" << endl;
			cout << "d = vcos" << theta << "/g (vsin" << theta << " + sqt( (vsin" << theta <<")" << superScriptTwo << " + 2gy0))" << endl;
			cout << "* initial height of the projectile should be 0 in most cases" << endl;
			cout << "* maximum distance is obtained if " << theta << " is 45 degrees" << endl;
			cout << "Please enter the velocity at which the projectile is launched" << endl;
			cin >> velocity;
			
			cout << "Please enter the angle" << endl;
			cin >> angle;
			
			cout << "Please enter the gravitational acceleration" << endl;
			cin >> acceleration;
			
			cout << "Please enter the initial height of the projectile" << endl;
			cin >> y0;
			
			distanceTraveled( velocity,  angle,  acceleration, y0);
			
			break;
	
		case 2:
			cout << "The forumula is :" << endl;
			cout << "t = d/vcos" << theta << "/g" << endl;
			
			cout << "Please enter the distance traveled" << endl;
			cin >> distance;
			
			cout << "Please enter the velocity at which the projectile is launched" << endl;
			cin >> velocity;
			
			cout << "Please enter the angle" << endl;
			cin >> angle;
			
			break;
	}
}	
void distanceTraveled(double velocity, double angle, double acceleration, double y0) {
	double firstPart = ( velocity * cos(angle));
	double secondPart = velocity * sin(angle) + sqrt(pow(velocity * sin(angle),2 ) + 2 * acceleration * y0);
	
	double answer = firstPart * secondPart;
	
	cout << "The answer is " << answer << endl;
	cout << "Writing the result to distanceTravel.txt" << endl;
	
	fileWriting("distanceTraveled", answer);
	cout << "Press 77 to return to the main menu" << endl;
	cout << "Press q to exit the program" << endl;
	cin >> mainMenu;
	switch (mainMenu) {
		case 77:
			cout << "Returning to the main menu" << endl;
			main();
			break;
		case 'q':
			exit(EXIT_SUCCESS);
			break;
			
	}
}
void timeOfFlight(double distance, double veolocity, double angle){
	doube answer = distance / (velocity * cos(angle));
	cout << "The answer is " << answer << endl;
	cout << "Writing the result to timeOfFlight.txt" << endl;
}

void fileWriting(string fileName, double answer) {
	ofstream myfile;
	myfile.open(fileName + ".txt");
	myfile << "The answer to the " << fileName << ": " << answer << endl;
	myfile.close(); 
}



