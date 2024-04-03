#include "customwidget.h"
#include <QPainter>
CustomWidget::CustomWidget(QWidget *parent)
    : QWidget{parent}
{}


void CustomWidget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.setBrush(Qt::red);
    p.setPen(Qt::NoPen);
    p.drawRect(rect());
}
