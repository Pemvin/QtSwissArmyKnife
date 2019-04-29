#-------------------------------------------------
#
# Project created by QtCreator 2018-07-06T22:57:33
#
#-------------------------------------------------

QT += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network

# 软件版本号
#DEFINES += SAK_VERSION=\"\\\"1.0.0\\\"\"

TARGET = QtSwissArmyKnife

TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, unTabPage the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/SAKGlobal.cpp \
    src/console/SAKConsole.cpp \
    src/console/SAKLogOutput.cpp \
    src/main.cpp \
    src/SAKApplication.cpp \
    src/mainwindow/SAKMainWindow.cpp \
    src/tabpage/SAKIODeviceWidget.cpp \
    src/tabpage/SAKIODevice.cpp \
    src/tabpage/SAKIODeviceControler.cpp \
    src/tabpage/read_write_setting/SAKReadWriteSetting.cc \
    src/tabpage/autoresponse/SAKAutoResponseItem.cpp \
    src/tabpage/autoresponse/SAKAutoResponseSettingPanel.cpp \
    src/tabpage/highlighter/SAKHighlighter.cpp \
    src/tabpage/highlighter/SAKHighlighterSettingPanel.cpp \
    src/mainwindow/SAKVersion.cpp \
    src/mainwindow/MoreInformation.cpp

HEADERS += \
    src/SAKApplication.hh \
    src/SAKGlobal.hh \
    src/TabPageSerialPort/SerialportSAKIODevice.hh \
    src/TabPageSerialPort/SerialportSAKIODeviceControler.hh \
    src/TabPageSerialPort/SerialportSAKIODeviceWidget.hh \
    src/TabPageTcpClient/TcpSAKIODevice.hh \
    src/TabPageTcpClient/TcpSAKIODeviceControler.hh \
    src/TabPageTcpClient/TcpSAKIODeviceWidget.hh \
    src/TabPageTcpServer/TcpServerSAKIODevice.hh \
    src/TabPageTcpServer/TcpServerSAKIODeviceControler.hh \
    src/TabPageTcpServer/TcpServerSAKIODeviceWidget.hh \
    src/TabPageUdpClient/UdpSAKIODevice.hh \
    src/TabPageUdpClient/UdpSAKIODeviceControler.hh \
    src/TabPageUdpClient/UdpSAKIODeviceWidget.hh \
    src/console/SAKConsole.hh \
    src/console/SAKLogOutput.hh \
    src/mainwindow/MoreInformation.hh \
    src/mainwindow/SAKMainWindow.hh \
    src/mainwindow/SAKVersion.hh \
    src/tabpage/SAKIODevice.hh \
    src/tabpage/SAKIODeviceControler.hh \
    src/tabpage/SAKIODeviceWidget.hh \
    src/tabpage/autoresponse/SAKAutoResponseItem.hh \
    src/tabpage/autoresponse/SAKAutoResponseSettingPanel.hh \
    src/tabpage/highlighter/SAKHighlighter.hh \
    src/tabpage/highlighter/SAKHighlighterSettingPanel.hh \
    src/tabpage/read_write_setting/SAKReadWriteSetting.hh

FORMS += \
    src/console/SAKConsole.ui \
    src/mainwindow/SAKMainWindow.ui \
    src/tabpage/SAKIODeviceWidget.ui \
    src/tabpage/autoresponse/SAKAutoResponseItem.ui \
    src/tabpage/autoresponse/SAKAutoResponseSettingPanel.ui \
    src/tabpage/highlighter/SAKHighlighterSettingPanel.ui \
    src/tabpage/read_write_setting/SAKReadWriteSetting.ui \
    src/mainwindow/SAKVersion.ui \
    src/mainwindow/MoreInformation.ui

INCLUDEPATH += \
    src \
    src/mainwindow \
    src/mainwindow/common \
    src/UdpClient \
    src/TcpClient \
    src/TcpServer \
    src/console \
    src/tabpage \
    src/tabpage/highlighter \
    src/tabpage/autoresponse \
    src/tabpage/read_write_setting

RESOURCES += \
    SAKResources.qrc \
    stylesheet/qss.qrc

win32{
    RC_ICONS = window.ico
}

# 静态编译版本不需要部署发布（静态编译时，禁用下面的）
DEFINES += NOT_USING_STATIC_EDITION

# 编译后不发布部署(发布时采用静态版本进行Qt进行编译)
#win32{
#    contains(DEFINES, NOT_USING_STATIC_EDITION){
#        CONFIG(debug, debug|release) {
#            win32-msvc {
#                QMAKE_POST_LINK += $$escape_expand(\\n) $$[QT_INSTALL_BINS]/windeployqt.exe --no-compiler-runtime --no-translations $$OUT_PWD/debug/$${TARGET}.exe $$escape_expand(\\n)
#            }
#        } else {
#            win32-msvc {
#                QMAKE_POST_LINK += $$escape_expand(\\n) $$[QT_INSTALL_BINS]/windeployqt.exe --no-compiler-runtime --no-translations $$OUT_PWD/release/$${TARGET}.exe $$escape_expand(\\n)
#            }
#        }
#    }
#}

#--------------------------------------------------------------------------------------------
#编译目录配置
MOC_DIR     = $$OUT_PWD/moc
OBJECTS_DIR = $$OUT_PWD/obj
RCC_DIR     = $$OUT_PWD/resource
UI_DIR      = $$OUT_PWD/ui

#--------------------------------------------------------------------------------------------
# 子项目
include(SAKTools.pri)

# 取消该宏的定义可以将串口模块屏蔽
winrt || arm-linux{
    DEFINES += SAK_NO_SERIALPORT_ASSISTANT
}

!contains(DEFINES, SAK_NO_SERIALPORT_ASSISTANT){
    QT  += serialport
    SOURCES += \
        src/TabPageSerialPort/SerialportSAKIODeviceWidget.cpp \
        src/TabPageSerialPort/SerialportSAKIODevice.cpp \
        src/TabPageSerialPort/SerialportSAKIODeviceControler.cpp
    HEADERS +=
    FORMS   += \
        src/TabPageSerialPort/SerialportSAKIODeviceControler.ui
    INCLUDEPATH += \
        src/TabPageSerialPort
}else {
    message( "该版本Qt可能不包含串口模块，已经忽略串口模块！（串口助手功能被屏蔽！）" )
}

# TCP 客户端
SOURCES += \
    src/TabPageTcpClient/TcpSAKIODevice.cpp \
    src/TabPageTcpClient/TcpSAKIODeviceControler.cpp \
    src/TabPageTcpClient/TcpSAKIODeviceWidget.cpp
HEADERS +=
FORMS   += \
    src/TabPageTcpClient/TcpSAKIODeviceControler.ui
INCLUDEPATH += \
    src/TabPageTcpClient

# TCP服务器
SOURCES += \
    src/TabPageTcpServer/TcpServerSAKIODeviceWidget.cpp \
    src/TabPageTcpServer/TcpServerSAKIODevice.cpp \
    src/TabPageTcpServer/TcpServerSAKIODeviceControler.cpp
HEADERS +=
FORMS   += \
    src/TabPageTcpServer/TcpServerSAKIODeviceControler.ui
INCLUDEPATH += \
    src/TabPageTcpServer

# UDP客户端
SOURCES += \
    src/TabPageUdpClient/UdpSAKIODevice.cpp \
    src/TabPageUdpClient/UdpSAKIODeviceControler.cpp \
    src/TabPageUdpClient/UdpSAKIODeviceWidget.cpp
HEADERS +=
FORMS   += \
    src/TabPageUdpClient/UdpSAKIODeviceControler.ui
INCLUDEPATH += \
    src/TabPageUdpClient

DISTFILES += \
    other/update.json
