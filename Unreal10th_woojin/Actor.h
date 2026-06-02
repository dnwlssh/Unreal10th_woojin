#pragma once
#include <iostream>
#include <string>

class Actor
{
public:
	int Health = 0;
	int AttackPowerMin = 0;
	int AttackPowerMax = 0;

public:
	Actor() = default;

	virtual ~Actor() = default;

	 int ApplyDamage(Actor& InPlayer);
	 void TakeDamage(int Damege);

};