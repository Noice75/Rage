#pragma once

#include "Rage/Layer.h"

#include "Rage/Events/ApplicationEvent.h"
#include "Rage/Events/KeyEvent.h"
#include "Rage/Events/MouseEvent.h"

namespace Rage {

	class RAGE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

	private:
		float m_Time = 0.0f;
	};

}