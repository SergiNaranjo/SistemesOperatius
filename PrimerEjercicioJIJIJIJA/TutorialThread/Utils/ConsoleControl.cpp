#include "ConsoleControl.h"

CC CC::GetInstance()
{
	static CC instance;
	return instance;
}

HANDLE CC::GetConsole()
{
	return GetInstance()._console;
}

void CC::SetColor(ConsoleColor textColor, ConsoleColor backgroundColor)
{
	WORD color = (backgroundColor << 4) | textColor;
	SetConsoleTextAttribute(GetConsole(), color);
}

void CC::SetPostion(short int x, short int y)
{
	COORD pos{ x, y };
	SetConsoleCursorPosition(GetConsole(), pos);
}

void CC::Clear()
{
	std::cout << "\033[2J\33[1;1H";
	//FillWithCharacter(' ', WHITE, BLACK);
}

void CC::FillWithCharacter(char character, ConsoleColor textColor, ConsoleColor backgroundColor)
{
	COORD topLeft = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;
	HANDLE console = GetConsole();

	WORD color = (backgroundColor << 4) | textColor;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(console, character, screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
	FillConsoleOutputAttribute(console, color, screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
	SetConsoleCursorPosition(console, topLeft);
}

void CC::ClearKeyBuffer()
{
	while (_kbhit())
	{
		_getch();
	}
}

int CC::ReadNextKey()
{
	int KB_code = 0;

	if (_kbhit())
	{
		KB_code = _getch();
	}

	return KB_code;
}

int CC::WaitForReadNextKey()
{
	int KB_code = 0;

	while (KB_code == 0)
	{
		if (_kbhit())
		{
			KB_code = _getch();
		}
	}

	return KB_code;
}

char CC::WaitForReadNextChar()
{
	char c = 0;

	while (c == 0)
	{
		if (_kbhit())
		{
			c = _getch();
		}
	}

	return c;
}

void CC::Lock()
{
	GetInstance()._consoleMutex->lock();
}

void CC::Unlock()
{
	GetInstance()._consoleMutex->unlock();
}