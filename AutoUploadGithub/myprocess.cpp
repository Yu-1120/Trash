#include "myprocess.h"
#include "ui_myprocess.h"
#include <QDebug>
#include <synchapi.h>
#include <QDir>
#include <QMessageBox>
#include <QFileDialog>
#include <QTime>
#include <QThread>
#define filepath "../1.txt"
#define add_data "/AutoUploadGithub"

MyProcess::MyProcess(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyProcess)
{
    ui->setupUi(this);

   pro = new QProcess(this);


}

MyProcess::~MyProcess()
{
    delete ui;
}

void MyProcess::on_pushButton_log_clicked()
{
    //如果进程未运行,启动
    if(pro->state()==QProcess::NotRunning){
        QStringList arguments;
        arguments << "/c" << " git log ";

        QProcess process(this);
        process.start("cmd.exe", arguments);
        process.waitForStarted(); //阻塞，直到进程启动；
        process.waitForFinished();
        QString strResult = QString::fromLocal8Bit(process.readAllStandardOutput());
        qDebug()<<strResult;
        QMessageBox msgBox(this);
        msgBox.setText(strResult);
        msgBox.exec();
//        this->window()->close();

    }
}

void MyProcess::on_pushButton_config_clicked()
{
    //如果进程未运行,启动
    if(pro->state()==QProcess::NotRunning){
        QStringList arguments;
        arguments << "/c" << " git config --local --list ";

        QProcess process(this);
        process.start("cmd.exe", arguments);
        process.waitForStarted(); //阻塞，直到进程启动；
        process.waitForFinished();
        QString strResult = QString::fromLocal8Bit(process.readAllStandardOutput());
        qDebug()<<strResult;
        Sleep(1000);
        QMessageBox msgBox(this);
        msgBox.setText(strResult);
        msgBox.exec();
//        this->window()->close();

    }
}

void MyProcess::on_pushButton_noRemoveTwo_clicked()
{
    //如果进程未运行,启动
    if(pro->state()==QProcess::NotRunning){
        QStringList arguments;
        arguments << "/c" << " git add  . &&  git commit -m \"update\"  &&  git push  origin main";
        qDebug()<<arguments;
        QProcess process(this);
        process.startDetached("cmd.exe", arguments);
        process.waitForStarted(); //阻塞，直到进程启动；
        process.waitForFinished();
        QString strResult = QString::fromLocal8Bit(process.readAllStandardOutput());
        qDebug()<<strResult;
        QMessageBox msgBox(this);
        msgBox.setText(strResult);
        msgBox.exec();
//        this->window()->close();

    }
}

void MyProcess::on_pushButton_force_cover_clicked()
{

    //如果进程未运行,启动
    if(pro->state()==QProcess::NotRunning){

        QStringList arguments;
        arguments << "/c" << " git add .  && git commit -m \"update\" &&  ";
        QProcess process(this);
        process.startDetached("cmd.exe", arguments);
        process.waitForStarted(-1); //阻塞，直到进程启动；
        process.waitForFinished(-1); //-1的意思就是等待你的事件真的结束
        Sleep(5);
        QString strResult = QString::fromLocal8Bit(process.readAllStandardOutput());
        qDebug()<<strResult;
        QMessageBox msgBox(this);
        msgBox.setText(strResult);
        msgBox.exec();
        pro->kill();
//        this->window()->close();

    }
}

void MyProcess::on_stop_clicked()
{
      pro->kill();
      //等待结束
    qDebug()<<"on_stop_clicked";
      pro->waitForFinished();
}

//*****************待完善*************************




void MyProcess::on_Github_clicked()
{
    QTime timeNow = QTime::currentTime();
    QString Nowtime  = timeNow.toString();
    qDebug()<<timeNow.toString();
    if(pro->state()==QProcess::NotRunning){
        QStringList arguments;

        //如果进程未运行,启动

        arguments << "/c" << "git add .  && git commit -m \"update+"+Nowtime+" \" && git push -f --set-upstream origin main:main";

        QProcess process(this);
        process.start("cmd.exe", arguments);
        process.waitForStarted(); //阻塞，直到进程启动；
        process.waitForFinished();
        QString strResult = QString::fromLocal8Bit(process.readAllStandardOutput());
        qDebug()<<strResult;
        QMessageBox msgBox(this);
        msgBox.setText(strResult);
        msgBox.exec();
//        this->window()->close();
    }
}
