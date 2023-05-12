/******************************************************************************
 * Copyright 2023 Qsaker(wuuhaii@outlook.com). All rights reserved.
 *
 * The file is encoded using "utf8 with bom", it is a part
 * of QtSwissArmyKnife project.
 *
 * QtSwissArmyKnife is licensed according to the terms in
 * the file LICENCE in the root of the source code directory.
 *****************************************************************************/
#include "SAKToolBoxUi.hh"
#include "SAKToolBoxUiParameters.hh"

#include "ui_SAKToolBoxUi.h"

SAKToolBoxUi::SAKToolBoxUi(QWidget *parent)
    : QWidget{parent}
    , ui(new Ui::SAKToolBoxUi)
{
    ui->setupUi(this);
    mToolBoxUiParameters = new SAKToolBoxUiParameters(this);
    mToolBoxUiParameters->setModal(true);
}

SAKToolBoxUi::~SAKToolBoxUi()
{
    delete ui;
}

void SAKToolBoxUi::init()
{
    ui->widgetController->setLayout(new QHBoxLayout());
    ui->widgetController->layout()->setContentsMargins(0, 0, 0, 0);
    QWidget *w = controller();
    if (w) {
        ui->widgetController->layout()->addWidget(w);
    }

    initUi();
    initSettings();
    initSignals();
}

void SAKToolBoxUi::initUi()
{
    initUiDevice();
    initUiInput();
    initUiOutput();
}

void SAKToolBoxUi::initUiDevice()
{

}

void SAKToolBoxUi::initUiInput()
{

}

void SAKToolBoxUi::initUiOutput()
{

}

void SAKToolBoxUi::initSettings()
{
    initSettingsDevice();
    initSettingsInput();
    initSettingsOutput();
}

void SAKToolBoxUi::initSettingsDevice()
{

}

void SAKToolBoxUi::initSettingsInput()
{

}

void SAKToolBoxUi::initSettingsOutput()
{

}

void SAKToolBoxUi::initSignals()
{
    initSignalsDevice();
    initSignalsInput();
    initSettingsOutput();
}

void SAKToolBoxUi::initSignalsDevice()
{

}

void SAKToolBoxUi::initSignalsInput()
{
    connect(ui->pushButtonInputSettings, &QPushButton::clicked,
            this, &SAKToolBoxUi::onPushButtonInputSetttingsClicked);
}

void SAKToolBoxUi::initSignalsOutput()
{

}

void SAKToolBoxUi::onPushButtonInputSetttingsClicked()
{
    mToolBoxUiParameters->showDialog(1);
}
