#include <iostream>
#include <string>
#include "windows.h"
#include <shellapi.h>
#pragma comment(lib,"shell32.lib") 
using namespace std;
namespace games {
	class Snake {
	public:
		void play() {
			ShellExecuteA(NULL, LPCSTR("open"), "C:/Users/saich/Documents/Programming/Misc/snake_game.html",
				NULL, NULL, SW_SHOWNORMAL);
		}
	};
}