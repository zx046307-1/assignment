#include"test.h"

test::Poker()
{

    poker[0] = 0;
    for (int i = 1;i <= 13;i++)    //|
    {                         //|
        poker[i] = i;           //|用建構函式對牌初始化
        poker[i + 13] = i;        //|
        poker[i + 26] = i;        //|
        poker[i + 39] = i;        //|
    }//for結束

    pokerValue[0] = 0;
    for (i = 1;i <= 52;i++)
    {
        if (poker[i] <= 10)  pokerValue[i] = poker[i];
        else              pokerValue[i] = 10;
    }//for結束


    pokerName[0] = "";
    for (i = 0;i < 4;i++)
    {
        pokerName[1 + 13 * i] = "A";
        pokerName[2 + 13 * i] = "2";
        pokerName[3 + 13 * i] = "3";
        pokerName[4 + 13 * i] = "4";
        pokerName[5 + 13 * i] = "5";
        pokerName[6 + 13 * i] = "6";
        pokerName[7 + 13 * i] = "7";
        pokerName[8 + 13 * i] = "8";
        pokerName[9 + 13 * i] = "9";
        pokerName[10 + 13 * i] = "10";
        pokerName[11 + 13 * i] = "J";
        pokerName[12 + 13 * i] = "Q";
        pokerName[13 + 13 * i] = "K";
    }//for結束

    money = 200;  //玩家開始玩遊戲時錢數是200
    bet = 0;

    for (i = 0;i < 5;i++)
    {
        pokerF[i] = 0;    //|對pokerOfFarmer初始化
        pokerL[i] = 0;    //|對pokerOfLandlord初始化
    }


    pokerNumF = 0;//玩家手中的牌數初始化為0
    pokerNumL = 0;//莊家手中的牌數初始化為0

    srand((int)time(0));
    for (i = 0;i < NUM;i++)
    {
        randNum[i] = rand() * 51 / 32767 + 1;//產生隨機數陣列
    }

}//建構函式Poker()結束
void test::initPoker()
{
    cout << "新一局遊戲開始，開始洗牌>>>>>" << endl;

    pokerF[0] = randNum[j++];  //產生1-52的隨機數
    pokerF[1] = randNum[j++];  //產生1-52的隨機數
    pokerL[0] = randNum[j++];  //產生1-52的隨機數
    pokerL[1] = randNum[j++];  //產生1-52的隨機數

    pokerNumF = 2;
    pokerNumL = 2;

    cout << "洗牌完成,你的牌為:" << getPokerF() << endl;
}//void Poker::initPoker()結束

string test::getPokerF()//用字串的形式返回玩家的牌
{
    int i;
    string result = "";

    for (i = 0;i < pokerNumF;i++)
        result = result + pokerName[pokerF[i]] + " ";

    return result;
}//string Poker::getPokerF()結束

string test::getPokerL()//用字串的形式返回莊家的牌
{
    int i;
    string result = "";

    for (i = 0;i < pokerNumL;i++)
        result = result + pokerName[pokerL[i]] + " ";

    return result;
}//string Poker::getPokerL()結束

int test::getSumF()   //返回玩家的總點數
{
    int result = 0;

    for (int i = 0;i < pokerNumF;i++)
        result = result + pokerValue[pokerF[i]];

    return result;
}

int test::getSumL()//返回莊家的總點數
{

    int result = 0;

    for (int i = 0;i < pokerNumL;i++)
        result = result + pokerValue[pokerL[i]];

    return result;
}

void test::farmerAsk()
{
    if (pokerNumF >= 5)
    {
        cout << "你的牌數已夠5張，不能再要牌了" << endl;
        landlordProcess();
    }
    else
    {
        pokerF[pokerNumF++] = randNum[j++];   //產生1-52的隨機數
        cout << "你的牌為:" << getPokerF() << endl;
        if (getSumF() > 21)
        {
            cout << "你撐死了,你輸了" << bet << "元" << endl;
            money = money - bet;
            if (money <= 0)
            {
                cout << "你已經輸光了，哈哈" << endl;
                cout << "遊戲結束" << endl;
                exit(0);
            }
            inputBet();
            initPoker();
        }
        else if (getSumF() == 21)
        {
            landlordProcess();
        }
    }
}

void test::landlordAsk()
{
    if (pokerNumL >= 5)
    {
        if (getSumF() > getSumL())
        {
            cout << "莊家的牌為" << getPokerL() << endl;
            cout << "你贏了,你贏了" << bet << "元" << endl;
            money = money + bet;
            inputBet();
            initPoker();
        }
        else if (getSumF() == getSumL())
        {
            cout << "莊家的牌為" << getPokerL() << endl;
            cout << "平手" << endl;
            inputBet();
            initPoker();
        }
        else if (getSumF() < getSumL())
        {
            cout << "莊家的牌為" << getPokerL() << endl;
            cout << "你輸了,你輸了" << bet << "元" << endl;
            money = money - bet;
            if (money <= 0)
            {
                cout << "你已經輸光了，哈哈" << endl;
                cout << "遊戲結束" << endl;
                exit(0);
            }
            inputBet();
            initPoker();
        }
    }
    else
    {
        pokerL[pokerNumL++] = randNum[j++];   //產生1-52的隨機數
        if (getSumL() > 21)
        {
            cout << "莊家的牌為" << getPokerL() << endl;
            cout << "莊家撐死了,你贏了" << bet << "元" << endl;
            money = money + bet;
            inputBet();
            initPoker();
        }
        else    landlordProcess();
    }
}
void test::inputBet()
{
    cout << "你現在有" << money << "元,請輸入賭注:";
    do
    {
        cin >> bet;
        if (bet > money)
            cout << "笨蛋，你沒那麼多錢，少來，重新輸入吧:";
    } while (bet > money);

}

void test::newGame()
{
    inputBet();
    initPoker();
    cout << "你得到的牌為:" << getPokerF() << endl;
}

void test::landlordProcess()
{
    if (getSumL() >= 17)
    {
        if (getSumL() > getSumF())
        {
            cout << "莊家的牌為" << getPokerL() << endl;
            cout << "莊家獲勝，你輸了" << bet << "元" << endl;
            money = money - bet;
            if (money <= 0)
            {
                cout << "你已經輸光了，哈哈" << endl;
                cout << "遊戲結束" << endl;
                exit(0);
            }
            inputBet();
            initPoker();
        }
        else if (getSumF() == getSumL())
        {
            cout << "莊家的牌為" << getPokerL() << endl;
            cout << "本次遊戲平手" << endl;
            inputBet();
            initPoker();
        }
        else
        {
            cout << "莊家的牌為" << getPokerL() << endl;
            cout << "你贏了,你贏了" << bet << "元" << endl;
            money = money + bet;
            inputBet();
            initPoker();
        }
    }
    else
    {
        landlordAsk();
    }
}