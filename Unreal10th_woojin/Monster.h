#pragma once
#include "Actor.h"
#include "Utils.h"
#include "Enemy.h"

class Monster : public MazeEnemy
{
public:
	std::string Name = "Àû1";
public:
	Monster()
		:MazeEnemy()
	{ }
	Monster(const std::string& InName)
		:Name(InName)
	{ }
};

class Goblin : public Monster
{
public:
	Goblin()
		:Monster()
	{ }
	Goblin(const std::string& InName)
		:Monster(InName)
	{ }
};

class Wraith : public Monster
{
public:
	std::string Name = "·¹ÀÌ½º";

public:
	Wraith()
		:Monster()
	{ }
	Wraith(const std::string& InName)
		:Monster(InName)
	{ }
};

class Gorlem : public Monster
{
public:
	std::string Name = "°ñ·½";

public:
	Gorlem()
		:Monster()
	{ }
	Gorlem(const std::string& InName)
		:Monster(InName)
	{ }
};