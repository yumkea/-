#include <iostream>
#include <windows.h>
#include "func.cpp"
#include "func1.cpp"

using namespace std;

/*�������---������*/
int main()
{    
  
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // ��ȡ��׼������
    SMALL_RECT windowSize = {0, 0, 60, 20}; // ���ô��ڵ����ϽǺ����½�����
    SetConsoleWindowInfo(hConsole, TRUE, &windowSize); // ���ô��ڴ�С
    COORD bufferSize = {65, 30}; // ���û�������С
    SetConsoleScreenBufferSize(hConsole, bufferSize); // ���û�������
    CONSOLE_FONT_INFOEX fontInfo;
    fontInfo.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    GetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo); // ��ȡ��ǰ������Ϣ
    fontInfo.dwFontSize.X = 20; // ����������
    fontInfo.dwFontSize.Y = 20; // ��������߶�
    SetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo); // ���������С
	CONSOLE_SCREEN_BUFFER_INFOEX bufferInfo;
    bufferInfo.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
    GetConsoleScreenBufferInfoEx(hConsole, &bufferInfo); // ��ȡ����̨��������Ϣ
    bufferInfo.ColorTable[0] = RGB(0, 0, 0); // ����һ����ɫ����Ϊ��ɫ
    bufferInfo.wAttributes &= ~(BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE); // ���ԭ�б�����ɫ
    bufferInfo.wAttributes |= BACKGROUND_INTENSITY; // ���ñ�����ɫΪ����
    SetConsoleScreenBufferInfoEx(hConsole, &bufferInfo); // ���ÿ���̨��������Ϣ
	Init_LinkList(L);
	Read_LinkList(L);
	menu1(L);
	return 0;
}







