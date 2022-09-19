#ifndef MYPROCESS_H
#define MYPROCESS_H

#include <QWidget>
#include <QProcess>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui { class MyProcess; }
QT_END_NAMESPACE

class MyProcess : public QWidget
{
    Q_OBJECT

public:
    MyProcess(QWidget *parent = nullptr);
    ~MyProcess();

private slots:

    void on_pushButton_log_clicked();

    void on_pushButton_config_clicked();

    void on_pushButton_noRemoveTwo_clicked();

    void on_pushButton_force_cover_clicked();

    void on_stop_clicked();
    void on_file_exist_clicked();


    void on_Github_clicked();

private:
    Ui::MyProcess *ui;
    QProcess *pro;

};
#endif // MYPROCESS_H
