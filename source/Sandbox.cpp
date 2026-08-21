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

	Vertex vertices[4] = {
		{ {-0.5f, 0.5f, 0.f}, {1.f, 0.f, 0.f} },
		{ {-0.5f,-0.5f, 0.f}, {0.f, 1.f, 0.f} },
		{ { 0.5f,-0.5f, 0.f}, {0.f, 0.f, 1.f} },
		{ { 0.5f, 0.5f, 0.f}, {1.f, 1.f, 1.f} },
	};

	uint32_t indices[6] = {
		0, 1, 2,
		2, 3, 0
	};

	m_VAO = std::make_unique<Atlas::VertexArray>();
	m_Shader = std::make_shared<Atlas::Shader>();

	//m_Shader->LoadFromFile(Atlas::ShaderType::Vertex, "assets/Vertex.glsl");
	//m_Shader->LoadFromFile(Atlas::ShaderType::Fragment, "assets/Fragment.glsl");
	m_Shader->LoadFromFile(Atlas::ShaderType::Basic, "assets/Basic.glsl");
	m_Shader->LinkObjectsToProgram();

	std::shared_ptr<Atlas::VertexBuffer> VBO = std::make_shared<Atlas::VertexBuffer>(&vertices, sizeof(Vertex) * 4);
	VBO->Use();
	VBO->SetLayout({
		{Atlas::ShaderDataType::Float3, "a_Position"},
		{Atlas::ShaderDataType::Float3, "a_Color"},
	});
	m_VAO->Use();
	m_VAO->AddVertexBuffer(VBO);

	std::shared_ptr<Atlas::IndexBuffer> IBO = std::make_shared<Atlas::IndexBuffer>(indices, 6);
	IBO->Use();
	m_VAO->SetIndexBuffer(IBO);
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
	m_Shader->Use();
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (const void*)0);
}

void Sandbox::OnImGuiRender()
{
	ImGui::Begin("Debug");
	ImGui::ColorEdit3("Clear Screen", glm::value_ptr(m_Color));
	ImGui::End();
}
