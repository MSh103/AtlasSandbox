#include <Atlas.h>
#include <Atlas/Core/Entrypoint.h>

#include "Sandbox.h"

class SandboxApp : public Atlas::Application
{
public:
	SandboxApp()
		:Application({

			.Window = {"Sandbox", 1280, 720}
			})
	{
		PushLayer(new Sandbox());
		Atlas::Log::Info("Hello, World from Sandbox!");
	}
};

Atlas::Application* Atlas::CreateApplication()
{
	return new SandboxApp();
}