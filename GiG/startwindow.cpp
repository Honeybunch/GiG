#include "startwindow.h"
#include "ui_startwindow.h"

StartWindow::StartWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);


    QString html = "<object type=\"application/x-shockwave-flash\" style=\"position:fixed;top:0px;left:0px;padding:0px;margin:0px;\" height=\"";
    html += QString::number(ui->webView->size().width());
    html += "\" width=\"";
    html += QString::number(ui->webView->size().height());
    html += "\" id=\"live_embed_player_flash\" data=\"http://www.twitch.tv/widgets/live_embed_player.swf?channel=twitchplayspokemon\" bgcolor=\"#000000\"><param name=\"allowFullScreen\" value=\"true\" /><param name=\"allowScriptAccess\" value=\"always\" /><param name=\"allowNetworking\" value=\"all\" /><param name=\"movie\" value=\"http://www.twitch.tv/widgets/live_embed_player.swf\" /><param name=\"flashvars\" value=\"hostname=www.twitch.tv&channel=twitchplayspokemon&auto_play=true&start_volume=25\" /></object>";

    ui->webView->setHtml(html);
    ui->webView->settings()->globalSettings()->setAttribute(QWebSettings::PluginsEnabled, true);

    dragging = false;
}

void StartWindow::mousePressEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        dragging = true;

        clickPoint = event->pos();
    }
}

void StartWindow::mouseMoveEvent(QMouseEvent* event)
{
    if(!dragging)
        return;

    move(event->globalPos() - clickPoint);

    QApplication::setOverrideCursor(Qt::SizeAllCursor);
}

void StartWindow::mouseReleaseEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        QApplication::restoreOverrideCursor();
        QApplication::restoreOverrideCursor();
        QApplication::restoreOverrideCursor();

        dragging = false;
    }
}

void StartWindow::resizeEvent(QResizeEvent* event)
{
    QWebElement object = ui->webView->page()->mainFrame()->findFirstElement("#live_embed_player_flash");

    int newWidth = ui->webView->size().width();
    int newHeight = ui->webView->size().height();

    object.setAttribute("width", QString::number(newWidth));
    object.setAttribute("height", QString::number(newHeight));

    this->setRoundedMask();
}

void StartWindow::setRoundedMask()
{
    int radius = 10;
    QRect rect = this->rect();

    QRegion region;

    //Subtract 4 corners from the region to get a rounded corner effect
    region += rect.adjusted(radius, 0, -radius, 0);
    region += rect.adjusted(0, radius, 0, -radius);

    QRect corner(rect.topLeft(), QSize(radius*2, radius*2));
    region += QRegion(corner, QRegion::Ellipse);

    corner.moveTopRight(rect.topRight());
    region += QRegion(corner, QRegion::Ellipse);

    corner.moveBottomLeft(rect.bottomLeft());
    region += QRegion(corner, QRegion::Ellipse);

    corner.moveBottomRight(rect.bottomRight());
    region += QRegion(corner, QRegion::Ellipse);

    //Set region
    this->setMask(region);
}

StartWindow::~StartWindow()
{
    delete ui;
}
