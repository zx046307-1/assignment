#ifndef test_multi_h
#define test_multi_h

#include <string>

using namespace std;

class test
{
private:

	int cards[53];
	int cardsValue[53];
	string cardsName[53];

	int money[4];
	int bet[4];

	int player[5];
	int computer[5];
	int playerNum;
	int computerNum;

public:

	test();
	void initCards();
	string getPlayer();
	string getComputer();
	int getSumPlayer();
	int getSumComputer();
	void farmerAsk();
	void landlordAsk();
	void inputBet();
	void newGame();
	void landlordProcess();

};

#endif
