#include"DxLib.h"
#include "Hero.h"
void Hero::Initialize() {
	posX = 320.0f;
	posY = 700.0f;
	heroSpeed = 5.0f;
	death = false;
	move = false;
	HP = 100;
	max = 440.0f;
	min = 200.0f;
	MoveTimer = 900.0f;
	index = 0;
	animeTime = 0;
}

void Hero::Update() {
	if (posX < 0) {
		posX = 0;
	}
	if (posX + 32 > 600) {
		posX = 568;
	}
}

void Hero::Manual(char* key) {
		if (key[KEY_INPUT_A]) {
			posX -= heroSpeed;
		}
		else if (key[KEY_INPUT_D]) {
			posX += heroSpeed;
		}
}

void Hero::Auto() {
	if (move == false) {
		posX += heroSpeed;
		//ˆÚ“®
		if (posX + 32 > 600) {
			heroSpeed = -5.0f;
		}
		if (posX < 0) {
			heroSpeed = 5.0f;
		}
	}
}

void Hero::Draw() {
	LoadDivGraph("player_anime32.png", 4, 4, 1, 32, 32, heroGraph);
	animeTime++;
	if (animeTime >= 6)
	{
		index = (index + 1) % 4;

		animeTime = 0;

	}
	DrawGraph(posX, posY, heroGraph[index], TRUE);

}
