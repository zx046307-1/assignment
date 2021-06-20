#ifndef multiplayer_h
#define multiplayer_h

using namespace std;

#include <string>

#include "test.h"

class multiplayer:public test
{
private:
	static int numOfPlayer;

public:
	multiplayer();
	static int getNumOfPlayer();
	void player();

};

#endif
