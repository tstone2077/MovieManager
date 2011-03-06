#include "WorkbenchWidget.h"
#include <QVBoxLayout>

#include <iostream>

using namespace project::gui;

WorkbenchWidget::WorkbenchWidget()
{
    //ctor
    SetupUI();
}

void WorkbenchWidget::SetupUI()
{
    QVBoxLayout * mainLayout = new QVBoxLayout;
    setLayout(mainLayout);
}

WorkbenchWidget::~WorkbenchWidget()
{
    //dtor
}
