#include <iostream>

#include "Day0529_Pratice.h"

void Day0529_Pratice()
{
	Postition P1(2, 3);
	Postition P2(5, 1);

	Postition P3 = P1 + P2;
	Postition P4 = P1 - P2;

	printf("P3 : (%d,%d)\n", P3.Pos_X , P3.Pos_Y);
	printf("P4 : (%d,%d)\n", P4.Pos_X , P4.Pos_Y);
}