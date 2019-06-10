#ifndef TODOEDITDIALOG_H
#define TODOEDITDIALOG_H

#include <QDialog>
#include <QModelIndex>
#include "modellodati.h"

namespace Ui {
class TodoEditDialog;
}

class TodoEditDialog : public QDialog {
    Q_OBJECT

public:
    explicit TodoEditDialog(const TodoElement& e, ModelloDati *md, QWidget *parent = nullptr);
    ~TodoEditDialog();

private slots:
    void commitChanges();
    void abortChanges();

private:
    QModelIndex m_index;
    Ui::TodoEditDialog *ui;
    const TodoElement& m_e;
    ModelloDati *m_md;
};

#endif // TODOEDITDIALOG_H
