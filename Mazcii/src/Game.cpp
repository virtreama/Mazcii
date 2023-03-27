#include "pch.h"
#include "Menu.h"
#include "Level.h"

Game::Game() = default;
Game::~Game() = default;

void Game::IStart()
{
	Renderer::Init(60, 40);

	m_pMenuScene = std::make_shared<Menu>();

	m_pLevelScene = std::make_shared<Level>();

	ChangeScene(EScene::Scene_Menu);

	m_isRunning = true;
}

void Game::IRun()
{
	if (!m_pCurrentScene)
		return;

	Input::Check();

	m_pCurrentScene->Update();

	m_pCurrentScene->Render();

	Input::Update();
}

void Game::IChangeScene(EScene _newScene)
{
	switch (_newScene)
	{
	case Scene_Menu:
		m_pCurrentScene = m_pMenuScene;
		break;
	case Scene_Level:
		m_pCurrentScene = m_pLevelScene;
		break;
	case SCENE_MAX:
		break;
	default:
		break;
	}

	m_pCurrentScene->Init();
}