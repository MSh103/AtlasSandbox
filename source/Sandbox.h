#pragma once

#include <Atlas.h>
#include <Atlas/Renderer.h>

struct Transform
{
	glm::vec3 Position;
	glm::vec3 Rotation;
	glm::vec3 Scale;
};

class Sandbox : public Atlas::Layer
{
public:
	Sandbox()
		:Layer("SandboxLayer")
	{}

	void OnAttach() override;
	void OnDetach() override;
	void OnEvent(Atlas::Event& e) override;
	void OnUpdate(Atlas::TimeStep ts) override;
	void OnRender() override;
	void OnImGuiRender() override;

private:
	glm::vec3 m_Color;
	Transform m_Transform;
	glm::mat4 m_Model, m_View, m_Projection;

	std::unique_ptr<Atlas::VertexArray> m_VAO;
	std::shared_ptr<Atlas::Shader> m_Shader;
};
