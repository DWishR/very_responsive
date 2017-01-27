#pragma once
#include "Component.h"
#include <iostream>

namespace vr_core
{
	using namespace std;

	map<type_index, ComponentAllocator> Component::allocMap;

	void Component::DestroyComponent(Component* which, type_index type)
	{
		allocMap[type].Destroy(which);
	}

	Component::~Component()
	{
		cout << "In Component destructor" << endl;
	}
	
	void* Component::operator new (size_t, void* who)
	{ 
		return who; 
	}

	void  Component::operator delete  (void*, void* who)
	{ 
		allocMap[typeid(*static_cast<Component*>(who))].Destroy(static_cast<Component*>(who)); 
	}
}
