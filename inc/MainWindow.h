#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "WorkbenchWidget.h"
#include "FirstDockWidget.h"

namespace project
{

namespace gui
{

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow();
        virtual ~MainWindow();

    public slots:
    signals:
    protected:
        void CloseEvent(QCloseEvent * event);
    private slots:
        void About();
    private:
        void CreateActions();
        void CreateMenus();
        void CreateConnections();
        void CreateDockWidgets();
        void LoadSettings();
        void SaveSettings();
        WorkbenchWidget * m_pWorkbenchWidget;
        FirstDockWidget * m_pFirstWidget;

        //Actions
        QAction * m_pExitAction;
        QAction * m_pAboutAction;
        QAction * m_pViewChatPaneAction;
        QAction * m_pViewContactPaneAction;
        QAction * m_pViewNavPaneAction;

        //Menus
        QMenu * m_pFileMenu;
        QMenu * m_pViewMenu;
        QMenu * m_pHelpMenu;

};
}//end gui namespace
}//end project namespace
#endif // MAINWINDOW_H
