#include "TestComponents.h"
#include "GameObject.h"
#include <iostream>

using namespace std;
using namespace vr_core;

int main(int argc, char* argv[])
{
	cout << "Run: ";
	for (auto ii = 0; ii < argc; ++ii)
	{
		cout << argv[ii];
		cout << " ";
	}
	cout << endl;

	auto awesomeObject = new GameObject();
	awesomeObject->AddComponent<TestComponentA>();
	awesomeObject->AddComponent<TestComponentB>();

	cout << endl;

	cout << "Size of Component: " << sizeof(Component) << endl;
	cout << "Size of TestComponentA: " << sizeof(TestComponentA) << endl;
	cout << "Size of TestComponentB: " << sizeof(TestComponentB) << endl;

	cout << "Find on Component: " << awesomeObject->GetComponent<Component>() << endl;
	cout << "Find on TestComponentA: " << awesomeObject->GetComponent<TestComponentA>() << endl;
	cout << "Find on TestComponentB: " << awesomeObject->GetComponent<TestComponentB>() << endl;

	delete awesomeObject;

	cin.ignore(80, '\n');
	return 0;
}
