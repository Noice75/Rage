#pragma once

#include <glm/glm.hpp>

#include "Rage/Core/KeyCodes.h"
#include "Rage/Core/MouseCodes.h"

namespace Rage {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}
