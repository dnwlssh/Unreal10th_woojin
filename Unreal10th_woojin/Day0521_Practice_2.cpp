#include <iostream>
#include <stdio.h>
#include <time.h>
#include "Day0521_Practice_2.h"

using namespace std;

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
			PlayerDoBetAgain(Bet, MaxBet);
		}
		else
		{
			//플레이어가 이김 => 컴퓨터가 베팅
			Bet = rand() % MaxBet + 1;
			printf("컴퓨터가 [%d]원을 베팅했습니다.\n", Bet);
		}
		//베팅 금액 차감
		PlayerMoney = BettingMoneySub(PlayerMoney, Bet);
		ComputerMoney = BettingMoneySub(ComputerMoney, Bet);

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
			Draw(PlayerMoney, Bet);
			Draw(ComputerMoney, Bet);
		}
		Turn++;
	}
	EndGameSequence(PlayerMoney);

}

int RandDice()	//주사위 굴리기 함수
{
	int Dice = (rand() % 6) + 1;
	return Dice;
}

int GetMaxBet(int PlayerMoney, int ComputerMoney)
{
	int MaxBet = (PlayerMoney < ComputerMoney) ? PlayerMoney : ComputerMoney;
	return MaxBet;
}

int PlayerDoBetAgain(int Bet ,int MaxBet) //플레이어가 베팅하는 함수
{
	do
	{
		printf("베팅 금액을 입력하세요 (1 ~ %d) : ", MaxBet);
		cin >> Bet;
		cin.clear();
		cin.ignore(10000, '\n');
	} while (Bet < 1 || Bet > MaxBet);
	return Bet;
}

int BettingMoneySub(int ExtraMoney, int Bet) // 베팅 금액을 차감해주는 함수
{
	ExtraMoney -= Bet;
	return ExtraMoney;
}

int TotalDice(int Dice1, int Dice2) //두 주사위의 합을 구하는 함수
{
	int TotalDice = Dice1 + Dice2;
	return TotalDice;
}

int CreditCalCulater(int Money, int Bet)
{
	Money += (Bet * 2);
	return Money;
}

int Draw(int Money, int Bet)
{
	Money += Bet;
	return Money;
}


void EndGameSequence(int PlayerMoney) //게임 종료 출력함수
{
	printf("\n-------------- 게임 종료  --------------\n");
	if (PlayerMoney > 0)
	{
		printf("당신의 최종 승리\n");
	}
	else
	{
		printf("컴퓨터의 최종 승리\n");
	}
}





