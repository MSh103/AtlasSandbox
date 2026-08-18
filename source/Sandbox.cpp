#include "Sandbox.h"

struct Vertex
{
	glm::vec3 pos;
	glm::vec3 color;
};

void Sandbox::OnAttach()
{
	m_Color.r = 0.3f;
	m_Color.g = 0.3f;
	m_Color.b = 0.3f;

	Vertex vertices[3] = {
		{ {-0.5f, 0.5f, 0.f}, {1.f, 0.f, 0.f} },
		{ {-0.5f,-0.5f, 0.f}, {0.f, 1.f, 0.f} },
		{ { 0.5f,-0.5f, 0.f}, {0.f, 0.f, 1.f} },
	};

	m_VAO = std::make_unique<Atlas::VertexArray>();

	std::shared_ptr<Atlas::VertexBuffer> VBO = std::make_shared<Atlas::VertexBuffer>(&vertices, sizeof(Vertex) * 3);
	VBO->Use();
	VBO->SetLayout({
		{Atlas::ShaderDataType::Float3, "a_Position"},
		{Atlas::ShaderDataType::Float3, "a_Color"},
	});
	m_VAO->Use();
	m_VAO->AddVertexBuffer(VBO);
}

void Sandbox::OnDetach()
{
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

	m_VAO->Use();
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void Sandbox::OnImGuiRender()
{
	ImGui::Begin("Debug");
	ImGui::ColorEdit3("Clear Screen", glm::value_ptr(m_Color));
	ImGui::End();
}
