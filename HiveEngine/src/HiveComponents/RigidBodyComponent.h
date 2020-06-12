#pragma once
#include "Component.h"
#include "HiveHelpers/Structs.h"



namespace Hive
{
	class RigidBodyComponent final : public Component
	{
	public:
		RigidBodyComponent(const RigidBodySettings& settings);
		virtual ~RigidBodyComponent() = default;
	protected:
		void Start() override;
		void FixedUpdate() override;

		b2Body* GetBody() const { return m_pBody; };
	private:
		b2Body* m_pBody;
		RigidBodySettings m_Settings;


	};

}


