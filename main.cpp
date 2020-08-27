#include "app.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    App w;
    w.setFixedSize( 1440, 900 );
    w.setWindowTitle( "Kus0054" );
    w.show();
    return a.exec();
}
