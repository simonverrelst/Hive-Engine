#include "HivePCH.h"
#include "GameObject.h"

#include "HiveComponents/TransformComponent.h"

namespace Hive
{
	GameObject::GameObject()
		:m_Transform{}
		,m_Tag{}
	{
		m_Transform = new TransformComponent();
		AddComponent(m_Transform);
	}

	GameObject::~GameObject()
	{
		for (Component * pComp : m_Components)
		{
			SafeDelete(pComp);
		}
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
		if (!m_IsActive) return;

		for (Component* component : m_Components)
			component->Update();
	}

	void GameObject::FixedUpdate()
	{
		if (!m_IsActive) return;

		for (Component* component : m_Components)
			component->FixedUpdate();
	}

	void GameObject::Render() const
	{
		if (!m_IsActive) return;

		for (Component* component : m_Components)
			component->Render();
	}


	void GameObject::OnEnable()
	{
		for (Component* component : m_Components)
			component->SetActive(true);
	}

	void GameObject::OnDisable()
	{
		for (Component* component : m_Components)
			component->SetActive(false);
	}

	void GameObject::OnTriggerEnter2D(const Collision& trigger)
	{
		if (!m_IsActive) return;

		for (Component* component : m_Components)
			component->OnTriggerEnter2D(trigger);
	}

	void GameObject::OnTriggerExit2D(const Collision& trigger)
	{
		if (!m_IsActive) return;

		for (Component* component : m_Components)
			component->OnTriggerExit2D(trigger);
	}

	void GameObject::OnCollisionEnter2D(const Collision& collision)
	{
		if (!m_IsActive) return;

		for (Component* component : m_Components)
			component->OnCollisionEnter2D(collision);
	}

	void GameObject::OnCollisionExit2D(const Collision& collision)
	{
		if (!m_IsActive) return;

		for (Component* component : m_Components)
			component->OnCollisionExit2D(collision);
	}

	void GameObject::SetActive(bool state)
	{
		m_IsActive = state;

		if (m_IsActive)
		{
			OnEnable();
		}
		else 
		{
			OnDisable();
		}
	}

}



