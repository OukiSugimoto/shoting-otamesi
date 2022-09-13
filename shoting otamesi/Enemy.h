#pragma once

class Enemy
{
public:
	/// <summary>
	/// ‰Šú‰»
	/// </summary>
	void Initialize();

	/// <summary>
	/// XV
	/// </summary>
	void Update();

	/// <summary>
	/// •`‰æ
	/// </summary>
	void Draw();

	/// <summary>
	/// ©“®
	/// </summary>
	void Auto();

	/// <summary>
	/// è“®
	/// </summary>
	void Manual(char *key);

	float enemyTimer = 1800.0f;
private:
	float posX, posY, speed;
	bool death = false;
	bool move = true;
	int HP;
	float max, min;
	int enemyGraph[4];
	int index, animeTime;
};

