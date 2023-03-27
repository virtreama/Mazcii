#pragma once

#include "Scene.h"

class Menu : public Scene
{
public:
	virtual void Init() override;

	virtual void Update() override;

private:
	bool m_startMarked = true;
};