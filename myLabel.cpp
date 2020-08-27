#include "myLabel.h"
#include <QDebug>

myLabel::myLabel(QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent) {

}

myLabel::~myLabel() {}

void myLabel::mousePressEvent(QMouseEvent* event) {
    emit clicked();
}
