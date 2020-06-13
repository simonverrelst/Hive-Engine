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

		glm::vec2 GetPosition() const { return m_Position; }
		float GetRotation() const { return m_Rotation; }
		glm::vec2 GetScale() const { return m_Scale; }

		void SetPosition(float x, float y);
		void SetPosition(const glm::vec2 & position);

		void SetRotation(float angle, bool euler);

		void SetScale(const glm::vec2& scale) { m_Scale = scale; };

	private:

		glm::vec2 m_Position{};
		float m_Rotation{};
		glm::vec2 m_Scale{1.f,1.f};
	};
}



