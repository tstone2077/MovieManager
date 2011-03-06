#pragma once

#include <QApplication>
#include <QSystemTrayIcon>
#include <QtCore/QSettings>
#include <map>
#include "MainWindow.h"

#define ORG_NAME "Organization"
#define APP_NAME "Application"
#define APP_VERSION "0.1"
#define APP_COPYRIGHT "2010"

namespace project
{

namespace gui
{


class MainApp : public QApplication
{
    Q_OBJECT

    public:
    	  MainApp(int& argc, char * argv[]);
        virtual ~MainApp();
        void InitResources();
        void InitLocale();
        MainWindow * m_pMainWindow;
        QSettings * m_pSettings;
    public slots:
    private slots:
    signals:
    private:
};
} //end gui namespace
} //end project namespace
