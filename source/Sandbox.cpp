#include "Sandbox.h"

void Sandbox::OnAttach()
{
	m_Color.r = 0.3f;
	m_Color.g = 0.3f;
	m_Color.b = 0.3f;
}

void Sandbox::OnEvent(Atlas::Event& e)
{
}

void Sandbox::OnUpdate(Atlas::TimeStep ts)
{
}

void Sandbox::OnRender()
{
	glClearColor(m_Color.r, m_Color.g, m_Color.b, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Sandbox::OnImGuiRender()
{
	float col[3] = {
		m_Color.r,
		m_Color.g,
		m_Color.b
	};
	ImGui::Begin("Debug");
	ImGui::ColorEdit3("Clear Screen", col);
	ImGui::End();

	m_Color.r = col[0];
	m_Color.g = col[1];
	m_Color.b = col[2];
}
