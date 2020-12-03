#ifndef FILELOAD_H
#define FILELOAD_H

#define CHARACTERS 2	//登場するキャラクターの数

extern int g_mapHandle[2][88];
extern int g_characterHandle[2][12];

void FileLoad();
void ErrorMessage();

#endif // !FILELOAD_H

