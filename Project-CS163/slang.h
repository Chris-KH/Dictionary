#ifndef SLANG_H
#define SLANG_H

#include <QDialog>
class MainWindow;
namespace Ui {
class Slang;
}

class Slang : public QDialog
{
    Q_OBJECT

public:
    explicit Slang(MainWindow *parent = nullptr);
    ~Slang();

private slots:
    void on_backButton_clicked();

private:
    Ui::Slang *ui;
    MainWindow *mainWindow; // Pointer to MainWindow instance

};

#endif // SLANG_H
