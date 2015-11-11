/*!
 *\file clicker.h
 * Файл класса кликера.
 */

#ifndef CLICKER_H
#define CLICKER_H

#include <QObject>
#include <QTimer>

/*!
 * Класс кликера.
 */
class Clicker : public QObject
{
    Q_OBJECT

public:
    /*!
     * Конструктор.
     */
    explicit Clicker();

    Q_PROPERTY(int clicksCount READ clicksCount NOTIFY clicksCountChanged)

    /*!
     * Получить количество кликов.
     *\return Количество кликов.
     */
    int clicksCount();

    /*!
     * Установить число, на которое будет увеличиваться количество кликов за
     * за один клик.
     *\param[in] Число, на которое будет увеличиваться количество кликов за
     * один клик.
     */
    Q_INVOKABLE void setPointsPerClick(int n);

    /*!
     * Запустить автокликинг.
     */
    Q_INVOKABLE void autoClick();

public slots:
    /*!
     * Увеличить количество кликов.
     */
    void increaseClicksCount();

signals:
    /*!
     * Изменилось количество кликов.
     */
    void clicksCountChanged();

    /*!
     * Достигнуто достижение.
     */
    void achivementReached();

    /*!
     * Можно купить способность x2.
     */
    void x2Unlocked();

    /*!
     * Можно купить способность автоклика.
     */
    void autoClickUnlocked();

private:
    int _clicksCount = 0; ///< Количество кликов.
    /*! Число, на которое увечиличивается количество кликов при одном клике. */
    int _pointsPerClick = 1;
    QTimer timer; ///< Таймер для автокликинга.
};

#endif // CLICKER_H
