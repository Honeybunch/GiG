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
