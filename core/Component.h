#pragma once
#include "ComponentAllocator.h"
#include <map>
#include <typeindex>

namespace vr_core
{
	class GameObject;

	class Component
	{
	public:
		template <class T> static T* CreateComponent(GameObject* owner);
		template <class T> static void DestroyComponent(T* which);
		static void DestroyComponent(Component* which, std::type_index type);

	protected:
		virtual ~Component() = 0;

	private:
		GameObject* _gameObject = nullptr;

		void* operator new     (size_t) = delete;
		void* operator new[]   (size_t) = delete;
		void  operator delete  (void*) { abort(); }
		void  operator delete[](void*) { abort(); }

		void* operator new    (size_t, void* who);
		void  operator delete (void*, void* who);

		static std::map<std::type_index, ComponentAllocator> allocMap;

		friend class ComponentAllocator;
	};

	template <class T>
	T* Component::CreateComponent(GameObject* owner)
	{
		static_assert(std::is_base_of<Component, T>(), "CreateComponent only works for Component derivatives");

		auto mem = allocMap[typeid(T)].Create(sizeof(T));
		auto component = new(mem) T();
		component->_gameObject = owner;
		return component;
	}

	template <class T>
	void Component::DestroyComponent(T* which)
	{
		static_assert(std::is_base_of<Component, T>(), "DestroyComponent only works for Component derivatives");
		allocMap[typeid(T)].Destroy(which);
	}
}
