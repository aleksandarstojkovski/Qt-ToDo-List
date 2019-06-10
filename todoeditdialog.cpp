#include "todoeditdialog.h"
#include "ui_todoeditdialog.h"
#include "todoelement.h"
#include <QPushButton>
#include <QDebug>

TodoEditDialog::TodoEditDialog(const TodoElement &e, ModelloDati *md, QWidget *parent) :
    QDialog{parent},
    ui{new Ui::TodoEditDialog},
m_e{e},
m_md{md}
{
    ui->setupUi(this);
    ui->title->setText(m_e.title());
    ui->description->setText(m_e.description());
    ui->priority->setValue(m_e.priority());

    QPushButton *okButton {ui->buttonBox->button(QDialogButtonBox::Ok)};
    connect(okButton, SIGNAL(clicked()), this, SLOT(commitChanges()));

    QPushButton *cancelButton {ui->buttonBox->button(QDialogButtonBox::Cancel)};
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(abortChanges()));
    ui->progressBar->setValue(ui->priority->value());

    connect(ui->priority, SIGNAL(valueChanged(int)), ui->progressBar, SLOT(setValue(int)));
}

TodoEditDialog::~TodoEditDialog()
{
    delete ui;
}

void TodoEditDialog::commitChanges()
{
    m_md->aggiornaElemento(m_e.id(),
                           ui->title->text(),
                           ui->description->text(),
                           ui->priority->value());
    this->close();
}

void TodoEditDialog::abortChanges()
{
    qDebug() << "Ignora modifiche elemento";
    this->close();
}
