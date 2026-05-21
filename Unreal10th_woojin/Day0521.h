/*
1.비트플래그를 이용한 캐릭터 상태 변환 구현하기
	-캐릭터의 상태는 대기, 점프, 공격, 무적 4가지가 존재
	-다음 작업을 수행하고 현재 상태 출력하기
	    -플레이어의 상태를 대기로 설정
	        - 점프 상태 추가
	        - 공격 상태 추가
	        - 대기 상태 해제
	        - 무적 상태 추가
	        -무적 상태 토글(XOR 사용)
	-현재 상태를 출력할 때는 다음과 같은 양식을 따를 것
	대기 : [O] , 점프 : [O] , 공격 : [X] , 무적 : [O]

	//풀이
	/*
		enum CharactorState
    {
        None        = 0,
        Standby     = 1,
        Jump        = 1 << 1,
        Attack      = 1 << 2,
        Invincable  = 1 << 3,
    };

    
    int State = None;
    //플레이어의 상태를 대기로 설정
    State |= Standby;       //Statedby를 Or 시키고 저장해라
    printf("\n현재 상태\n");
    printf("대기 : [%c], 점프 : [%c], 공격 : [%c], 무적 : [%c]",
        (State & Standby) ? 'O' : 'X',
        (State & Jump) ? 'O' : 'X',
        (State & Attack) ? 'O' : 'X',
        (State & Invincable) ? 'O' : 'X');

    //점프 상태 추가
    State |= Jump;
    printf("\n현재 상태\n");
    printf("대기 : [%c], 점프 : [%c], 공격 : [%c], 무적 : [%c]",
        (State & Standby) ? 'O' : 'X',
        (State & Jump) ? 'O' : 'X',
        (State & Attack) ? 'O' : 'X',
        (State & Invincable) ? 'O' : 'X');

    //공격 상태 추가
    State |= Attack;
    printf("\n현재 상태\n");
    printf("대기 : [%c], 점프 : [%c], 공격 : [%c], 무적 : [%c]",
        (State & Standby) ? 'O' : 'X',
        (State & Jump) ? 'O' : 'X',
        (State & Attack) ? 'O' : 'X',
        (State & Invincable) ? 'O' : 'X');

    //대기 상태 해제
    // State = State & (~Standby); // State에 Not 시킨 Standby를 And 시키고 저장
    State = State & (~Standby);
    printf("\n현재 상태\n");
    printf("대기 : [%c], 점프 : [%c], 공격 : [%c], 무적 : [%c]",
        (State & Standby) ? 'O' : 'X',
        (State & Jump) ? 'O' : 'X',
        (State & Attack) ? 'O' : 'X',
        (State & Invincable) ? 'O' : 'X');

    //무적 상태 추가
    State |= Invincable;
    printf("\n현재 상태\n");
    printf("대기 : [%c], 점프 : [%c], 공격 : [%c], 무적 : [%c]",
        (State& Standby) ? 'O' : 'X',
        (State& Jump) ? 'O' : 'X',
        (State& Attack) ? 'O' : 'X',
        (State& Invincable) ? 'O' : 'X');

    //무적 상태 토글 (XOR)
    State ^= Invincable;
    printf("\n현재 상태\n");
    printf("대기 : [%c], 점프 : [%c], 공격 : [%c], 무적 : [%c]",
        (State& Standby) ? 'O' : 'X',
        (State& Jump) ? 'O' : 'X',
        (State& Attack) ? 'O' : 'X',
        (State& Invincable) ? 'O' : 'X');
	*/

/*

2.주사위 게임
	- 초기 세팅
	    플레이어와 컴퓨터 모두 일정 금액(예 : 10000원)으로 시작한다.
	- 1차 주사위 굴리기
	    게임 시작 시, 플레이어와 컴퓨터가 각각 주사위(1~6)를 한 번 굴린다.
	    각자 주사위 결과를 공개한다.
	- 배팅
	    이전 판에서 진 쪽이 배팅 금액을 제시한다.
	    제시한 배팅 금액은 두 사람 모두의 현재 소지 금액 이하이어야 한다.
	    배팅 금액은 두 사람 모두에게서 차감된다.
	- 2차 주사위 굴리기
	    다시 플레이어와 컴퓨터가 각각 주사위를 한 번씩 굴린다.
	    (1차 + 2차) 주사위의 합을 계산한다.
	- 승패 판정 및 금액 증감
	    합이 더 큰 쪽이 배팅 금액의 총합(즉, 2×배팅금액)을 모두 가져간다.
	    동점일 경우 배팅 금액은 그대로 반환한다.
	- 다음 판 진행
	    소지금이 0 이하인 쪽이 나오면 게임 종료.

       
	   const int InitialMoney = 10000;			//시작시 소유 금액
	unsigned int Seed = (unsigned int)time(0);
	Seed = 0;

	//srand((unsigned int)time(0));		//시드 값 초기화

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
		PlayerDice1 = (rand() % 6) + 1;
		ComputerDice1 = (rand() % 6) + 1;
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
		MaxBet = (PlayerMoney < ComputerMoney) ? PlayerMoney : ComputerMoney;

		if (PlayerLost)
		{
			//플레이어가 졌을 시 => 플레이어 베팅
			do
			{
				printf("베팅 금액을 입력하세요 (1 ~ %d) : ", MaxBet);
				cin >> Bet;
				cin.clear();				//에러 상태 해제
				cin.ignore(10000, '\n');	//이전 입력 제거
			} while (Bet < 1 || Bet > MaxBet); //범위를 벗어난 값이나 잘못 입력 했을 떄를 위해 다시 입력 받는 처리
		}
		else
		{
			//플레이어가 이김 => 컴퓨터가 베팅
			Bet = rand() % MaxBet + 1;
			printf("컴퓨터가 [%d]원을 베팅했습니다.\n", Bet);
		}
		//베팅 금액 차감
		PlayerMoney -= Bet;
		ComputerMoney -= Bet;

		//2차 주사위 굴리기
		PlayerDice2 = (rand() % 6) + 1;
		ComputerDice2 = (rand() % 6) + 1;
		printf("플레이어 2차 주사위 : %d\n", PlayerDice2);
		printf("컴퓨터 2차 주사위 : %d\n", ComputerDice2);

		int PlayerSum = PlayerDice1 + PlayerDice2;		// 주사위 합계 출력
		int ComputerSum = ComputerDice1 + ComputerDice2;
		printf("=================================\n");
		printf("플레이어 주사위 합계 : %d\n", PlayerSum);
		printf("컴퓨터 주사위 합계 : %d\n", ComputerSum);

		//승패 판정
		if (PlayerSum > ComputerSum)
		{
			printf("플레이어 승리! 플레이어가 [%d]원을 획득 합니다.\n", Bet * 2);
			PlayerMoney += (Bet * 2);
			PlayerLost = false;
		}
		else if (ComputerSum > PlayerSum)
		{
			printf("컴퓨터 승리! 컴퓨터가 [%d]원을 획득 합니다.\n", Bet * 2);
			ComputerMoney += (Bet * 2);
			PlayerLost = true;
		}
		else
		{
			printf("무승부입니다. 베팅금액은 반환됩니다.");
			PlayerMoney += Bet;
			ComputerMoney += Bet;
		}
		Turn++;
	}

	printf("\n-------------- 게임 종료  --------------\n");
	if (PlayerMoney > 0)
	{
		printf("당신의 최종 승리\n");
	}
	else
	{
		printf("컴퓨터의 최종 승리\n");
	}
    */
/*
3.홀짝 게임
	초기 금액 및 배팅
	플레이어는 기본금 100원으로 베팅을 시작한다.
	홀짝 선택
	플레이어가 1(홀)또는 2(짝)을 선택한다.
	결과 결정
	컴퓨터가 랜덤으로 1(홀)또는 2(짝)을 선택한다.
	플레이어의 선택과 결과가 일치하면 승리(이기면 배팅금의 2배 획득), 다르면 패배(배팅금 전액 잃음).
	연속 배팅 선택
	승리 시 플레이어는 두 가지 중 하나를 선택 :
	(A)이긴 금액을 모두 다시 한 번에 배팅(연승 도전)
	(B)이긴 금액을 얻고, 다시 100원부터 새로 배팅 시작
	게임 종료 조건
	플레이어가 소지금이 100원 미만일 경우 게임 종료.

	//베팅
		printf("\n현재 소지금 : [%d]원\n", Money);
		printf("현재 베팅 금액 : [%d]원\n", CurrentBet);
		Money -= CurrentBet;	//베팅한 금액 만큼 감소

		//홀짝 선택
		int Select = 0;
		while (Select != 1 && Select != 2)	//오입력 방지
		{
		printf("홀(1) 또는 짝(2)을 선택하세요 : ");
		cin >> Select;									//입력받고
		cin.clear();									//잘못된 입력일 때 에러 리셋
		cin.ignore(10000, '\n');							//버퍼 비우기
		}

		//결과 결정
		int Result = (rand() % 2) + 1;	// 랜덤으로 1 or 2 고르기
		printf("결과는 [%s]입니다.\n", (Result == 1)? "홀" : "짝");

		if (Select == Result)
		{
			int WinPrice = CurrentBet * WinMultiplier;	//승리 상금은 현재 베팅 금액의 두배
			printf("축하합니다! [%d]원을 획득 할 수 잇습니다.\n",WinPrice);
			printf("1) [%d]원을 모두 다시 베팅\n", WinPrice);
			printf("2) [%d]원을 받고 다시 [%d]원 부터 베팅\n", WinPrice,MinimumBet);
			printf("1 또는 2 중 하나를 선택하세요 : ");

			int KeepGoing = 0;
			while (KeepGoing != 1 && KeepGoing != 2)	//선택지 입력 받기
			{
				cin >> KeepGoing;
				cin.clear();
				cin.ignore(10000,'n');
			}
			if (KeepGoing == 1)
			{
				CurrentBet = WinPrice;					//상금을 다시 그대로 베팅
			}
			else
			{
				Money += WinPrice;						//상금을 받고
				CurrentBet = MinimumBet;				//100원부터 다시 베팅
			}
		}
		else
		{
			printf("안타깝네요! 베팅한 [%d]원을 모두 잃었습니다.\n",CurrentBet);
			CurrentBet = MinimumBet;					//베팅 금액 초기화
		}
	}

	printf("소지금이 부족해서 더이상 진행 할 수 없습니다.\n");
	*/