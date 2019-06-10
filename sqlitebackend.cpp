#include "sqlitebackend.h"
#include <QStringList>
#include <QSqlQuery>
#include <QVariant>

SQLiteBackend::SQLiteBackend()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("todolist.db");
    if (db.open()) {
        if (!db.tables().contains(QLatin1String{"todos"})) {
            QSqlQuery createQuery;
            createQuery.exec("create table todos (id integer primary key, title text, description text, priority integer)");
        }
    }
}

SQLiteBackend::~SQLiteBackend()
{
    if (db.isOpen()) {
        db.close();
    }
    QSqlDatabase::removeDatabase("QSQLITE");
}

unsigned int SQLiteBackend::aggiungiElemento(const QString &titolo, const QString &descrizione, unsigned int importanza)
{
    QSqlQuery insertQuery;
    insertQuery.exec(QString{"insert into todos values(NULL, '%1', '%2', %3)"}.arg(titolo).arg(descrizione).arg(importanza));
    return insertQuery.lastInsertId().toUInt();
}

bool SQLiteBackend::rimuoviElemento(unsigned int id)
{
    QSqlQuery deleteQuery;
    return deleteQuery.exec(QString{"delete from todos where id=%1"}.arg(id));
}

bool SQLiteBackend::aggiornaElemento(unsigned int id, const QString &titolo, const QString &descrizione, unsigned int importanza)
{
    QSqlQuery updateQuery;
    return updateQuery.exec(QString{"update todos SET title='%1', description='%2', priority=%3 where id=%4"}.arg(titolo).arg(descrizione).arg(importanza).arg(id));

}

QList<TodoElement> SQLiteBackend::elementi() const
{
    QList<TodoElement> results;
    QSqlQuery getQuery{QString{"select * from todos"}};
    while (getQuery.next()) {
        results.push_back(TodoElement{getQuery.value(0).toUInt(),
                                      getQuery.value(1).toString(),
                                      getQuery.value(2).toString(),
                                      getQuery.value(3).toUInt()});
    }
    return results;
}
