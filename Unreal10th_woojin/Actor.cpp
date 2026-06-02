#include "Actor.h"
#include "Utils.h"
#include "MazeCommon.h"
#include "Enemy.h"

int Actor::ApplyDamage(Actor& InPlayer)
{
	return GetRandomRange(InPlayer.AttackPowerMin, InPlayer.AttackPowerMax);
}

void Actor::TakeDamage(int Damage)
{
	Health -= Damage;
}
