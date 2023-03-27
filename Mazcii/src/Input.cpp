#include "pch.h"

Input::Input() = default;
Input::~Input() = default;

void Input::ICheck()
{
	m_keys[EKey::Key_W] = GetAsyncKeyState((unsigned short)'W') < 0;
	m_keys[EKey::Key_S] = GetAsyncKeyState((unsigned short)'S') < 0;
	m_keys[EKey::Key_A] = GetAsyncKeyState((unsigned short)'A') < 0;
	m_keys[EKey::Key_D] = GetAsyncKeyState((unsigned short)'D') < 0;
	m_keys[EKey::Key_Return] = GetAsyncKeyState(VK_RETURN) < 0;
	m_keys[EKey::Key_Escape] = GetAsyncKeyState(VK_ESCAPE) < 0;
}

void Input::IUpdate()
{
	for (int i = 0; i < EKey::KEY_MAX; i++)
		m_keysLastFrame[i] = m_keys[i];
}