#include "pch.h"
#include "Scene.h"

void Scene::Init()
{
	m_screen.reserve(Renderer::GetScreenSize());

	for (int i = 0; i < Renderer::GetScreenSize(); i++)
		m_screen += ' ';
}

void Scene::Render()
{
	Renderer::Render(m_screen);
}