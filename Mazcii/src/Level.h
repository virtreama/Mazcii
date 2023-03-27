#pragma once

#include "Scene.h"

class Level : public Scene
{
public:
	virtual void Init() override;

	virtual void Update() override;

private:
	uint16_t m_playerPos = 0;

	uint16_t m_playerNextPos = 0;
};