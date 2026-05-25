#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QtGlobal>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    bool okA = false;
    bool okB = false;
    bool okC = false;

    double a = ui->le_a->text().toDouble(&okA);
    double b = ui->le_b->text().toDouble(&okB);
    double c = ui->le_c->text().toDouble(&okC);

    if (!okA || !okB || !okC) {
        QMessageBox::warning(this, "Error", "Please enter valid numeric values for A, B, and C.");
        if (!okA) ui->le_a->clear();
        if (!okB) ui->le_b->clear();
        if (!okC) ui->le_c->clear();
        ui->l_ac->setText("0");
        ui->l_bc->setText("0");
        ui->l_sum->setText("0");
        ui->le_a->setFocus();
        return;
    }

    double ac = qAbs(a - c);
    double bc = qAbs(b - c);
    double sum = ac + bc;

    ui->l_ac->setText(QString::number(ac));
    ui->l_bc->setText(QString::number(bc));
    ui->l_sum->setText(QString::number(sum));
}

void MainWindow::on_actionLoad_from_file_triggered()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Open file",
                                                    QDir::currentPath(), "Text files (*.txt);;All files (*)");
    if (filePath.isEmpty()) {
        return;
    }

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Cannot open file!");
        return;
    }

    QTextStream in(&file);
    QString sa, sb, sc;
    in >> sa >> sb >> sc;
    file.close();

    if (sa.isEmpty() || sb.isEmpty() || sc.isEmpty()) {
        QMessageBox::warning(this, "Error", "File must contain three numeric values.");
        return;
    }

    ui->le_a->setText(sa);
    ui->le_b->setText(sb);
    ui->le_c->setText(sc);
}

void MainWindow::on_actionSave_to_file_triggered()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Save file",
                                                    QDir::currentPath(), "Text files (*.txt);;All files (*)");
    if (filePath.isEmpty()) {
        return;
    }

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error",
                              "Cannot open file:\n" + file.errorString());
        return;
    }

    QTextStream out(&file);
    out << "A=" << ui->le_a->text() << "\n";
    out << "B=" << ui->le_b->text() << "\n";
    out << "C=" << ui->le_c->text() << "\n";
    out << "AC=" << ui->l_ac->text() << "\n";
    out << "BC=" << ui->l_bc->text() << "\n";
    out << "AC+BC=" << ui->l_sum->text() << "\n";
    file.close();
}
