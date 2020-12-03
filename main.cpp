#include "DxLib.h"
#include "main.h"
#include "fileload.h"
#include "player.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // �E�B���h�E���[�h�ɐݒ�
    ChangeWindowMode(TRUE);
    // DX���C�u��������������
    if (DxLib_Init() != 0) {
        //�G���[�Ȃ�I������
        return -1;
    }
    //�`���𗠉�ʂɂ���
    SetDrawScreen(DX_SCREEN_BACK);

    //�摜��ǂݍ���
    FileLoad();

    // ��ʃ��[�h�̕ύX 
    // SetGraphMode(800, 600, 32);

    // while(����ʂ�\��ʂɔ��f, ���b�Z�[�W����, ��ʃN���A)
    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) 
    {
        //DrawFormatString(0, 0, GetColor(255, 255, 255), "ESC�L�[�ŏI�����܂�");
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
    // DX���C�u�����I������
    DxLib_End();   
    return 0;
}