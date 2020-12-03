#include "DXLib.h"
#include "player.h"
#include "fileload.h"

//�v���C���[���ړ�����
//�����P�F�v���C���[�̂����W
//�����Q�F�v���C���[�̂����W
//�����R�F���݂̌���
//�����S�F�A�j���[�V�����̏���
void MovePlayer(int *x, int *y, int *vector, int *turn)
{
    //int vector = 1; //���݂̌���
    //int turn = 0;   //�ړ����̃A�j���[�V�����̏���
    //��Ɉړ�����
    if (CheckHitKey(KEY_INPUT_UP) != 0)     
    {
        *y -= WALK_SPEED;
        //������̂Ƃ�
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
    //���Ɉړ�����
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
    //�E�Ɉړ�����
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
    //���Ɉړ�����
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

//�v���C���[��\������
void DisplayPlayer()
{
    static int x = 0;   //�v���C���[�̂����W
    static int y = 0;   //�v���C���[�̂����W
    static int vector = 1;
    static int turn = 0;

    MovePlayer(&x, &y, &vector, &turn);
    DrawGraph(x, y, g_characterHandle[0][vector], TRUE);
}

//�v���C���[�̌��݂̌������m�F����
/*void CheckVectorPlayer(int *vector, int *turn)
{
    
}*/

