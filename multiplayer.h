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
	static int getNumOfPlayer();

};

#endif
