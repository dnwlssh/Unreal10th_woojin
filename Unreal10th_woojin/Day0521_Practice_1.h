#pragma once

enum CharactorState
{
    None = 0,
    Standby = 1,
    Jump = 1 << 1,
    Attack = 1 << 2,
    Invincable = 1 << 3,
};

int StateAdd(int SetState, int InputState);
int StateSub(int SetState, int InputState);
int StateToggle(int SetState, int InputState);
void ShowMeTheState(int SetState);