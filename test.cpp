#include <iostream>
#include <ctime>
#include <cstdlib>

#include "test.h"

#define NUM 1000
int randNum[NUM];
int n = 2;

test::test()
{

    cards[0] = 0;
    for (int i = 1;i <= 13;i++)
    {
        cards[i] = i;
        cards[i + 13] = i;
        cards[i + 26] = i;
        cards[i + 39] = i;
    }

    cardsValue[0] = 0;
    for (int i = 1;i <= 52;i++)
    {
        if (cards[i] <= 10)  cardsValue[i] = cards[i];
        else              cardsValue[i] = 10;
    }


    cardsName[0] = "";
    for (int i = 0;i < 4 ; i++)
    {
        cardsName[1 + 13 * i] = "A";
        cardsName[2 + 13 * i] = "2";
        cardsName[3 + 13 * i] = "3";
        cardsName[4 + 13 * i] = "4";
        cardsName[5 + 13 * i] = "5";
        cardsName[6 + 13 * i] = "6";
        cardsName[7 + 13 * i] = "7";
        cardsName[8 + 13 * i] = "8";
        cardsName[9 + 13 * i] = "9";
        cardsName[10 + 13 * i] = "10";
        cardsName[11 + 13 * i] = "J";
        cardsName[12 + 13 * i] = "Q";
        cardsName[13 + 13 * i] = "K";
    }

    money = 200;
    bet = 0;

    for (int i = 0;i < 5 ; i++)
    {
        player[i] = 0;
        computer[i] = 0;
    }


    playerNum = 0;
    computerNum = 0;

    srand((int)time(0));
    for (int i = 0;i < NUM;i++)
    {
        randNum[i] = rand() * 51 / 32767 + 1;
    }

}
void test::initCards()
{
    cout << "新一局遊戲開始，開始洗牌>>>>>" << endl;

    player[0] = randNum[n++];
    player[1] = randNum[n++];
    computer[0] = randNum[n++];
    computer[1] = randNum[n++];

    playerNum = 2;
    computerNum = 2;

    cout << "洗牌完成,你的牌為:" << getPlayer() << endl;
}

string test::getPlayer()
{
    int i;
    string result = "";

    for (i = 0;i < playerNum;i++)
    {
        result = result + cardsName[player[i]] + " ";
    }
        
    return result;
}

string test::getComputer()
{
    int i;
    string result = "";

    for (i = 0;i < computerNum;i++)
    {
        result = result + cardsName[computer[i]] + " ";
    }

    return result;
}

int test::getSumPlayer()
{
    int result = 0;

    for (int i = 0;i < playerNum;i++)
    {
        result = result + cardsValue[player[i]];
    }

    return result;
}

int test::getSumComputer()
{

    int result = 0;

    for (int i = 0;i < computerNum;i++)
    {
        result = result + cardsValue[computer[i]];
    }

    return result;
}

void test::farmerAsk()
{
    if (playerNum >= 5)
    {
        cout << "你的牌數已夠5張，不能再要牌了" << endl;
        landlordProcess();
    }
    else
    {
        player[playerNum++] = randNum[n++];
        cout << "你的牌為:" << getPlayer() << endl;
        if (getSumPlayer() > 21)
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
            initCards();
        }
        else if (getSumPlayer() == 21)
        {
            landlordProcess();
        }
    }
}

void test::landlordAsk()
{
    if (computerNum >= 5)
    {
        if (getSumPlayer() > getSumComputer())
        {
            cout << "莊家的牌為" << getComputer() << endl;
            cout << "你贏了,你贏了" << bet << "元" << endl;
            money = money + bet;
            inputBet();
            initCards();
        }
        else if (getSumPlayer() == getSumComputer())
        {
            cout << "莊家的牌為" << getComputer() << endl;
            cout << "平手" << endl;
            inputBet();
            initCards();
        }
        else if (getSumPlayer() < getSumComputer())
        {
            cout << "莊家的牌為" << getComputer() << endl;
            cout << "你輸了,你輸了" << bet << "元" << endl;
            money = money - bet;
            if (money <= 0)
            {
                cout << "你已經輸光了，哈哈" << endl;
                cout << "遊戲結束" << endl;
                exit(0);
            }
            inputBet();
            initCards();
        }
    }
    else
    {
        computer[computerNum++] = randNum[n++];
        if (getSumComputer() > 21)
        {
            cout << "莊家的牌為" << getComputer() << endl;
            cout << "莊家爆了,你賺了" << bet << "元" << endl;
            money = money + bet;
            inputBet();
            initCards();
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
            cout << "你沒那麼多錢，重新輸入吧:";
    } while (bet > money);

}

void test::newGame()
{
    inputBet();
    initCards();
    cout << "你得到的牌為:" << getPlayer() << endl;
}

void test::landlordProcess()
{
    if (getSumComputer() >= 17)
    {
        if (getSumComputer() > getSumPlayer())
        {
            cout << "莊家的牌為" << getComputer() << endl;
            cout << "你輸了,你賠了" << bet << "元" << endl;
            money = money - bet;
            if (money <= 0)
            {
                cout << "你已經輸光了" << endl;
                cout << "遊戲結束" << endl;
                exit(0);
            }
            inputBet();
            initCards();
        }
        else if (getSumPlayer() == getSumComputer())
        {
            cout << "莊家的牌為" << getComputer() << endl;
            cout << "本次遊戲平手" << endl;
            inputBet();
            initCards();
        }
        else
        {
            cout << "莊家的牌為" << getComputer() << endl;
            cout << "你贏了,你賺了" << bet << "元" << endl;
            money = money + bet;
            inputBet();
            initCards();
        }
    }
    else
    {
        landlordAsk();
    }
}
