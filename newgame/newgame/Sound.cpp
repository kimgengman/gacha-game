#include "Sound.h"
#include <windows.h> // 실제 구현 파일에도 포함

void playMelody()
{
    // 멜로디: 솔 솔 라 라 솔 솔 미, 솔 솔 미 미 레
    int melody[] = {
        392,
        392,
        392,
        440,
        440,
        392,
        392,
        329,
        // 솔 솔 라 라 솔 솔 미
        392,
        392,
        329,
        329,
        294         // 솔 솔 미 미 레
    };
    int duration = 200;
    int rest = 30;

    int melodySize = sizeof(melody) / sizeof(melody[0]);

    // 멜로디 재생
    for (int i = 0; i < melodySize; i++) {
        Beep(melody[i], duration);
        Sleep(rest);
    }
}
