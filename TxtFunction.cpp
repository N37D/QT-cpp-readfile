#include "txtfunction.h"
#include "ui_txtfunction.h"
#include<QFile>
#include<QFileDialog>
#include<QFileInfo>   //获取文件信息
#include<QDebug>
#include<QDateTime>
#include<QString>
#include<QDataStream>  //数据流

TxtFunction::TxtFunction(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TxtFunction)
{
    ui->setupUi(this);
}

TxtFunction::~TxtFunction()
{
    delete ui;
}



void TxtFunction::on_buttonRead_clicked()
{

    QString path = QFileDialog::getOpenFileName(this,"opne","../","TXT(*txt)"); //弹出对话框 选取文件路径

    if(path.isEmpty() == false){
       QFile file(path);  //文件对象
      bool isok = file.open(QIODevice::ReadOnly); //打开文件 只读方式
      if(isok == true){

#if 0
          QByteArray arry =  file.readAll();  //读文件 默认值识别utf8的编码
          ui->textdis->setText(QString(arry));  //显示到编辑区
#endif
          QByteArray arry;
          while (file.atEnd() == false) {  //一行一行的读取 判断是否到达结尾
              arry += file.readLine();
          }
          ui->textdis->setText(arry);  //显示到编辑区
      }
      file.close();

      //获取文件信息
      QFileInfo info(path);
      qDebug()<<"文件名字 ："<<info.fileName();
      qDebug()<<"文件后缀 ："<<info.suffix();
      qDebug()<<"文件大小 ："<<info.size();
      qDebug()<<"文件创建时间 ："<<info.created().toString("yyyy-MM-dd hh:mm:ss");  //2016-01-04 15:13:00
    }
}

void TxtFunction::on_buttonWrite_clicked()
{

    QString path = QFileDialog::getSaveFileName(this,"save","../","TXT(*txt)");
    if(path.isEmpty() == false){
        QFile file;  //创建文件对象
        file.setFileName(path);  //关联文件名
        bool isok = file.open(QIODevice::WriteOnly);  //打开文件 只写方式
        if(isok == true){

            QString str = ui->textdis->toPlainText();  //获取编辑区内容
            //QString->QByteArry
            file.write(str.toUtf8());

        }
        file.close();
    }
}
