#ifndef TXTFUNCTION_H
#define TXTFUNCTION_H

#include <QWidget>

namespace Ui {
class TxtFunction;
}

class TxtFunction : public QWidget
{
    Q_OBJECT

public:
    explicit TxtFunction(QWidget *parent = 0);
    ~TxtFunction();

private slots:

    void on_buttonRead_clicked();

    void on_buttonWrite_clicked();

private:
    Ui::TxtFunction *ui;
};

#endif // TXTFUNCTION_H
