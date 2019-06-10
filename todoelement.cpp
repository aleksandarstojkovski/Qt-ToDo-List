#include "todoelement.h"

TodoElement::TodoElement()
{
}

TodoElement::TodoElement(const TodoElement &other)
{
    m_id = other.m_id;
    m_title = other.m_title;
    m_description = other.m_description;
    m_priority = other.m_priority;
}

TodoElement::TodoElement(unsigned int id, const QString &title, const QString &description, unsigned int priority) :
    m_id{id}, m_title{title}, m_description{description}, m_priority{priority}
{
}

void TodoElement::update(unsigned int id, const QString &title, const QString &description, unsigned int priority)
{
    m_id = id;
    m_title = title;
    m_description = description;
    m_priority = priority;
}

unsigned int TodoElement::id() const
{
    return m_id;
}

const QString &TodoElement::title() const
{
    return m_title;
}

const QString &TodoElement::description() const
{
    return m_description;
}

unsigned int TodoElement::priority() const
{
    return m_priority;
}

void TodoElement::setId(unsigned int id)
{
    m_id = id;
}

void TodoElement::setTitle(const QString &title)
{
    m_title = title;
}

void TodoElement::setDescription(const QString &description)
{
    m_description = description;
}

void TodoElement::setPriority(unsigned int priority)
{
    m_priority = priority;
}

TodoElement &TodoElement::operator =(const TodoElement &other)
{
    m_id = other.id();
    m_title = other.title();
    m_description = other.description();
    m_priority = other.priority();
    return *this;
}
