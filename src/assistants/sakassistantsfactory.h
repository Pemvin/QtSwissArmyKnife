﻿/******************************************************************************
 * Copyright 2022-2023 Qsaker(qsaker@outlook.com). All rights reserved.
 *
 * The file is encoded using "utf8 with bom", it is a part of QtSwissArmyKnife
 * project(https://github.com/qsaker/QtSwissArmyKnife).
 *
 * QtSwissArmyKnife is licensed according to the terms in the file LICENCE in
 * the root of the source code directory.
 *****************************************************************************/
#ifndef SAKASSISTANTSFACTORY_H
#define SAKASSISTANTSFACTORY_H

#include <QMap>
#include <QObject>

class SAKAssistantsFactory : QObject {
  Q_OBJECT
 private:
  SAKAssistantsFactory(QObject* parent = Q_NULLPTR);

 private:
  enum Assistants {
    kCrcAssistant,
    kFileCheckAssistant,
    kAsciiAssistant,
    kNumberAssistant,
    kStringAssistant,
    kBroadcastAssistant,
    kBase64Assistant
  };

 public:
  static SAKAssistantsFactory* instance();

  QList<int> SupportedAssistants();
  QString AssistantName(int type) const;
  QWidget* NewAssistant(int type);

 private:
  QMap<int, QString> type_name_map_;
};

#endif  // SAKASSISTANTSFACTORY_H
