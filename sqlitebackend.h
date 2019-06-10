#ifndef SQLITEBACKEND_H
#define SQLITEBACKEND_H
#include <QSqlDatabase>
#include "todoelement.h"
#include <QString>

class SQLiteBackend {
public:
    SQLiteBackend();

    virtual ~SQLiteBackend();

    unsigned int aggiungiElemento(const QString& titolo, const  QString& descrizione, unsigned int importanza);

    bool rimuoviElemento(unsigned int id);

    bool aggiornaElemento(unsigned int id, const QString& titolo, const  QString& descrizione, unsigned int importanza);

    QList<TodoElement> elementi() const;

private:
    QSqlDatabase db;
};

#endif // SQLITEBACKEND_H
