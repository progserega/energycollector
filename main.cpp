#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "qml2ctranslator.h"
#include "listview.h"
#include "xmlasutpdata.h"
#include <QQmlContext>
#include <QSysInfo>
#include <QDebug>
#include <QStandardPaths>
#include <sys/utsname.h>
#include <QDir>

/* // Android native api:
#include <QAndroidJniEnvironment>
#include <QAndroidJniObject>
*/

//QString osVersion();

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    // Определяем систему, где мы запустились:
    //qDebug() << __FUNCTION__ << ":" << __LINE__ << "OS: " << osVersion();

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    // отладка путей:
    //QStandardPaths path;
    qDebug() << __FUNCTION__ << ":" << __LINE__ << "QStandardPaths::HomeLocation: " << QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    qDebug() << __FUNCTION__ << ":" << __LINE__ << "QStandardPaths::DesktopLocation: " << QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    qDebug() << __FUNCTION__ << ":" << __LINE__ << "QStandardPaths::TempLocation: " << QStandardPaths::writableLocation(QStandardPaths::TempLocation);
    qDebug() << __FUNCTION__ << ":" << __LINE__ << "QStandardPaths::CacheLocation: " << QStandardPaths::writableLocation(QStandardPaths::CacheLocation);
    qDebug() << __FUNCTION__ << ":" << __LINE__ << "QStandardPaths::DataLocation: " << QStandardPaths::writableLocation(QStandardPaths::DataLocation);
    qDebug() << __FUNCTION__ << ":" << __LINE__ << "QStandardPaths::ConfigLocation: " << QStandardPaths::writableLocation(QStandardPaths::ConfigLocation);
    qDebug() << __FUNCTION__ << ":" << __LINE__ << "QStandardPaths::DownloadLocation" << QStandardPaths::writableLocation(QStandardPaths::DownloadLocation);
    qDebug() << __FUNCTION__ << ":" << __LINE__ << "getenv(\"EXTERNAL_STORAGE\"): " << getenv("EXTERNAL_STORAGE");

    QString config_path,data_path;
    QDir dir;
#ifdef Q_OS_ANDROID
    data_path=(QString)getenv("EXTERNAL_STORAGE")+"/EnergyCollector";
    config_path=(QString)getenv("EXTERNAL_STORAGE")+"/EnergyCollector/config";
    if(!dir.exists(config_path))
    {
        if(!dir.mkpath(config_path))
        {
            qDebug() << __FUNCTION__ << ":" << __LINE__ << "Error create path: " << config_path;
        }
    }
    /*
    QAndroidJniObject mediaDir = QAndroidJniObject::callStaticObjectMethod("android/os/Environment", "getExternalStorageDirectory", "()Ljava/io/File;");
    QString dataAbsPath = mediaDir.toString();
    QAndroidJniEnvironment env;
    if (env->ExceptionCheck())
    {
        // Handle exception here.
        env->ExceptionClear();
        qDebug() << __FUNCTION__ << ":" << __LINE__ << "error get Android method getExternalStorageDirectory()";
    }
    else
    {
        qDebug() << __FUNCTION__ << ":" << __LINE__ << "getExternalStorageDirectory() android api: " << dataAbsPath;
    }
    */

#else
    data_path=QStandardPaths::writableLocation(QStandardPaths::DataLocation)+"/EnergyCollector";
    config_path=QStandardPaths::writableLocation(QStandardPaths::ConfigLocation)+"/EnergyCollector";
    if(!dir.exists(config_path))
    {
        if(!dir.mkpath(config_path))
        {
            qDebug() << __FUNCTION__ << ":" << __LINE__ << "Error create path: " << config_path;
        }
    }
    if(!dir.exists(data_path))
    {
        if(!dir.mkpath(data_path))
        {
            qDebug() << __FUNCTION__ << ":" << __LINE__ << "Error create path: " << data_path;
        }
    }
#endif


    // Загрузка XML с данными:
    xmlAsutpData asutpData(QString(data_path+"/asutp_potrebiteli.xml"));

    qml2Ctranslator qml2c;
    qml2c.setEngine(&engine);
    qml2c.setAsutpData(&asutpData);

    engine.rootContext()->setContextProperty("qml2c", &qml2c);


    return app.exec();
}
/*
QString osVersion()
{
    static QString osVersion;
    if(osVersion.isEmpty())
    {
#if defined(Q_OS_MAC)
        switch(QSysInfo::MacintoshVersion)
        {
            case QSysInfo::MV_LEOPARD:
                osVersion = QLatin1String("MacOS 10.5(Leopard)");
                break;
            case QSysInfo::MV_TIGER:
                osVersion = QLatin1String("MacOS 10.4(Tiger)");
                break;
            case QSysInfo::MV_PANTHER:
                osVersion = QLatin1String("MacOS 10.3(Panther)");
                break;
            case QSysInfo::MV_JAGUAR:
                osVersion = QLatin1String("MacOS 10.2(Jaguar)");
                break;
            case QSysInfo::MV_PUMA:
                osVersion = QLatin1String("MacOS 10.1(Puma)");
                break;
            case QSysInfo::MV_CHEETAH:
                osVersion = QLatin1String("MacOS 10.0(Cheetah)");
                break;
            case QSysInfo::MV_9:
                osVersion = QLatin1String("MacOS 9");
                break;

            case QSysInfo::MV_Unknown:
            default:
                osVersion = QLatin1String("MacOS(unknown)");
                break;
        }
#elif defined(Q_OS_UNIX)
        utsname buf;
        if(uname(&buf) != -1)
        {
            osVersion.append(buf.release).append(QLatin1Char(' '));
            osVersion.append(buf.sysname).append(QLatin1Char(' '));
            osVersion.append(buf.machine).append(QLatin1Char(' '));
            osVersion.append(QLatin1String(" (")).append(buf.machine).append(QLatin1Char(')'));
        }
        else
        {
            osVersion = QLatin1String("Linux/Unix(unknown)");
        }
#elif defined(Q_WS_WIN) || defined(Q_OS_CYGWIN)
        switch(QSysInfo::WindowsVersion)
        {
            case QSysInfo::WV_CE_6:
                osVersion = QLatin1String("Windows CE 6.x");
                break;
            case QSysInfo::WV_CE_5:
                osVersion = QLatin1String("Windows CE 5.x");
                break;
            case QSysInfo::WV_CENET:
                osVersion = QLatin1String("Windows CE .NET");
                break;
            case QSysInfo::WV_CE:
                osVersion = QLatin1String("Windows CE");
                break;

            case QSysInfo::WV_VISTA:
                osVersion = QLatin1String("Windows Vista");
                break;
            case QSysInfo::WV_2003:
                osVersion = QLatin1String("Windows Server 2003");
                break;
            case QSysInfo::WV_XP:
                osVersion = QLatin1String("Windows XP");
                break;
            case QSysInfo::WV_2000:
                osVersion = QLatin1String("Windows 2000");
                break;
            case QSysInfo::WV_NT:
                osVersion = QLatin1String("Windows NT");
                break;

            case QSysInfo::WV_Me:
                osVersion = QLatin1String("Windows Me");
                break;
            case QSysInfo::WV_98:
                osVersion = QLatin1String("Windows 98");
                break;
            case QSysInfo::WV_95:
                osVersion = QLatin1String("Windows 95");
                break;
            case QSysInfo::WV_32s:
                osVersion = QLatin1String("Windows 3.1 with Win32s");
                break;

            default:
                osVersion = QLatin1String("Windows(unknown)");
                break;
        }

        if(QSysInfo::WindowsVersion & QSysInfo::WV_CE_based)
            osVersion.append(QLatin1String(" (CE-based)"));
        else if(QSysInfo::WindowsVersion & QSysInfo::WV_NT_based)
            osVersion.append(QLatin1String(" (NT-based)"));
        else if(QSysInfo::WindowsVersion & QSysInfo::WV_DOS_based)
            osVersion.append(QLatin1String(" (MS-DOS-based)"));
#else
        return QLatin1String("Unknown");
#endif
    }

    return osVersion;
}
*/
