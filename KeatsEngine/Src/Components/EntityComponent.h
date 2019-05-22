#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>


class Component;
class Entity;

#pragma region Helper Methods


using ComponentID = std::size_t;

inline ComponentID GetComponentTypeID()
{
	static ComponentID lastID = 0u;
	return lastID++;
}

template <typename T> inline ComponentID GetComponentTypeID() noexcept
{
	static ComponentID typeID = GetComponentTypeID();
	return typeID;
}

constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset<maxComponents>;

using ComponentArray = std::array<Component*, maxComponents>;

#pragma endregion


#pragma region Entity - Component Classes

							//COMPONENT CLASS
class Component
{
public:
	Entity* entity;

	virtual void Initialize() {}
	virtual void Update() {}
	virtual void Draw() {}

	virtual ~Component() {}
};




							//ENTITY CLASS
class Entity
{
public:
	void Update()
	{
		for (auto& c : components) c->Update();
	}
	void Draw() 
	{
		for (auto& c : components) c->Draw();
	}
	bool isActive() const { return active; }
	void Destroy() { active = false; }

	//check for components method
	template <typename T> bool HasComponent() const
	{
		return ComponentBitSet[GetComponentTypeID<T>];
	}

	//"Add" method
	template <typename T, typename... TArgs>
	T& AddComponent(TArgs&&... mArgs)
	{
		T* c(new T(std::forward<TArgs>(mArgs)...));
		c->entity = this;
		std::unique_ptr<Component>uPtr { c };
		components.emplace_back(std::move(uPtr));

		componentArray[GetComponentTypeID<T>()] = c;
		componentBitSet[GetComponentTypeID<T>()] = true;
		 
		c->Initialize();
		return *c;
	}
	//get component method
	template<typename T> T& GetComponent() const
	{

		auto ptr(componentArray[GetComponentTypeID<T>()]);
		return *static_cast<T*>(ptr);
	}


private:
	bool active = true;
	std::vector<std::unique_ptr<Component>> components;

	ComponentArray componentArray;
	ComponentBitSet componentBitSet;
};




							//MANAGER CLASS
class Manager
{
public:
	void Update()
	{
		for (auto& e : entityList) e->Update();
	}
	void Draw()
	{
		for (auto& e : entityList) e->Draw();
	}

	void Refresh()
	{
		entityList.erase(std::remove_if(std::begin(entityList), std::end(entityList),
			[](const std::unique_ptr<Entity> &mEntity)
		{
			return !mEntity->isActive();
		}),
			std::end(entityList));
	}

	Entity& AddEntity()
	{
		Entity *e = new Entity();
		std::unique_ptr<Entity> uPtr{ e };
		entityList.emplace_back(std::move(uPtr));
		return *e;
	}


private:
	std::vector<std::unique_ptr<Entity>> entityList;

};

#pragma endregion