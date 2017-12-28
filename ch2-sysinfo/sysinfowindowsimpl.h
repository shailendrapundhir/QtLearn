#ifndef SYSINFOWINDOWSIMPL_H
#define SYSINFOWINDOWSIMPL_H

#include <QtGlobal>
#include <QVector>

#include "sysinfo.h"

typedef struct _FILETIME FILETIME;

class SysInfoWindowsImpl : public SysInfo
{
private:
    QVector<qulonglong> mCpuLoadLastValues;

public:
    SysInfoWindowsImpl();
    void init() override;
    double cpuLoadAverage() override;
    double memoryUsed() override;

private:
    QVector<qulonglong> cpuRawData();
    qulonglong convertFileTime(const FILETIME& filetime) const;
};

#endif // SYSINFOWINDOWSIMPL_H
