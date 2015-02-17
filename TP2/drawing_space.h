#ifndef DRAWING_SPACE_H
#define DRAWING_SPACE_H

#include <QWidget>
#include <QPaintEvent>
#include <QList>
#include <QDebug>
#include <QPainter>

class DrawingSpace : public QWidget{

public:
    DrawingSpace();

protected:
    void paintEvent( QPaintEvent* e );
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

public slots:
    void newLine();
    void adjustLine();

private :
    QPoint pos;
    QList<QLine> lines;
    QLine *current;

};


#endif // DRAWING_SPACE_H
