#include "app.h"

#include<QDebug>


App::App(QWidget *parent)
    : QMainWindow(parent)
{

    //? -- signal mapper for custom parametres send via signal
    //? -- and received in slots
    this->_signalMapper = new QSignalMapper( this );

    //*** -- main window on which everything gonna be displayed
    this->_mainWindow = new QFrame();
    this->_mainWindow->setGeometry( 0, 0, 1440, 900);

    //** -- First window
    this->_firstWindow = new QFrame( this->_mainWindow );
    this->_firstWindow->setGeometry( 0, 0, 1440, 900);

    // -- another fancy cut
    this->_footerLine1 = new QFrame( this->_firstWindow );
    this->_footerLine1->setGeometry( 0, 51, 1440, 4 );

    // -- another fancy cut
    this->_footerLine2 = new QFrame( this->_firstWindow );
    this->_footerLine2->setGeometry( 0, 48, 1440, 3 );

    // -- my full name
    this->_fullName = new QLabel("Jan Kusák", this->_firstWindow );
    this->_fullName->setGeometry( 1190, 10, 120, 30 );

    // -- another fancy cut
    this->_footerLine3 = new QFrame( this->_firstWindow );
    this->_footerLine3->setGeometry( 1300, 13, 2, 22 );

    // -- my login
    this->_login = new QLabel("Kus0054", this->_firstWindow );
    this->_login->setGeometry( 1305, 10, 120, 30 );

    // -- user Picture,, clickable (to show menu)
    this->_userPic = new myLabel( this->_firstWindow );
    QPixmap pic("../img/icon.png");
    this->_userPic->setPixmap( pic );
    this->_userPic->setCursor( QCursor( Qt::PointingHandCursor ) );
    this->_userPic->setGeometry( 1400, 7, 32, 32 );

    //* -- menu
    this->_menu = new QFrame( this->_firstWindow );
    this->_menu->setGeometry( 1180, 55, 260, 100 );
    this->_menu->hide();

    // -- menu text for dark/light mode
    this->_darkLight = new QLabel("Tmavý režim", this->_menu );
    this->_darkLight->setGeometry( 15, 15, 120, 20 );

    // -- menu switcher for dark/light mode,, clickable
    this->_switchDL = new myLabel( this->_menu );
    pic.load("../img/slideLSide.png");
    this->_switchDL->setPixmap( pic );
    this->_switchDL->setCursor( QCursor( Qt::PointingHandCursor ) );
    this->_switchDL->setGeometry( 170, 10, 64, 32 );

    // -- menu price
    this->_price = new QLabel("Peníze na účtě: 1 000 000 Kč", this->_menu );
    this->_price->setGeometry( 15, 65, 225, 20 );

    // -- another fancy cut in menu to divide items
    this->_footerLine7 = new QFrame( this->_menu );
    this->_footerLine7->setGeometry( 0, 50, 260, 2 );

    // -- another fancy cut
    this->_footerLine4 = new QFrame( this->_firstWindow );
    this->_footerLine4->setGeometry( 298, 75, 2, 825 );

    // -- Title of header
    this->_textLabel1 = new QLabel("Knihy", this->_firstWindow );
    this->_textLabel1->setGeometry( 90, 100, 120, 50 );

    // -- Owned text,, clickable
    this->_owned = new myLabel( this->_firstWindow );
    this->_owned->setText("Vlastněné");
    this->_owned->setCursor( QCursor( Qt::PointingHandCursor ) );
    this->_owned->setGeometry( 30, 175, 120, 50 );

    // -- Radio button to owned,, clickable
    this->_ownedPic = new myLabel( this->_firstWindow );
    pic.load("../img/radioButton.png");
    this->_ownedPic->setPixmap( pic );
    this->_ownedPic->setCursor( QCursor( Qt::PointingHandCursor ) );
    this->_ownedPic->setGeometry( 200, 177, 20, 50 );

    // -- Buyout text,, clickable
    this->_buyout = new myLabel( this->_firstWindow );
    this->_buyout->setText("Na trhu");
    this->_buyout->setCursor( QCursor( Qt::PointingHandCursor ) );
    this->_buyout->setGeometry( 30, 235, 120, 50 );

    // -- Radio button to buyout,, clickable
    this->_buyoutPic = new myLabel( this->_firstWindow );
    this->_buyoutPic->setPixmap( pic );
    this->_buyoutPic->setCursor( QCursor( Qt::PointingHandCursor ) );
    this->_buyoutPic->setGeometry( 200, 237, 20, 50 );

    // -- another cut
    this->_footerLine5 = new QFrame( this->_firstWindow );
    this->_footerLine5->setGeometry( 25, 335, 250, 2 );

    // -- Chapter on the left side
    for( int i = 0; i < this->_sections.length(); i++ )
    {
        // -- left 'border'
        this->_sectionsFrame.push_back( new QFrame( this->_firstWindow ) );
        this->_sectionsFrame.at( i )->setStyleSheet("background-color: "+ this->GREEN_COLOR +";");
        this->_sectionsFrame.at( i )->setGeometry( 24, 358 + i * 36, 3, 24 );

        // -- text,, clickable
        this->_sectionsLabel.push_back( new myLabel( this->_firstWindow ) );
        this->_sectionsLabel.at( i )->setText( this->_sections.at( i ) );
        this->_sectionsLabel.at( i )->setCursor( QCursor( Qt::PointingHandCursor ) );
        this->_sectionsLabel.at( i )->setGeometry( 30, 360 + i * 36, 120, 20 );

    }
    // -- Another cut line
    this->_footerLine6 = new QFrame( this->_firstWindow );
    this->_footerLine6->setGeometry( 0, 850, 300, 2 );

    // -- Version of software
    this->_textLabel2 = new QLabel("v.1.0.0.0", this->_firstWindow );
    this->_textLabel2->setGeometry( 118, 860, 90, 30 );

    // -- Search bar
    this->_search = new QLineEdit( "Najdi si svoji knížku...", this->_firstWindow );
    this->_search->setAlignment( Qt::AlignRight );
    this->_search->setGeometry( 620, 100, 512, 64 );

    // -- Book order
    int counter = 0;
    for( int i = 0; i < this->_booksTitle.length(); i ++ ){
        // -- Book picture,, clickable
        pic.load("../img/bookIcon.png");
        this->_booksLabel.push_back( new myLabel( this->_firstWindow ) );
        this->_booksLabel.at( i )->setPixmap( pic );
        this->_booksLabel.at( i )->setCursor( QCursor( Qt::PointingHandCursor ) );
        this->_booksLabel.at( i )->setGeometry( 400 + ( i - counter * 3) *  350, 200 + counter * 350, 250, 250 );

        // -- Book Title
        this->_bookNames.push_back( new QLabel( this->_firstWindow ) );
        this->_bookNames.at( i )->setText( this->_booksTitle.at( i ) );
        this->_bookNames.at( i )->setAlignment( Qt::AlignCenter );
        this->_bookNames.at( i )->setGeometry( 400 + ( i - counter * 3) *  350 , 460 + counter * 350, 250, 30 );

        // -- Book Author
        this->_bookAuthors.push_back( new QLabel( this->_firstWindow ) );
        this->_bookAuthors.at( i )->setText( this->_booksAuthor.at( i ) );
        this->_bookAuthors.at( i )->setAlignment( Qt::AlignCenter );
        this->_bookAuthors.at( i )->setGeometry( 400 + ( i - counter * 3) *  350 , 490 + counter * 350, 250, 30 );

        // -- Making offset
        if( i == 2)
            counter = 1;
    }

    //** -- Second window
    this->_secondWindow = new QFrame( this->_mainWindow );
    this->_secondWindow->setGeometry( 0, 0, 1440, 900);
    this->_secondWindow->hide();

    //* -- Left panel on the second window
    this->_lPanel = new QFrame( this->_secondWindow );
    this->_lPanel->setGeometry( 0, 0, 300, 900 );

    // -- Name of book on the second window
    this->_book = new QLabel( this->_lPanel );
    this->_book->setGeometry( 50, 65, 220, 30 );

    // -- Name of author book on the second window
    this->_author = new QLabel( this->_lPanel );
    this->_author->setGeometry( 53, 95, 200, 30 );

    // -- Button on the left panel of second window
    // -- function : get back to first window
    this->_getBack = new QPushButton( "Zpátky", this->_lPanel );
    this->_getBack->setCursor( QCursor( Qt::PointingHandCursor ) );
    this->_getBack->setGeometry( 60, 800, 150, 50 );

    // -- Button to hide/show left panel
    pic.load("../img/hideL.png");
    this->_lPanelMove = new myLabel( this->_secondWindow );
    this->_lPanelMove->setPixmap( pic );
    this->_lPanelMove->setCursor( QCursor( Qt::PointingHandCursor ) );
    this->_lPanelMove->setGeometry( 300, 50, 32, 32 );

    // -- Chapters under line
    this->_chapUnderline = new QFrame( this->_secondWindow );
    this->_chapUnderline->setGeometry( 86, 267, 52, 10 );

    // -- Each chapter
    for( int i = 0; i < 10; i++ )
    {

        this->_chapsLabel.push_back( new myLabel( this->_secondWindow ) );
        this->_chapsLabel.at( i )->setText( "Kapitola " + QString::number( i + 1 ) );
        this->_chapsLabel.at( i )->setCursor( QCursor( Qt::PointingHandCursor ) );
        this->_chapsLabel.at( i )->setAlignment( Qt::AlignRight );
        this->_chapsLabel.at( i )->setGeometry( 0, 250 + i * 50, 135, 25 );

    }

    //* -- Right panel
    this->_rPanel = new QFrame( this->_secondWindow );
    this->_rPanel->setGeometry( 1140, 0, 300, 900 );

    // -- Button to hide/show right panel
    pic.load("../img/hideR.png");
    this->_rPanelMove = new myLabel( this->_secondWindow );
    this->_rPanelMove->setPixmap( pic );
    this->_rPanelMove->setCursor( QCursor( Qt::PointingHandCursor ) );
    this->_rPanelMove->setGeometry( 1108, 50, 32, 32 );

    // -- Text of the book
    this->_bookText = new QTextEdit( this->_secondWindow );
    this->_bookText->setReadOnly( true );
    this->_bookText->setGeometry( 400, 30, 640, 830 );

    for( int i = 0; i < 15; i ++ )
    {

        this->_bookText->setText( this->_bookText->toPlainText() +
                                  "\nLorem ipsum dolor sit amet, consectetuer adipiscing elit.\n" +
                                  " Phasellus rhoncus. In dapibus augue non sapien. Ut tempus purus at lorem.\n"+
                                  " Aliquam erat volutpat. Nunc auctor. Aliquam ornare wisi eu metus.\n"+
                                  " Praesent in mauris eu tortor porttitor accumsan. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.\n"+
                                  " Integer in sapien.\n" );
    }


    //! -- Seting the Central widget
    setCentralWidget( this->_mainWindow );
    //! -- Colorized -> for setting colors to each element
    this->_colorized();
    //! -- SetFont -> for setting font to each label
    this->_setFont();
    //! -- setMapping -> for setting each custom parameter giver to slot
    this->_setMapping();

}

App::~App()
{    //! -- Delete Actions

    delete _firstWindow;
    delete _secondWindow;
    delete _signalMapper;
    delete _mainWindow;

}

void App::_colorized(){    //! -- Customizing colors

    this->_firstWindow->setStyleSheet("background-color: " +  ( this->_isDark ? this->DARK_COLOR : this->LIGHT_COLOR )  + ";");
    this->_secondWindow->setStyleSheet("background-color: " +  ( this->_isDark ? this->DARK_COLOR : this->LIGHT_COLOR )  + ";");
    this->_fullName->setStyleSheet("color: " +  ( !this->_isDark ? this->DARK_COLOR : this->LIGHT_COLOR )  + ";");
    this->_footerLine2->setStyleSheet("background-color: "+ this->GREEN_COLOR +";");
    this->_footerLine1->setStyleSheet("background-color: "+ this->GREEN_COLOR +";");
    this->_footerLine3->setStyleSheet("background-color: "+ this->GREEN_COLOR +";");
    this->_login->setStyleSheet("color: " +  ( !this->_isDark ? this->DARK_COLOR : this->LIGHT_COLOR )  + ";");
    this->_footerLine4->setStyleSheet("background-color: "+ this->GREEN_COLOR +";");
    this->_textLabel1->setStyleSheet("color: " +  ( !this->_isDark ? this->DARK_COLOR : this->LIGHT_COLOR )  + ";");
    this->_owned->setStyleSheet("color: " +  ( !this->_isDark ? this->DARK_COLOR : this->LIGHT_COLOR )  + ";");
    this->_buyout->setStyleSheet("color: " +  ( !this->_isDark ? this->DARK_COLOR : this->LIGHT_COLOR )  + ";");
    this->_footerLine5->setStyleSheet("background-color: "+ this->GREEN_COLOR +";");
    this->_footerLine6->setStyleSheet("background-color: "+ this->GREEN_COLOR +";");
    this->_textLabel2->setStyleSheet("color: " +  ( !this->_isDark ? this->DARK_COLOR : this->LIGHT_COLOR )  + ";");
    this->_menu->setStyleSheet("background-color: " +  ( this->_isDark ? this->DARK_COLOR : this->LIGHT_COLOR )  + ";" +
        "border: 2px solid "+ this->GREEN_COLOR +";");
    this->_footerLine7->setStyleSheet("background-color: "+ this->GREEN_COLOR +";");
    this->_darkLight->setStyleSheet("border: 0 ;color: " +  ( !this->_isDark ? this->DARK_COLOR : this->LIGHT_COLOR )  + ";");
    this->_price->setStyleSheet("border: 0 ;color: " +  ( !this->_isDark ? this->DARK_COLOR : this->LIGHT_COLOR )  + ";");
    this->_switchDL->setStyleSheet("border: 0 ;color: " +  ( !this->_isDark ? this->DARK_COLOR : this->LIGHT_COLOR )  + ";");
    this->_search->setStyleSheet( "border: 4px solid " +this->GREEN_COLOR +
                                  "; color: " + (!this->_isDark ? this->DARK_COLOR2 : this->LIGHT_COLOR2) +
                                  "; background-color: " + (this->_isDark ? this->DARK_COLOR2 : this->LIGHT_COLOR2) +
                                  "; border-radius: 32px; padding-right: 5px;");
    this->_lPanel->setStyleSheet( "padding:0;border-right:2px solid " + this->GREEN_COLOR + ";");
    this->_book->setStyleSheet( "border:0; color: " + ( !this->_isDark ? this->DARK_COLOR : this->LIGHT_COLOR ) + ";");
    this->_getBack->setStyleSheet("background-color: " +  ( this->_isDark ? this->DARK_COLOR2 : this->LIGHT_COLOR2 )  + ";" +
                                "border: 2px solid " + this->RED_COLOR + "; color: " + this->RED_COLOR + "; border-radius: 15px;");
    this->_author->setStyleSheet( "border:0; color: " + ( !this->_isDark ? this->DARK_COLOR : this->LIGHT_COLOR ) + ";");
    this->_rPanel->setStyleSheet( "border-left:2px solid " + this->GREEN_COLOR + ";");
    this->_lPanelMove->setStyleSheet("color: " +  ( !this->_isDark ? this->DARK_COLOR : this->LIGHT_COLOR )  + ";");
    this->_rPanelMove->setStyleSheet("color: " +  ( !this->_isDark ? this->DARK_COLOR : this->LIGHT_COLOR )  + ";");
    this->_bookText->setStyleSheet( " border: 0; color: " +  ( !this->_isDark ? this->DARK_COLOR : this->LIGHT_COLOR )  + ";" );
    this->_chapUnderline->setStyleSheet("background-color: "+ this->GREEN_COLOR +";");

    for( int i = 0; i < this->_sectionsLabel.length(); i ++ )
        this->_sectionsLabel.at( i )->setStyleSheet("color: " +  ( !this->_isDark ? this->DARK_COLOR : this->LIGHT_COLOR )  + ";");

    for( int i = 0; i < this->_chapsLabel.length(); i ++ )
        this->_chapsLabel.at( i )->setStyleSheet("padding-right:5px;color: " +  ( !this->_isDark ? this->DARK_COLOR : this->LIGHT_COLOR )  + ";");

    for( int i = 0; i < this->_bookNames.length(); i ++ )
        this->_bookNames.at( i )->setStyleSheet( " color: " +  ( !this->_isDark ? this->DARK_COLOR : this->LIGHT_COLOR )  + ";" );

    for( int i = 0; i < this->_bookAuthors.length(); i ++ )
        this->_bookAuthors.at( i )->setStyleSheet( " color: " +  ( !this->_isDark ? this->DARK_COLOR : this->LIGHT_COLOR )  + ";" );

}

void App::_setFont(){ //! Customizing font

    this->_fullName->setFont( QFont("Helvetika", 16, QFont::Bold) );
    this->_login->setFont( QFont("Helvetika", 16, QFont::Bold) );
    this->_textLabel1->setFont( QFont("Helvetika", 30, QFont::Bold) );
    this->_owned->setFont( QFont("Helvetika", 20, QFont::Normal) );
    this->_buyout->setFont( QFont("Helvetika", 20, QFont::Normal) );    
    this->_textLabel2->setFont( QFont("Helvetika", 12, QFont::Bold, QFont::Cursive ) );
    this->_darkLight->setFont( QFont("Helvetika", 12, QFont::Bold ) );
    this->_price->setFont( QFont("Helvetika", 12, QFont::Bold ) );
    this->_search->setFont( QFont("Helvetika", 18, QFont::Normal, QFont::Cursive ) );
    this->_book->setFont( QFont("Helvetika", 20, QFont::Bold ) );
    this->_getBack->setFont( QFont("Helvetika", 12, QFont::Bold ) );
    this->_author->setFont( QFont("Helvetika", 12, QFont::Normal ) );
    this->_bookText->setFont( QFont("Helvetika", 14, QFont::Normal ) );

    for( int i = 0; i < this->_sectionsLabel.length(); i ++ )
        this->_sectionsLabel.at( i )->setFont( QFont("Helvetika", 12, QFont::Normal) );

    for( int i = 0; i < this->_chapsLabel.length(); i ++ )
        this->_chapsLabel.at( i )->setFont( QFont("Helvetika", 14, QFont::Normal ) );

    for( int i = 0; i < this->_bookNames.length(); i ++ )
        this->_bookNames.at( i )->setFont( QFont("Helvetika", 20, QFont::Bold ) );

    for( int i = 0; i < this->_bookAuthors.length(); i ++ )
        this->_bookAuthors.at( i )->setFont( QFont("Helvetika", 14, QFont::Normal ) );

}

void App::_setMapping()
{ //! Setting custom parameters

    connect( this->_getBack, SIGNAL( clicked() ), this, SLOT( _setBack() ) );
    connect( this->_owned, SIGNAL( clicked() ), this->_signalMapper, SLOT( map() ) );
    connect( this->_ownedPic, SIGNAL( clicked() ), this->_signalMapper, SLOT( map() ) );
    connect( this->_buyout, SIGNAL( clicked() ), this->_signalMapper, SLOT( map() ) );
    connect( this->_buyoutPic, SIGNAL( clicked() ), this->_signalMapper, SLOT( map() ) );
    connect( this->_userPic, SIGNAL( clicked() ), this->_signalMapper, SLOT( map() ) );
    connect( this->_switchDL, SIGNAL( clicked() ), this->_signalMapper, SLOT( map() ) );
    connect( this->_lPanelMove, SIGNAL( clicked() ), this->_signalMapper, SLOT( map() ) );
    connect( this->_rPanelMove, SIGNAL( clicked() ), this->_signalMapper, SLOT( map() ) );

    for( int i = 0; i < this->_sectionsLabel.length(); i ++ )
        connect( this->_sectionsLabel.at( i ), SIGNAL( clicked() ), this->_signalMapper, SLOT( map() ) );

    for( int i = 0; i < this->_booksLabel.length(); i ++ )
        connect( this->_booksLabel.at( i ), SIGNAL( clicked() ), this->_signalMapper, SLOT( map() ) );

    for( int i = 0; i < this->_chapsLabel.length(); i ++ )
        connect( this->_chapsLabel.at( i ), SIGNAL( clicked() ), this->_signalMapper, SLOT( map() ) );


    this->_signalMapper->setMapping( this->_owned, 0 );
    this->_signalMapper->setMapping( this->_ownedPic, 0 );
    this->_signalMapper->setMapping( this->_buyout, 1 );
    this->_signalMapper->setMapping( this->_buyoutPic, 1 );

    for( int i = 0; i < this->_sectionsLabel.length(); i ++ )
    {

        this->_signalMapper->setMapping( this->_sectionsLabel.at( i ), i + 2 );

    }
    this->_signalMapper->setMapping( this->_userPic, 12 );
    this->_signalMapper->setMapping( this->_switchDL, 13 );

    for( int i = 0; i < this->_booksLabel.length(); i ++ )
    {

                this->_signalMapper->setMapping( this->_booksLabel.at( i ), i + 14 );

    }
    this->_signalMapper->setMapping( this->_lPanelMove, 20 );
    this->_signalMapper->setMapping( this->_rPanelMove, 21 );

    for( int i = 0; i < this->_chapsLabel.length(); i ++ )
        this->_signalMapper->setMapping( this->_chapsLabel.at( i ), i + 22 );


    connect( this->_signalMapper, SIGNAL( mapped( int ) ), this, SLOT( _clickedElement( int ) ) );

}

void App::_clickedElement( int pos ){ //! slot function
    switch( pos ){
    case 0: {
        QPixmap pic( ( this->_isOwned? "../img/radioButton.png": "../img/radioButtonFilled.png") );
        this->_ownedPic->setPixmap( pic );
        this->_isOwned = !this->_isOwned;
        break;
    }
    case 1: {
        QPixmap pic( ( this->_isBuyout? "../img/radioButton.png": "../img/radioButtonFilled.png") );
        this->_buyoutPic->setPixmap( pic );
        this->_isBuyout = !this->_isBuyout;
        break;
    }
    case 2 ... 11: {

        for( int i = 0; i < this->_sectionsLabel.length(); i ++ )
        {

            this->_sectionsLabel.at( i )->setFont( QFont("Helvetika", 12, QFont::Normal ) );
            this->_sectionsFrame.at( i )->setStyleSheet("background-color: " + this->GREEN_COLOR + ";");

        }

        this->_sectionsLabel.at( pos - 2 )->setFont( QFont("Helvetika", 12, QFont::Bold, QFont::Cursive) );
        this->_sectionsFrame.at( pos - 2 )->setStyleSheet("background-color: " + this->GOLD_COLOR + ";");
        break;
    }
    case 12:{
        this->_isMenu? this->_menu->hide():this->_menu->show();
        this->_isMenu = !this->_isMenu;
        break;
    }
    case 13:{
        QPixmap pic( ( this->_isDark? "../img/slideRSide.png": "../img/slideLSide.png") );
        this->_isDark = !this->_isDark;
        this->_darkLight->setText( this->_isDark? "Tmavý režim": "Světlý režim" );
        this->_switchDL->setPixmap( pic );
        this->_colorized();
        break;
    }
    case 14 ... 19:{
        this->_firstWindow->hide();
        this->_secondWindow->show();
        this->_book->setText( this->_booksTitle.at( pos - 14 ));
        this->_author->setText( this->_booksAuthor.at( pos - 14 ));
        break;
    }
    case 20:{
        this->_isLPanel ? this->_lPanel->hide(): this->_lPanel->show();
        this->_isLPanel ? this->_lPanelMove->setGeometry( 0, 50, 32, 32 )
                        : this->_lPanelMove->setGeometry( 300, 50, 32, 32 );
        QPixmap pic( ( this->_isLPanel? "../img/showL.png": "../img/hideL.png") );
        this->_lPanelMove->setPixmap( pic );
        this->_isLPanel = !this->_isLPanel;

        break;
    }
    case 21:{
        this->_isRPanel ? this->_rPanel->hide(): this->_rPanel->show();
        this->_isRPanel ? this->_rPanelMove->setGeometry( 1408, 50, 32, 32 )
                        : this->_rPanelMove->setGeometry( 1108, 50, 32, 32 );
        QPixmap pic( ( this->_isRPanel? "../img/showR.png": "../img/hideR.png") );
        this->_rPanelMove->setPixmap( pic );
        this->_isRPanel = !this->_isRPanel;
        break;
    }
    case 22 ... 31:{
        this->_chapUnderline->setGeometry( 86, 267 + ( pos - 22 ) * 50, 52, 10 );
        break;
    }
    default:
        qInfo() << pos;
    }
}

void App::_setBack()
{//! Returnig from second window to first one

    this->_secondWindow->hide();
    this->_firstWindow->show();
    this->_isRPanel = true;
    this->_rPanel->show();
    QPixmap pic( "../img/hideR.png" );
    this->_rPanelMove->setPixmap( pic );
    this->_chapUnderline->setGeometry( 86, 267, 52, 10 );

}

