#pragma once
#include "MazeCommon.h"
#include "Actor.h"

class Player : public Actor
{
public:
    Position Pos{ InvalidPosition, InvalidPosition };
    int MaxHealth = InitHealth;
    int Money = InitMoney;
public:
    Player()
    {
        Health = InitHealth;
        AttackPowerMin = 5;
        AttackPowerMax = 15;
    }
    
};