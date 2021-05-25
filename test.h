#ifndef test_h
#define test_h

#include<string>

using namespace std;

class test
{
private:
	int poker[53];     //���J
	int pokerValue[53]; //���J�N���ƭ�
	string pokerName[53]; //���J�W

	int money;   //���a����  
	int bet;     //���a����`

	int pokerF[5];   //���a�⤤���P F:Farmer   L:Landlord
	int pokerL[5];   //���a�⤤���P F:Farmer   L:Landlord
	int pokerNumF;   //���a�⤤���P��
	int pokerNumL;   //���a�⤤���P��
public:
	Poker();           //�غc�禡�A��P��l��
	void initPoker();  //�~�P,�b�C���C���}�l�e�i��
	string getPokerF();  //�Φr�ꪺ�Φ���^���a���P
	string getPokerL();  //�Φr�ꪺ�Φ���^���a���P
	int getSumF();       //��^���a�P���I�ơA�ΥH�P�_�O�_�W�L21�I
	int getSumL();       //��^���a�P���I��
	void farmerAsk();           //���a�n�P
	void landlordAsk();         //���a�n�P
	void inputBet();            //���a��J��`
	void newGame();            //�}�l�s�C��
	void landlordProcess();        //�b���a���n�P�ɶi��B�z

};

#endif