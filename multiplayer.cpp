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

void multiplayer::player()
{
	for (int i = 0;i < numOfPlayer;i++)
	{
		getPlayer();
	}
}
