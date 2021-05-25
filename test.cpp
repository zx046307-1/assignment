#include"test.h"

test::Poker()
{

    poker[0] = 0;
    for (int i = 1;i <= 13;i++)    //|
    {                         //|
        poker[i] = i;           //|�Ϋغc�禡��P��l��
        poker[i + 13] = i;        //|
        poker[i + 26] = i;        //|
        poker[i + 39] = i;        //|
    }//for����

    pokerValue[0] = 0;
    for (i = 1;i <= 52;i++)
    {
        if (poker[i] <= 10)  pokerValue[i] = poker[i];
        else              pokerValue[i] = 10;
    }//for����


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
    }//for����

    money = 200;  //���a�}�l���C���ɿ��ƬO200
    bet = 0;

    for (i = 0;i < 5;i++)
    {
        pokerF[i] = 0;    //|��pokerOfFarmer��l��
        pokerL[i] = 0;    //|��pokerOfLandlord��l��
    }


    pokerNumF = 0;//���a�⤤���P�ƪ�l�Ƭ�0
    pokerNumL = 0;//���a�⤤���P�ƪ�l�Ƭ�0

    srand((int)time(0));
    for (i = 0;i < NUM;i++)
    {
        randNum[i] = rand() * 51 / 32767 + 1;//�����H���ư}�C
    }

}//�غc�禡Poker()����
void test::initPoker()
{
    cout << "�s�@���C���}�l�A�}�l�~�P>>>>>" << endl;

    pokerF[0] = randNum[j++];  //����1-52���H����
    pokerF[1] = randNum[j++];  //����1-52���H����
    pokerL[0] = randNum[j++];  //����1-52���H����
    pokerL[1] = randNum[j++];  //����1-52���H����

    pokerNumF = 2;
    pokerNumL = 2;

    cout << "�~�P����,�A���P��:" << getPokerF() << endl;
}//void Poker::initPoker()����

string test::getPokerF()//�Φr�ꪺ�Φ���^���a���P
{
    int i;
    string result = "";

    for (i = 0;i < pokerNumF;i++)
        result = result + pokerName[pokerF[i]] + " ";

    return result;
}//string Poker::getPokerF()����

string test::getPokerL()//�Φr�ꪺ�Φ���^���a���P
{
    int i;
    string result = "";

    for (i = 0;i < pokerNumL;i++)
        result = result + pokerName[pokerL[i]] + " ";

    return result;
}//string Poker::getPokerL()����

int test::getSumF()   //��^���a���`�I��
{
    int result = 0;

    for (int i = 0;i < pokerNumF;i++)
        result = result + pokerValue[pokerF[i]];

    return result;
}

int test::getSumL()//��^���a���`�I��
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
        cout << "�A���P�Ƥw��5�i�A����A�n�P�F" << endl;
        landlordProcess();
    }
    else
    {
        pokerF[pokerNumF++] = randNum[j++];   //����1-52���H����
        cout << "�A���P��:" << getPokerF() << endl;
        if (getSumF() > 21)
        {
            cout << "�A�����F,�A��F" << bet << "��" << endl;
            money = money - bet;
            if (money <= 0)
            {
                cout << "�A�w�g����F�A����" << endl;
                cout << "�C������" << endl;
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
            cout << "���a���P��" << getPokerL() << endl;
            cout << "�AĹ�F,�AĹ�F" << bet << "��" << endl;
            money = money + bet;
            inputBet();
            initPoker();
        }
        else if (getSumF() == getSumL())
        {
            cout << "���a���P��" << getPokerL() << endl;
            cout << "����" << endl;
            inputBet();
            initPoker();
        }
        else if (getSumF() < getSumL())
        {
            cout << "���a���P��" << getPokerL() << endl;
            cout << "�A��F,�A��F" << bet << "��" << endl;
            money = money - bet;
            if (money <= 0)
            {
                cout << "�A�w�g����F�A����" << endl;
                cout << "�C������" << endl;
                exit(0);
            }
            inputBet();
            initPoker();
        }
    }
    else
    {
        pokerL[pokerNumL++] = randNum[j++];   //����1-52���H����
        if (getSumL() > 21)
        {
            cout << "���a���P��" << getPokerL() << endl;
            cout << "���a�����F,�AĹ�F" << bet << "��" << endl;
            money = money + bet;
            inputBet();
            initPoker();
        }
        else    landlordProcess();
    }
}
void test::inputBet()
{
    cout << "�A�{�b��" << money << "��,�п�J��`:";
    do
    {
        cin >> bet;
        if (bet > money)
            cout << "�³J�A�A�S����h���A�֨ӡA���s��J�a:";
    } while (bet > money);

}

void test::newGame()
{
    inputBet();
    initPoker();
    cout << "�A�o�쪺�P��:" << getPokerF() << endl;
}

void test::landlordProcess()
{
    if (getSumL() >= 17)
    {
        if (getSumL() > getSumF())
        {
            cout << "���a���P��" << getPokerL() << endl;
            cout << "���a��ӡA�A��F" << bet << "��" << endl;
            money = money - bet;
            if (money <= 0)
            {
                cout << "�A�w�g����F�A����" << endl;
                cout << "�C������" << endl;
                exit(0);
            }
            inputBet();
            initPoker();
        }
        else if (getSumF() == getSumL())
        {
            cout << "���a���P��" << getPokerL() << endl;
            cout << "�����C������" << endl;
            inputBet();
            initPoker();
        }
        else
        {
            cout << "���a���P��" << getPokerL() << endl;
            cout << "�AĹ�F,�AĹ�F" << bet << "��" << endl;
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