#pragma once
#include "HiveCore/Core.h"


namespace Hive
{
	class GameObject;

	class  Component
	{
	public:
		Component() = default;
		virtual ~Component();

		virtual void Start() = 0;
		virtual void Update() = 0;
		virtual void Render() = 0;

		GameObject* gameObject = nullptr;
	};
}




