/********************************************************************************
** Form generated from reading UI file 'win.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIN_H
#define UI_WIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Win
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *Win)
    {
        if (Win->objectName().isEmpty())
            Win->setObjectName(QStringLiteral("Win"));
        Win->resize(700, 800);
        Win->setStyleSheet(QStringLiteral("background-color: rgb(180, 255, 58);"));
        label = new QLabel(Win);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 140, 511, 211));
        QFont font;
        font.setFamily(QStringLiteral("MS UI Gothic"));
        font.setPointSize(72);
        label->setFont(font);
        pushButton = new QPushButton(Win);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(150, 530, 381, 81));
        QFont font1;
        font1.setPointSize(26);
        pushButton->setFont(font1);
        pushButton->setFocusPolicy(Qt::ClickFocus);

        retranslateUi(Win);

        QMetaObject::connectSlotsByName(Win);
    } // setupUi

    void retranslateUi(QWidget *Win)
    {
        Win->setWindowTitle(QApplication::translate("Win", "Form", 0));
        label->setText(QApplication::translate("Win", "YOU  WIN!!!", 0));
        pushButton->setText(QApplication::translate("Win", "PLAY AGAIN!", 0));
    } // retranslateUi

};

namespace Ui {
    class Win: public Ui_Win {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIN_H
