#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QMouseEvent>
#include <QWebPage>
#include <QWebFrame>
#include <QWebElement>

namespace Ui {
class StartWindow;
}

class StartWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = 0);

    ~StartWindow();

protected:

    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void resizeEvent(QResizeEvent *);

    void setRoundedMask();


private:
    Ui::StartWindow *ui;


    bool dragging;
    QPoint clickPoint;

};

#endif // STARTWINDOW_H
