#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

int main ()
{
	map<string, int> mp = 
	{
		{"test", 8},
		{"testar", 5}
	};

	cout << mp["test"] << endl;
}