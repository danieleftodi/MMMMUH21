#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

int main ()
{

	cout << left << setfill (' ') << setw (18) << "Ludwig" << endl;
	cout << right << setfill (' ') << setw (18) << "Ludwig" << endl;

	double cost = 3.6193593938;
	cout << cost << endl;
	cout << setprecision (3) << cost << endl;

	return 0;
}