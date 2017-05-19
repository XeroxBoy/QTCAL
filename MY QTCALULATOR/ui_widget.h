/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *minE;
    QLabel *minL;
    QLineEdit *maxE;
    QLabel *maxL;
    QPushButton *printB;
    QPushButton *pushButton;
    QPushButton *calB;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QLabel *label4;
    QLabel *label5;
    QLabel *label10;
    QLabel *label6;
    QLabel *label7;
    QLabel *label8;
    QLabel *label9;
    QLabel *label11;
    QLabel *label12;
    QLabel *functionL;
    QLabel *label_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(640, 464);
        verticalLayoutWidget = new QWidget(Widget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(530, 10, 95, 200));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        minE = new QLineEdit(verticalLayoutWidget);
        minE->setObjectName(QStringLiteral("minE"));

        verticalLayout->addWidget(minE);

        minL = new QLabel(verticalLayoutWidget);
        minL->setObjectName(QStringLiteral("minL"));
        minL->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(minL);

        maxE = new QLineEdit(verticalLayoutWidget);
        maxE->setObjectName(QStringLiteral("maxE"));

        verticalLayout->addWidget(maxE);

        maxL = new QLabel(verticalLayoutWidget);
        maxL->setObjectName(QStringLiteral("maxL"));
        maxL->setLayoutDirection(Qt::LeftToRight);
        maxL->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(maxL);

        printB = new QPushButton(verticalLayoutWidget);
        printB->setObjectName(QStringLiteral("printB"));

        verticalLayout->addWidget(printB);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        calB = new QPushButton(verticalLayoutWidget);
        calB->setObjectName(QStringLiteral("calB"));

        verticalLayout->addWidget(calB);

        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 504, 501, 16));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(68, 440, 31, 16));
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(112, 440, 31, 16));
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(154, 440, 31, 16));
        label_6 = new QLabel(Widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(200, 440, 31, 16));
        label_7 = new QLabel(Widget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(244, 440, 31, 16));
        label_8 = new QLabel(Widget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(288, 440, 31, 16));
        label_9 = new QLabel(Widget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(332, 440, 31, 16));
        label_10 = new QLabel(Widget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(376, 440, 31, 16));
        label_11 = new QLabel(Widget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(420, 440, 31, 16));
        label_12 = new QLabel(Widget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(464, 440, 31, 16));
        label_13 = new QLabel(Widget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(508, 440, 31, 16));
        label1 = new QLabel(Widget);
        label1->setObjectName(QStringLiteral("label1"));
        label1->setGeometry(QRect(28, 425, 38, 21));
        label1->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label2 = new QLabel(Widget);
        label2->setObjectName(QStringLiteral("label2"));
        label2->setGeometry(QRect(28, 390, 38, 21));
        label2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label3 = new QLabel(Widget);
        label3->setObjectName(QStringLiteral("label3"));
        label3->setGeometry(QRect(28, 355, 38, 21));
        label4 = new QLabel(Widget);
        label4->setObjectName(QStringLiteral("label4"));
        label4->setGeometry(QRect(28, 318, 38, 21));
        label5 = new QLabel(Widget);
        label5->setObjectName(QStringLiteral("label5"));
        label5->setGeometry(QRect(28, 285, 38, 21));
        label10 = new QLabel(Widget);
        label10->setObjectName(QStringLiteral("label10"));
        label10->setGeometry(QRect(28, 110, 38, 21));
        label6 = new QLabel(Widget);
        label6->setObjectName(QStringLiteral("label6"));
        label6->setGeometry(QRect(28, 250, 38, 21));
        label7 = new QLabel(Widget);
        label7->setObjectName(QStringLiteral("label7"));
        label7->setGeometry(QRect(28, 215, 38, 21));
        label8 = new QLabel(Widget);
        label8->setObjectName(QStringLiteral("label8"));
        label8->setGeometry(QRect(28, 180, 38, 21));
        label9 = new QLabel(Widget);
        label9->setObjectName(QStringLiteral("label9"));
        label9->setGeometry(QRect(28, 145, 38, 21));
        label11 = new QLabel(Widget);
        label11->setObjectName(QStringLiteral("label11"));
        label11->setGeometry(QRect(28, 75, 38, 21));
        label12 = new QLabel(Widget);
        label12->setObjectName(QStringLiteral("label12"));
        label12->setGeometry(QRect(28, 40, 38, 21));
        functionL = new QLabel(Widget);
        functionL->setObjectName(QStringLiteral("functionL"));
        functionL->setEnabled(true);
        functionL->setGeometry(QRect(0, 15, 81, 21));
        functionL->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(540, 220, 81, 211));

        retranslateUi(Widget);
        QObject::connect(printB, SIGNAL(clicked()), Widget, SLOT(Printimage()));
        QObject::connect(calB, SIGNAL(clicked()), Widget, SLOT(Calculate()));

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        minL->setText(QApplication::translate("Widget", "X\346\234\200\345\260\217\345\200\274", 0));
        maxL->setText(QApplication::translate("Widget", "X\346\234\200\345\244\247\345\200\274", 0));
        printB->setText(QApplication::translate("Widget", "\347\273\230\345\210\266\345\233\276\345\203\217", 0));
        pushButton->setText(QApplication::translate("Widget", "\346\277\200\346\264\273", 0));
        calB->setText(QApplication::translate("Widget", "\346\261\202\346\240\271", 0));
        label->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        label_6->setText(QString());
        label_7->setText(QString());
        label_8->setText(QString());
        label_9->setText(QString());
        label_10->setText(QString());
        label_11->setText(QString());
        label_12->setText(QString());
        label_13->setText(QString());
        label1->setText(QString());
        label2->setText(QString());
        label3->setText(QString());
        label4->setText(QString());
        label5->setText(QString());
        label10->setText(QString());
        label6->setText(QString());
        label7->setText(QString());
        label8->setText(QString());
        label9->setText(QString());
        label11->setText(QString());
        label12->setText(QString());
        functionL->setText(QApplication::translate("Widget", "\350\257\267\350\276\223\345\205\245\345\207\275\346\225\260", 0));
        label_2->setText(QApplication::translate("Widget", "sin\347\255\211\344\270\211\350\247\222\345\207\275\346\225\260\350\257\267\347\224\250sinnx\347\232\204\345\275\242\345\274\217 \345\246\202sin2x \345\205\266\344\273\226\345\207\275\346\225\260\347\263\273\346\225\260\350\257\267\345\213\277\347\234\201*(\345\215\263\344\275\277\346\230\257\344\270\211\350\247\222\345\207\275\346\225\260,\345\234\250\345\212\240\344\272\206\346\213\254\345\217\267\345\220\216 \347\263\273\346\225\260\345\220\216\344\271\237\350\257\267\350\276\223\345\205\245*,\345\246\202sin(2*x+5) \345\246\2022x\345\272\224\345\206\231\344\270\2722*x \347\273\230\345\233\276\345\220\216\346\226\271\350\203\275\n"
"\346\261\202\346\240\271\343\200\202\346\240\271\345\217\267\347\232\204\345\271\202\350\257\267\345\206\231\346\210\220\345\260\217\346\225\260\345\275\242\345\274\217 \345\213\277\347\224\250\345\210\206\346\225\260\350\241\250\347\244\272", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
