#ifndef APP_H
#define APP_H

#include <QMainWindow>
#include <QFrame>
#include <QLabel>
#include <QSignalMapper>
#include <QVector>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <myLabel.h>

QT_BEGIN_NAMESPACE
namespace Ui { class App; }
QT_END_NAMESPACE

class App : public QMainWindow
{
    Q_OBJECT


public:
    App(QWidget *parent = nullptr);
    ~App();

private:

    void _colorized();
    void _setFont();
    void _setMapping();

    bool _isDark = true,
         _isOwned = false,
         _isBuyout = false,
         _isMenu = false,
         _isLPanel = true,
         _isRPanel = true;

    QSignalMapper *_signalMapper;

    QVector<QString> _sections =    {"Drama", "Komedie", "Roman",
                                    "Kronika", "Atlas", "Encyklopedie",
                                    "Akční", "Romance", "Historičné"},
                     _booksTitle =  {"Romeo a Julie", "Figarova svatba",
                                    "Dekameron", "Božská komedie",
                                    "Sluha dvou pánů", "Odysseia"},
                     _booksAuthor = {"William Shakespeare", "Beaumarchais Pierre",
                                     "Boccaccio Giovanni", "Dante Alighieri",
                                     "Goldoni Carlo", "Homér"};
    QVector<int> _booksPrice =  {100, 90, 75, 110, 100, 150};
    QVector<bool> _booksOwned =  {false, true, false, false, false, true};

    QVector<myLabel*> _sectionsLabel,
                      _booksLabel,
                      _chapsLabel;

    QVector<QFrame*>  _sectionsFrame;

    QVector<QLabel*> _bookNames,
                     _bookAuthors;

    QString DARK_COLOR = "rgb( 38, 38, 38 )",
            DARK_COLOR2 = "rgb( 57, 57, 57 )",
            LIGHT_COLOR = "rgb( 217, 217, 217 )",
            LIGHT_COLOR2 = "rgb( 230, 230, 230 )",
            GREEN_COLOR = "rgb( 45, 196, 154 )",
            RED_COLOR = "rgb( 191, 4, 38 )",
            GOLD_COLOR = "rgb( 255, 176, 59 )";

    QFrame *_mainWindow,
           *_firstWindow,
           *_secondWindow,
           *_menu,
           *_footerLine1,
           *_footerLine2,
           *_footerLine3,
           *_footerLine4,
           *_footerLine5,
           *_footerLine6,
           *_footerLine7,
           *_lPanel,
           *_chapUnderline,
           *_rPanel;

    QLabel *_fullName,
           *_login,
           *_darkLight,
           *_price,
           *_book,
           *_author,
           *_textLabel1,
           *_textLabel2;

    QLineEdit *_search;

    QPushButton *_getBack;

    QTextEdit *_bookText;

    myLabel *_switchDL,
            *_owned,
            *_ownedPic,
            *_buyout,
            *_buyoutPic,
            *_userPic,
            *_lPanelMove,
            *_rPanelMove;

private slots:
     void _clickedElement( int );
     void _setBack();

};
#endif // APP_H
