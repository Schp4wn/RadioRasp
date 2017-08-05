#include <iostream>
#include <cmath>

using namespace std;
int pin;
int sender;
int module;
string state;

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

int main (int argc, char** argv)
{
	pin = atoi(argv[1]);
	sender = atoi(argv[2]);
	module = atoi(argv[3]);
	state = argv[4];

	cout << itob(sender, 26) << "0" << state << itob(module, 4) << endl;
}
