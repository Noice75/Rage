#include "rapch.h"
#include "Platform/OpenGL/OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Rage {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		RA_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		RA_PROFILE_FUNCTION();

		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		RA_CORE_ASSERT(status, "Failed to initialize Glad!");

		RA_CORE_INFO("OpenGL Info:");
		RA_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		RA_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		RA_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));

		RA_CORE_ASSERT(GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 5), "Rage requires at least OpenGL version 4.5!");
	}

	void OpenGLContext::SwapBuffers()
	{
		RA_PROFILE_FUNCTION();

		glfwSwapBuffers(m_WindowHandle);
	}

}
