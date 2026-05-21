#pragma once

int RandDice();

int GetMaxBet(int PlayerMoney, int ComputerMoney);
int PlayerDoBetAgain(int Bet, int MaxBet);
int BettingMoneySub(int Player, int Bet);
int TotalDice(int Dice1, int Dice2);

int CreditCalCulater(int Money, int Bet);
int Draw(int Money, int Bet);

void EndGameSequence(int PlayerMoney);