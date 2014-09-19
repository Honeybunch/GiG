/*
   Game in Game (GiG): A makeshift cross platform "Picture in Picture"
   solution for displaying a Twitch.tv stream over games and other windows

   Copyright (C) 2014  Arsen 'Honeybunch' Tufankjian

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
*/

#ifndef OVERLAYWINDOW_H
#define OVERLAYWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QMouseEvent>
#include <QWebPage>
#include <QWebFrame>
#include <QWebElement>

namespace Ui {
class OverlayWindow;
}

class OverlayWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit OverlayWindow(QWidget *parent = 0);
    void setChannel(QString channel);

    ~OverlayWindow();

protected:

    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void resizeEvent(QResizeEvent *);

    void setRoundedMask();


private:
    Ui::OverlayWindow *ui;

    QString channel;
    bool dragging;
    QPoint clickPoint;

};

#endif // OVERLAYWINDOW_H
