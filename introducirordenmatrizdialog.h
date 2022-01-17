#ifndef INTRODUCIRORDENMATRIZDIALOG_H
#define INTRODUCIRORDENMATRIZDIALOG_H

#include <QDialog>

namespace Ui {
class IntroducirOrdenMatrizDialog;
}

class IntroducirOrdenMatrizDialog : public QDialog
{
    Q_OBJECT

public:
    explicit IntroducirOrdenMatrizDialog(QWidget *parent = nullptr);
    ~IntroducirOrdenMatrizDialog();
    int getNumeroDeFilas() const;
    int getNumeroDeColumnas() const;
private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::IntroducirOrdenMatrizDialog *ui;
};

#endif // INTRODUCIRORDENMATRIZDIALOG_H
