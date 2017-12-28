#ifndef TASK_H
#define TASK_H

#include <QWidget>
#include <QString>

namespace Ui {
class Task;
}

class Task : public QWidget
{
    Q_OBJECT

public:
    explicit Task(const QString& name,QWidget *parent = 0);
    ~Task();

    void setName(const QString& name);
    QString name() const;
    bool isCompleted() const;

private:
    Ui::Task *ui;

public slots:
    void rename();
    void checked(bool checked);

signals:
    void removed(Task* task);
    void statusChanged(Task* task);

};
#endif // TASK_H
