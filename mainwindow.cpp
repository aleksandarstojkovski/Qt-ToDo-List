#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "todoeditdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow{parent},
    ui{new Ui::MainWindow},
m_modello{new ModelloDati{this}}
{
    ui->setupUi(this); // collega il modello alla view
    ui->listView->setModel(m_modello);
    connect(this->ui->actionAggiungi_todo, SIGNAL(triggered()), this, SLOT(newElement()));
    connect(this->ui->actionElimina, SIGNAL(triggered()), this, SLOT(removeSelected()));
    connect(this->ui->actionModifica, SIGNAL(triggered()), this, SLOT(editSelected()));
    connect(this->ui->actionEsci, SIGNAL(triggered()), this, SLOT(close()));
    connect(this->ui->listView, SIGNAL(doubleClicked(QModelIndex)),
            this, SLOT(editSelected()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newElement()
{
    qDebug() << m_modello->aggiungiElemento("Titolo",
                                            "Descrizione",
                                            1);
}

void MainWindow::removeSelected()
{
    auto indice{ui->listView->currentIndex()};
    if (indice.row() >= 0) {
        m_modello->rimuoviElemento(
            m_modello->elemento(indice.row()).id());
    }
}

void MainWindow::editSelected()
{
    auto indice{ui->listView->currentIndex()};
    if (indice.row() >= 0) {
        const auto& el{m_modello->elemento(indice.row())};
        TodoEditDialog tde{el, m_modello, this};
        tde.exec();
    }
}
