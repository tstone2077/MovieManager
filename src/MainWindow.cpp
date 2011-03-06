#include "MainWindow.h"
#include "MainApp.h"
#include <QApplication>
#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QString>

#include <iostream>

using namespace project::gui;

MainWindow::MainWindow()
{
    //ctor
    setWindowIcon(QIcon(":/images/icon-small.png"));
    setWindowTitle(tr(APP_NAME)+" "+APP_VERSION);

    m_pWorkbenchWidget = new WorkbenchWidget();
    setCentralWidget(m_pWorkbenchWidget);

    CreateDockWidgets();
    CreateActions();
    CreateMenus();
    CreateConnections();
    LoadSettings();
}

MainWindow::~MainWindow()
{
    //dtor
    delete m_pWorkbenchWidget;
    delete m_pExitAction;
    delete m_pAboutAction;
}

void MainWindow::CreateConnections()
{
    connect(m_pExitAction,SIGNAL(triggered()),this,SLOT(close()));
    connect(m_pAboutAction,SIGNAL(triggered()),SLOT(About()));
    connect(qApp,SIGNAL(ChangedWorkplace(Workplace *,Utility *)),this,SLOT(setActiveWorkplace(Workplace *,Utility *)));
}

void MainWindow::CreateActions()
{
    //Exit Action
    m_pExitAction = new QAction(tr("E&xit"), this);
    m_pExitAction->setShortcut(tr("Ctrl+X"));
    m_pExitAction->setStatusTip(tr("Exit ")+tr(APP_NAME));

    //About Action
    m_pAboutAction = new QAction(tr("&About"),this);
    m_pAboutAction->setShortcut(tr("Ctrl+A"));
    m_pAboutAction->setStatusTip(tr("Show information about ")+tr(APP_NAME));

}

void MainWindow::CloseEvent(QCloseEvent * event)
{
	SaveSettings();
}
void MainWindow::SaveSettings()
{
	 MainApp * app = static_cast<MainApp *> qApp;
    //save the settings
    app->m_pSettings->beginGroup("mainWindow");
    app->m_pSettings->setValue("maximized",isMaximized());
    //if it is not maximized, save the size and position
    if (!isMaximized())
    {
        app->m_pSettings->setValue("size",size());
        app->m_pSettings->setValue("pos",pos());
    }
    app->m_pSettings->setValue("state",saveState());
    app->m_pSettings->endGroup();
}
void MainWindow::LoadSettings()
{
	MainApp * app = static_cast<MainApp *> qApp;
    app->m_pSettings->beginGroup("mainWindow");
    restoreState(app->m_pSettings->value("state").toByteArray());
    resize(app->m_pSettings->value("size",QSize(800,600)).toSize());
    move(app->m_pSettings->value("pos").toPoint());
    if (app->m_pSettings->value("maximized",false).toBool())
        setWindowState(Qt::WindowMaximized);

    app->m_pSettings->endGroup();
}

void MainWindow::CreateMenus()
{
    //File Menu
    m_pFileMenu = menuBar()->addMenu(tr("&File"));
    m_pFileMenu->addAction(m_pExitAction);
 
    //View Menu
    //m_pViewMenu = createPopupMenu();
    QMenu * popupMenu = createPopupMenu();
    popupMenu->setTitle("&Dock Windows");
    m_pViewMenu = menuBar()->addMenu("&View");
    m_pViewMenu->addMenu(popupMenu);


    //Help Menu
    m_pHelpMenu = menuBar()->addMenu(tr("&Help"));
    m_pHelpMenu->addAction(m_pAboutAction);
}

void MainWindow::About()
{
    QString aboutStr = "<h2>"+tr(APP_NAME)+" "+tr(APP_VERSION)+"</h2>";
    aboutStr += "<p><h4>Copyright "+tr(APP_COPYRIGHT)+"</h4></p>";
    aboutStr += tr("<p>Describe Application Here!</p>");
    QMessageBox::about(this,tr("About ") + tr(APP_NAME),
            aboutStr);
}

void MainWindow::CreateDockWidgets()
{
    m_pFirstWidget = new FirstDockWidget();
    m_pFirstWidget->setObjectName("FirstDockWidget"); //object name needs to be set for saveState() to work
    addDockWidget(Qt::LeftDockWidgetArea, m_pFirstWidget);

}
