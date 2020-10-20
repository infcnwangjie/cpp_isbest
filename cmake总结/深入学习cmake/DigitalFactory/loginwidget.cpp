#include "loginwidget.h"
#include <QPainter>

void LoginWidget::paintEvent(QPaintEvent *event){
    QPainter p(this);
//    p.drawRoundedRect(0, 0, width() - 1, height() - 1, 20, 20);
    p.drawPixmap(rect(),QPixmap(":/resource/images/loginbg.png"));
}
