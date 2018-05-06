/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label;
    QWidget *tab_2;
    QToolBox *Alternate_2;
    QWidget *Alternate;
    QWidget *page_3;
    QToolBox *toolBox;
    QWidget *page;
    QWidget *page_10;
    QWidget *page_11;
    QWidget *page_12;
    QWidget *page_4;
    QWidget *page_5;
    QToolBox *toolBox_2;
    QWidget *page_13;
    QWidget *page_14;
    QWidget *page_6;
    QWidget *page_7;
    QWidget *page_8;
    QWidget *page_2;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(890, 643);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 881, 621));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 380, 101, 20));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        Alternate_2 = new QToolBox(tab_2);
        Alternate_2->setObjectName(QStringLiteral("Alternate_2"));
        Alternate_2->setGeometry(QRect(10, 10, 851, 601));
        Alternate = new QWidget();
        Alternate->setObjectName(QStringLiteral("Alternate"));
        Alternate->setGeometry(QRect(0, 0, 851, 329));
        Alternate_2->addItem(Alternate, QStringLiteral("Alternate"));
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        page_3->setGeometry(QRect(0, 0, 100, 30));
        toolBox = new QToolBox(page_3);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setGeometry(QRect(30, 0, 351, 251));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 351, 115));
        toolBox->addItem(page, QStringLiteral("Fade Pixel Red"));
        page_10 = new QWidget();
        page_10->setObjectName(QStringLiteral("page_10"));
        page_10->setGeometry(QRect(0, 0, 100, 30));
        toolBox->addItem(page_10, QStringLiteral("Fade Pixel Green"));
        page_11 = new QWidget();
        page_11->setObjectName(QStringLiteral("page_11"));
        page_11->setGeometry(QRect(0, 0, 100, 30));
        toolBox->addItem(page_11, QStringLiteral("Fade Pixel Blue"));
        page_12 = new QWidget();
        page_12->setObjectName(QStringLiteral("page_12"));
        page_12->setGeometry(QRect(0, 0, 100, 30));
        toolBox->addItem(page_12, QStringLiteral("Fade Pixel All"));
        Alternate_2->addItem(page_3, QStringLiteral("Fade Pixel"));
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        page_4->setGeometry(QRect(0, 0, 100, 30));
        Alternate_2->addItem(page_4, QStringLiteral("Multi Pixel Run"));
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        page_5->setGeometry(QRect(0, 0, 100, 30));
        toolBox_2 = new QToolBox(page_5);
        toolBox_2->setObjectName(QStringLiteral("toolBox_2"));
        toolBox_2->setGeometry(QRect(50, 10, 801, 271));
        page_13 = new QWidget();
        page_13->setObjectName(QStringLiteral("page_13"));
        page_13->setGeometry(QRect(0, 0, 801, 203));
        toolBox_2->addItem(page_13, QStringLiteral("Pixel Run"));
        page_14 = new QWidget();
        page_14->setObjectName(QStringLiteral("page_14"));
        page_14->setGeometry(QRect(0, 0, 100, 30));
        toolBox_2->addItem(page_14, QStringLiteral("Pixel Run With Trail"));
        Alternate_2->addItem(page_5, QStringLiteral("Pixel Run"));
        page_6 = new QWidget();
        page_6->setObjectName(QStringLiteral("page_6"));
        page_6->setGeometry(QRect(0, 0, 100, 30));
        Alternate_2->addItem(page_6, QStringLiteral("Smooth Chase"));
        page_7 = new QWidget();
        page_7->setObjectName(QStringLiteral("page_7"));
        page_7->setGeometry(QRect(0, 0, 100, 30));
        Alternate_2->addItem(page_7, QStringLiteral("Sparkle To Color"));
        page_8 = new QWidget();
        page_8->setObjectName(QStringLiteral("page_8"));
        page_8->setGeometry(QRect(0, 0, 100, 30));
        Alternate_2->addItem(page_8, QStringLiteral("Wipe"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setGeometry(QRect(0, 0, 100, 30));
        Alternate_2->addItem(page_2, QStringLiteral("Page 2"));
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        Alternate_2->setCurrentIndex(0);
        toolBox->setCurrentIndex(0);
        toolBox_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QApplication::translate("MainWindow", "Color Selection", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Static Color", 0));
        Alternate_2->setItemText(Alternate_2->indexOf(Alternate), QApplication::translate("MainWindow", "Alternate", 0));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("MainWindow", "Fade Pixel Red", 0));
        toolBox->setItemText(toolBox->indexOf(page_10), QApplication::translate("MainWindow", "Fade Pixel Green", 0));
        toolBox->setItemText(toolBox->indexOf(page_11), QApplication::translate("MainWindow", "Fade Pixel Blue", 0));
        toolBox->setItemText(toolBox->indexOf(page_12), QApplication::translate("MainWindow", "Fade Pixel All", 0));
        Alternate_2->setItemText(Alternate_2->indexOf(page_3), QApplication::translate("MainWindow", "Fade Pixel", 0));
        Alternate_2->setItemText(Alternate_2->indexOf(page_4), QApplication::translate("MainWindow", "Multi Pixel Run", 0));
        toolBox_2->setItemText(toolBox_2->indexOf(page_13), QApplication::translate("MainWindow", "Pixel Run", 0));
        toolBox_2->setItemText(toolBox_2->indexOf(page_14), QApplication::translate("MainWindow", "Pixel Run With Trail", 0));
        Alternate_2->setItemText(Alternate_2->indexOf(page_5), QApplication::translate("MainWindow", "Pixel Run", 0));
        Alternate_2->setItemText(Alternate_2->indexOf(page_6), QApplication::translate("MainWindow", "Smooth Chase", 0));
        Alternate_2->setItemText(Alternate_2->indexOf(page_7), QApplication::translate("MainWindow", "Sparkle To Color", 0));
        Alternate_2->setItemText(Alternate_2->indexOf(page_8), QApplication::translate("MainWindow", "Wipe", 0));
        Alternate_2->setItemText(Alternate_2->indexOf(page_2), QApplication::translate("MainWindow", "Page 2", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Animation", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
