#include "Game.h"
#include <limits>
#include <ios>
#include <iostream>

using namespace std;

int main() {
    // 초마다 랜덤하게 생성
    srand((unsigned int)time(0));

    cout << "======= Gacha Game LIfe 랜덤 게임 시작 =======\n" << endl;
    cout << "======= 행복도가 100 or 돈이 50만원이 넘으면 게임 clear! =======" << endl;

    // Game 클래스의 인스턴스 생성
    Game myGame;

    myGame.printStatus();

    // 게임 루프
    while (!myGame.isGameFinished()) {

        // ** LOSE 조건 1: 돈 부족 (뽑기 전 확인)**
        // Game 클래스 내부에 money 변수가 private이므로, 
        // 외부에서 money를 직접 접근하는 대신 돈 부족 여부를 확인하는 
        // 공용 함수를 Game.h에 추가하는 것이 좋습니다.
        // 하지만 편의상 현재 구조에서는 money < 1000 체크는 Game::startNextTurn()
        // 내부에서 더 깔끔하게 처리하는 것이 좋습니다. (아래 설명을 위해 임시로 제외)

        cout << "\n ** 엔터를 누르면 뽑기 (1회 비용: 10000원)가 진행됩니다. ** \n";
       

        // Enter 입력 대기
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        cout << "\n === 무언가가 나오는 중.... ===\n\n **";

        // 다음 턴 시작
        myGame.startNextTurn();

        // 게임 오버가 아니라면, 업데이트된 상태 출력
        if (!myGame.isGameFinished()) {
            myGame.printStatus();
        }
    }

    // 게임 종료 (WIN/LOSE) 메시지 출력
    cout << "\n==== 게임이 종료되었습니다 ====\n" << endl;

    return 0;


}