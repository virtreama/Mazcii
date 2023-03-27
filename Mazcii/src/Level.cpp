#include "pch.h"
#include "Level.h"
#include "Menu.h"

void Level::Init()
{
	Scene::Init();

	m_screen  = "############################################################";
	m_screen += "#X                                                         #";
	m_screen += "# ####################################################### ##";
	m_screen += "# ####################################################### ##";
	m_screen += "#                                                      ## ##";
	m_screen += "# ############################### ####################### ##";
	m_screen += "# ############################### ####################### ##";
	m_screen += "# ####### #######################                   ##### ##";
	m_screen += "# ####### ####################### ############## ######## ##";
	m_screen += "# ####### ###################################### ######## ##";
	m_screen += "# #######                                 ###### ######## ##";
	m_screen += "# ####### ##################### ######### ###### ######## ##";
	m_screen += "# ####### ##################### ######### ###### ######## ##";
	m_screen += "# ####### ##################### ######### ###### ######## ##";
	m_screen += "# ####### ##################### #####          # ######## ##";
	m_screen += "# ####### ######### ########### ################ ######## ##";
	m_screen += "# ####### ######### ########### ######################### ##";
	m_screen += "# ####### ######### ###########                  ######## ##";
	m_screen += "# ####### ####      ########### ######### ###### ######## ##";
	m_screen += "# #######     ##### ########### ######### ###### ######## ##";
	m_screen += "# ####### ######### ########### ######### ###### ######## ##";
	m_screen += "# ####### ######### ########### ######### ###### ######## ##";
	m_screen += "# ####### ######### ########### ######### ###### ######## ##";
	m_screen += "# ####### ######### ########### ######### ###### ######## ##";
	m_screen += "# ####### ######### ########### ######### ###### ######## ##";
	m_screen += "# ####### ######### ##################### ###### ######## ##";
	m_screen += "#                                            ### ######## ##";
	m_screen += "# ############################################## ######## ##";
	m_screen += "# ################### ########################## ######## ##";
	m_screen += "# ###################                            ######## ##";
	m_screen += "# ################### ########################## ######## ##";
	m_screen += "# ############################################## ######## ##";
	m_screen += "# #######                                        ######## ##";
	m_screen += "# ############ ################################# ####     ##";
	m_screen += "# ############ ####################            #     #### ##";
	m_screen += "# ############ ############################ #### ### #### ##";
	m_screen += "# ############                        ##### #### ### #### ##";
	m_screen += "# ############ #####################  ##### ######## #### ##";
	m_screen += "# ############                        #####O           ## ##";
	m_screen += "############################################################";

	m_playerPos = 61;
	m_playerNextPos = m_playerPos;
}

void Level::Update()
{
	if (Input::KeyPressed(EKey::Key_W))
		m_playerNextPos = m_playerPos - Renderer::GetWidth();
	else if (Input::KeyPressed(EKey::Key_S))
		m_playerNextPos = m_playerPos + Renderer::GetWidth();
	else if (Input::KeyPressed(EKey::Key_A))
		m_playerNextPos = m_playerPos - 1;
	else if (Input::KeyPressed(EKey::Key_D))
		m_playerNextPos = m_playerPos + 1;

	if (m_screen[m_playerNextPos] == ' ')
	{
		m_screen[m_playerPos] = ' ';
		m_screen[m_playerNextPos] = 'X';
		m_playerPos = m_playerNextPos;
	}
	else if (m_screen[m_playerNextPos] == 'O')
	{
		Game::ChangeScene(EScene::Scene_Level);
	}

	if (Input::KeyPressed(EKey::Key_Escape))
		Game::ChangeScene(EScene::Scene_Menu);
}