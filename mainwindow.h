#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "modellodati.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void newElement();
    void removeSelected();
    void editSelected();

private:
    Ui::MainWindow *ui;
    ModelloDati* m_modello;
};

#endif // MAINWINDOW_H
