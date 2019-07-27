#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    pbSetting();
}

Widget::~Widget()
{
    delete ui;
}


void Widget::changeMoney(int n)
{
    money += n;
    ui->lcdNumber->display(QString::number(money));
    pbSetting();
}

void Widget::pbSetting()
{
    if(money >= 100)
        ui->pbCoffee->setEnabled(true);
    else
        ui->pbCoffee->setEnabled(false);

    if(money >= 150)
        ui->pbTea->setEnabled(true);
    else
        ui->pbTea->setEnabled(false);

    if(money >= 200)
        ui->pbChoco->setEnabled(true);
    else
        ui->pbChoco->setEnabled(false);
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbChoco_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbChange_clicked()
{
    QString str = "";
    int coin[4];

    coin[0] = money / 500;
    money -= 500 * coin[0];
    coin[1] = money / 100;
    money -= 100 * coin[1];
    coin[2] = money / 50;
    money -= 50 * coin[2];
    coin[3] = money / 10;
    money -= 10 * coin[3];
    changeMoney(0);

    str+= "500원 : "; str+= QString::number(coin[0]); str+= " 개\n";
    str+= "100원 : "; str+= QString::number(coin[1]); str+= " 개\n";
    str+= "50원  : "; str+= QString::number(coin[2]); str+= " 개\n";
    str+= "10원  : "; str+= QString::number(coin[3]); str+= " 개";

    QMessageBox msg;
    msg.information(nullptr,"Change",str);

}
