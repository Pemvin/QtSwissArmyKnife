﻿/*
 * Copyright 2020 Qter(qsaker@qq.com). All rights reserved.
 *
 * The file is encoded using "utf8 with bom", it is a part
 * of QtSwissArmyKnife project.
 *
 * QtSwissArmyKnife is licensed according to the terms in
 * the file LICENCE in the root of the source code directory.
 */
#ifndef SAKDEBUGPAGEINPUTCONTROLLER_HH
#define SAKDEBUGPAGEINPUTCONTROLLER_HH

#include <QLabel>
#include <QTimer>
#include <QObject>
#include <QTextEdit>
#include <QComboBox>
#include <QCheckBox>
#include <QPushButton>
#include <QListWidget>

class SAKDebugPage;
class SAKInputDataItem;
class SAKCRCInterface;
class SAKInputDataFactory;
class SAKInputDataItemManager;
class SAKInputCrcSettingsDialog;
class SAKDebugPageInputController:public QObject
{
    Q_OBJECT
public:
    SAKDebugPageInputController(SAKDebugPage *debugPage, QObject *parent = Q_NULLPTR);
    ~SAKDebugPageInputController();

    /**
     * @brief The InputParameters struct    --  输入上下文
     */
    struct InputParameters {
        bool    addCRC;         // 追加crc校验数据标志
        bool    bigEndian;      // 大端序添加crc值
        int     cycleTime;      // 循环发送时间（周期）
        int     inputModel;     // 数据输入模式
        int     crcModel;       // crc参数模型
        int     startByte;      // crc数据起始字段
        int     endByte;        // crc数据结束字段（从右边开始数）
    };

    /**
     * @brief showCrcSettingsDialog 显示crc参数设置弹窗
     */
    void showCrcSettingsDialog();

    friend class SAKInputDataItem;
private:
    SAKDebugPage *debugPage;

    QComboBox   *inputModelComboBox;
    QCheckBox   *cycleEnableCheckBox;
    QLineEdit   *cycleTimeLineEdit;
    QPushButton *saveInputDataPushButton;
    QPushButton *readinFilePushButton;
    QCheckBox   *addCRCCheckBox;
    QPushButton *clearInputPushButton;
    QPushButton *sendPushButton;
    QTextEdit   *inputTextEdit;
    QComboBox   *crcParameterModelsComboBox;
    QLabel      *crcLabel;
    QPushButton *presetPushButton;
    QPushButton *sendPresetPushButton;

private:
    /// 输入文本格式法神改变时执行该函数
    void changeInputModel(const QString &text);
    /// 循环使能发生改变时执行该函数
    void changeCycleEnableFlag();
    /// 改变循环发送时间
    void changeCycleTime();
    /// 保存发送输入框数据至文本
    void saveInputDataToFile();
    /// 读入文本文件
    void readinFile();
    /// crc添加标志发生该表是执行该函数
    void changeAddCRCFlag();
    /// 清空输入区域
    void clearInputArea();
    /// 输入框数据发生改变时，执行该函数
    void inputTextEditTextChanged();
    /// 发送数据
    void sendRawData();
    /// 发送数据
    void sendOtherRawData(QString data, int textFormat);
    /// crc参数模型发生改变时执行该函数
    void changeCRCModel();
    /// 设置预设数据
    void setPresetData();
    /// 发送预设数据
    void sendPresetData();

private:
    /// 初始化输入参数
    void initParameters();
    /// 启动/停止循环发送定时器
    void setCycleEnable();    
private:
    /// 循环发送定时器
    QTimer timingTimer;
    /// 循环发送定时器溢出后，执行该函数，执行该函数后，将会发送一个请求发送数据信号
    void cycleTimerTimeout();

private:
    SAKInputDataFactory *inputDataFactory;
    InputParameters inputParameters;
    SAKCRCInterface *crcInterface;
    SAKInputDataItemManager *inputDataItemManager;
    SAKInputCrcSettingsDialog *crcSettingsDialog;

    void updateCRC();
    void formattingInputText(QTextEdit *textEdit, int model);
signals:
    /// 该函数并不会真的发送数据，而是发送一个信号，该信号携带需要发送的数据,数据需要经过处理后才能发送
    void rawDataChanged(QString rawData, InputParameters parameters);
};
Q_DECLARE_METATYPE(SAKDebugPageInputController::InputParameters);

#endif
