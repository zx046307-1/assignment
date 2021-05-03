#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

const int SIZE=52;

void randomArray (int array[])
{
	int i, j, a, b;
	initArray(array);
	for(j=SIZE-1;j>=0;j--)
	{
		a=rand()%(j+1);
		
		b=array[a];
		array[a]=array[j];
		array[j]=b;
	}
}

void initArray (int array[])
{
	int i;
	for(i=0;i<=SIZE-1;i++)
	{
		array[i]=i;
	}
}
