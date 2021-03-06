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

#include "overlaywindow.h"
#include "ui_overlaywindow.h"

OverlayWindow::OverlayWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OverlayWindow)
{
    ui->setupUi(this);

    ui->webView->settings()->globalSettings()->setAttribute(QWebSettings::PluginsEnabled, true);

    dragging = false;

    qDebug() << "Constructed";
}

void OverlayWindow::setChannel(QString channel)
{
    this->channel = channel;

    QString html = "<object type=\"application/x-shockwave-flash\" style=\"position:fixed;top:0px;left:0px;padding:0px;margin:0px;\" height=\"";
    html += QString::number(ui->webView->size().width());
    html += "\" width=\"";
    html += QString::number(ui->webView->size().height());
    html += "\" id=\"live_embed_player_flash\" data=\"http://www.twitch.tv/widgets/live_embed_player.swf?channel=";
    html += channel;
    html += "\" bgcolor=\"#000000\"><param name=\"allowFullScreen\" value=\"false\" /><param name=\"allowScriptAccess\" value=\"always\" /><param name=\"allowNetworking\" value=\"all\" /><param name=\"movie\" value=\"http://www.twitch.tv/widgets/live_embed_player.swf\" /><param name=\"flashvars\" value=\"hostname=www.twitch.tv&channel=";
    html += channel;
    html += "&auto_play=true&start_volume=25\" /></object>";

    ui->webView->setHtml(html);
}

void OverlayWindow::mousePressEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        dragging = true;

        clickPoint = event->pos();
    }
}

void OverlayWindow::mouseMoveEvent(QMouseEvent* event)
{
    if(!dragging)
        return;

    move(event->globalPos() - clickPoint);

    QApplication::setOverrideCursor(Qt::SizeAllCursor);
}

void OverlayWindow::mouseReleaseEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        QApplication::restoreOverrideCursor();
        QApplication::restoreOverrideCursor();
        QApplication::restoreOverrideCursor();

        dragging = false;
    }
}

void OverlayWindow::resizeEvent(QResizeEvent* event)
{
    QWebElement object = ui->webView->page()->mainFrame()->findFirstElement("#live_embed_player_flash");

    int newWidth = ui->webView->size().width();
    int newHeight = ui->webView->size().height();

    object.setAttribute("width", QString::number(newWidth));
    object.setAttribute("height", QString::number(newHeight));

    this->setRoundedMask();
}

void OverlayWindow::setRoundedMask()
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

OverlayWindow::~OverlayWindow()
{
    delete ui;
}
