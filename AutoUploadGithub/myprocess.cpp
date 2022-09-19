#include "myprocess.h"
#include "ui_myprocess.h"
#include <QDebug>
#include <synchapi.h>
#include <QDir>
#include <QMessageBox>
#include <QFileDialog>
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
        this->window()->close();

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
        this->window()->close();

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
        this->window()->close();

    }
}

void MyProcess::on_pushButton_force_cover_clicked()
{
    //如果进程未运行,启动
    if(pro->state()==QProcess::NotRunning){
        QStringList arguments;
        arguments << "/c" << " git add .  && git commit -m \"update\" && git push -f --set-upstream origin main:main";

        QProcess process(this);
        process.startDetached("cmd.exe", arguments);
        process.waitForStarted(); //阻塞，直到进程启动；
        process.waitForFinished();
        QString strResult = QString::fromLocal8Bit(process.readAllStandardOutput());
        qDebug()<<strResult;
        QMessageBox msgBox(this);
        msgBox.setText(strResult);
        msgBox.exec();
        this->window()->close();

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

void MyProcess::on_file_exist_clicked()
{

    //判断指定文件是否存在.也可以用来判断在指定路径下是否有文件和你将要创建的文件重名.
    //存在返回true，不存在返回false
    bool exist = QFile::exists(filepath);

  if(exist) {

      //先打开文件
      QFile file(filepath);
      if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){  return;}
      QString linelist = "";
//使用QTextStream一行一行读取文件
      QTextStream in(&file);
/*
 *******************************************************
      while (!in.atEnd()) {
          QString line = in.readLine();
          qInfo() << "line = " << line;
      }
 ******************************************************
 */
      while (!in.atEnd()) {
          QString line = in.readLine();      //整行读取
          if (line == add_data) { //读取每一行比较
              qDebug() << "是这个数据";

              continue;
          } else  {
              qDebug() << "不是这个数据";
              linelist+=line;
              continue;

          }
      }
      qDebug() << linelist;
/*

      if(file_exist){

          QTextStream stream( & file);
          qDebug() << "里面没有这个数据";
          QFile *file = new QFile(filepath);
          // 打开文件，读写与追加
          bool ok = file->open(QIODevice::ReadWrite | QIODevice::Append);
          // 如果文件没有被占用可以打开
          if(ok){
              // 输出debug信息
              qDebug() << "write";
              // 创建stream
              QTextStream txtOutput(file);
              // 在stream追加数据，并换行
              txtOutput << add_data << endl;
          }
          // 关闭文件, 保存数据
          file->close();
      }
*/

  }else{
      //打开文件，不存在则创建
      QString str= add_data;
      QFile file(filepath);
      file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
      file.write((str+ "\n").toUtf8());
      file.close();
  }
}





void MyProcess::on_Github_clicked()
{
    //如果进程未运行,启动
    if(pro->state()==QProcess::NotRunning){
        QStringList arguments;
        arguments << "/c" << "git add .  && git commit -m \"update\" && git push -f --set-upstream origin main:main";

        QProcess process(this);
        process.start("cmd.exe", arguments);
        process.waitForStarted(); //阻塞，直到进程启动；
        process.waitForFinished();
        QString strResult = QString::fromLocal8Bit(process.readAllStandardOutput());
        qDebug()<<strResult;
        QMessageBox msgBox(this);
        msgBox.setText(strResult);
        msgBox.exec();
        this->window()->close();
    }
}
