#include <Rage.h>
#include <Rage/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Rage {

	class Ragenut : public Application
	{
	public:
		Ragenut(ApplicationCommandLineArgs args)
			: Application("Ragenut", args)
		{
			PushLayer(new EditorLayer());
		}

		~Ragenut()
		{
		}
	};

	Application* CreateApplication(ApplicationCommandLineArgs args)
	{
		return new Ragenut(args);
	}

}
