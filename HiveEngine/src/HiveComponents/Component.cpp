#include "HivePCH.h"
#include "HiveHelpers/Structs.h"
#include "Component.h"

namespace Hive
{
	Component::~Component()
	{
	}

	void Component::OnTriggerEnter2D(const Collision& trigger)
	{
		
		
		UNREFERENCED_PARAMETER(trigger);
	}

	void Component::OnTriggerExit2D(const Collision& trigger)
	{
		UNREFERENCED_PARAMETER(trigger);
	}

	void Component::OnCollisionEnter2D(const Collision& collision)
	{
		UNREFERENCED_PARAMETER(collision);
	}

	void Component::OnCollisionExit2D(const Collision& collision)
	{
		UNREFERENCED_PARAMETER(collision);
	}

	void Component::OnEnable()
	{

	}

	void Component::OnDisable()
	{

	}

	void Component::SetActive(bool state)
	{
		m_IsActive = state;
		if (m_IsActive) {
			OnEnable();
		}
		else {
			OnDisable();
		}
	}

}


