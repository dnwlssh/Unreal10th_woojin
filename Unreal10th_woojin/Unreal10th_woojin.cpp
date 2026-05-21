


#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

//void RockPaperScissors()
//{
//    srand(time(0));
//    enum RPC
//    {
//        Scissors = 1,
//        Rock,
//        Paper
//    };
//
//    int PlayerHand = 0;      // 플레이어 핸드
//    int PlayerWinning = 0;      // 플레이어 승리 스택
//    int ComputerWinning = 0;   // 컴퓨터 승리 스택
//
//    while (true)
//    {
//        printf("점수\n플레이어[%d] | 컴퓨터 [%d]\n", PlayerWinning, ComputerWinning);
//        printf("나의 핸드 선택\n1.가위\n2.바위\n3.보\n[나의 핸드] : ");
//        cin >> PlayerHand;
//
//        int ComputerHand = (rand() % 3) + 1;
//
//        printf("나의 핸드 : %d | ", PlayerHand);
//        printf("컴퓨터의 핸드 : %d\n", ComputerHand);
//        printf("--------------------------------\n");
//
//        switch (ComputerHand)
//        {
//        case Scissors://1      //컴퓨터가 가위
//            if (PlayerHand == Scissors) //플레이어 가위 
//            {
//                printf("비겼습니다.\n");
//            }
//            else if (PlayerHand == Rock) //플레이어 바위 
//            {
//                printf("플레이어가 이겼습니다.\n");
//                PlayerWinning++;
//            }
//            else // 플레이어 보
//            {
//                printf("컴퓨터가 이겼습니다.\n");
//                ComputerWinning++;
//            }
//            PlayerHand = 0;
//            ComputerHand = 0;
//            break;
//
//        case Rock://2      //컴퓨터가 바위
//            if (PlayerHand == Scissors) //플레이어 가위 
//            {
//                printf("컴퓨터가 이겼습니다.\n");
//                ComputerWinning++;
//            }
//            else if (PlayerHand == Rock) //플레이어 바위 
//            {
//                printf("비겼습니다.\n");
//            }
//            else // 플레이어 보
//            {
//                printf("플레이어가 이겼습니다.\n");
//                PlayerWinning++;
//            }
//            PlayerHand = 0;
//            ComputerHand = 0;
//            break;
//
//        case Paper://3         //컴퓨터가 보
//            if (PlayerHand == Scissors) //플레이어 가위 
//            {
//                printf("플레이어가 이겼습니다.\n");
//                PlayerWinning++;
//            }
//            else if (PlayerHand == Rock) //플레이어 바위 
//            {
//                printf("컴퓨터가 이겼습니다.\n");
//                ComputerWinning++;
//            }
//            else // 플레이어 보
//            {
//                printf("비겼습니다.\n");
//            }
//            PlayerHand = 0;
//            ComputerHand = 0;
//            break;
//        default:
//            break;
//        }
//
//        printf("--------------------------------\n");
//        printf("========================================================\n");
//
//        if (PlayerWinning == 3) {
//            printf("*게임종료*\n[플레이어 승리]\n");
//            break;
//        }
//        else if (ComputerWinning == 3)
//        {
//            printf("*게임종료*\n[컴퓨터 승리]\n");
//            break;
//        }
//    }
//
//}
//
//void HighLow()
//{
//    srand(time(0));
//    int AnswerNum = (rand() % 100) + 1;
//
//    int Limit = 0;
//    int interfaceLimit = 5;
//    while (Limit < 5)
//    {
//        int UserNum;
//        ;
//        printf("남은 기회 : [%d]\n", interfaceLimit);
//        printf("숫자 입력 : ");
//        cin >> UserNum;
//
//        if (UserNum < AnswerNum)
//        {
//            printf("더 높게\n");
//            interfaceLimit--;
//        }
//        else if (UserNum > AnswerNum)
//        {
//            printf("더 낮게\n");
//            interfaceLimit--;
//        }
//        else
//        {
//            printf("정답!\n");
//            break;
//        }
//
//        if (interfaceLimit == 0)
//        {
//            printf("정답 기회 없음 ㅈㅈㅇ~ㅇ\n");
//            break;
//        }
//    }
//
//}
//
//// On/Off 상태에 많이 쓰임 비트플래그
//void Prob1()
//{
//    enum CharactorState
//    {
//        Standby = 1,
//        Jump = 1 << 1,
//        Attack = 1 << 2,
//        Invincable = 1 << 3,
//    };
//
//    enum OX
//    {
//        O,
//        X = 15,
//    };
//
//    int PlayerStatus = Standby | Jump | Attack | Invincable;
//    int StatusOnOff = O | X;
//
//    char O = 'O', X = 'X';
//
//    printf("현재 플레이어 상태 출력 : \n대기:[O],점프:[X],공격:[X],무적:[X]\n");
//    int InputPlayerStatus;
//    printf("숫자를 입력해 상태를 변경하세요 :\n1.대기\n2.점프\n3.공격\n4.무적\n숫자 입력 : ");
//    cin >> InputPlayerStatus;
//
//    PlayerStatus = 1 << (InputPlayerStatus - 1);
//
//    if ((PlayerStatus & StatusOnOff) == 0)
//    {
//        StatusOnOff = O;
//        printf("현재 플레이어 상태 출력 : \n대기:[%c],점프:[%c],공격:[%c],무적:[%c]\n",O,X,X,X);
//    }
//    else
//    {
//        StatusOnOff = X;
//    }
//
//}
//
//void Prob2()
//{
//    srand(time(0));
//
//    int PlayerBullet = 10000, ComputerBullet = 10000;
//
//
//    int PlayerRandDice = ((rand() % 6) + 1);
//    int ComputerRandDice = ((rand() % 6) + 1);
//    int SecondPlayerRandDice = ((rand() % 6) + 1);
//    int SecondComputerRandDice = ((rand() % 6) + 1);
//
//    int BetSugest;
//    int ComputerBet = ((rand() % 10000) + 1);
//
//    int PlayerTotal, ComputerTotal;
//    int i = 1;
//
//    while (((PlayerBullet > 0) && (PlayerBullet < 10001)) || ((ComputerBullet > 0) && (ComputerBullet < 10001)))
//    {
//
//        printf("\n----------------%d 회차----------------\n", i);
//        printf("남은 금액\n=============================================\n");
//        printf("플레이어 : [%d] | 컴퓨터 : [%d]\n\n", PlayerBullet, ComputerBullet);
//
//
//        //1차 주사위 굴리기
//        while (true)
//        {
//            if (PlayerRandDice != ComputerRandDice)
//            {
//                printf("첫번째 주사위 결과 : 플레이어 : [%d] | 컴퓨터 : [%d]\n\n", PlayerRandDice, ComputerRandDice);
//                break;
//            }
//        }
//
//        int DiceSizeCheck = PlayerRandDice - ComputerRandDice;
//        //베팅
//        if (DiceSizeCheck < 0)
//        {
//            printf("베팅할 금액을 입력 : ");                     //플레이어 베팅
//            cin >> BetSugest;
//
//        }
//        else
//        {
//            printf("컴퓨터가 베팅한 금액 : %d\n\n", ComputerBet);      // 컴퓨터 베팅
//            BetSugest = ComputerBet;
//        }
//
//        if ((BetSugest > PlayerBullet) || (BetSugest > ComputerBullet))
//        {
//            printf("\n베팅할 금액이 부족합니다.\n");
//            while ((BetSugest < PlayerBullet) && (BetSugest < ComputerBullet))
//            {
//                if (DiceSizeCheck < 0)
//                {
//                    printf("베팅할 금액을 입력 : ");                     //플레이어 재베팅
//                    cin >> BetSugest;
//
//                }
//                else
//                {
//                    printf("컴퓨터가 베팅한 금액 : %d\n\n", ComputerBet);      // 컴퓨터 재베팅
//                    BetSugest = ComputerBet;
//                }
//            }
//        }
//
//        PlayerBullet = PlayerBullet - BetSugest;            // 베팅 금액을 각 잔액에서 차감
//        ComputerBullet = ComputerBullet - BetSugest;
//
//
//
//        printf("\n\n베팅이 끝났습니다.\n\n두번째 주사위 굴리기.\n");
//
//
//        //2차 주사위 굴리기
//        printf("\n두번째 주사위 결과 : 플레이어 : [%d] | 컴퓨터 : [%d]\n\n", SecondPlayerRandDice, SecondComputerRandDice);
//
//        PlayerTotal = PlayerRandDice + SecondPlayerRandDice;
//        ComputerTotal = ComputerRandDice + SecondComputerRandDice;
//
//        if (PlayerTotal > ComputerTotal)
//        {
//            printf("플레이어 승!\n플레이어 획득 금액 : +%d\n\n", 2 * BetSugest);
//            PlayerBullet = PlayerBullet + (2 * BetSugest);
//        }
//        else if (PlayerTotal < ComputerTotal)
//        {
//            printf("컴퓨터 승!\n컴퓨터 획득 금액 : +%d\n\n", 2 * BetSugest);
//            ComputerBullet = ComputerBullet + (2 * BetSugest);
//        }
//        else
//        {
//            printf("두 주사위 합이 같습니다. 베팅금을 반환합니다\n\n\n");
//            PlayerBullet = PlayerBullet + BetSugest;            // 베팅 금액을 각 잔액에서 차감
//            ComputerBullet = ComputerBullet + BetSugest;
//        }
//        i++;
//
//    }
//    printf("\n======================== *최종결과* ========================\n");
//    printf("플레이어 : [%d] | 컴퓨터 : [%d]\n\n", PlayerBullet, ComputerBullet);
//
//    if (PlayerBullet > ComputerBullet)
//    {
//        printf("플레이어 승리!\n");
//    }
//    else
//    {
//        printf("컴퓨터 승리!\n");
//    }
//}
//
//void Prob3()
//{
//    srand(time(0));
//
//    int PlayerCredit = 100;
//    int InputNum;
//
//    int ComputerInputNum;
//    int PleaseBet = 0;
//
//    int WinningStreak;
//    while (PlayerCredit >= 100)
//    {
//        ComputerInputNum = ((rand() % 2) + 1);
//        printf("남은 크레딧 : [%d]\n", PlayerCredit);
//        printf("베팅할 금액 입력 : ");
//        cin >> PleaseBet;
//
//        while (true)
//        {
//            if (PlayerCredit < PleaseBet)
//            {
//                printf("베팅할 금액 입력 : ");
//                cin >> PleaseBet;
//                break;
//            }
//            else
//            {
//                break;
//            }
//
//        }
//
//
//        printf("홀/짝 선택 : \n1.홀\n2.짝\n입력 : ");
//        cin >> InputNum;
//
//        printf("플레이어 선택 : [%d] , 컴퓨터 선택 : [%d]\n", InputNum, ComputerInputNum);
//
//        if (InputNum == ComputerInputNum)
//        {
//            printf("플레이어 승!\n");
//            PleaseBet = 2 * PleaseBet;
//
//            printf("연속 도전 선택 : \n1.연승 도전\n2.도전 안함\n");
//            cin >> WinningStreak;
//            if (WinningStreak == 1)
//            {
//                PleaseBet = 2 * PleaseBet;
//            }
//            else
//            {
//                PlayerCredit += PleaseBet;
//            }
//        }
//        else
//        {
//            printf("플레이어 패배!\n");
//            PlayerCredit -= PleaseBet;
//        }
//    }
//
//
//}

int main()
{

}