#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mTasks()
{
    ui->setupUi(this);
    //A simple signal slot example. function is : connect(sender, &sender::signal_name, reciever , &reciever::slot_name);
    connect(ui->addTaskButton, &QPushButton::clicked, this , &MainWindow::addTask);
    updateStatus();
}

void MainWindow::addTask(){
    bool ok;
    //QInput dialog params : QInputDialog::getText(where(this), tr("title"),tr("label"),etc... see documentation for more.
    QString name = QInputDialog::getText(this, tr("Add Task"), tr("Task name"), QLineEdit::Normal, tr("Untitled Task"), &ok);

    if(ok && !name.isEmpty()){
        qDebug()<<"Adding new Task";
        Task* task = new Task(name);
        connect(task,&Task::removed,this,&MainWindow::removeTask);
        connect(task,&Task::statusChanged,this,&MainWindow::taskStatusChanged);
        mTasks.append(task);
        ui->tasksLayout->addWidget(task);
        updateStatus();
    }
}

void MainWindow::removeTask(Task *task)
{
    mTasks.removeOne(task);
    ui->tasksLayout->removeWidget(task);
    task->setParent(0);
    delete task;
    updateStatus();
}

void MainWindow::taskStatusChanged(Task *task)
{
    updateStatus();
}

void MainWindow::updateStatus()
{
    int completedCount = 0;
    for (auto t:mTasks){
        if(t->isCompleted()){
            completedCount++;
        }
    }

    int todoCount = mTasks.size() - completedCount;
    ui->statusLabel->setText(QString("Status: %1 todo / %2 completed").arg(todoCount).arg(completedCount));;
}

MainWindow::~MainWindow()
{
    delete ui;
}
