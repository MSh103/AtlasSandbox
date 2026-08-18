#pragma once

#include <Atlas.h>
#include <Atlas/Renderer.h>

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

	std::unique_ptr<Atlas::VertexArray> m_VAO;
};
