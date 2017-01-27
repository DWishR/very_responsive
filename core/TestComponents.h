#pragma once
#include "Component.h"
#include <iostream>

namespace vr_core
{
	class TestComponentA : public Component
	{
	protected:
		virtual ~TestComponentA()
		{
			std::cout << "In TestComponentA destructor" << std::endl;
		}

	private:
		int _anInt = 0;
	};

	class TestComponentB : public Component
	{
	protected:
		virtual ~TestComponentB()
		{
			std::cout << "In TestComponentB destructor" << std::endl;
		}
	};
}
