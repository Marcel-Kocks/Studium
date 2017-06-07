// Bingo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "gamemaster.h"
#include <string>

#include <crtdbg.h>

#define _CRTDBG_MAP_ALLOC

#define new DEBUGNEW
#ifdef _DEBUG
#define DEBUGNEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#else  
#define DEBUGNEW new
#endif

using namespace std;
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	gamemaster boss;

	boss.createPlayer("Marcel");
	boss.createPlayer("Lucas");
	boss.createPlayer("Thomas");
	boss.createPlayer("Arthur");

	boss.play();

	system("PAUSE");
    return 0;
}

