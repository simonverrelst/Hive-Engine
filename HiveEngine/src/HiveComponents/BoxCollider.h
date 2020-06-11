#pragma once
#include "Component.h"
namespace Hive
{
	class BoxCollider final : public Component
	{
		BoxCollider() = default;
		virtual ~BoxCollider() = default;
	public:
		void Start() override;

		void Update() override;

		void Render() override;

	};

}