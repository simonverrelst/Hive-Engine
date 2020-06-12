#pragma once
#include "HiveCore/Core.h"
#include "Component.h"

#include <glm/vec3.hpp>
#include <glm/vec2.hpp>



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

		void SetPosition(const glm::vec3 position);
		void SetPosition(float x, float y, float z);
		void SetPosition(const glm::vec2 position);

		void SetRotation(float angle) { m_Rotation = angle; }

	private:

		glm::vec3 m_Position;
		float m_Rotation;
	};
}



