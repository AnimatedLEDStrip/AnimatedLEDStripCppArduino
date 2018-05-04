/********************************************************************************
** Form generated from reading UI file 'led_gui.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LED_GUI_H
#define UI_LED_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_led_gui
{
public:
    QWidget *centralWidget;
    QTabWidget *tabObject;
    QWidget *tab1;
    QWidget *tab_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QToolBox *toolBox;
    QWidget *page;
    QWidget *page_2;
    QScrollBar *verticalScrollBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *led_gui)
    {
        if (led_gui->objectName().isEmpty())
            led_gui->setObjectName(QStringLiteral("led_gui"));
        led_gui->resize(868, 625);
        centralWidget = new QWidget(led_gui);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabObject = new QTabWidget(centralWidget);
        tabObject->setObjectName(QStringLiteral("tabObject"));
        tabObject->setGeometry(QRect(10, 10, 851, 581));
        tabObject->setMovable(false);
        tab1 = new QWidget();
        tab1->setObjectName(QStringLiteral("tab1"));
        tabObject->addTab(tab1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        scrollArea = new QScrollArea(tab_2);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(-1, -1, 851, 551));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 849, 549));
        toolBox = new QToolBox(scrollAreaWidgetContents);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setGeometry(QRect(10, 10, 791, 721));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 791, 463));
        toolBox->addItem(page, QStringLiteral("Page 1"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setGeometry(QRect(0, 0, 791, 653));
        toolBox->addItem(page_2, QStringLiteral("Page 2"));
        verticalScrollBar = new QScrollBar(scrollAreaWidgetContents);
        verticalScrollBar->setObjectName(QStringLiteral("verticalScrollBar"));
        verticalScrollBar->setGeometry(QRect(830, 0, 16, 541));
        verticalScrollBar->setOrientation(Qt::Vertical);
        scrollArea->setWidget(scrollAreaWidgetContents);
        tabObject->addTab(tab_2, QString());
        led_gui->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(led_gui);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        led_gui->setStatusBar(statusBar);

        retranslateUi(led_gui);

        tabObject->setCurrentIndex(1);
        toolBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(led_gui);
    } // setupUi

    void retranslateUi(QMainWindow *led_gui)
    {
        led_gui->setWindowTitle(QApplication::translate("led_gui", "led_gui", 0));
        tabObject->setTabText(tabObject->indexOf(tab1), QApplication::translate("led_gui", "Static Color", 0));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("led_gui", "Page 1", 0));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("led_gui", "Page 2", 0));
        tabObject->setTabText(tabObject->indexOf(tab_2), QApplication::translate("led_gui", "Animation", 0));
    } // retranslateUi

};

namespace Ui {
    class led_gui: public Ui_led_gui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LED_GUI_H
