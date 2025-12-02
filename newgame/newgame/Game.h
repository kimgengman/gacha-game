#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <cstdlib> // rand, srand
#include <ctime>   // time

class Game {
private:
    // 게임 상태 변수
    int happy;
    int money;
    bool hasKey;
    bool isGameOver;

    // 내부 로직 함수
    void checkGameStatus();
    void runEvent();

public:
    // 생성자 (초기값 설정)
    Game();

    // 외부에서 호출할 게임 진행 함수
    void printStatus() const; // const: 멤버 변수를 변경하지 않음
    bool isGameFinished() const { return isGameOver; }
    void startNextTurn();
    void restart();
};

#endif // GAME_H
