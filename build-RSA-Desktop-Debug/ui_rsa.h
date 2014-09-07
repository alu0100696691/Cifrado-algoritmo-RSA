/********************************************************************************
** Form generated from reading UI file 'rsa.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RSA_H
#define UI_RSA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RSA
{
public:
    QWidget *centralWidget;
    QFrame *panel1;
    QLabel *label_2;
    QLineEdit *pw;
    QLineEdit *qW;
    QLabel *label_3;
    QLineEdit *dw;
    QLabel *label_4;
    QLabel *label_5;
    QTextEdit *textow;
    QLineEdit *nAleatoriosw;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *fiw;
    QLabel *label_10;
    QLineEdit *ew;
    QPushButton *ejecutar;
    QPushButton *ejecutar_2;
    QFrame *panel1_2;
    QLabel *label_6;
    QTextEdit *salidaw;
    QLabel *label_7;
    QTextEdit *cifradow;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RSA)
    {
        if (RSA->objectName().isEmpty())
            RSA->setObjectName(QStringLiteral("RSA"));
        RSA->resize(1307, 643);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RSA->sizePolicy().hasHeightForWidth());
        RSA->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(RSA);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        panel1 = new QFrame(centralWidget);
        panel1->setObjectName(QStringLiteral("panel1"));
        panel1->setGeometry(QRect(20, 10, 521, 471));
        panel1->setFrameShape(QFrame::Panel);
        panel1->setFrameShadow(QFrame::Raised);
        panel1->setLineWidth(5);
        panel1->setMidLineWidth(5);
        label_2 = new QLabel(panel1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 20, 21, 17));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        pw = new QLineEdit(panel1);
        pw->setObjectName(QStringLiteral("pw"));
        pw->setGeometry(QRect(40, 20, 113, 27));
        qW = new QLineEdit(panel1);
        qW->setObjectName(QStringLiteral("qW"));
        qW->setGeometry(QRect(210, 20, 113, 27));
        label_3 = new QLabel(panel1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(190, 20, 21, 17));
        label_3->setFont(font);
        dw = new QLineEdit(panel1);
        dw->setObjectName(QStringLiteral("dw"));
        dw->setGeometry(QRect(380, 20, 113, 27));
        label_4 = new QLabel(panel1);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(360, 20, 21, 17));
        label_4->setFont(font);
        label_5 = new QLabel(panel1);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(200, 100, 121, 17));
        label_5->setFont(font);
        textow = new QTextEdit(panel1);
        textow->setObjectName(QStringLiteral("textow"));
        textow->setGeometry(QRect(30, 120, 471, 331));
        nAleatoriosw = new QLineEdit(panel1);
        nAleatoriosw->setObjectName(QStringLiteral("nAleatoriosw"));
        nAleatoriosw->setGeometry(QRect(40, 80, 111, 27));
        label_8 = new QLabel(panel1);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 60, 121, 17));
        label_8->setFont(font);
        label_9 = new QLabel(panel1);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(340, 60, 31, 17));
        label_9->setFont(font);
        fiw = new QLineEdit(panel1);
        fiw->setObjectName(QStringLiteral("fiw"));
        fiw->setEnabled(false);
        fiw->setGeometry(QRect(380, 60, 113, 27));
        label_10 = new QLabel(panel1);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(180, 60, 31, 17));
        label_10->setFont(font);
        ew = new QLineEdit(panel1);
        ew->setObjectName(QStringLiteral("ew"));
        ew->setEnabled(false);
        ew->setGeometry(QRect(210, 60, 113, 27));
        ejecutar = new QPushButton(centralWidget);
        ejecutar->setObjectName(QStringLiteral("ejecutar"));
        ejecutar->setGeometry(QRect(810, 510, 201, 51));
        ejecutar->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/ejecutar.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        ejecutar->setIcon(icon);
        ejecutar->setIconSize(QSize(36, 36));
        ejecutar_2 = new QPushButton(centralWidget);
        ejecutar_2->setObjectName(QStringLiteral("ejecutar_2"));
        ejecutar_2->setGeometry(QRect(1040, 510, 201, 51));
        ejecutar_2->setFont(font);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/prefix1/exit.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        ejecutar_2->setIcon(icon1);
        ejecutar_2->setIconSize(QSize(27, 27));
        panel1_2 = new QFrame(centralWidget);
        panel1_2->setObjectName(QStringLiteral("panel1_2"));
        panel1_2->setGeometry(QRect(550, 10, 741, 471));
        panel1_2->setFrameShape(QFrame::Panel);
        panel1_2->setFrameShadow(QFrame::Raised);
        panel1_2->setLineWidth(5);
        panel1_2->setMidLineWidth(5);
        label_6 = new QLabel(panel1_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 10, 67, 17));
        label_6->setFont(font);
        salidaw = new QTextEdit(panel1_2);
        salidaw->setObjectName(QStringLiteral("salidaw"));
        salidaw->setGeometry(QRect(10, 30, 721, 301));
        label_7 = new QLabel(panel1_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 340, 131, 17));
        label_7->setFont(font);
        cifradow = new QTextEdit(panel1_2);
        cifradow->setObjectName(QStringLiteral("cifradow"));
        cifradow->setGeometry(QRect(10, 360, 721, 91));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setEnabled(false);
        label->setGeometry(QRect(180, 490, 221, 101));
        QPalette palette;
        QBrush brush(QColor(0, 0, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        QBrush brush1(QColor(159, 158, 158, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        label->setPalette(palette);
        QFont font1;
        font1.setPointSize(82);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setWeight(75);
        font1.setStrikeOut(false);
        font1.setKerning(true);
        label->setFont(font1);
        RSA->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(RSA);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1307, 25));
        RSA->setMenuBar(menuBar);
        mainToolBar = new QToolBar(RSA);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        RSA->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(RSA);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        RSA->setStatusBar(statusBar);

        retranslateUi(RSA);

        QMetaObject::connectSlotsByName(RSA);
    } // setupUi

    void retranslateUi(QMainWindow *RSA)
    {
        RSA->setWindowTitle(QApplication::translate("RSA", "RSA", 0));
        label_2->setText(QApplication::translate("RSA", "P:", 0));
        pw->setText(QApplication::translate("RSA", "2347", 0));
        qW->setText(QApplication::translate("RSA", "347", 0));
        label_3->setText(QApplication::translate("RSA", "Q:", 0));
        dw->setText(QApplication::translate("RSA", "5", 0));
        label_4->setText(QApplication::translate("RSA", "D:", 0));
        label_5->setText(QApplication::translate("RSA", "TEXTO A CIFRAR:", 0));
        textow->setHtml(QApplication::translate("RSA", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">amigo mio</p></body></html>", 0));
        nAleatoriosw->setText(QApplication::translate("RSA", "100", 0));
        label_8->setText(QApplication::translate("RSA", "N\302\272 ALEATORIOS:", 0));
        label_9->setText(QApplication::translate("RSA", "0(n):", 0));
        fiw->setText(QString());
        label_10->setText(QApplication::translate("RSA", "e:", 0));
        ew->setText(QString());
        ejecutar->setText(QApplication::translate("RSA", "EJECUTAR", 0));
        ejecutar_2->setText(QApplication::translate("RSA", "SALIR", 0));
        label_6->setText(QApplication::translate("RSA", "SALIDA:", 0));
        label_7->setText(QApplication::translate("RSA", "TEXTO CIFRADO:", 0));
        label->setText(QApplication::translate("RSA", "RSA", 0));
    } // retranslateUi

};

namespace Ui {
    class RSA: public Ui_RSA {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RSA_H
