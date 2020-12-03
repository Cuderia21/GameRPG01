#include "DxLib.h"
#include "main.h"
#include "fileload.h"
#include "player.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // ウィンドウモードに設定
    ChangeWindowMode(TRUE);
    // DXライブラリ初期化処理
    if (DxLib_Init() != 0) {
        //エラーなら終了する
        return -1;
    }
    //描画先を裏画面にする
    SetDrawScreen(DX_SCREEN_BACK);

    //画像を読み込む
    FileLoad();

    // 画面モードの変更 
    // SetGraphMode(800, 600, 32);

    // while(裏画面を表画面に反映, メッセージ処理, 画面クリア)
    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) 
    {
        //DrawFormatString(0, 0, GetColor(255, 255, 255), "ESCキーで終了します");
        /*int num = 0;
        for (int x = 0; x < 4; x++)
        {
            for (int y = 0; y < 3; y++)
            {
               // DrawGraph(y * 32, x * 32, g_mapHandle[0][num], FALSE);
                DrawGraph(y * 32, x * 32, g_characterHandle[0][num],TRUE);
                num++;
            }
        }*/
        /*DrawGraph(hero_pos_x, hero_pos_y, g_characterHandle[0][1], TRUE);
        if (CheckHitKey(KEY_INPUT_UP) != 0) 
        {
            hero_pos_y -= WALK_SPEED;
        }
        if (CheckHitKey(KEY_INPUT_DOWN) != 0) 
        {
            hero_pos_y += WALK_SPEED;
        }
        if (CheckHitKey(KEY_INPUT_RIGHT) != 0) 
        {
            hero_pos_x += WALK_SPEED;
        }
        if (CheckHitKey(KEY_INPUT_LEFT) != 0) 
        {
            hero_pos_x -= WALK_SPEED;
        }*/
        DisplayPlayer();

        if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) 
        {
            break;
        }
    }
    // DXライブラリ終了処理
    DxLib_End();   
    return 0;
}