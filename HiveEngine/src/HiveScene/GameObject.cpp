#include "HivePCH.h"
#include "GameObject.h"

#include "HiveComponents/TransformComponent.h"

namespace Hive
{
	void GameObject::AddComponent(Component* comp)
	{
		comp->gameObject = this;
		m_Components.push_back(comp);

	}

	void GameObject::Start()
	{
		m_Transform = new TransformComponent();
		AddComponent(m_Transform);
	}

	void GameObject::Update()
	{
		for (Component* component : m_Components)
			component->Update();
	}

	void GameObject::Render() const
	{
		for (Component* component : m_Components)
			component->Render();
	}


	GameObject::GameObject()
		:m_Transform{}
	{

	}

	GameObject::~GameObject()
	{
	}
}



