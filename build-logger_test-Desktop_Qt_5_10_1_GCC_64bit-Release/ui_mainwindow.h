/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionStart;
    QAction *actionPause;
    QAction *actionStop;
    QAction *actionLog_to;
    QAction *actionFrequency;
    QAction *actionMode;
    QAction *actionSave_data;
    QAction *actionttyUSB0;
    QAction *actionttyACM0;
    QAction *actionCSV;
    QAction *actionClear;
    QAction *actionScale;
    QAction *actionSave_img;
    QAction *actionClear_2;
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuSetup;
    QMenu *menuPort;
    QMenu *menuMeasure;
    QMenu *menuLog;
    QMenu *menuFormat;
    QMenu *menuGraph;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionStart = new QAction(MainWindow);
        actionStart->setObjectName(QStringLiteral("actionStart"));
        actionPause = new QAction(MainWindow);
        actionPause->setObjectName(QStringLiteral("actionPause"));
        actionStop = new QAction(MainWindow);
        actionStop->setObjectName(QStringLiteral("actionStop"));
        actionLog_to = new QAction(MainWindow);
        actionLog_to->setObjectName(QStringLiteral("actionLog_to"));
        actionFrequency = new QAction(MainWindow);
        actionFrequency->setObjectName(QStringLiteral("actionFrequency"));
        actionMode = new QAction(MainWindow);
        actionMode->setObjectName(QStringLiteral("actionMode"));
        actionSave_data = new QAction(MainWindow);
        actionSave_data->setObjectName(QStringLiteral("actionSave_data"));
        actionttyUSB0 = new QAction(MainWindow);
        actionttyUSB0->setObjectName(QStringLiteral("actionttyUSB0"));
        actionttyACM0 = new QAction(MainWindow);
        actionttyACM0->setObjectName(QStringLiteral("actionttyACM0"));
        actionCSV = new QAction(MainWindow);
        actionCSV->setObjectName(QStringLiteral("actionCSV"));
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName(QStringLiteral("actionClear"));
        actionScale = new QAction(MainWindow);
        actionScale->setObjectName(QStringLiteral("actionScale"));
        actionSave_img = new QAction(MainWindow);
        actionSave_img->setObjectName(QStringLiteral("actionSave_img"));
        actionClear_2 = new QAction(MainWindow);
        actionClear_2->setObjectName(QStringLiteral("actionClear_2"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(9, 9, 381, 231));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        textEdit = new QTextEdit(verticalLayoutWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout->addWidget(textEdit);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 20));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuSetup = new QMenu(menuBar);
        menuSetup->setObjectName(QStringLiteral("menuSetup"));
        menuPort = new QMenu(menuSetup);
        menuPort->setObjectName(QStringLiteral("menuPort"));
        menuMeasure = new QMenu(menuBar);
        menuMeasure->setObjectName(QStringLiteral("menuMeasure"));
        menuLog = new QMenu(menuBar);
        menuLog->setObjectName(QStringLiteral("menuLog"));
        menuFormat = new QMenu(menuLog);
        menuFormat->setObjectName(QStringLiteral("menuFormat"));
        menuGraph = new QMenu(menuBar);
        menuGraph->setObjectName(QStringLiteral("menuGraph"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuSetup->menuAction());
        menuBar->addAction(menuMeasure->menuAction());
        menuBar->addAction(menuLog->menuAction());
        menuBar->addAction(menuGraph->menuAction());
        menuFile->addAction(actionSave_data);
        menuFile->addSeparator();
        menuFile->addAction(actionSave_img);
        menuFile->addAction(actionExit);
        menuSetup->addAction(actionFrequency);
        menuSetup->addAction(actionMode);
        menuSetup->addAction(menuPort->menuAction());
        menuPort->addAction(actionttyUSB0);
        menuPort->addAction(actionttyACM0);
        menuMeasure->addAction(actionStart);
        menuMeasure->addAction(actionPause);
        menuMeasure->addAction(actionStop);
        menuLog->addAction(actionLog_to);
        menuLog->addAction(menuFormat->menuAction());
        menuLog->addAction(actionClear_2);
        menuFormat->addAction(actionCSV);
        menuGraph->addAction(actionScale);
        menuGraph->addAction(actionClear);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Logger_Test", nullptr));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        actionStart->setText(QApplication::translate("MainWindow", "Start", nullptr));
        actionPause->setText(QApplication::translate("MainWindow", "Pause", nullptr));
        actionStop->setText(QApplication::translate("MainWindow", "Stop", nullptr));
        actionLog_to->setText(QApplication::translate("MainWindow", "Log to...", nullptr));
        actionFrequency->setText(QApplication::translate("MainWindow", "Frequency", nullptr));
        actionMode->setText(QApplication::translate("MainWindow", "Mode", nullptr));
        actionSave_data->setText(QApplication::translate("MainWindow", "Save raw data", nullptr));
        actionttyUSB0->setText(QApplication::translate("MainWindow", "ttyUSB0", nullptr));
        actionttyACM0->setText(QApplication::translate("MainWindow", "ttyACM0", nullptr));
        actionCSV->setText(QApplication::translate("MainWindow", "CSV", nullptr));
        actionClear->setText(QApplication::translate("MainWindow", "Clear", nullptr));
        actionScale->setText(QApplication::translate("MainWindow", "Scale", nullptr));
        actionSave_img->setText(QApplication::translate("MainWindow", "Save img", nullptr));
        actionClear_2->setText(QApplication::translate("MainWindow", "Clear", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuSetup->setTitle(QApplication::translate("MainWindow", "Setup", nullptr));
        menuPort->setTitle(QApplication::translate("MainWindow", "Port", nullptr));
        menuMeasure->setTitle(QApplication::translate("MainWindow", "Measure", nullptr));
        menuLog->setTitle(QApplication::translate("MainWindow", "Log", nullptr));
        menuFormat->setTitle(QApplication::translate("MainWindow", "Format", nullptr));
        menuGraph->setTitle(QApplication::translate("MainWindow", "Graph", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
