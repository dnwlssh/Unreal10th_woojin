#include "Weekend_Practice0605_BattleShip_Solution.h"
#include "PlayerMap.h"
#include "HiddenMap.h"
#include <iostream>

void BattleShip::Initialze()
{
	MapHidden = new HiddenMap();
	MapPlayer = new PlayerMap();
	EnemyFleet = new ShipManager();
}

void BattleShip::Clear()
{
	if (MapHidden)
	{
		delete MapHidden;
		MapPlayer = nullptr;
	}
	if (MapPlayer)
	{
		delete MapPlayer;
		MapPlayer = nullptr;
	}
}
void BattleShip::Play()
{
	if (!MapHidden || !MapPlayer || !EnemyFleet)
	{
		printf("ERROR : 초기화가 안되었습니다.\n");
		return;
	}

	printf("배틀쉽 게임 시작!\n%d턴 안에 모든 적을 침몰 시키세요\n",MaxTurn);
	while (!IsGameOver())
	{
		PrintGameStatus();
		InputHandle();
	}
	PrintGameStatus();
}

bool BattleShip::Shoot(int InX, int InY)
{
	return false;
}


void BattleShip::PrintGameStatus() const
{
	if (IsTestMode)
	{
		MapHidden->PrintMap();
	}
	MapPlayer->PrintMap();
	printf("남은 턴 ");
}

void BattleShip::PrintGameResult() const
{
}
