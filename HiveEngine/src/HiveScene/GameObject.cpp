#include "HivePCH.h"
#include "GameObject.h"

#include "HiveComponents/TransformComponent.h"

namespace Hive
{
	GameObject::GameObject()
		:m_Transform{}
	{
		m_Transform = new TransformComponent();
		AddComponent(m_Transform);
	}

	GameObject::~GameObject()
	{
	}

	void GameObject::AddComponent(Component* comp)
	{
		comp->gameObject = this;
		m_Components.push_back(comp);

		comp->Start();
	}

	void GameObject::Start()
	{

	}

	void GameObject::Update()
	{
		for (Component* component : m_Components)
			component->Update();
	}

	void GameObject::FixedUpdate()
	{
		for (Component* component : m_Components)
			component->FixedUpdate();
	}

	void GameObject::Render() const
	{
		for (Component* component : m_Components)
			component->Render();
	}


	void GameObject::OnTriggerEnter2D(const Collision& trigger)
	{
		for (Component* component : m_Components)
			component->OnTriggerEnter2D(trigger);
	}

	void GameObject::OnTriggerExit2D(const Collision& trigger)
	{
		for (Component* component : m_Components)
			component->OnTriggerExit2D(trigger);
	}

	void GameObject::OnCollisionEnter2D(const Collision& collision)
	{
		for (Component* component : m_Components)
			component->OnCollisionEnter2D(collision);
	}

	void GameObject::OnCollisionExit2D(const Collision& collision)
	{
		for (Component* component : m_Components)
			component->OnCollisionExit2D(collision);
	}
}



