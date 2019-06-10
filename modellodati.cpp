#include "modellodati.h"

ModelloDati::ModelloDati(QObject *parent) : QAbstractListModel{parent}
{
    m_elementi = backend.elementi();
}


int ModelloDati::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_elementi.size();
}

QVariant ModelloDati::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) return QVariant{};
    auto row{index.row()};
    if (row >= m_elementi.size()) return QVariant{};
    auto& e{m_elementi.at(row)};
    switch(role) {
    case Qt::DisplayRole:
        return QString{"%1 - %2 (%3)"}.arg(e.title(), e.description())
               .arg(e.priority());
    default:
        return QVariant{};
    }
}

unsigned int ModelloDati::aggiungiElemento(const QString &titolo, const QString &descrizione, unsigned int importanza)
{
    unsigned int id {backend.aggiungiElemento(titolo, descrizione, importanza)};
    beginInsertRows(QModelIndex{}, m_elementi.size(), m_elementi.size());
    m_elementi.push_back({id, titolo, descrizione, importanza});
    endInsertRows();
    return id;
}

const TodoElement &ModelloDati::elemento(int riga) const
{
    return m_elementi.at(riga);
}

static int rigaDaId(const QList<TodoElement>& lista, unsigned int id)
{
    for(int i=0; i<lista.size(); i++) {
        const auto& t {lista.at(i)};
        if (t.id() == id) {
            return i;
        }
    }
    return -1;
}

bool ModelloDati::rimuoviElemento(unsigned int id)
{
    if (backend.rimuoviElemento(id)) {
        auto riga{rigaDaId(m_elementi, id)};
        if (riga < 0) return false;
        beginRemoveRows(QModelIndex{}, riga, riga);
        m_elementi.removeAt(riga);
        endRemoveRows();
        return true;
    }
    else {
        return false;
    }
}

bool ModelloDati::aggiornaElemento(unsigned int id, const QString &titolo, const QString &descrizione, unsigned int importanza)
{
    if (backend.aggiornaElemento(id, titolo, descrizione, importanza)) {
        auto riga{rigaDaId(m_elementi, id)};
        if (riga < 0) return false;
        auto& el{m_elementi[riga]};
        el.setTitle(titolo);
        el.setDescription(descrizione);
        el.setPriority(importanza);
        emit dataChanged(index(riga), index(riga));
        return true;
    }
    else {
        return false;
    }
}
