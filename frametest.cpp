#include "frametest.h"
#include "ui_frametest.h"
#include<QStyleOption>
#include<QPainter>

Frametest::Frametest(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Frametest)
{
    ui->setupUi(this);
}

Frametest::~Frametest()
{
    delete ui;
}
