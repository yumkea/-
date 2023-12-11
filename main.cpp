#include <iostream>
#include <windows.h>
#include "func.cpp"
#include "func1.cpp"

using namespace std;

/*程序入口---主函数*/
int main()
{    
  
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // 获取标准输出句柄
    SMALL_RECT windowSize = {0, 0, 60, 20}; // 设置窗口的左上角和右下角坐标
    SetConsoleWindowInfo(hConsole, TRUE, &windowSize); // 设置窗口大小
    COORD bufferSize = {65, 30}; // 设置缓冲区大小
    SetConsoleScreenBufferSize(hConsole, bufferSize); // 设置缓冲区大
    CONSOLE_FONT_INFOEX fontInfo;
    fontInfo.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    GetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo); // 获取当前字体信息
    fontInfo.dwFontSize.X = 20; // 设置字体宽度
    fontInfo.dwFontSize.Y = 20; // 设置字体高度
    SetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo); // 设置字体大小
	CONSOLE_SCREEN_BUFFER_INFOEX bufferInfo;
    bufferInfo.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
    GetConsoleScreenBufferInfoEx(hConsole, &bufferInfo); // 获取控制台缓冲区信息
    bufferInfo.ColorTable[0] = RGB(0, 0, 0); // 将第一个颜色设置为黑色
    bufferInfo.wAttributes &= ~(BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE); // 清除原有背景颜色
    bufferInfo.wAttributes |= BACKGROUND_INTENSITY; // 设置背景颜色为高亮
    SetConsoleScreenBufferInfoEx(hConsole, &bufferInfo); // 设置控制台缓冲区信息
	Init_LinkList(L);
	Read_LinkList(L);
	menu1(L);
	return 0;
}







