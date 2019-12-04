#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"usersql.h"
#include"sql.h"
#include"whole.h"

#include<iostream>
#include<qdebug.h>
#include<QMessageBox>
#include<QCompleter>
#include<QTableView>
#include<QItemDelegate>
#include<QPainter>
#include<QStandardItemModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
        QStyleOption opt;
        opt.init(this);
        QPainter p(this);
        style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

    ui->setupUi(this);
    //这是一个简单的connect点击操作
    connect(this->ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(login()));
    connect(this->ui->registered,SIGNAL(clicked(bool)),this,SLOT(registered()));
//    this->ui->pushButton->setStyleSheet("QPushButton{"
//                                        "font-size:12px;"
//                                          " border-radius:2px;"
//                                           "color:rgba(51,51,51,1);"
//                                          " background:qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgba(242,242,242,1), stop:1 rgba(255,255,255,1));"
//                                          "border:1px solid rgba(221,221,221,1); "
//                                        "}");
//    this->ui->registered->setStyleSheet("QPushButton{"
//                                        "font-size:12px;"
//                                          " border-radius:2px;"
//                                           "color:rgba(51,51,51,1);"
//                                          " background:qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgba(242,242,242,1), stop:1 rgba(255,255,255,1));"
//                                          "border:1px solid rgba(221,221,221,1); "
//                                        "}");


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::login(){
    std::vector<Person> personVector;
    UserSql userSql;
    personVector=userSql.findAllUser();
    QString id=this->ui->login->text();
    QString pass=this->ui->password->text();
    bool flag=false;
    for(unsigned int i=0;i<personVector.size();i++){
        if(personVector[i].getPersonId()==id&&personVector[i].getPassword()==pass){
            flag=true;
        }
    }
    if(flag==true){
        this->close();
        Person person=userSql.findUserById(id);
        if(person.getRole()==1){
            //把用户登录的id保存在文件级变量中
           // globalId=person.getPersonId();
            Whole::id=person.getPersonId();

            loginFace.show();
            loginFace.creatTable();

            loginFace.exec();
        }else if(person.getRole()==2){
            //把用户登录的id保存在文件级变量中
            //类静态成员使用之前需要先初始化
            Whole::id=person.getPersonId();

            //globalId=person.getPersonId();
            chargeFace.show();
            chargeFace.exec();
        }
    }else{
        QMessageBox *msgBox;
        msgBox = new QMessageBox("提示",		///--这里是设置消息框标题
                "账号或密码错误",						///--这里是设置消息框显示的内容
                QMessageBox::Critical,							///--这里是在消息框显示的图标
                QMessageBox::Ok | QMessageBox::Default,		///---这里是显示消息框上的按钮情况
                0,
               // QMessageBox::Cancel | QMessageBox::Escape,	///---这里与 键盘上的 escape 键结合。当用户按下该键，消息框将执行cancel按钮事件
                0);														///---这里是 定义第三个按钮， 该例子 只是 了显示2个按钮
            msgBox->show();									///---显示消息框
            msgBox->exec();
    }
}
void MainWindow::registered(){
    this->hide();
    this->dialog.show();
    this->dialog.exec();
    this->show();
}
