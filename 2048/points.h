#ifndef POINTS_H
#define POINTS_H

#include <QObject>

class Points
{
public:
    Points();
    ~Points();
    void backZero();
    void changePoint(int a);
    int get();
    int prev();
private:
    int points;
    int prepoints;
};

#endif // POINTS_H
