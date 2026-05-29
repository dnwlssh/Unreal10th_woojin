#pragma once

struct Postition
{
	int Pos_X = 0;
	int Pos_Y = 0;
	Postition() = default;
	Postition(int x, int y)
	{
		Pos_X = x;
		Pos_Y = y;
	}

	Postition operator+(const Postition& other)
	{
		Postition Sum;
		Sum.Pos_X = Pos_X + other.Pos_X;
		Sum.Pos_Y = Pos_Y + other.Pos_Y;

		return Sum;
	}

	Postition operator-(const Postition& other)
	{
		Postition Sub;
		Sub.Pos_X = Pos_X - other.Pos_X;
		Sub.Pos_Y = Pos_Y - other.Pos_Y;

		return Sub;
	}
};

void Day0529_Pratice();