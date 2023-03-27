#include <iostream>

#include "pch.h"

Renderer::Renderer() = default;
Renderer::~Renderer() = default;

void Renderer::IInit(const size_t& _width, const size_t& _height)
{
	m_width = _width;
	m_height = _height;

	m_console = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, nullptr, CONSOLE_TEXTMODE_BUFFER, nullptr);
	SetConsoleActiveScreenBuffer(m_console);

	m_screen.reserve(_width * _height);

	for (int i = 0; i < Renderer::GetScreenSize(); i++)
		m_screen += ' ';

	m_init = true;
}

void Renderer::IRender(const std::string& _screen)
{
	if (!m_init || (m_screen.size() != _screen.size()))
		return;

	for (int i = 0; i < m_width * m_height; i++)
		m_screen[i] = _screen[i];

	WriteConsoleOutputCharacter(m_console, m_screen.c_str(), m_width * m_height, { 0, 0 }, &m_bytesWritten);
}