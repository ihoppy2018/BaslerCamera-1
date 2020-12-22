#-------------------------------------------------
#
# Project created by QtCreator 2019-08-02T09:05:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = baslerSDK
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    camera/cameraform.cpp \
    camera/cameramanager.cpp \
    camera/camerascene.cpp \
    camera/camerawindow.cpp \
    camera/devicesdock.cpp \
    camera/mycamera.cpp \
    camera/mylistwidget.cpp \
    camera/mypixmapitem.cpp \
    camera/paramdock.cpp \
    myalgorithm.cpp

HEADERS += \
    camera/cameraform.h \
    camera/cameramanager.h \
    camera/camerascene.h \
    camera/camerawindow.h \
    camera/devicesdock.h \
    camera/mycamera.h \
    camera/mylistwidget.h \
    camera/mypixmapitem.h \
    camera/paramdock.h \
    myalgorithm.h

FORMS += \
    camera/cameraform.ui \
    camera/camerawindow.ui \
    camera/devicesdock.ui \
    camera/paramdock.ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
# opencv
win32:CONFIG(release, debug|release): LIBS += -LD:/opencv/build/x64/vc14/lib/ -lopencv_world331
else:win32:CONFIG(debug, debug|release): LIBS += -LD:/opencv/build/x64/vc14/lib/ -lopencv_world331d
else:unix: LIBS += -LD:/opencv/build/x64/vc14/lib/ -lopencv_world331

INCLUDEPATH += D:/opencv/build/include
DEPENDPATH += D:/opencv/build/include

# basler
unix|win32: LIBS += -L'D:/Program Files (x86)/Tools/BaslerDevelopment/lib/x64/' -lPylonBase_v6_0
unix|win32: LIBS += -L'D:/Program Files (x86)/Tools/BaslerDevelopment/lib/x64/' -lGCBase_MD_VC141_v3_1_Basler_pylon
unix|win32: LIBS += -L'D:/Program Files (x86)/Tools/BaslerDevelopment/lib/x64/' -lGenApi_MD_VC141_v3_1_Basler_pylon
unix|win32: LIBS += -L'D:/Program Files (x86)/Tools/BaslerDevelopment/lib/x64/' -lPylonC
unix|win32: LIBS += -L'D:/Program Files (x86)/Tools/BaslerDevelopment/lib/x64/' -lPylonGUI_v6_0
unix|win32: LIBS += -L'D:/Program Files (x86)/Tools/BaslerDevelopment/lib/x64/' -lPylonUtility_v6_0

INCLUDEPATH += 'D:/Program Files (x86)/Tools/BaslerDevelopment/include'
DEPENDPATH += 'D:/Program Files (x86)/Tools/BaslerDevelopment/include'

RESOURCES += \
    image.qrc

# zbar
unix|win32: LIBS += -L'D:/Program Files (x86)/Tools/ZBar_64/lib/' -llibzbar64-0

INCLUDEPATH += 'D:/Program Files (x86)/Tools/ZBar_64/include'
DEPENDPATH += 'D:/Program Files (x86)/Tools/ZBar_64/include'
