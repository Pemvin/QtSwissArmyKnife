/***************************************************************************************************
 * Copyright 2023-2024 Qsaker(qsaker@foxmail.com). All rights reserved.
 *
 * The file is encoded using "utf8 with bom", it is a part of QtSwissArmyKnife project.
 *
 * QtSwissArmyKnife is licensed according to the terms in the file LICENCE in the root of the source
 * code directory.
 **************************************************************************************************/
#ifndef SAKTOOLBOX_H
#define SAKTOOLBOX_H

#include <QObject>
#include <QVariant>

#include "sakbasetool.h"
#include "sakcommunicationtool.h"
#include "sakemittertool.h"
#include "sakprestorertool.h"
#include "sakresponsertool.h"
#include "sakserialporttransmittertool.h"
#include "sakstatisticiantool.h"
#include "sakstorertool.h"
#include "saktcptransmittertool.h"
#include "sakudptransmittertool.h"
#include "sakvelometertool.h"
#include "sakwebsockettransmittertool.h"

class SAKToolBox : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariant communicaton READ communicaton NOTIFY communicatonChanged)
    Q_PROPERTY(QVariant emitter READ emitter CONSTANT)
    Q_PROPERTY(QVariant responser READ responser CONSTANT)
    Q_PROPERTY(QVariant storer READ storer CONSTANT)
    Q_PROPERTY(QVariant prestorer READ prestorer CONSTANT)
    Q_PROPERTY(QVariant rxVelometer READ rxVelometer CONSTANT)
    Q_PROPERTY(QVariant txVelometer READ txVelometer CONSTANT)
    Q_PROPERTY(QVariant rxStatistician READ rxStatistician CONSTANT)
    Q_PROPERTY(QVariant txStatistician READ txStatistician CONSTANT)

    Q_PROPERTY(QVariant udpTransmitter READ udpTransmitter CONSTANT)
    Q_PROPERTY(QVariant tcpTransmitter READ tcpTransmitter CONSTANT)
    Q_PROPERTY(QVariant webSocketTransmitter READ webSocketTransmitter CONSTANT)
    Q_PROPERTY(QVariant serialPortTransmitter READ serialPortTransmitter CONSTANT)

    Q_PROPERTY(bool isWorking READ isWorking NOTIFY isWorkingChanged)
public:
    explicit SAKToolBox(QObject* parent = nullptr);
    ~SAKToolBox();

    /// You must call the interface before useing.
    Q_INVOKABLE void initialize(int type);

    Q_INVOKABLE void open();
    Q_INVOKABLE void close();
    Q_INVOKABLE void send(const QByteArray& bytes);
    bool isWorking();

    SAKCommunicationTool* getCommunicationTool();
    SAKEmitterTool* getEmitterTool();
    SAKResponserTool* getResponserTool();
    SAKStorerTool* getStorerTool();
    SAKPrestorerTool* getPrestorerTool();
    SAKVelometerTool* getRxVelometerTool();
    SAKVelometerTool* getTxVelometerTool();
    SAKStatisticianTool* getRxStatisticianTool();
    SAKStatisticianTool* getTxStatisticianTool();
    SAKUdpTransmitterTool* getUdpTransmitterTool();
    SAKTcpTransmitterTool* getTcpTransmitterTool();
    SAKWebSocketTransmitterTool* getWebSocketTransmitterTool();
    SAKSerialPortTransmitterTool* getSerialPortTransmitterTool();

signals:
    void errorOccurred(const QString& errorString);

private:
    QList<SAKBaseTool*> m_tools;

private:
    void uninitializedTips();

private:
    SAKCommunicationTool* m_comunicationTool{nullptr};
    SAKEmitterTool* m_emitterTool{nullptr};
    SAKResponserTool* m_responserTool{nullptr};
    SAKStorerTool* m_storerTool{nullptr};
    SAKPrestorerTool* m_prestorerTool{nullptr};
    SAKVelometerTool* m_rxVelometerTool{nullptr};
    SAKVelometerTool* m_txVelometerTool{nullptr};
    SAKStatisticianTool* m_rxStatisticianTool{nullptr};
    SAKStatisticianTool* m_txStatisticianTool{nullptr};
    SAKUdpTransmitterTool* m_udpTransmitterTool{nullptr};
    SAKTcpTransmitterTool* m_tcpTransmitterTool{nullptr};
    SAKWebSocketTransmitterTool* m_webSocketTransmitterTool{nullptr};
    SAKSerialPortTransmitterTool* m_serialPortTransmitterTool{nullptr};
    bool m_isWorking{false};

private:
    QVariant communicaton();
    QVariant txMasker();
    QVariant rxMasker();
    QVariant txAnalyzer();
    QVariant rxAnalyzer();
    QVariant emitter();
    QVariant responser();
    QVariant storer();
    QVariant prestorer();
    QVariant rxVelometer();
    QVariant txVelometer();
    QVariant rxStatistician();
    QVariant txStatistician();
    QVariant udpTransmitter();
    QVariant tcpTransmitter();
    QVariant webSocketTransmitter();
    QVariant serialPortTransmitter();

signals:
    void isWorkingChanged();
    void communicatonChanged();
};

#endif // SAKTOOLBOX_H
