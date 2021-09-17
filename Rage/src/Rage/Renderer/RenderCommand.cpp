#include "rapch.h"
#include "Rage/Renderer/RenderCommand.h"

namespace Rage {

	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();

}