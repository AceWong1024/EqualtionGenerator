#include "Random.h"



Random::Random()
{
}


Random::~Random()
{
}

int Random::getRanNum(int a,int b) {
	if (a >= b)
		return -1;
	return (rand() % (b - a + 1) + a);
}
