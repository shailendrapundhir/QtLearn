#ifndef SYSINFOWIDGET_H
#define SYSINFOWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QtCharts/QChartView>

class SysInfoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SysInfoWidget(QWidget *parent = 0, int startDelayMs = 500, int updateSeriesDelayMs = 500);

protected:
    QtCharts::QChartView& chartView();
signals:

public slots:
};

#endif // SYSINFOWIDGET_H
