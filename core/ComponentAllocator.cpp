#include "ComponentAllocator.h"
#include "Component.h"
#include <cassert>

namespace vr_core
{
	void* ComponentAllocator::Create(size_t size)
	{
		std::call_once(_once, [&]()->void {_myComponentSize = size; });
		assert(size == _myComponentSize);
		auto val = malloc(size);
		return val;
	}

	void ComponentAllocator::Destroy(Component* component)
	{
		if (component == nullptr) return;
		component->~Component();
		free(component);
	}
}
