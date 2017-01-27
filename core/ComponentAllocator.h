#pragma once
#include <mutex>

namespace vr_core
{
	class Component;

	class ComponentAllocator
	{
	public:
		void* Create(size_t size);
		void Destroy(Component* component);

	private:
		std::once_flag _once;
		size_t _myComponentSize=0;
	};
}
