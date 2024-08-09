#ifndef EMOIJ_H
#define EMOIJ_H

#include <QDialog>

class MainWindow; // Forward declaration of MainWindow class

namespace Ui {
class emoij;
}

class emoij : public QDialog
{
    Q_OBJECT

public:
    explicit emoij(MainWindow *parent = nullptr);
    ~emoij();

private slots:
    void on_backButton_clicked();

private:
    Ui::emoij *ui;
    MainWindow *mainWindow; // Pointer to MainWindow instance

};

#endif // EMOIJ_H
