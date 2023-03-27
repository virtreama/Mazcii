#pragma once

#include <windows.h>
#include <array>

enum EKey
{
	Key_W = 0,
	Key_S = 1,
	Key_A = 2,
	Key_D = 3,
	Key_Return = 4,
	Key_Escape = 5,
	KEY_MAX = 6
};

class Input
{
public:
	static inline Input& Get()
	{
		static Input instance;
		return instance;
	}

	static inline void Check() { Get().ICheck(); }

	static inline void Update() { Get().IUpdate(); }

	static inline bool Key(EKey _key) { return Get().m_keys[(int)_key]; }

	static inline bool KeyPressed(EKey _key) { return Get().m_keys[(int)_key] && !Get().m_keysLastFrame[(int)_key]; }
	
	static inline bool KeyReleased(EKey _key) { return !Get().m_keys[(int)_key] && Get().m_keysLastFrame[(int)_key]; }

private:
	Input();

	~Input();

	Input(const Input&) = delete;

	Input& operator=(const Input&) = delete;

	std::array<bool, EKey::KEY_MAX> m_keys;

	std::array<bool, EKey::KEY_MAX> m_keysLastFrame;

	void ICheck();

	void IUpdate();
};