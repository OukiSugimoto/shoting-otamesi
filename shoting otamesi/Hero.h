#pragma once
class Hero
{
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	/// <summary>
	/// 自動
	/// </summary>
	void Auto();

	/// <summary>
	/// 手動
	/// </summary>
	void Manual(char* key);

	float MoveTimer = 900.0f;

private:
	float posX, posY, heroSpeed;
	bool death = false;
	bool move = true;
	int HP;
	float max, min;
	int heroGraph[4];
	int index, animeTime;
};

