


#include <iostream>
#include <stdio.h>
#include <time.h>
#include "Day0521_Practice_1.h"
#include "Day0521_Practice_2.h"
#include "Day0521_Practice_3.h"

using namespace std;

void Pratice_1()
{
    int State = None;
    //플레이어의 상태를 대기로 설정
    State = StateAdd(State, Standby);
    ShowMeTheState(State);

    //점프 상태 추가
    State = StateAdd(State, Jump);
    ShowMeTheState(State);

    //공격 상태 추가
    State = StateAdd(State, Attack);
    ShowMeTheState(State);

    //대기 상태 해제
    State = StateSub(State, Standby);
    ShowMeTheState(State);

    //무적 상태 추가
    State = StateAdd(State, Invincable);
    ShowMeTheState(State);

    //무적 상태 토글 (XOR)
    State = StateToggle(State, Invincable);
    ShowMeTheState(State);
}

void Practice_2()
{
    const int InitialMoney = 10000;			//시작시 소유 금액
    unsigned int Seed = (unsigned int)time(0);
    Seed = 0;

    srand((unsigned int)time(0));		//시드 값 초기화

    int PlayerMoney = InitialMoney;			//플레이어 소유 금액
    int ComputerMoney = InitialMoney;		//컴퓨터 소유 금액

    //주사위 값 저장 변수 생성
    int PlayerDice1 = 0;					//플레이어 첫번째 주사위 값
    int PlayerDice2 = 0;					//플레이어 두번째 주사위 값
    int ComputerDice1 = 0;					//컴퓨터 첫번째 주사위 값
    int ComputerDice2 = 0;					//컴퓨터 두번째 주사위 값

    int Bet = 0;								//현재 베팅 금액 (각각의)
    bool PlayerLost = false;				//이전판의 승자 기록용 bool (총 플레이어가 2명이기 때문에 bool로 생성, Player가 지면 True, 플레이어가 이기면 False)
    int MaxBet;		//최대 베팅 금액


    int Turn = 1;						// 현재 턴

	while (PlayerMoney > 0 && ComputerMoney > 0) // 둘중 돈이 남아 있는 한 반복
	{
		//턴 상황 표시
		printf("\n-------------- %d 회차 --------------\n", Turn);
		printf("플레이어 금액 : [%d]\t|\t컴퓨터 금액 : [%d]\n", PlayerMoney, ComputerMoney);

		//1차 주사위 굴리기
		const int DiceSize = 6;
		PlayerDice1 = RandDice();
		ComputerDice1 = RandDice();
		printf("플레이어 1차 주사위 : %d\n", PlayerDice1);
		printf("컴퓨터 1차 주사위 : %d\n", ComputerDice1);

		//베팅
		//if (PlayerMoney < ComputerMoney)
		//{
		//	MaxBet = PlayerMoney;
		//}
		//{
		//	MaxBet = ComputerMoney;
		//}
		//3항연산자로 만들시
		MaxBet = GetMaxBet(PlayerMoney, ComputerMoney);

		if (PlayerLost)
		{
			//플레이어가 졌을 시 => 플레이어 베팅
			PlayerDoBetAgain(Bet,MaxBet);
		}
		else
		{
			//플레이어가 이김 => 컴퓨터가 베팅
			Bet = rand() % MaxBet + 1;
			printf("컴퓨터가 [%d]원을 베팅했습니다.\n", Bet);
		}
		//베팅 금액 차감
		PlayerMoney = BettingMoneySub(PlayerMoney, Bet);
		ComputerMoney= BettingMoneySub(ComputerMoney, Bet);

		//2차 주사위 굴리기
		PlayerDice2 = RandDice();
		ComputerDice2 = RandDice();
		printf("플레이어 2차 주사위 : %d\n", PlayerDice2);
		printf("컴퓨터 2차 주사위 : %d\n", ComputerDice2);

		// 주사위 합계 출력
		int PlayerSum = TotalDice(PlayerDice1, PlayerDice2);
		int ComputerSum = TotalDice(ComputerDice1, ComputerDice2);
		printf("=================================\n");
		printf("플레이어 주사위 합계 : %d\n", PlayerSum);
		printf("컴퓨터 주사위 합계 : %d\n", ComputerSum);

		//승패 판정
		if (PlayerSum > ComputerSum)
		{
			printf("플레이어 승리! 플레이어가 [%d]원을 획득 합니다.\n", Bet * 2);
			CreditCalCulater(PlayerMoney, Bet);
			PlayerLost = false;
		}
		else if (ComputerSum > PlayerSum)
		{
			printf("컴퓨터 승리! 컴퓨터가 [%d]원을 획득 합니다.\n", Bet * 2);
			CreditCalCulater(ComputerMoney, Bet);
			PlayerLost = true;
		}
		else
		{
			printf("무승부입니다. 베팅금액은 반환됩니다.");
			Draw(PlayerMoney,Bet);
			Draw(ComputerMoney,Bet);
		}
		Turn++;
	}
		EndGameSequence(PlayerMoney);
	
}

void Practice_3()
{
	const int InitialMoney = 10000;	// 게임 시작할 때 플레이어의 돈
	const int MinimumBet = 100;		// 최소 배팅 금액
	const int WinMultiplier = 2;	// 이겼을 때 배율
	
	int Money = InitialMoney;		// 플레이어의 현재 돈
	int CurrentBet = MinimumBet;	// 현재 배팅 금액
	
	unsigned int Seed = (unsigned int)time(0);
	Seed = 0;		// 테스트용으로 임시로 설정
	
	srand(Seed);	// 시드값 초기화
	
	while (Money >= 100)	// 게임 종료 조건 : 플레이어가 소지금이 100원 미만일 경우 게임 종료.
	{
	// 배팅
	// 플레이어는 기본금 100원으로 베팅을 시작한다.
		LetsBet(Money, CurrentBet);

	// 홀짝 선택
	//	플레이어가 1(홀)또는 2(짝)을 선택한다.
		int Select = ChooseOddOrEven(Select);

	// 결과 결정
	//	컴퓨터가 랜덤으로 1(홀)또는 2(짝)을 선택한다.
	//	플레이어의 선택과 결과가 일치하면 승리(이기면 배팅금의 2배 획득), 다르면 패배(배팅금 전액 잃음).
		int Result = RandOddOrEven(Result); 	// 랜덤으로 1 or 2 고르기
	
		printf("결과는 [%s]입니다.\n", (Result == 1) ? "홀" : "짝");
 
		if (Select == Result)
		{
			PirzeOrKeepoing(MinimumBet, CurrentBet, Money);
		}
		else
		{
			printf("안타깝네요! 배팅한 [%d]원을 모두 잃었습니다.\n", CurrentBet);
			CurrentBet = MinimumBet;	// 배팅 금액 초기화
		}
	}
	printf("소지금이 부족해서 더 이상 진행할 수 없습니다.\n");
}

int main()
{
    //Practice_2();
}