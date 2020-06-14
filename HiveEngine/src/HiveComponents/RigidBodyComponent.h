#pragma once
#include "Component.h"
#include "HiveHelpers/Structs.h"

#pragma warning( push )
#pragma warning( disable : 4201)
#include "glm/vec2.hpp"
#pragma warning( pop ) 

namespace Hive
{
	class RigidBodyComponent final : public Component
	{
	public:
		RigidBodyComponent(const RigidBodySettings& settings);
		virtual ~RigidBodyComponent();

		void Translate(const glm::vec2 & position);
		void Rotate(float rotation);

		b2Body* GetBody() const { return m_pBody; };

		bool IsInFixedUpdate() const { return m_pUpdatingObject; }
	protected:
		void Start() override;
		void FixedUpdate() override;

	private:
		b2Body* m_pBody;
		RigidBodySettings m_Settings;
		bool m_pUpdatingObject;

		

	};

}


