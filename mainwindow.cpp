#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <hamming_encoding.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_codeButton_clicked()
{
    QString text = ui->inputText->text();
    text = Encode_to_Hamming(text, ui->blockSize->text().toInt());
    ui->codedText->setText(text);
}
