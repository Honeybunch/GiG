#ifndef CHOOSEWINDOW_H
#define CHOOSEWINDOW_H

#include <QMainWindow>
#include <QDebug>

#include "overlaywindow.h"

namespace Ui {
class ChooseWindow;
}

class ChooseWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChooseWindow(QWidget *parent = 0);
    ~ChooseWindow();

private:
    Ui::ChooseWindow *ui;
    QString getChannel(QString url);
    OverlayWindow* overlay;

public slots:
    void displayStream();
};

#endif // CHOOSEWINDOW_H
