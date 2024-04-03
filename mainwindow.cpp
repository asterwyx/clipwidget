#include "mainwindow.h"
#include "customwidget.h"
#include "dclipeffectwidget.h"
// #include <DClipEffectWidget>
#include <QPainterPath>
#include <QVBoxLayout>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    auto label = new QLabel();
    QImage wallpaper("/home/astrea/Pictures/Wallpapers/hightech-core.png");
    auto pixmap = QPixmap::fromImage(wallpaper);
    label->setPixmap(pixmap);
    setCentralWidget(label);
    auto widget = new CustomWidget(label);
    widget->move(192, 10);
    widget->resize(233, 233);
    auto clipWidget = new DClipEffectWidget(widget);
    // clipWidget->setMargins(QMargins(1,1,1,1));
    QPainterPath path;
    path.addRoundedRect(widget->rect(), 17, 17);
    clipWidget->setClipPath(path);
}

MainWindow::~MainWindow() {}
