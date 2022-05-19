#include "mixedcombobox.h"

#include <QMenu>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QWidgetAction>

MixedComboBox::MixedComboBox(QWidget *parent)
    : QComboBox(parent)
{
    m_menu = new QMenu(this);

    for (int k = 0; k < 10; ++k)
    {
        QComboBox *combo = new QComboBox(this);
        for (int i = 0; i < 10; ++i)
        {
            combo->addItem(QString::number(i+1));
        }
        QWidgetAction *action = new QWidgetAction(this);
        action->setDefaultWidget(combo);
        m_menu->addAction(action);
    }
}

MixedComboBox::~MixedComboBox()
{
    // nothing to do here
}

void MixedComboBox::mousePressEvent(QMouseEvent *e)
{
    reset();
    popupMenu();
    e->ignore();
}

void MixedComboBox::paintEvent(QPaintEvent *e)
{
    QComboBox::paintEvent(e);
}

void MixedComboBox::reset()
{
    QList<QAction*> A = m_menu->actions();
    std::for_each(A.begin(), A.end(), [&](QAction *a)
    {
        QWidgetAction *w = dynamic_cast<QWidgetAction*>(a);
        QComboBox *c = dynamic_cast<QComboBox*>(w->defaultWidget());
        c->setFixedWidth(width());
    });
    m_menu->setFixedWidth(width());
}

void MixedComboBox::popupMenu()
{
    QPoint p = mapFromParent(pos());
    p = mapToGlobal(p);
    p.ry() += height();
    m_menu->popup(p);
}
