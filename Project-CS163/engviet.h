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
    void on_historyButton_clicked(); // Declare the slot
    void on_favouristButton_clicked();
    void addNewWord();


private:
    Ui::EngViet *ui;
    MainWindow *mainWindow; // Pointer to MainWindow instance

};

#endif // ENGVIIET_H
