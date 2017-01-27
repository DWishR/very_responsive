#pragma once
#include "Component.h"
#include <iostream>

namespace vr_core
{
	class TestComponentA : public Component
	{
	public:
		virtual ~TestComponentA()
		{
			std::cout << "In TestComponentA destructor" << std::endl;
		}
	private:
		int i = 0;
	};

	class TestComponentB : public Component
	{
	public:
		virtual ~TestComponentB()
		{
			std::cout << "In TestComponentB destructor" << std::endl;
		}
	};
}
