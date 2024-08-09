#ifndef ENGENG_H
#define ENGENG_H

#include <QDialog>
class MainWindow;
namespace Ui {
class EngEng;
}

class EngEng : public QDialog
{
    Q_OBJECT

public:
    explicit EngEng(MainWindow *parent = nullptr);
    ~EngEng();

private slots:
    void on_backButton_clicked();

private:
    Ui::EngEng *ui;
    MainWindow* mainWindow;
};

#endif // ENGENG_H
