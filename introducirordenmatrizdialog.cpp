#include "introducirordenmatrizdialog.h"
#include "ui_introducirordenmatrizdialog.h"

IntroducirOrdenMatrizDialog::IntroducirOrdenMatrizDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IntroducirOrdenMatrizDialog)
{
    ui->setupUi(this);
}

IntroducirOrdenMatrizDialog::~IntroducirOrdenMatrizDialog()
{
    delete ui;
}

int IntroducirOrdenMatrizDialog::getNumeroDeFilas() const
{
    return ui->numeroFilasSpinBox->value();
}

int IntroducirOrdenMatrizDialog::getNumeroDeColumnas() const
{
    return ui->numeroColumnasSpinBox->value();
}

void IntroducirOrdenMatrizDialog::on_buttonBox_accepted()
{
    accept();
}

void IntroducirOrdenMatrizDialog::on_buttonBox_rejected()
{
    reject();
}
