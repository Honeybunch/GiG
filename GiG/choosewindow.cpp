#include "choosewindow.h"
#include "ui_choosewindow.h"

#ifdef _WIN32
#include <Windows.h>
#endif

ChooseWindow::ChooseWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChooseWindow)
{
    ui->setupUi(this);
    connect(ui->displayButton, SIGNAL(clicked()), this, SLOT(displayStream()));

    overlay = new OverlayWindow();
}

//Try to open a stream with the given URL
void ChooseWindow::displayStream()
{
    QString url = ui->streamInput->text();

    QString channel = getChannel(url);

    if(channel == NULL)
        return;

    //If we have a valid channel name, lets launch the overlay and then minimize to the taskbar
    overlay->setChannel(channel);
    overlay->show();

#if _WIN32
    //Get window with windows API
    HWND handle;
    handle = FindWindow(NULL, TEXT("OverlayWindow"));

    if(handle == 0)
    {
        qDebug() << "Can't find overlay window" << endl;
        return;
    }

    SetWindowPos(handle, HWND_TOPMOST, overlay->pos().x(), overlay->pos().y(), 0,0,SWP_NOOWNERZORDER);
#endif

}

//Parses the channel name from the url
QString ChooseWindow::getChannel(QString url)
{
    //trim off some excess
    if(url.startsWith("http://"))
        url.remove("http://");

    if(url.startsWith("www."))
        url.remove("www.");

    //If this isn't a twitch url, lets throw an error
    if(!url.startsWith("twitch.tv"))
    {
        qDebug("Not a twitch link");
        return NULL;
    }

    //If there isn't just one '/' charater, then we're not at a channel url
    if(url.count("/") != 1)
    {
        qDebug("Not a valid channel link");
        return NULL;
    }

    //Finally find the channel name and return it
    int splitIndex = url.lastIndexOf("/");
    QString channel = url.right(url.size() - splitIndex - 1);

    return channel;
}

ChooseWindow::~ChooseWindow()
{
    delete overlay;
    delete ui;
}
