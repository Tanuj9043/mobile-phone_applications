#ifndef BOX_H
#define BOX_H
#include <windows.h>
using namespace std;

void printBox()
{
    cout << endl << endl << endl << endl << endl << endl;
    for(int i=0; i<=15; i++) cout << " ";
    cout << (char)201;
    for(int i=0; i<=35; i++) cout << (char)205;
    cout << (char)187;
    cout << endl;
    for(int i=0; i<2; i++){
            for(int i=0; i<=15; i++) cout << " ";
    cout << (char)186;
    for(int i=0; i<=35; i++) cout << " ";
    cout << (char)186 << endl;
    }
    for(int i=0; i<=15; i++) cout << " ";
    cout << (char)186;
    for(int i=0; i<=12; i++) cout << " ";

    HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
      WORD wOldColorAttrs;
      CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

      /*
       * First save the current color information
       */
      GetConsoleScreenBufferInfo(h, &csbiInfo);
      wOldColorAttrs = csbiInfo.wAttributes;

      /*
       * Set the new color information
       */
      SetConsoleTextAttribute ( h, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
      cout << "THANK YOU";

      /*
       * Restore the original colors
       */
      SetConsoleTextAttribute ( h, wOldColorAttrs);


    for(int i=0; i<=13; i++) cout << " ";
    cout << (char)186;
    cout << endl;
    for(int i=0; i<2; i++){
            for(int i=0; i<=15; i++) cout << " ";
    cout << (char)186;
    for(int i=0; i<=35; i++) cout << " ";
    cout << (char)186 << endl;
    }
    for(int i=0; i<=15; i++) cout << " ";
    cout << (char)200;
    for(int i=0; i<=35; i++) cout << (char)205;
    cout << (char)188;
    cout << endl << endl << endl << endl << endl << endl;
}
#endif
