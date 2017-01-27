#include "GameObject.h"

namespace vr_core
{
	GameObject::~GameObject()
	{
		for(auto ii=0 ; ii<_count; ++ii)
		{
			Component::DestroyComponent(_components[ii], typeid(*_components[ii]));
		}
	}

}
