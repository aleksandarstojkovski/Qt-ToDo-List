#ifndef TODOELEMENT_H
#define TODOELEMENT_H

#include <QString>

class TodoElement
{
public:
    TodoElement();
    TodoElement(const TodoElement& other);
    TodoElement(unsigned int id, const QString& title, const QString& description, unsigned int priority);

    void update(unsigned int id, const QString& title, const QString& description, unsigned int priority);

    unsigned int id() const;
    const QString& title() const;
    const QString& description() const;
    unsigned int priority() const;

    void setId(unsigned int id);
    void setTitle(const QString& title);
    void setDescription(const QString& description);
    void setPriority(unsigned int priority);

    TodoElement& operator=(const TodoElement& other);

private:
    unsigned int m_id;
    QString m_title;
    QString m_description;
    unsigned int m_priority;
};

#endif // TODOELEMENT_H
