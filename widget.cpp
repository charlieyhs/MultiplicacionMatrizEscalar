#include "widget.h"
#include "ui_widget.h"
#include "introducirordenmatrizdialog.h"
#include "doublespinboxdelegate.h"

#include <QStandardItemModel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mModel = new QStandardItemModel(this);
    //mModel = new QStandardItemModel(this);
    ui->tableView->setModel(mModel);
    ui->tableView->setItemDelegate(new DoubleSpinBoxDelegate(this));
    ui->tableView->setContextMenuPolicy(Qt::ActionsContextMenu);
    ui->tableView->addAction(ui->actionIntroducirMatriz);
    ui->escalarDoubleSpinBox->setMinimum(-9999999999.9);
    ui->escalarDoubleSpinBox->setMaximum(+9999999999.9);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_multiplicarPushButton_clicked()
{
    const int rowCount = mModel->rowCount();
    const int colCount = mModel->columnCount();

    for(int ix=0;ix<rowCount;ix++){
        for(int jx=0;jx<colCount;jx++){
            const double mij = getValueAt(ix,jx);
            const double escalar = ui->escalarDoubleSpinBox->value();
            const double r = mij * escalar;
            setValueAt(ix,jx,r);
        }
    }

}

void Widget::on_SalirPushButton_clicked()
{
    close();
}

void Widget::on_actionIntroducirMatriz_triggered()
{
    IntroducirOrdenMatrizDialog d(this);
    if(d.exec() == QDialog::Rejected){
        return;
    }
    mModel->setRowCount(d.getNumeroDeFilas());
    mModel->setColumnCount(d.getNumeroDeColumnas());

}

void Widget::setValueAt(int ix, int jx, double value)
{
     if(mModel->item(ix,jx)){
         mModel->item(ix,jx)->setText(QString::number(value));
     }else{
         mModel->setItem(ix,jx, new QStandardItem(QString::number(value)));
     }
}

double Widget::getValueAt(int ix, int jx) const
{
    if(!mModel->item(ix,jx)){
        return 0.0;
    }
    return mModel->item(ix,jx)->text().toDouble();
}
