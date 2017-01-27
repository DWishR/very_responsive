#pragma once
#include "Component.h"
#include <iostream>

namespace vr_core
{
	using namespace std;

	map<type_index, ComponentAllocator> Component::allocMap;

	Component::~Component()
	{
		cout << "In Component destructor" << endl;
	}
}
