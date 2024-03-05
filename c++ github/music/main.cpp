#include <iostream>
#include <windows.h>
#pragma comment(lib, "winmm.lib")

using namespace std;

int main() {
    bool played = PlaySound(TEXT("music.wav"), NULL, SND_SYNC);
    cout << "Success or not: " << played << endl;
    return 0;
}
