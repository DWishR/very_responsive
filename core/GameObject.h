#pragma once
#include "Component.h"
#include <cassert>
#include <type_traits>

namespace vr_core
{
	constexpr size_t MAX_COMPONENTS = 31;

	class GameObject
	{
	public:
		~GameObject();

		template<class T> T* AddComponent();
		template<class T> T* GetComponent();
		template<class T> void RemoveComponent(T* which);

	private:
		size_t _count = 0;
		Component* _components[MAX_COMPONENTS];

	};

	template <class T>
	T* GameObject::AddComponent()
	{
		static_assert(std::is_base_of<Component, T>(), "AddComponent only works for Component derivatives");
		assert(_count < MAX_COMPONENTS);

		T* created = Component::CreateComponent<T>(this);
		_components[_count++] = static_cast<Component*>(created);
		return created;
	}

	template <class T>
	T* GameObject::GetComponent()
	{
		for(auto ii=0 ; ii<_count ; ++ii)
		{
			if (!_components[ii]) continue;
			if (typeid(*_components[ii]) == typeid(T)) return static_cast<T*>(_components[ii]);
		}

		return nullptr;
	}

	template <class T>
	void GameObject::RemoveComponent(T* which)
	{
		for (auto ii = 0; ii<_count; ++ii)
		{
			if (_components[ii] == which)
			{
				_components[ii] = _components[--_count];
				Component::DestroyComponent(which);
				return;
			}
		}

		throw std::invalid_argument("Component not attached to GameObject");
	}
}
