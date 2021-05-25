#ifndef test_h
#define test_h

#include<string>

using namespace std;

class test
{
private:
	int poker[53];     //撲克
	int pokerValue[53]; //撲克代表的數值
	string pokerName[53]; //撲克名

	int money;   //玩家錢數  
	int bet;     //玩家的賭注

	int pokerF[5];   //玩家手中的牌 F:Farmer   L:Landlord
	int pokerL[5];   //莊家手中的牌 F:Farmer   L:Landlord
	int pokerNumF;   //玩家手中的牌數
	int pokerNumL;   //莊家手中的牌數
public:
	Poker();           //建構函式，對牌初始化
	void initPoker();  //洗牌,在每輪遊戲開始前進行
	string getPokerF();  //用字串的形式返回玩家的牌
	string getPokerL();  //用字串的形式返回莊家的牌
	int getSumF();       //返回玩家牌的點數，用以判斷是否超過21點
	int getSumL();       //返回莊家牌的點數
	void farmerAsk();           //玩家要牌
	void landlordAsk();         //莊家要牌
	void inputBet();            //玩家輸入賭注
	void newGame();            //開始新遊戲
	void landlordProcess();        //在玩家不要牌時進行處理

};

#endif