#pragma once
#include "Component.h"
#include "HiveHelpers/Structs.h"



namespace Hive
{
	class RigidBodyComponent final : public Component
	{
	public:
		RigidBodyComponent(const RigidBodySettings& settings);
		virtual ~RigidBodyComponent();


		b2Body* GetBody() const { return m_pBody; };
	protected:
		void Start() override;
		void FixedUpdate() override;

	private:
		b2Body* m_pBody;
		RigidBodySettings m_Settings;


	};

}


