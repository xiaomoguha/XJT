#include "mediakeyfilter.h"
#include <QApplication>
#include <QDebug>
#ifdef Q_OS_WIN
#include <windows.h>
#endif

MediaKeyFilter::MediaKeyFilter(PlaylistManager* manager)
    : m_manager(manager), clickCount(0)
{
    qApp->installNativeEventFilter(this);

    timer = new QTimer(this);
    timer->setSingleShot(true);
    timer->setInterval(400); // 400ms 内连续点击算多次
    connect(timer, &QTimer::timeout, this, &MediaKeyFilter::handleClick);
}

bool MediaKeyFilter::nativeEventFilter(const QByteArray &eventType, void *message, qintptr *)
{
#ifdef Q_OS_WIN
    if (eventType == "windows_generic_MSG")
    {
        MSG* msg = static_cast<MSG*>(message);
        if (msg->message == WM_APPCOMMAND)
        {
            switch(GET_APPCOMMAND_LPARAM(msg->lParam))
            {
            case APPCOMMAND_MEDIA_PLAY_PAUSE:
                clickCount++;
                timer->start(); // 每次点击重置计时器
                break;
            case APPCOMMAND_MEDIA_NEXTTRACK:
                m_manager->playNext();
                break;
            case APPCOMMAND_MEDIA_PREVIOUSTRACK:
                m_manager->playPrevious();
                break;
            }
        }
    }
#endif
    return false;
}

void MediaKeyFilter::handleClick()
{
    if (clickCount == 1)
        m_manager->playstop();
    else if (clickCount == 2)
        m_manager->playNext();
    else if (clickCount >= 3)
        m_manager->playPrevious();

    clickCount = 0;
}
