#include "DxLib.h"
#include "fileload.h"

//画像を格納する
int g_mapHandle[2][88];
int g_characterHandle[CHARACTERS][12];

//画像を読み込む
void FileLoad()
{
	if (LoadDivGraph("Mapchip/pipo-map001.png", 88, 8, 11, 32, 32, g_mapHandle[0]) != 0)
	{
		//ErrorMessage();
	}
	if(LoadDivGraph("Character/pipo-charachip021.png",12,3,4,32,32,g_characterHandle[0]) != 0)
	{
		//ErrorMessage();
	}
}

void ErrorMessage()
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "読み込みが失敗しました。");
}