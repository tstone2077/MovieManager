#ifndef WORKBENCHWIDGET_H
#define WORKBENCHWIDGET_H

#include <QWidget>

namespace project
{

namespace gui
{

class WorkbenchWidget : public QWidget
{
	Q_OBJECT

    public:
        WorkbenchWidget();
        virtual ~WorkbenchWidget();
    protected:
    private:
        void SetupUI();
};
} //end gui namespace
} //end project namespace
#endif // WORKBENCHWIDGET_H
