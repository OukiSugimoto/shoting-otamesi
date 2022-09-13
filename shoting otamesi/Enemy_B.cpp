#include "Enemy_B.h"

void Enemy_B::Initialize(float& posX, float& posY) {
	posX_ = posX;
	posY_ = posY;
	speed = 5.0f;
	deathTime = 200;
	death = false;
}
void Enemy_B::Update() {
	posY_ -= speed;
	if (--deathTime <= 0) {
		death = true;
	}
}
void Enemy_B::Draw() {

}
void Enemy_B::OnCollision() {
	death = true;
}