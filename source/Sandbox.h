#pragma once

#include <Atlas.h>

class Sandbox : public Atlas::Layer
{
public:
	Sandbox()
		:Layer("SandboxLayer")
	{}

	void OnAttach() override;
	void OnEvent(Atlas::Event& e) override;
	void OnUpdate(Atlas::TimeStep ts) override;
	void OnRender() override;
	void OnImGuiRender() override;

private:
	struct Color
	{
		float r, g, b;
	} m_Color;
};
