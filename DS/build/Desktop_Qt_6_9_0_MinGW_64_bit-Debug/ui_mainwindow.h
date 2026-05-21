/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QWidget *sidebarWidget;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QLabel *sidebarTitleLabel;
    QPushButton *addEdgeButton;
    QPushButton *addCityButton;
    QPushButton *graphTraverseButton;
    QPushButton *shortestButton;
    QPushButton *loadButton;
    QPushButton *deleteButton;
    QPushButton *displayButton;
    QPushButton *exitButton;
    QSpacerItem *verticalSpacer;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox_2;
    QLabel *label_2;
    QLineEdit *frcityEdit;
    QLabel *label_3;
    QLineEdit *secityEdit;
    QPushButton *edgeButton;
    QLabel *label_4;
    QLineEdit *distanceEdit;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox;
    QLineEdit *cityEdit;
    QPushButton *cityButton;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_5;
    QComboBox *startBox;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *bfsButton;
    QRadioButton *dfsButton;
    QPushButton *traverseButton;
    QTextEdit *resultTraverse;
    QWidget *page_4;
    QVBoxLayout *verticalLayout_8;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_3;
    QTextEdit *resultShortest;
    QLabel *label_6;
    QComboBox *sourceBox;
    QComboBox *destinationBox;
    QPushButton *findButton;
    QRadioButton *shortradioButton;
    QRadioButton *cheapradioButton;
    QWidget *page_5;
    QVBoxLayout *verticalLayout_10;
    QWidget *widget;
    QVBoxLayout *verticalLayout_11;
    QPlainTextEdit *loadResultText;
    QWidget *page_6;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_8;
    QWidget *page_7;
    QVBoxLayout *verticalLayout_12;
    QGroupBox *groupBox_5;
    QLineEdit *deleteVertexInput;
    QPushButton *deletevertexButton;
    QGroupBox *groupBox_6;
    QLineEdit *deleteEdgeV1Input;
    QLineEdit *deleteEdgeV2Input;
    QPushButton *deleteedgeButton;
    QWidget *page_8;
    QVBoxLayout *verticalLayout_13;
    QGroupBox *groupBox_7;
    QVBoxLayout *verticalLayout_14;
    QTextEdit *graphDisplayTextEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(802, 597);
        MainWindow->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #34495e;\n"
"    color: #ffffff;\n"
"    border-radius: 5px;\n"
"    padding: 8px;\n"
"    text-align: center;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #4a657d;\n"
"}\n"
"QWidget#sidebarWidget {\n"
"  \n"
"\n"
"	background-color: rgb(238, 238, 238);\n"
"    border: 2px solid #1a2836;}\n"
"QLabel {\n"
"\n"
"     color: #34495e;\n"
"     font-size: 18px;\n"
"     font-weight: bold;\n"
"     text-align: center;\n"
"     margin-bottom: 10px;\n"
"}\n"
"QMainWindow {\n"
"    background-color: white;\n"
"}\n"
"\n"
"#leftPanel {\n"
"    background-color: #2c3e50;\n"
"}\n"
"\n"
"#headerLabel {\n"
"    background-color: #3498db;\n"
"    color: white;\n"
"}\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        sidebarWidget = new QWidget(centralwidget);
        sidebarWidget->setObjectName("sidebarWidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sidebarWidget->sizePolicy().hasHeightForWidth());
        sidebarWidget->setSizePolicy(sizePolicy);
        sidebarWidget->setMinimumSize(QSize(200, 0));
        sidebarWidget->setMaximumSize(QSize(200, 16777215));
        verticalLayout = new QVBoxLayout(sidebarWidget);
        verticalLayout->setObjectName("verticalLayout");
        frame = new QFrame(sidebarWidget);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Plain);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName("verticalLayout_2");
        sidebarTitleLabel = new QLabel(frame);
        sidebarTitleLabel->setObjectName("sidebarTitleLabel");

        verticalLayout_2->addWidget(sidebarTitleLabel);

        addEdgeButton = new QPushButton(frame);
        addEdgeButton->setObjectName("addEdgeButton");

        verticalLayout_2->addWidget(addEdgeButton);

        addCityButton = new QPushButton(frame);
        addCityButton->setObjectName("addCityButton");

        verticalLayout_2->addWidget(addCityButton);

        graphTraverseButton = new QPushButton(frame);
        graphTraverseButton->setObjectName("graphTraverseButton");

        verticalLayout_2->addWidget(graphTraverseButton);

        shortestButton = new QPushButton(frame);
        shortestButton->setObjectName("shortestButton");

        verticalLayout_2->addWidget(shortestButton);

        loadButton = new QPushButton(frame);
        loadButton->setObjectName("loadButton");
        loadButton->setMinimumSize(QSize(100, 0));

        verticalLayout_2->addWidget(loadButton);

        deleteButton = new QPushButton(frame);
        deleteButton->setObjectName("deleteButton");

        verticalLayout_2->addWidget(deleteButton);

        displayButton = new QPushButton(frame);
        displayButton->setObjectName("displayButton");

        verticalLayout_2->addWidget(displayButton);

        exitButton = new QPushButton(frame);
        exitButton->setObjectName("exitButton");
        exitButton->setStyleSheet(QString::fromUtf8("background-color: rgb(234, 47, 30);"));

        verticalLayout_2->addWidget(exitButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        verticalLayout->addWidget(frame);


        horizontalLayout->addWidget(sidebarWidget);

        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName("frame_2");
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        label = new QLabel(frame_2);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("background-color: #3498db; color: white; font-size: 24px; font-weight: bold; padding: 15px;\n"
""));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_3->addWidget(label);

        stackedWidget = new QStackedWidget(frame_2);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setStyleSheet(QString::fromUtf8("color: #34495e;\n"
"background-color: rgb(238, 238, 238);"));
        page = new QWidget();
        page->setObjectName("page");
        verticalLayout_5 = new QVBoxLayout(page);
        verticalLayout_5->setObjectName("verticalLayout_5");
        groupBox_2 = new QGroupBox(page);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setStyleSheet(QString::fromUtf8("color: #34495e;\n"
"background-color: rgb(238, 238, 238);"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 50, 101, 31));
        frcityEdit = new QLineEdit(groupBox_2);
        frcityEdit->setObjectName("frcityEdit");
        frcityEdit->setGeometry(QRect(20, 90, 411, 31));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 140, 111, 31));
        secityEdit = new QLineEdit(groupBox_2);
        secityEdit->setObjectName("secityEdit");
        secityEdit->setGeometry(QRect(20, 180, 411, 31));
        edgeButton = new QPushButton(groupBox_2);
        edgeButton->setObjectName("edgeButton");
        edgeButton->setGeometry(QRect(400, 350, 93, 29));
        edgeButton->setStyleSheet(QString::fromUtf8(" background-color: #34495e;\n"
"    color: #ffffff;\n"
"    border-radius: 5px;\n"
"    padding: 8px;\n"
"    text-align: center;"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 230, 101, 31));
        distanceEdit = new QLineEdit(groupBox_2);
        distanceEdit->setObjectName("distanceEdit");
        distanceEdit->setGeometry(QRect(20, 270, 411, 31));

        verticalLayout_5->addWidget(groupBox_2);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        verticalLayout_4 = new QVBoxLayout(page_2);
        verticalLayout_4->setObjectName("verticalLayout_4");
        groupBox = new QGroupBox(page_2);
        groupBox->setObjectName("groupBox");
        groupBox->setStyleSheet(QString::fromUtf8("color: #34495e;\n"
"background-color: rgb(238, 238, 238);"));
        cityEdit = new QLineEdit(groupBox);
        cityEdit->setObjectName("cityEdit");
        cityEdit->setGeometry(QRect(22, 80, 301, 26));
        cityButton = new QPushButton(groupBox);
        cityButton->setObjectName("cityButton");
        cityButton->setGeometry(QRect(340, 330, 154, 36));
        cityButton->setMinimumSize(QSize(100, 0));
        cityButton->setStyleSheet(QString::fromUtf8(" background-color: #34495e;\n"
"    color: #ffffff;\n"
"    border-radius: 5px;\n"
"    padding: 8px;\n"
"    text-align: center;\n"
""));

        verticalLayout_4->addWidget(groupBox);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        verticalLayout_6 = new QVBoxLayout(page_3);
        verticalLayout_6->setObjectName("verticalLayout_6");
        groupBox_3 = new QGroupBox(page_3);
        groupBox_3->setObjectName("groupBox_3");
        verticalLayout_7 = new QVBoxLayout(groupBox_3);
        verticalLayout_7->setObjectName("verticalLayout_7");
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName("label_5");

        verticalLayout_7->addWidget(label_5);

        startBox = new QComboBox(groupBox_3);
        startBox->setObjectName("startBox");

        verticalLayout_7->addWidget(startBox);

        frame_3 = new QFrame(groupBox_3);
        frame_3->setObjectName("frame_3");
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_3);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        bfsButton = new QRadioButton(frame_3);
        bfsButton->setObjectName("bfsButton");

        horizontalLayout_2->addWidget(bfsButton);

        dfsButton = new QRadioButton(frame_3);
        dfsButton->setObjectName("dfsButton");

        horizontalLayout_2->addWidget(dfsButton);


        verticalLayout_7->addWidget(frame_3);

        traverseButton = new QPushButton(groupBox_3);
        traverseButton->setObjectName("traverseButton");
        traverseButton->setMinimumSize(QSize(150, 0));
        traverseButton->setMaximumSize(QSize(150, 16777215));
        traverseButton->setStyleSheet(QString::fromUtf8(" background-color: #34495e;\n"
"    color: #ffffff;\n"
"    border-radius: 5px;\n"
"    padding: 8px;\n"
"    text-align: center;\n"
""));

        verticalLayout_7->addWidget(traverseButton);

        resultTraverse = new QTextEdit(groupBox_3);
        resultTraverse->setObjectName("resultTraverse");
        resultTraverse->setStyleSheet(QString::fromUtf8("visibile:none"));
        resultTraverse->setReadOnly(true);

        verticalLayout_7->addWidget(resultTraverse);


        verticalLayout_6->addWidget(groupBox_3);

        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        verticalLayout_8 = new QVBoxLayout(page_4);
        verticalLayout_8->setObjectName("verticalLayout_8");
        groupBox_4 = new QGroupBox(page_4);
        groupBox_4->setObjectName("groupBox_4");
        gridLayout = new QGridLayout(groupBox_4);
        gridLayout->setObjectName("gridLayout");
        horizontalSpacer_2 = new QSpacerItem(148, 38, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName("label_7");

        gridLayout->addWidget(label_7, 1, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(148, 38, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 2, 1, 1);

        resultShortest = new QTextEdit(groupBox_4);
        resultShortest->setObjectName("resultShortest");

        gridLayout->addWidget(resultShortest, 4, 0, 1, 3);

        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName("label_6");

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        sourceBox = new QComboBox(groupBox_4);
        sourceBox->setObjectName("sourceBox");

        gridLayout->addWidget(sourceBox, 0, 1, 1, 1);

        destinationBox = new QComboBox(groupBox_4);
        destinationBox->setObjectName("destinationBox");

        gridLayout->addWidget(destinationBox, 1, 1, 1, 1);

        findButton = new QPushButton(groupBox_4);
        findButton->setObjectName("findButton");
        findButton->setStyleSheet(QString::fromUtf8(" background-color: #34495e;\n"
"    color: #ffffff;\n"
"    border-radius: 5px;\n"
"    padding: 8px;\n"
"    text-align: center;\n"
""));

        gridLayout->addWidget(findButton, 3, 0, 1, 1);

        shortradioButton = new QRadioButton(groupBox_4);
        shortradioButton->setObjectName("shortradioButton");

        gridLayout->addWidget(shortradioButton, 2, 0, 1, 1);

        cheapradioButton = new QRadioButton(groupBox_4);
        cheapradioButton->setObjectName("cheapradioButton");

        gridLayout->addWidget(cheapradioButton, 2, 1, 1, 1);


        verticalLayout_8->addWidget(groupBox_4);

        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        verticalLayout_10 = new QVBoxLayout(page_5);
        verticalLayout_10->setObjectName("verticalLayout_10");
        widget = new QWidget(page_5);
        widget->setObjectName("widget");
        verticalLayout_11 = new QVBoxLayout(widget);
        verticalLayout_11->setObjectName("verticalLayout_11");
        loadResultText = new QPlainTextEdit(widget);
        loadResultText->setObjectName("loadResultText");

        verticalLayout_11->addWidget(loadResultText);


        verticalLayout_10->addWidget(widget);

        stackedWidget->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName("page_6");
        page_6->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_9 = new QVBoxLayout(page_6);
        verticalLayout_9->setObjectName("verticalLayout_9");
        label_8 = new QLabel(page_6);
        label_8->setObjectName("label_8");
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/icons/main.png")));
        label_8->setScaledContents(true);

        verticalLayout_9->addWidget(label_8);

        stackedWidget->addWidget(page_6);
        page_7 = new QWidget();
        page_7->setObjectName("page_7");
        verticalLayout_12 = new QVBoxLayout(page_7);
        verticalLayout_12->setObjectName("verticalLayout_12");
        groupBox_5 = new QGroupBox(page_7);
        groupBox_5->setObjectName("groupBox_5");
        deleteVertexInput = new QLineEdit(groupBox_5);
        deleteVertexInput->setObjectName("deleteVertexInput");
        deleteVertexInput->setGeometry(QRect(30, 70, 251, 26));
        deletevertexButton = new QPushButton(groupBox_5);
        deletevertexButton->setObjectName("deletevertexButton");
        deletevertexButton->setGeometry(QRect(400, 130, 93, 29));
        deletevertexButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);\n"
"    color: #ffffff;\n"
"    border-radius: 5px;\n"
"    padding: 8px;\n"
"    text-align: center;"));

        verticalLayout_12->addWidget(groupBox_5);

        groupBox_6 = new QGroupBox(page_7);
        groupBox_6->setObjectName("groupBox_6");
        deleteEdgeV1Input = new QLineEdit(groupBox_6);
        deleteEdgeV1Input->setObjectName("deleteEdgeV1Input");
        deleteEdgeV1Input->setGeometry(QRect(30, 50, 231, 26));
        deleteEdgeV2Input = new QLineEdit(groupBox_6);
        deleteEdgeV2Input->setObjectName("deleteEdgeV2Input");
        deleteEdgeV2Input->setGeometry(QRect(30, 100, 231, 26));
        deleteedgeButton = new QPushButton(groupBox_6);
        deleteedgeButton->setObjectName("deleteedgeButton");
        deleteedgeButton->setGeometry(QRect(410, 140, 93, 29));
        deleteedgeButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);\n"
"    color: #ffffff;\n"
"    border-radius: 5px;\n"
"    padding: 8px;\n"
"    text-align: center;"));

        verticalLayout_12->addWidget(groupBox_6);

        stackedWidget->addWidget(page_7);
        page_8 = new QWidget();
        page_8->setObjectName("page_8");
        verticalLayout_13 = new QVBoxLayout(page_8);
        verticalLayout_13->setObjectName("verticalLayout_13");
        groupBox_7 = new QGroupBox(page_8);
        groupBox_7->setObjectName("groupBox_7");
        verticalLayout_14 = new QVBoxLayout(groupBox_7);
        verticalLayout_14->setObjectName("verticalLayout_14");
        graphDisplayTextEdit = new QTextEdit(groupBox_7);
        graphDisplayTextEdit->setObjectName("graphDisplayTextEdit");

        verticalLayout_14->addWidget(graphDisplayTextEdit);


        verticalLayout_13->addWidget(groupBox_7);

        stackedWidget->addWidget(page_8);

        verticalLayout_3->addWidget(stackedWidget);


        horizontalLayout->addWidget(frame_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 802, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        sidebarTitleLabel->setText(QCoreApplication::translate("MainWindow", "Program Menu", nullptr));
        addEdgeButton->setText(QCoreApplication::translate("MainWindow", "AddEdge", nullptr));
        addCityButton->setText(QCoreApplication::translate("MainWindow", "AddCity", nullptr));
        graphTraverseButton->setText(QCoreApplication::translate("MainWindow", "GraphTraverse", nullptr));
        shortestButton->setText(QCoreApplication::translate("MainWindow", "Path", nullptr));
        loadButton->setText(QCoreApplication::translate("MainWindow", "SaveandLoad", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        displayButton->setText(QCoreApplication::translate("MainWindow", "DisplayGraph", nullptr));
        exitButton->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "          Mini \331\210\330\265\331\204\331\206\331\212 ", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Add Edge", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "First City:", nullptr));
        frcityEdit->setText(QString());
        frcityEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Cairo", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Secod City:", nullptr));
        secityEdit->setText(QString());
        secityEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Alex", nullptr));
        edgeButton->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Distance:", nullptr));
        distanceEdit->setText(QString());
        distanceEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "100", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Add City", nullptr));
        cityEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Cairo", nullptr));
        cityButton->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Traversal", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "StartCity:", nullptr));
        bfsButton->setText(QCoreApplication::translate("MainWindow", "BFS", nullptr));
        dfsButton->setText(QCoreApplication::translate("MainWindow", "DFS", nullptr));
        traverseButton->setText(QCoreApplication::translate("MainWindow", "Traverse", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Explore your path", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Destination city:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Source city:", nullptr));
        findButton->setText(QCoreApplication::translate("MainWindow", "Find path", nullptr));
        shortradioButton->setText(QCoreApplication::translate("MainWindow", "Shortest path", nullptr));
        cheapradioButton->setText(QCoreApplication::translate("MainWindow", "cheapest path", nullptr));
        label_8->setText(QString());
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "Deletevertex", nullptr));
        deleteVertexInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "city  ", nullptr));
        deletevertexButton->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "Deleteedge", nullptr));
        deleteEdgeV1Input->setPlaceholderText(QCoreApplication::translate("MainWindow", "cityName", nullptr));
        deleteEdgeV2Input->setPlaceholderText(QCoreApplication::translate("MainWindow", "cityName", nullptr));
        deleteedgeButton->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("MainWindow", "Displaygraph", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
