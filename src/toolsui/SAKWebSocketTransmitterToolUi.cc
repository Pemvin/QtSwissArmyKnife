/******************************************************************************
 * Copyright 2023 Qsaker(wuuhaii@outlook.com). All rights reserved.
 *
 * The file is encoded using "utf8 with bom", it is a part
 * of QtSwissArmyKnife project.
 *
 * QtSwissArmyKnife is licensed according to the terms in
 * the file LICENCE in the root of the source code directory.
 *****************************************************************************/
#include "SAKWebSocketTransmitterToolUi.hh"

SAKWebSocketTransmitterToolUi::SAKWebSocketTransmitterToolUi(QWidget *parent)
    : SAKTransmitterToolUi{"SAK.WebSocketTransmitterToolUi", parent}
{
    mEditor= new SAKWebSocketTransmitterToolUiEditor(this);
}

QDialog *SAKWebSocketTransmitterToolUi::itemEditor()
{
    return mEditor;
}