#include "drawing_space.h"
#include "Transitions.h"

DrawingSpace::DrawingSpace() : QWidget()
{
    setMinimumSize(300,200);
    current = NULL;

//    QState *waitPress = new QState();
//    QState *onPress = new QState();

//    addMouseTrans(waitPress,onPress,this,QEvent::MouseButtonPress,Qt::LeftButton,
//                  this,SLOT(newLine()),pos);
//    addMouseTrans(onPress,onPress,this,QEvent::MouseMove,Qt::NoButton,
//                  this,SLOT(adjustLine()),pos);

}

void DrawingSpace::paintEvent( QPaintEvent* e ){
    QPainter painter(this);
    foreach(QLine line, lines){
        painter.drawLine(line);
    }
    if(current != NULL)
        painter.drawLine(*current);
}

void DrawingSpace::mousePressEvent(QMouseEvent *e){
    qDebug() << "press";
    current = new QLine(e->pos(),e->pos());
    update();
}

void DrawingSpace::mouseMoveEvent(QMouseEvent *e){
    qDebug() << "move";
    current = new QLine(current->p1(),e->pos());
    update();
}

void DrawingSpace::mouseReleaseEvent(QMouseEvent *e){
    qDebug() << "release";
    lines.append(*current);
    current = NULL;
    update();
}

void DrawingSpace::newLine(){

}

void DrawingSpace::adjustLine(){

}
