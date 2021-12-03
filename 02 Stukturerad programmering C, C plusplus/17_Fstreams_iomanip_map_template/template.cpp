#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

template <typename L>
void Print (L value)
{
	cout << value << endl;
}
int main ()
{

	Print(5);
	Print("Hello");
	Print(8);

	cin.get ();
}