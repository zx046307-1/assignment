#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector> 

using namespace std;

const int numOfCards = 52;
string suits[4] = {"¶Â®ç","¬õ¤ß","¤è¶ô","±öªá"};
string ranks[13] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};

int main()
{
	vector<int> deck(numOfCards);
	
	for(int i=0;i<numOfCards;i++)
	{
		deck[i]=i;
	} 
	
	srand(time(0));
	for(int i=0;i<numOfCards;i++)
	{
		int index=rand()%numOfCards;
		int temp=deck[i];
		deck[i]=deck[index];
		deck[index]=temp;
	}
	
	for(int i=0;i<numOfCards;i++)
	{
		cout<<ranks[deck[i]%13]<<suits[deck[i]/13]<<endl;
	}
	
}
