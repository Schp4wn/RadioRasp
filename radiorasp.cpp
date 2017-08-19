#include <iostream>
#include <cmath>

using namespace std;
int pin;
int sender;
int module;
int state;

static void show_usage(string name)
{
	cout << "Usage: " << name << " PIN SENDER MODULE STATE" << "\n"
	     << "Send and emit radio code with Raspberry."
	     << endl;
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
	if (argc != 5) {
		show_usage(argv[0]);
		return 1;
	}
	
	pin = atoi(argv[1]);
	sender = atoi(argv[2]);
	module = atoi(argv[3]);
	string a4 = argv[4];
	state = (a4 == "on" || a4 == "1") ? 1 : 0;

	cout << itob(sender, 26) << 0 << state << itob(module, 4) << endl;
}
