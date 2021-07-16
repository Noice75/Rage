#include "rapch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Rage {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}