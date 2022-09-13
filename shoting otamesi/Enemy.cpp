#include"DxLib.h"
#include "Enemy.h"
void Enemy::Initialize() {
	posX = 320.0f;
	posY = 160.0f;
	speed = 5.0f;
	death = false;
	move = true;
	HP = 100;
	max = 440.0f;
	min = 200.0f;
	enemyTimer = 180.0f;
	index = 0;
	animeTime = 0;
}

void Enemy::Update() {
	if (posX < 0) {
		posX = 0;
	}
	if (posX + 64 > 600) {
		posX = 536;
	}
	
}

void Enemy::Manual(char* key) {
		if (key[KEY_INPUT_A]) {
			posX -= speed;
		}
		else if (key[KEY_INPUT_D]) {
			posX += speed;
		}
}

void Enemy::Auto() {
		posX += speed;
		//ˆÚ“®
		if (posX + 64 > 600) {
			speed = -5.0f;
		}
		if (posX < 0) {
			speed = 5.0f;
		}
}

void Enemy::Draw() {
	LoadDivGraph("boss_anime64.png", 4, 4, 1, 64, 64, enemyGraph);
	animeTime++;
	if (animeTime >= 6)
	{
		index = (index + 1) % 4;

		animeTime = 0;
		
	}
	DrawGraph(posX, posY, enemyGraph[index], TRUE);
	DrawFormatString(0, 0, GetColor(255, 255, 255), "timer = %d", enemyTimer);
}
