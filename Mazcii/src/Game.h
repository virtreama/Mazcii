#pragma once

#include <memory>

#include "Scene.h"

enum EScene
{
	Scene_Menu = 0,
	Scene_Level = 1,
	SCENE_MAX = 2
};

class Game
{
public:
	static Game& Get()
	{
		static Game instance;
		return instance;
	}

	static inline void Start() { Get().IStart(); }

	static inline void Run() { Get().IRun(); }

	static inline void Quit() { Get().m_isRunning = false; }

	static inline void ChangeScene(EScene _newScene) { Get().IChangeScene(_newScene); }

	static inline bool IsRunning() { return Get().m_isRunning; }

private:
	Game();
	
	~Game();

	Game(const Game&) = delete;

	Game& operator=(const Game&) = delete;

	bool m_isRunning = false;

	std::shared_ptr<Scene> m_pCurrentScene;

	std::shared_ptr<Scene> m_pMenuScene = nullptr;

	std::shared_ptr<Scene> m_pLevelScene = nullptr;

	void IStart();

	void IRun();

	void IChangeScene(EScene _newScene);
};