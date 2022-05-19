#ifndef MIXEDCOMBOBOX_H
#define MIXEDCOMBOBOX_H

#include <QComboBox>

class QMenu;

class MixedComboBox : public QComboBox
{
    Q_OBJECT
public:
    explicit MixedComboBox(QWidget *parent = nullptr);
    virtual ~MixedComboBox();
protected:
    void mousePressEvent(QMouseEvent *e) override;
    void paintEvent(QPaintEvent *e) override;
private:
    void reset();
    void popupMenu();

    QMenu *m_menu;
};

#endif // MIXEDCOMBOBOX_H
