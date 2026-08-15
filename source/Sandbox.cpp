#include "Sandbox.h"

void Sandbox::OnAttach()
{
	m_Color.r = 0.3f;
	m_Color.g = 0.3f;
	m_Color.b = 0.3f;

	m_Vertices = new float[3*3](
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f
	);

	glCreateVertexArrays(1, &m_VAO);
	glBindVertexArray(m_VAO);

	glGenBuffers(1, &m_VBO);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, 9*sizeof(float), m_Vertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

}

void Sandbox::OnDetach()
{
	delete[] m_Vertices;
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

	glBindVertexArray(m_VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void Sandbox::OnImGuiRender()
{
	ImGui::Begin("Debug");
	ImGui::ColorEdit3("Clear Screen", glm::value_ptr(m_Color));
	ImGui::End();
}
