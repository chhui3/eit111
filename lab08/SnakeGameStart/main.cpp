// olcPixelGameEngine is a tool used in javidx9's YouTube videos and projects.
// Copyright 2018, 2019, 2020 OneLoneCoder.com

#include <iostream>
using namespace std;

// use olcPixelGameEngine
#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"


// modify this class to implement the game
class GameApp : public olc::PixelGameEngine
{
private:
	static const int snakeBuf = 200;
	float fTimePassed = 0.;
	float fFrameDuration = 0.1f;
	int iVelocity = 1;
	olc::vf2d i2dVelocity = { iVelocity, 0 };
	olc::vf2d iFoodPosition = { 9, 18 };
	int snakeLen = 1;
	olc::vi2d snake[snakeBuf];

public:
	bool OnUserCreate() {
		snakeLen = 2;
		olc::vi2d snakeHead = { 5, 5 };
		snake[0] = snakeHead;
		snake[1] = snakeHead - olc::vi2d({ 1, 0 });
		//for (int i = 0; i < snakeLen; i++) {
		//	if (i == 0) snake[i] = snakeHead;
		//}
		return true;
	}
	bool OnUserUpdate(float fElapsedTime) {
		// this_thread::sleep_for(250ms);

		if (GetKey(olc::Key::LEFT).bPressed) i2dVelocity = olc::vi2d{ -iVelocity, 0 };
		if (GetKey(olc::Key::RIGHT).bPressed) i2dVelocity = olc::vi2d{ iVelocity, 0 };
		if (GetKey(olc::Key::DOWN).bPressed) i2dVelocity = olc::vi2d{ 0, iVelocity };
		if (GetKey(olc::Key::UP).bPressed) i2dVelocity = olc::vi2d{ 0, -iVelocity };

		//snake[0] += f2dVelocity * fElapsedTime;
		fTimePassed += fElapsedTime;
		if (fTimePassed > fFrameDuration) {
			Clear(olc::BLACK);
			UpdateSnake();
			CheckEat();
			DrawSnake();
			DrawFood();
			fTimePassed = 0.0;
		}
		return true;
	}
	bool DrawFood() {
		Draw(iFoodPosition, olc::RED);
		return 0;
	}
	bool DrawSnake() {
		for (int i = 0; i < snakeLen; i++) {
			Draw(snake[i]);
		}
		return true;
	}
	bool UpdateSnake() {
		for (int i = snakeLen - 1; i > 0; i--) {
			snake[i] = snake[i - 1];
		}
		snake[0] += i2dVelocity;
		snake[0].x = snake[0].x < 0 ? 22 : snake[0].x;
		snake[0].x = snake[0].x > 22 ? 0 : snake[0].x;

		return true;
	}
	bool CheckEat() {
		if (snake[0] == iFoodPosition) {
			snakeLen++;
			UpdateSnake();
			NewFood();
		}
		return true;
	}
	bool NewFood() {
		iFoodPosition = olc::vi2d({ 1 + rand() % 20, 1 + rand() % 20 });
		return true;
	}

};

int main()
{
	GameApp app;
	app.Construct(22, 22, 20, 20);  // 22 by 22 pixel grid, pixel size 40
	app.Start();

	return 0;
}
