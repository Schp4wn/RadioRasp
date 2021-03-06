#include <iostream>
#include <cmath>
#include <wiringPi.h>
#include <unistd.h>

using namespace std;
int pin;
int identifier;
int button;
int state;

static int show_usage(string name)
{
	cout << "Usage: " << name << " pin identifier button state" << "\n"
	     << "Send and emit radio signal with Raspberry."
	     << endl;
	return 1;
}

static void log(string a)
{
	cout << a << endl;
}

string itob(int integer, int length) {
	string result;
	for (int i = 0; i < length; i++) {
		if ((integer / pow(2, length - 1 - i)) >= 1) {
			integer -= pow(2, length - 1 - i);
			result += "1";
		} else {
			result += "0";
		}
	}

	return result;
}

int main (int argc, char* argv[])
{
	if (getuid() > 0) {
		log("You must run this tool as root.");
		return 1;
	}

	if (argc != 5) {
		show_usage(argv[0]);
	}
	
	pin = atoi(argv[1]);
	identifier = atoi(argv[2]);
	button = atoi(argv[3]);
	string a4 = argv[4];
	state = (a4 == "on" || a4 == "1") ? 1 : 0;

	if (wiringPiSetup() == -1) {
		log("RadioRasp needs WiringPi library to work.");
		return 1;
	}

	pinMode(pin, OUTPUT);
	log("Pin " + to_string(pin) + " configured in output mode.");
	
	log(itob(identifier, 26) + "0" + to_string(state) + itob(button, 4));
}
