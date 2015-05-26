#include "points.h"

Points::Points()
{
    points=0;
    prepoints=0;
}

Points::~Points()
{

}
void Points::backZero()
{
    points=0;
    prepoints=0;

}
void Points::changePoint(int a)
{
    prepoints=points;
    points+=a;

}
int Points::get()
{
    return points;
}

int Points::prev()
{
    return prepoints;
}
