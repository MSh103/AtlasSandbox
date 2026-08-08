#include <print>

#include <Atlas.h>
#include <Atlas/Core/Entrypoint.h>

class SandboxLayer : public Atlas::Layer
{
public:
	SandboxLayer()
		: Atlas::Layer("SandboxLayer")
	{}

	void OnAttach() override
	{
		m_Color.r = 0.3f;
		m_Color.g = 0.3f;
		m_Color.b = 0.3f;
	}

	void OnEvent(Atlas::Event& e) override
	{
		Atlas::EventDispatcher dispatcher(e);
		dispatcher.Dispatch<Atlas::WindowResizeEvent>(AT_BIND_EVENT_FN(SandboxLayer::OnResizeEvent));
	}

	bool OnResizeEvent(Atlas::WindowResizeEvent& e)
	{
		m_Color.r = e.GetWidth() / 1000.f;
		m_Color.g = e.GetHeight() / 1000.f;
		m_Color.b = (e.GetWidth() / 1000.f) * (e.GetHeight() / 1000.f);
		return false;
	}

	void OnUpdate(Atlas::TimeStep ts) override
	{}

	void OnRender() override
	{
		glClearColor(m_Color.r, m_Color.g, m_Color.b, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void OnImGuiRender() override
	{
		ImGui::ShowDemoWindow();
	}

private:
	struct Color
	{
		float r, g, b;
	} m_Color;
};


class Sandbox : public Atlas::Application
{
public:
	Sandbox()
		:Application({

			.Window = {"Sandbox", 1280, 720}
			})
	{
		PushLayer(new SandboxLayer());
		Atlas::Log::Info("Hello, World from Sandbox!");
	}
};

Atlas::Application* Atlas::CreateApplication()
{
	return new Sandbox();
}