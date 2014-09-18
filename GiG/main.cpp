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

#include "startwindow.h"
#include <QApplication>

#ifdef _WIN32
#include <Windows.h>
#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartWindow w;

    w.setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);

    w.show();

#if _WIN32
    //Get window with windows API
    HWND handle;
    handle = FindWindow(NULL, TEXT("StartWindow"));

    if(handle == 0)
    {
        qDebug() << "crap" << endl;
        return 0;
    }

    SetWindowPos(handle, HWND_TOPMOST, w.pos().x(), w.pos().y(), 0,0,SWP_NOOWNERZORDER);
#endif

    return a.exec();
}
