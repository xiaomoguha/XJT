#ifndef MEDIAKEYFILTER_H
#define MEDIAKEYFILTER_H
#pragma once
#include <QObject>
#include <QAbstractNativeEventFilter>
#include <QTimer>
#include "playlistmanager.h"
#endif
class MediaKeyFilter : public QObject, public QAbstractNativeEventFilter
{
    Q_OBJECT
public:
    explicit MediaKeyFilter(PlaylistManager* manager);

    bool nativeEventFilter(const QByteArray &eventType, void *message, qintptr *result) override;

private slots:
    void handleClick();

private:
    PlaylistManager* m_manager;
    int clickCount;
    QTimer* timer;
};


