#pragma once

#include <QDockWidget>
#include <QVBoxLayout>
#include <QWidget>


namespace project
{

namespace gui
{

class FirstDockWidget : public QDockWidget
{
    Q_OBJECT
    public:
        FirstDockWidget();
        virtual ~FirstDockWidget();
    protected:
        void CloseEvent(QCloseEvent * event);
    signals:
        /*
            The default signals for a doc object only contain "visibilityChanged(bool)".
            If this is connected to the "Panes" menu items, then there is a hard crash when
            the dock widget is placed on top of another (to become a tabbed widget).
        //*/
        void Closed(bool);
    private:
        void SetupUI();
        QWidget * m_pMainWidget;
};

}//end gui namespace
}//end project  namespace
