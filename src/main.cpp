#define QT_NO_CAST_FROM_ASCII

#include "MainApp.h"
#include <QSplashScreen>
#include <QtCore/QTranslator>

int main (int argc, char * argv[])
{
    bool splashOn = true;
    project::gui::MainApp app(argc,argv);

    //load App
    QSplashScreen * splash = new QSplashScreen;
    Qt::Alignment displayLocation = Qt::AlignCenter | Qt::AlignBottom;
    int color = Qt::black;
    if (splashOn)
    {
        splash->setPixmap(QPixmap(QString::fromAscii(":/images/loading-splash.png")));
        splash->show();
        splash->showMessage(QObject::tr("Loading workplaces..."),displayLocation,color);
    }

    if (splashOn)
    {
        splash->showMessage(QObject::tr("Setting up main window..."),displayLocation,color);
    }

    if (splashOn)
    {
        splash->showMessage(QObject::tr("Loading Application..."),displayLocation,color);
    }
    app.m_pMainWindow->show();

    if (splashOn)
    {
        splash->finish(app.m_pMainWindow);
    }
    delete splash;

    return app.exec();
}
