#include "FirstDockWidget.h"

#include <QVBoxLayout>

using namespace project::gui;

FirstDockWidget::FirstDockWidget()
{
    //ctor
    setWindowTitle(tr("Dock Title"));
    m_pMainWidget = new QWidget();
    SetupUI();
    setWidget(m_pMainWidget);
}

FirstDockWidget::~FirstDockWidget()
{
    //dtor
}

void FirstDockWidget::SetupUI()
{
	QVBoxLayout * vboxLayout = new QVBoxLayout(m_pMainWidget);
	vboxLayout->setContentsMargins(0, 0, 0, 0);
}

void FirstDockWidget::CloseEvent(QCloseEvent * event)
{
    emit Closed(false);
}
