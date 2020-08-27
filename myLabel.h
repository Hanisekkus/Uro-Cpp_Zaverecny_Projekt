#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QWidget>
#include <Qt>

class myLabel : public QLabel {
    Q_OBJECT

public:
    explicit myLabel(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ~myLabel();

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent* event);

};
#endif // MYLABEL_H
