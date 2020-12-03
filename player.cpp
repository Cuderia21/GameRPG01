#include "DXLib.h"
#include "player.h"
#include "fileload.h"

//プレイヤーを移動する
//引数１：プレイヤーのｘ座標
//引数２：プレイヤーのｙ座標
//引数３：現在の向き
//引数４：アニメーションの順番
void MovePlayer(int *x, int *y, int *vector, int *turn)
{
    //int vector = 1; //現在の向き
    //int turn = 0;   //移動時のアニメーションの順番
    //上に移動する
    if (CheckHitKey(KEY_INPUT_UP) != 0)     
    {
        *y -= WALK_SPEED;
        //上向きのとき
        if (*vector < 9 || *vector > 11)
        {
            *vector = 9;
            *turn = 1;
        }
        else {
            *vector += *turn;
            if (*vector == 11)
            {
                *turn = -1;
            }
            else if (*vector == 9)
            {
                *turn = 1;
            }
        }
    }
    //下に移動する
    if (CheckHitKey(KEY_INPUT_DOWN) != 0)
    {
        *y += WALK_SPEED;
        if (*vector < 0 || *vector > 2)
        {
            *vector = 0;
            *turn = 1;
        }
        else {
            *vector += *turn;
            if (*vector == 2)
            {
                *turn = -1;
            }
            else if (*vector == 0)
            {
               *turn = 1;
            }
        }
    }
    //右に移動する
    if (CheckHitKey(KEY_INPUT_RIGHT) != 0)
    {
        *x += WALK_SPEED;
        if (*vector < 6 || *vector > 8)
        {
            *vector = 6;
            *turn = 1;
        }
        else {
            *vector += *turn;
            if (*vector == 8)
            {
                *turn = -1;
            }
            else if (*vector == 6)
            {
                *turn = 1;
            }
        }
    }
    //左に移動する
    if (CheckHitKey(KEY_INPUT_LEFT) != 0)
    {
        *x -= WALK_SPEED;
        if (*vector < 3 || *vector > 5)
        {
            *vector = 3;
            *turn = 1;
        }
        else {
            *vector += *turn;
            if (*vector == 5)
            {
                *turn = -1;
            }
            else if (*vector == 3)
            {
                *turn = 1;
            }
        }
    }
}

//プレイヤーを表示する
void DisplayPlayer()
{
    static int x = 0;   //プレイヤーのｘ座標
    static int y = 0;   //プレイヤーのｙ座標
    static int vector = 1;
    static int turn = 0;

    MovePlayer(&x, &y, &vector, &turn);
    DrawGraph(x, y, g_characterHandle[0][vector], TRUE);
}

//プレイヤーの現在の向きを確認する
/*void CheckVectorPlayer(int *vector, int *turn)
{
    
}*/

