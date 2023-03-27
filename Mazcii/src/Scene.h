#pragma once

#include <string>

class Scene
{
public:
	virtual void Init();

	virtual void Update() = 0;

	void Render();

protected:
	std::string m_screen;

	void GetInput();

	void UpdateInput();
};