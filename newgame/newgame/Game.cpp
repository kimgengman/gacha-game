#include "Game.h"
#include "Sound.h"

// 생성자
Game::Game() : happy(50), money(100000), hasKey(false), isGameOver(false) {
    // 난수 생성기 시드 초기화는 main에서 한 번만 하는 것이 일반적이지만,
    // 여기서는 Game 인스턴스마다 초기화되지 않도록 주의해야 합니다.
    // 편의상 main 함수에서 srand(time(0))을 호출하는 것을 추천합니다.
}

// 상태 출력 함수 const 
void Game::printStatus() const {

    std::cout << "\n==================================" << std::endl;
    std::cout << " 현재 상태: 행복(" << happy << "), 돈(" << money << "원)";
    std::cout << std::endl << "==================================" << std::endl;
}

// 이벤트 실행 함수
void Game::runEvent() {
    // 1부터 100까지의 랜덤 숫자 생성
    int randomNumber = (rand() % 100) + 1;

    std::cout << " 뽑기 결과: ";

    if (randomNumber <= 3) { // 1~3 (3%)
        std::cout << " 황금 열쇠 획득! " << std::endl;
        hasKey = true;
    }
    else if (randomNumber <= 24) { // 4~24 (21%)
        std::cout << " 돈 +10,000원! (^-^ $$)" << std::endl;
        money += 10000;
    }
    else if (randomNumber <= 34) { // 25~34 (10%)
        std::cout << " 행복 -30! (ㅠㅠ)" << std::endl;
        happy -= 30;
    }
    else if (randomNumber <= 44) { // 35~44 (10%)
        std::cout << " 행복 +10! (O.O)" << std::endl;
        happy += 10;
    }
    else if (randomNumber <= 54) { // 45~54 (10%)
        std::cout << " 행복 +30! (O^O)" << std::endl;
        happy += 30;
    }
    else if (randomNumber <= 64) { // 55~64 (10%)
        std::cout << " 행복 +20! (>_<!!!!)" << std::endl;
        happy += 20;
    }
    else if (randomNumber <= 74) { // 65~74 (10%)
        std::cout << " 행복 -10! (@~@....)" << std::endl;
        happy -= 10;
    }
    else if (randomNumber <= 84) { // 75~84 (10%)
        std::cout << " 행복 -20! (-_-^)" << std::endl;
        happy -= 20;
    }
    else if (randomNumber <= 89) { // 85~89 (5%)
        std::cout << " 돈 +20,000원 ($_$!!!!!)" << std::endl;
        money += 20000;
    }
    else if (randomNumber <= 92) { // 90~92 (3%)
        std::cout << " 돈 -30,000원 (+_+.....)" << std::endl;
        money -= 30000;
    }
    else { // 93~100 (3%)
        std::cout << " 행복 -50 (ㅠ_ㅠ)" << std::endl;
        happy -= 50;
    }

    // 최소/최대값 제한
    if (happy < 0) happy = 0;
    if (money < 0) money = 0;
}

// 게임 종료 조건 확인 함수
void Game::checkGameStatus() {
    // WIN 조건
    if (hasKey || happy >= 100 || money >= 500000) {
        std::cout << "\n 게임 클리어! (WIN) " << std::endl;
        isGameOver = true;
        return;
    }
    // LOSE 조건
    else if (happy <= 0 || money <= 0) {
        std::cout << "\n 게임 오버! (LOSE) " << std::endl;
		restart();  
    }
}


// 게임 재시작 함수    

void Game::restart() {
    char choice;
    std::cout << "\n게임이 종료되었습니다. 다시 시작하시겠습니까? (y/n): ";
    std::cin >> choice;


    if (choice == 'y' || choice == 'Y') {
  
        happy = 50;
        money = 100000;
        hasKey = false;
        isGameOver = false;

        std::cout << "\n==== 게임이 재시작되었습니다! ====\n";

     
    }
    else {
        std::cout << "\n게임을 종료합니다.\n";
        isGameOver = true; 
    }
}


// 다음 턴을 진행하는 메인 로직 함수
void Game::startNextTurn() {

    playMelody(); // <--- 외부 함수 호출

    // 뽑기 비용 차감
    money -= 10000;

    // 이벤트 실행 및 상태 업데이트
    runEvent();

    // 게임 종료 조건 확인
    checkGameStatus();
}