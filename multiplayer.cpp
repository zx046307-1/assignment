#include"multiplayer.h"

int numOfPlayer = 0;

multiplayer::multiplayer()
{
	numOfPlayer++;
}

int multiplayer::getNumOfPlayer()
{
	return numOfPlayer;
}
