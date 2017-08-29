/*
 * Formula obtained at https://en.wikipedia.org/wiki/Trajectory_of_a_projectile*/
#include <clocale>
#include <iostream>
#include <cmath>
#include <stdlib.h>

using namespace std;

#define thetaAngle 233
#define square 253

char theta = thetaAngle;
char superScriptTwo = square; //ascii value of super script two
int mainMenu;

//Function prototype
void notation();
void finalPosition();

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
			break;
	}
}

