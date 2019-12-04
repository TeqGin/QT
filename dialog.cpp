#include "dialog.h"
#include "ui_dialog.h"
#include"sql.h"
#include"domain.h"
#include<QMessageBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
   connect(this->ui->submit,SIGNAL(clicked(bool)),this,SLOT(submit()));
   connect(this->ui->cancel,SIGNAL(clicked(bool)),this,SLOT(cancel()));
}

Dialog::~Dialog()
{
    delete ui;
}

void setErrorMessageBox(QString text){
    QMessageBox *message;
    message=new QMessageBox(
                "提示",
                text,
                QMessageBox::Critical,
                QMessageBox::Ok|QMessageBox::Default,
                0,
                0
                );
     message->exec();
     return ;
}
void setPassMessageBox(QString text){
    QMessageBox *message;
    message=new QMessageBox(
                "提示",
                text,
                QMessageBox::Information,
                QMessageBox::Ok|QMessageBox::Default,
                0,
                0
                );
     message->exec();
     return;
}

void Dialog::submit(){
    QString name=this->ui->name->text();
    QString id=this->ui->id->text();
    QString password1=this->ui->password1->text();
    QString password2=this->ui->password2->text();
    QString sex=this->ui->select->currentText();
    QString checkCode=this->ui->checkCode->text();

    qDebug()<<sex;

    if(id==""){
        setErrorMessageBox("id不允许为空");
         return ;
    }
    if(password1==""||password2==""){
        setErrorMessageBox("密码不允许为空");
         return ;
    }
    UserSql userSql;
    Person user=userSql.findUserById(id);
    if(user.getPersonId()==id){
        setErrorMessageBox("该用户已存在");
         return ;
    }else{
        if(password1!=password2){
            setErrorMessageBox("两次输入的密码不一致");
            return ;
        }else{
            if(checkCode==""){
                //注册普通用户
                Guests guests(
                            name,
                            id,
                            sex,
                            password1
                            );
                user=guests;
                userSql.insert(user);
                setPassMessageBox("用户注册成功");
                this->close();
                 return ;
            }
            if(checkCode=="1234"){
                Charger charger(
                            name,
                            id,
                            sex,
                            password1
                            );
                user=charger;
                userSql.insert(user);
                setPassMessageBox("管理员注册成功");
                this->close();
                 return ;
            }else{
                setErrorMessageBox("校验码错误！");
                return;
            }
        }
    }
   // setErrorMessageBox("注册失败");
    //this->close();
}

void Dialog::cancel(){
    this->close();
}
