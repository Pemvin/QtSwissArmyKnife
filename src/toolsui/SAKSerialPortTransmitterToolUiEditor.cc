/******************************************************************************
 * Copyright 2023 Qsaker(wuuhaii@outlook.com). All rights reserved.
 *
 * The file is encoded using "utf8 with bom", it is a part
 * of QtSwissArmyKnife project.
 *
 * QtSwissArmyKnife is licensed according to the terms in
 * the file LICENCE in the root of the source code directory.
 *****************************************************************************/
#include "SAKSerialPortTransmitterToolUiEditor.hh"
#include "ui_SAKSerialPortTransmitterToolUiEditor.h"

SAKSerialPortTransmitterToolUiEditor::
    SAKSerialPortTransmitterToolUiEditor(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SAKSerialPortTransmitterToolUiEditor)
{
    ui->setupUi(this);
}

SAKSerialPortTransmitterToolUiEditor::~SAKSerialPortTransmitterToolUiEditor()
{
    delete ui;
}