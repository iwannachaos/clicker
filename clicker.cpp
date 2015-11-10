#include "clicker.h"

Clicker::Clicker()
    : timer(this)
{
}

int Clicker::clicksCount()
{
    return _clicksCount;
}

void Clicker::setPointsPerClick(int n)
{
    _pointsPerClick = n >= 0 ? n : -n;
}

void Clicker::autoClick()
{
    timer.start(1000);
    connect(&timer, SIGNAL(timeout()), this, SLOT(increaseClicksCount()));
}

void Clicker::increaseClicksCount()
{
    _clicksCount += _pointsPerClick;
    emit clicksCountChanged();

    if (_clicksCount == 10 ||
            _clicksCount == 100 ||
            _clicksCount == 1000 ||
            _clicksCount == 10000)
    {
        emit achivementReached();
    }

    if (_clicksCount == 5000)
    {
        emit x2Unlocked();
    }

    if (_clicksCount == 10000)
    {
        emit autoClickUnlocked();
    }
}
