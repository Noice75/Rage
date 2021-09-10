#pragma once

#include "Rage.h"

class ExampleLayer : public Rage::Layer
{
public:
	ExampleLayer();
	virtual ~ExampleLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Rage::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Rage::Event& e) override;
private:
	Rage::ShaderLibrary m_ShaderLibrary;
	Rage::Ref<Rage::Shader> m_Shader;
	Rage::Ref<Rage::VertexArray> m_VertexArray;

	Rage::Ref<Rage::Shader> m_FlatColorShader;
	Rage::Ref<Rage::VertexArray> m_SquareVA;

	Rage::Ref<Rage::Texture2D> m_Texture, m_ChernoLogoTexture;

	Rage::OrthographicCameraController m_CameraController;
	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};

