#pragma once
class Hero
{
public:
	/// <summary>
	/// ������
	/// </summary>
	void Initialize();

	/// <summary>
	/// �X�V
	/// </summary>
	void Update();

	/// <summary>
	/// �`��
	/// </summary>
	void Draw();

	/// <summary>
	/// ����
	/// </summary>
	void Auto();

	/// <summary>
	/// �蓮
	/// </summary>
	void Manual(char* key);

	float MoveTimer = 1800.0f;

private:
	float posX, posY, speed;
	bool death = false;
	bool move = true;
	int HP;
	float max, min;
	int heroGraph[4];
	int index, animeTime;
};

