#include"enemy.h"
#include"Hero.h"
#include "DxLib.h"
#include "Window.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	ChangeWindowMode(TRUE);                   // ウィンドウモードに設定
	SetWindowSizeChangeEnableFlag(true, true);// ウィンドウサイズを手動では変更させず、かつウィンドウサイズに合わせて拡大できないようにする
	SetMainWindowText(TITLE);                 // タイトルを変更
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);  // 画面サイズの最大サイズ、カラービット数を設定(モニターの解像度に合わせる)
	SetWindowSizeExtendRate(1.0);             // 画面サイズを設定(解像度との比率で設定)
	SetBackgroundColor(0x00, 0x00, 0x00);     // 画面の背景色を設定する
	SetDrawScreen(DX_SCREEN_BACK);            // (ダブルバッファ)描画先グラフィック領域は裏面を指定
	if (DxLib_Init() == -1) { return -1; }    // DXlibの初期化

	// 画像などのリソースデータの変数宣言と読み込み
	int backGraph = LoadGraph("haikei.png");
	int backGraph2 = backGraph;

	// ゲームループで使う変数の宣言
	char keys[256] = { 0 };   // 最新のキーボード情報用
	char oldkeys[256] = { 0 };// 1ループ(フレーム)前のキーボード情報

	int speed = 0;
	float changeTime = 900.0f;

	bool moveFlage = false;
	
	Enemy *enemy = new Enemy;
	Hero* hero = new Hero;

	enemy->Initialize();
	hero->Initialize();

	// ゲームループ
	while (true)
	{
		// 最新のキーボード情報だったものは1フレーム前のキーボード情報として保存
		for (int i = 0; i < 256; i++)
		{
			oldkeys[i] = keys[i];
		}
		GetHitKeyStateAll(keys);// 最新のキーボード情報を取得
		ClearDrawScreen();      // 画面クリア

		//---------  ここからプログラムを記述  ----------//

		// 更新処理
		changeTime--;
		
		if (changeTime == 0) {
			if (moveFlage == false) {
				moveFlage = true;
			}
			else if (moveFlage == true) {
				moveFlage = false;
			}
			changeTime = 900.0f;
		}

		if (moveFlage == true) {
			enemy->Manual(keys);
			hero->Auto();
		}
		else {
			enemy->Auto();
			hero->Manual(keys);
		}
		
		enemy->Update();
		hero->Update();

		// 描画処理
		DrawGraph(0 , speed, backGraph, true);
		DrawGraph(0 ,-800 + speed,backGraph2,true);

		DrawFormatString(0, 0, GetColor(255, 255, 255), "timer = %3.0f", changeTime);
		enemy->Draw();
		
		hero->Draw();
		
		//---------  ここまでにプログラムを記述  ---------//

		ScreenFlip();// (ダブルバッファ)裏面
		WaitTimer(20);// 20ミリ秒待機(疑似60FPS)
		// Windowsシステムからくる情報を処理する
		if (ProcessMessage() == -1)
		{
			break;
		}
		// ESCキーが押されたらループから抜ける
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			break;
		}
	}
	DxLib_End();// Dxライブラリ終了処理

	return 0;// 正常終了
}
