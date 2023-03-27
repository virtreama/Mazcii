#include "pch.h"
#include "Menu.h"
#include "Level.h"

void Menu::Init()
{
	Scene::Init();

	m_screen  = "############################################################";
	m_screen += "#                                                          #";
	m_screen += "#                                                          #";
	m_screen += "#                                                          #";
	m_screen += "#                                                          #";
	m_screen += "#                                                          #";
	m_screen += "#                                                          #";
	m_screen += "#                                                          #";
	m_screen += "#                                                          #";
	m_screen += "#                                                          #";
	m_screen += "#                                                          #";
	m_screen += "#              ###  #####    #    ####  #####              #";
	m_screen += "#             #   #   #     # #   #   #   #                #";
	m_screen += "#             #       #     # #   #   #   #                #";
	m_screen += "#              ###    #    #####  ####    #                #";
	m_screen += "#                 #   #    #   #  #  #    #                #";
	m_screen += "#             #   #   #   #     # #   #   #                #";
	m_screen += "#              ###    #   #     # #   #   #                #";
	m_screen += "#             -------------------------------              #";
	m_screen += "#                                                          #";
	m_screen += "#                                                          #";
	m_screen += "#                 ##### #     # # #####                    #";
	m_screen += "#                 #      #   #  #   #                      #";
	m_screen += "#                 #       # #   #   #                      #";
	m_screen += "#                 ####     #    #   #                      #";
	m_screen += "#                 #       # #   #   #                      #";
	m_screen += "#                 #      #   #  #   #                      #";
	m_screen += "#                 ##### #     # #   #                      #";
	m_screen += "#                                                          #";
	m_screen += "#                                                          #";
	m_screen += "#                                                          #";
	m_screen += "#                                                          #";
	m_screen += "#                                                          #";
	m_screen += "#                                                          #";
	m_screen += "#                                                          #";
	m_screen += "#                                                          #";
	m_screen += "#                                                          #";
	m_screen += "#                                                          #";
	m_screen += "#                                                          #";
	m_screen += "############################################################";
}

void Menu::Update()
{
	if (Input::KeyPressed(EKey::Key_S) && m_startMarked)
	{
		m_startMarked = false;

		for (int i = 0; i < 31; i++)
			m_screen[1094 + i] = ' ';

		for (int i = 0; i < 21; i++)
			m_screen[1698 + i] = '-';
	}

	else if (Input::KeyPressed(EKey::Key_W) && !m_startMarked)
	{
		m_startMarked = true;

		for (int i = 0; i < 31; i++)
			m_screen[1094 + i] = '-';

		for (int i = 0; i < 21; i++)
			m_screen[1698 + i] = ' ';
	}

	if (Input::KeyPressed(EKey::Key_Return))
	{
		if (m_startMarked)
			Game::ChangeScene(EScene::Scene_Level);
		else
			Game::Quit();
	}

	if (Input::KeyPressed(EKey::Key_Escape))
		Game::Quit();
}