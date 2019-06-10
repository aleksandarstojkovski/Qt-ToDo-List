#ifndef MODELLODATI_H
#define MODELLODATI_H

#include <QAbstractListModel>
#include <QList>
#include "todoelement.h"
#include "sqlitebackend.h"

class ModelloDati : public QAbstractListModel {
    Q_OBJECT
public:
    explicit ModelloDati(QObject *parent = nullptr);


    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;

    unsigned int aggiungiElemento(const QString& titolo,
                                  const QString& descrizione,
                                  unsigned int importanza);
    const TodoElement &elemento(int riga) const;
    bool rimuoviElemento(unsigned int id);
    bool aggiornaElemento(unsigned int id,
                          const QString& titolo,
                          const QString& descrizione,
                          unsigned int importanza);
private:
    SQLiteBackend backend;
    QList<TodoElement> m_elementi;
};

#endif // MODELLODATI_H
