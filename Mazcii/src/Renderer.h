#pragma once

#include <string>
#include <Windows.h>

class Renderer
{
public:
	static inline Renderer& Get()
	{
		static Renderer instance;
		return instance;
	}

	static inline uint8_t GetWidth() { return Get().m_width; }

	static inline uint8_t GetHeight() { return Get().m_height; }

	static inline uint16_t GetScreenSize() { return Get().m_width * Get().m_height; }

	static inline void Init(const size_t& _width, const size_t& _height) { Get().IInit(_width, _height); }

	static inline void Render(const std::string& _screen) { Get().IRender(_screen); }

private:
	Renderer();

	~Renderer();

	Renderer(const Renderer&) = delete;

	Renderer& operator=(const Renderer&) = delete;

	bool m_init = false;

	uint8_t m_width = 0;

	uint8_t m_height = 0;

	HANDLE m_console = nullptr;

	std::wstring m_screen;

	DWORD m_bytesWritten = 0;

	void IInit(const size_t& _width, const size_t& _height);

	void IRender(const std::string& _screen);
};