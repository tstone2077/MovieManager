#include <QtCore/QTranslator>
#include <QtCore/QLocale>
#include <QMessageBox>
#include "MainApp.h"


using namespace project::gui;
MainApp::MainApp(int& argc, char * argv[]) : QApplication(argc,argv)
{
    //ctor
    InitResources();
    InitLocale();
    m_pSettings = new QSettings(QSettings::IniFormat,QSettings::UserScope,ORG_NAME,APP_NAME);
    m_pMainWindow = new MainWindow();
}

MainApp::~MainApp()
{
    //dtor
    delete m_pSettings;
    delete m_pMainWindow;
}

void MainApp::InitResources()
{
    //initialize the resources
    //Q_INIT_RESOURCE(Resources);
}

void MainApp::InitLocale()
{
    //initialize the translation to the user's locale
    QString locale = QLocale::system().name();
    QString langStr = QString::fromAscii("app_")+locale;
    QTranslator translator;
    translator.load(langStr,QString::fromAscii(":/qms"));
    installTranslator(&translator);
}


