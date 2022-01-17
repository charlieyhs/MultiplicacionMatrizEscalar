#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT



public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_multiplicarPushButton_clicked();
    void on_SalirPushButton_clicked();
    void on_actionIntroducirMatriz_triggered();
private:
    Ui::Widget *ui;
    QStandardItemModel *mModel;
    void setValueAt(int ix, int jx, double value);
    double getValueAt(int ix, int jx)const;


};
#endif // WIDGET_H
