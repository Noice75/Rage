#pragma once

#include "Rage.h"

class Sandbox2D : public Rage::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Rage::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Rage::Event& e) override;
private:
	Rage::OrthographicCameraController m_CameraController;
	
	// Temp
	Rage::Ref<Rage::VertexArray> m_SquareVA;
	Rage::Ref<Rage::Shader> m_FlatColorShader;

	Rage::Ref<Rage::Texture2D> m_CheckerboardTexture;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};