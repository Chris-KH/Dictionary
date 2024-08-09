#ifndef VIETENG_H
#define VIETENG_H

#include <QDialog>

class MainWindow;

namespace Ui {
class VietEng;
}

class VietEng : public QDialog
{
    Q_OBJECT

public:
    explicit VietEng(MainWindow *parent = nullptr);
    ~VietEng();

private slots:
    void on_backButton_clicked();

private:
    Ui::VietEng *ui;
    MainWindow *mainWindow;
};

#endif // VIETENG_H
