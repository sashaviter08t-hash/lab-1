/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad_from_file;
    QAction *actionSave_to_file;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *labelTitle;
    QGridLayout *gridLayout;
    QLabel *labelA;
    QLineEdit *le_a;
    QLabel *labelB;
    QLineEdit *le_b;
    QLabel *labelC;
    QLineEdit *le_c;
    QLabel *labelAC;
    QLabel *l_ac;
    QLabel *labelBC;
    QLabel *l_bc;
    QLabel *labelSum;
    QLabel *l_sum;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(540, 360);
        actionLoad_from_file = new QAction(MainWindow);
        actionLoad_from_file->setObjectName("actionLoad_from_file");
        actionSave_to_file = new QAction(MainWindow);
        actionSave_to_file->setObjectName("actionSave_to_file");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        labelTitle = new QLabel(centralwidget);
        labelTitle->setObjectName("labelTitle");
        labelTitle->setAlignment(Qt::AlignCenter);
        labelTitle->setMargin(8);

        verticalLayout->addWidget(labelTitle);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        labelA = new QLabel(centralwidget);
        labelA->setObjectName("labelA");

        gridLayout->addWidget(labelA, 0, 0, 1, 1);

        le_a = new QLineEdit(centralwidget);
        le_a->setObjectName("le_a");

        gridLayout->addWidget(le_a, 0, 1, 1, 1);

        labelB = new QLabel(centralwidget);
        labelB->setObjectName("labelB");

        gridLayout->addWidget(labelB, 1, 0, 1, 1);

        le_b = new QLineEdit(centralwidget);
        le_b->setObjectName("le_b");

        gridLayout->addWidget(le_b, 1, 1, 1, 1);

        labelC = new QLabel(centralwidget);
        labelC->setObjectName("labelC");

        gridLayout->addWidget(labelC, 2, 0, 1, 1);

        le_c = new QLineEdit(centralwidget);
        le_c->setObjectName("le_c");

        gridLayout->addWidget(le_c, 2, 1, 1, 1);

        labelAC = new QLabel(centralwidget);
        labelAC->setObjectName("labelAC");

        gridLayout->addWidget(labelAC, 3, 0, 1, 1);

        l_ac = new QLabel(centralwidget);
        l_ac->setObjectName("l_ac");
        l_ac->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(l_ac, 3, 1, 1, 1);

        labelBC = new QLabel(centralwidget);
        labelBC->setObjectName("labelBC");

        gridLayout->addWidget(labelBC, 4, 0, 1, 1);

        l_bc = new QLabel(centralwidget);
        l_bc->setObjectName("l_bc");
        l_bc->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(l_bc, 4, 1, 1, 1);

        labelSum = new QLabel(centralwidget);
        labelSum->setObjectName("labelSum");

        gridLayout->addWidget(labelSum, 5, 0, 1, 1);

        l_sum = new QLabel(centralwidget);
        l_sum->setObjectName("l_sum");
        l_sum->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(l_sum, 5, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 540, 20));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionLoad_from_file);
        menuFile->addAction(actionSave_to_file);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Segment Lengths", nullptr));
        actionLoad_from_file->setText(QCoreApplication::translate("MainWindow", "Load from file", nullptr));
        actionSave_to_file->setText(QCoreApplication::translate("MainWindow", "Save to file", nullptr));
        labelTitle->setText(QCoreApplication::translate("MainWindow", "Enter three points A, B, C on the number line", nullptr));
        labelA->setText(QCoreApplication::translate("MainWindow", "Point A:", nullptr));
        labelB->setText(QCoreApplication::translate("MainWindow", "Point B:", nullptr));
        labelC->setText(QCoreApplication::translate("MainWindow", "Point C:", nullptr));
        labelAC->setText(QCoreApplication::translate("MainWindow", "Length AC:", nullptr));
        l_ac->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        labelBC->setText(QCoreApplication::translate("MainWindow", "Length BC:", nullptr));
        l_bc->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        labelSum->setText(QCoreApplication::translate("MainWindow", "AC + BC:", nullptr));
        l_sum->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Calculate", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
