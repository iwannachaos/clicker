#ifndef CLICKER_H
#define CLICKER_H

#include <QObject>
#include <QTimer>

class Clicker : public QObject
{
    Q_OBJECT

public:
    explicit Clicker();

    Q_PROPERTY(int clicksCount READ clicksCount NOTIFY clicksCountChanged)
    int clicksCount();
    Q_INVOKABLE void setPointsPerClick(int n);
    Q_INVOKABLE void autoClick();

public slots:
    void increaseClicksCount();

signals:
    void clicksCountChanged();
    void achivementReached();
    void x2Unlocked();
    void autoClickUnlocked();

private:
    int _clicksCount = 0;
    int _pointsPerClick = 1;
    QTimer timer;
};

#endif // CLICKER_H
