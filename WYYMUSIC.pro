QT += quick
QT += quickcontrols2
QT += network
QT += multimedia
QT += widgets
RC_ICONS = $$PWD/image/wyymusic.ico
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        CPPSrc/HttpGetRequester.cpp \
        CPPSrc/gethostsearch.cpp \
        CPPSrc/lyricparser.cpp \
        CPPSrc/mediakeyfilter.cpp \
        CPPSrc/playlistmanager.cpp \
        CPPSrc/recommendation.cpp \
        CPPSrc/searchcomplex.cpp \
        CPPSrc/trayhandler.cpp \
        main.cpp

RESOURCES += qml.qrc \
    image.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    CPPSrc/HttpGetRequester.h \
    CPPSrc/gethostsearch.h \
    CPPSrc/lyricparser.h \
    CPPSrc/mediakeyfilter.h \
    CPPSrc/playlistmanager.h \
    CPPSrc/recommendation.h \
    CPPSrc/searchcomplex.h \
    CPPSrc/trayhandler.h
