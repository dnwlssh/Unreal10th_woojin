


#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

void RockPaperScissors()
{
	srand(time(0));
	enum RPC
	{
		Scissors = 1,
		Rock,
		Paper	
	};

	int PlayerHand = 0;		// 플레이어 핸드
	int PlayerWinning = 0;		// 플레이어 승리 스택
	int ComputerWinning = 0;	// 컴퓨터 승리 스택
		
	while (true)
	{
		printf("점수\n플레이어[%d] | 컴퓨터 [%d]\n", PlayerWinning, ComputerWinning);
		printf("나의 핸드 선택\n1.가위\n2.바위\n3.보\n[나의 핸드] : ");
		cin >> PlayerHand;

			int ComputerHand = (rand() % 3) + 1;

			printf("나의 핸드 : %d | ", PlayerHand);
			printf("컴퓨터의 핸드 : %d\n", ComputerHand);
			printf("--------------------------------\n");

			switch (ComputerHand)
			{
			case Scissors://1		//컴퓨터가 가위
				if (PlayerHand == Scissors) //플레이어 가위 
				{
					printf("비겼습니다.\n");
				}
				else if (PlayerHand == Rock) //플레이어 바위 
				{
					printf("플레이어가 이겼습니다.\n");
					PlayerWinning++;
				}
				else // 플레이어 보
				{
					printf("컴퓨터가 이겼습니다.\n");
					ComputerWinning++;
				}
				PlayerHand = 0;
				ComputerHand = 0;
				break;

			case Rock://2		//컴퓨터가 바위
				if (PlayerHand == Scissors) //플레이어 가위 
				{
					printf("컴퓨터가 이겼습니다.\n");
					ComputerWinning++;
				}
				else if (PlayerHand == Rock) //플레이어 바위 
				{
					printf("비겼습니다.\n");
				}
				else // 플레이어 보
				{
					printf("플레이어가 이겼습니다.\n");
					PlayerWinning++;
				}
				PlayerHand = 0;
				ComputerHand = 0;
				break;

			case Paper://3			//컴퓨터가 보
				if (PlayerHand == Scissors) //플레이어 가위 
				{
					printf("플레이어가 이겼습니다.\n");
					PlayerWinning++;
				}
				else if (PlayerHand == Rock) //플레이어 바위 
				{
					printf("컴퓨터가 이겼습니다.\n");
					ComputerWinning++;
				}
				else // 플레이어 보
				{
					printf("비겼습니다.\n");
				}
				PlayerHand = 0;
				ComputerHand = 0;
				break;
			default:
				break;
			}

			printf("--------------------------------\n");
			printf("========================================================\n");

			if (PlayerWinning == 3) {
				printf("*게임종료*\n[플레이어 승리]\n");
				break;
			}
			else if (ComputerWinning == 3)
			{
				printf("*게임종료*\n[컴퓨터 승리]\n");
				break;
			}
		}
		
}

void HighLow()
{
	srand(time(0));
	int AnswerNum = (rand() % 100) + 1;

	int Limit = 0;
	int interfaceLimit = 5;
	while (Limit < 5)
	{
		int UserNum;
		;
		printf("남은 기회 : [%d]\n", interfaceLimit);
		printf("숫자 입력 : ");
		cin >> UserNum;

		if (UserNum < AnswerNum)
		{
			printf("더 높게\n");
			interfaceLimit--;
		}
		else if (UserNum > AnswerNum)
		{
			printf("더 낮게\n");
			interfaceLimit--;
		}
		else
		{
			printf("정답!\n");
		}

		if (interfaceLimit == 0)
		{
			printf("정답 기회 없음 ㅈㅈㅇ~ㅇ\n");
			break;
		}
	}
	
}

// On/Off 상태에 많이 쓰임 비트플래그
void Prob1()
{
	enum CharactorState
	{
		Standby		= 1,
		Jump		= 1 << 1,
		Attack		= 1 << 2,
		Invincable	= 1 << 3,
	};

	char StandbyStatus = 'O';
	char JumpStatus = 'X';
	char AttackStatus = 'X';
	char InvincableStatus = 'X';
	int PlayerStatus = Jump | Attack | Standby | Invincable ;
	printf("현재 플레이어 상태 출력 : \n대기:[O],점프:[X],공격:[X],무적:[X]\n");
	int InputPlayerStatus;
	printf("숫자를 입력해 상태를 변경하세요 :\n1.대기\n2.점프\n3.공격\n4.무적\n숫자 입력 : ");
	cin >> InputPlayerStatus;
	
	// 인풋플레이어스테이터스에 입력된 정수값 
	int CheckSwitch = (1 << (InputPlayerStatus - 1));
	switch (CheckSwitch)
	{
	case Standby:
		if (StandbyStatus == 'O')
		{
			StandbyStatus == 'X';
		}
		else
		{
			StandbyStatus == 'O';
		}
		break;
	case Jump: 
		if (JumpStatus == 'O')
		{
			JumpStatus == 'X';
		}
		else if (JumpStatus == 'X')
		{
			JumpStatus == 'O';
		}
		break;
	case Attack:
		if (AttackStatus == 'O')
		{
			AttackStatus == 'X';
		}
		else
		{
			AttackStatus == 'O';
		}
		break;
	case Invincable:
		if (InvincableStatus == 'O')
		{
			InvincableStatus == 'X';
		}
		else
		{
			InvincableStatus == 'O';
		}
		break;
	}
	printf("현재 상태 : \n대기:[%c],점프:[%c],공격:[%c],무적:[%c]\n", StandbyStatus, JumpStatus, AttackStatus, InvincableStatus);


}

void Prob2()
{
	srand(time(0));

	int PlayerBullet = 10000 ,ComputerBullet = 10000;
	
	
	int PlayerRandDice = ((rand() % 6) + 1);
	int ComputerRandDice = ((rand() % 6) + 1);
	int SecondPlayerRandDice = ((rand() % 6) + 1);
	int SecondComputerRandDice = ((rand() % 6) + 1);
	
	int BetSugest;
	int ComputerBet = ((rand() % 10000) + 1);

	int PlayerTotal, ComputerTotal;
	int i = 1;

	while (((PlayerBullet > 0) && (PlayerBullet < 10001)) || ((ComputerBullet > 0) && (ComputerBullet < 10001)))
	{
		
		printf("\n----------------%d 회차----------------\n",i);
		printf("남은 금액\n=============================================\n");
		printf("플레이어 : [%d] | 컴퓨터 : [%d]\n\n", PlayerBullet, ComputerBullet);

		int DiceSizeCheck = PlayerRandDice - ComputerRandDice;

		//1차 주사위 굴리기
		while (true)
		{
			printf("첫번째 주사위 결과 : 플레이어 : [%d] | 컴퓨터 : [%d]\n\n", PlayerRandDice, ComputerRandDice);
			if (PlayerRandDice != ComputerRandDice)
			{
				break;
			}
		}
		//베팅
		if (DiceSizeCheck < 0)
		{
			printf("베팅할 금액을 입력 : ");							//플레이어 베팅
			cin >> BetSugest;
		}
		else
		{
			printf("컴퓨터가 베팅한 금액 : %d\n\n", ComputerBet);		// 컴퓨터 베팅
			BetSugest = ComputerBet;
		}

		PlayerBullet = PlayerBullet - BetSugest;				// 베팅 금액을 각 잔액에서 차감
		ComputerBullet = ComputerBullet - BetSugest;

		printf("\n\n베팅이 끝났습니다.\n\n두번째 주사위 굴리기.\n");
		//2차 주사위 굴리기
		printf("두번째 주사위 결과 : 플레이어 : [%d] | 컴퓨터 : [%d]\n\n", SecondPlayerRandDice, SecondComputerRandDice);

		PlayerTotal = PlayerRandDice + SecondPlayerRandDice;
		ComputerTotal = ComputerRandDice + SecondComputerRandDice;
		
		if (PlayerTotal > ComputerTotal)
		{
			printf("플레이어 승!\n플레이어 획득 금액 : +%d\n\n", 2 * BetSugest);
			PlayerBullet = PlayerBullet + (2 * BetSugest);
		}
		else if (PlayerTotal < ComputerTotal)
		{
			printf("컴퓨터 승!\n컴퓨터 획득 금액 : +%d\n\n", 2 * BetSugest);
			ComputerBullet = ComputerBullet + (2 * BetSugest);
		}
		else
		{
			printf("두 주사위 합이 같습니다. 베팅금을 반환합니다\n\n\n");
			PlayerBullet = PlayerBullet + BetSugest;				// 베팅 금액을 각 잔액에서 차감
			ComputerBullet = ComputerBullet + BetSugest;
		}
		i++;
	}
	printf("\n======================== *최종결과* ========================\n");
	printf("플레이어 : [%d] | 컴퓨터 : [%d]\n\n", PlayerBullet, ComputerBullet);

	if (PlayerBullet > ComputerBullet)
	{
		printf("플레이어 승리!");
	}
	else
	{
		printf("컴퓨터 승리!");
	}
}
int main()
{
	//간단 실습
	// 1. 가위 바위 보 게임 만들기
	//		- 3선승제
	//		- enum 활용
	// 2. 하이 로우
	//		- 컴퓨터가 1~100사이의 임의의 숫자를 선택하고 사용자가 맞출때 까지 입력을 받아 "더 높게", "더 낮게" 등의 힌트를 제공
	//		- 5번 안에 맞춰야 함
	//RockPaperScissors();
	//HighLow();
	Prob2();
}

	
	
