#pragma once
#include "HiveCore/Core.h"
#include "Component.h"

#include <glm/vec3.hpp>



namespace Hive
{
	class  TransformComponent final :
		public Component
	{
	public:
		TransformComponent() = default;
		virtual ~TransformComponent();

		virtual void Start() override;
		virtual void Update() override;
		virtual void Render() override;

		glm::vec3 GetPosition() const { return m_Position; }
		void SetPosition(float x, float y, float z);

	private:

		glm::vec3 m_Position;
	};
}



