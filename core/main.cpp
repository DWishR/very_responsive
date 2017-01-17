#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	cout << "Run: ";
	for (int ii = 0; ii < argc; ++ii)
	{
		cout << argv[ii];
		cout << " ";
	}
	cout << endl;

	cout << "Hello, World!" << endl;

	return 0;
}
