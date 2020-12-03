#include "DxLib.h"
#include "fileload.h"

//‰æ‘œ‚ğŠi”[‚·‚é
int g_mapHandle[2][88];
int g_characterHandle[CHARACTERS][12];

//‰æ‘œ‚ğ“Ç‚İ‚Ş
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
	DrawFormatString(0, 0, GetColor(255, 255, 255), "“Ç‚İ‚İ‚ª¸”s‚µ‚Ü‚µ‚½B");
}