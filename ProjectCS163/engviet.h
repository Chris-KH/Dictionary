#ifndef ENGVIIET_H
#define ENGVIIET_H

#include <QDialog>
#include <QListWidget>
#include <QLabel>
#include <QString>
#include <vector>
// struct word{
//     QString name,definition;
// };

class MainWindow; // Forward declaration of MainWindow class

namespace Ui {
class EngViet;
}

class EngViet : public QDialog
{
    Q_OBJECT

public:
    explicit EngViet(MainWindow *parent = nullptr);
    ~EngViet();

private slots:
    void on_backButton_clicked();
private:
    void on_historyButton_clicked(); // Declare the slot
    void on_favoriteButton_clicked();
    void on_gameButton_clicked();
protected:
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::EngViet *ui;
    MainWindow *mainWindow; // Pointer to MainWindow instance

};

#endif // ENGVIIET_H
