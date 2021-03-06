// LangtonsAntConsole.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "olcConsoleGameEngine.h"

using namespace std;

class LangtonsAntConsole : public olcConsoleGameEngine
{
public:
	LangtonsAntConsole() {
		m_sAppName = L"Langton's Ant";
	}

private:
	int grid[400][400];
	int x;
	int y;
	int dir;

	const int ANTUP = 0;
	const int ANTRIGHT = 1;
	const int ANTDOWN = 2;
	const int ANTLEFT = 3;

	void turnRight() {
		dir++;
		if (dir > ANTLEFT) {
			dir = ANTUP;
		}
	}

	void turnLeft() {
		dir--;
		if (dir < ANTUP) {
			dir = ANTLEFT;
		}
	}

	void moveForward() {
		if (dir == ANTUP) {
			y--;
		} else if (dir == ANTRIGHT) {
			x++;
		} else if (dir == ANTDOWN) {
			y++;
		} else if (dir == ANTLEFT) {
			x--;
		}

		if (x > ScreenWidth() - 1) {
			x = 0;
		} else if (x < 0) {
			x = ScreenWidth() - 1;
		}

		if (y > ScreenHeight() - 1) {
			y = 0;
		} else if (y < 0) {
			y = ScreenHeight() - 1;
		}
	}

	virtual bool OnUserCreate() {
		x = ScreenWidth() / 2;
		y = ScreenHeight() / 2;
		dir = ANTUP;

		return true;
	}

	virtual bool OnUserUpdate(float fElapsedTime) {
		int state = grid[x][y];
		if (state == 0) {
			turnRight();
			grid[x][y] = 1;
		} else if (state == 1) {
			turnLeft();
			grid[x][y] = 0;
		}

		if (grid[x][y] == 1) {
			Draw(x, y, PIXEL_SOLID, FG_BLACK);
		} else {
			Draw(x, y, PIXEL_SOLID, FG_WHITE);
		}

		moveForward();

		return true;
	}
};


int main()
{
	LangtonsAntConsole langtonsAnt;
	langtonsAnt.ConstructConsole(400, 400, 2, 2);
	langtonsAnt.Start();
    return 0;
}

