#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QClipboard>
#include <QTimer>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_upperCheckBox_toggled(bool checked) {
    ui->upperSpinBox->setEnabled(checked);
}

void MainWindow::on_lowerCheckBox_toggled(bool checked) {
    ui->lowerSpinBox->setEnabled(checked);
}

void MainWindow::on_numberCheckBox_toggled(bool checked) {
    ui->numberSpinBox->setEnabled(checked);
}

void MainWindow::on_specialCheckBox_toggled(bool checked) {
    ui->specialSpinBox->setEnabled(checked);
}

void MainWindow::on_minLengthCheckBox_toggled(bool checked) {
    ui->minLengthSpinBox->setEnabled(checked);
}

void MainWindow::on_passwordLineEdit_focused(bool hasFocus) {
    if(hasFocus) {
        QClipboard* clipboard = QApplication::clipboard();
        clipboard->setText(ui->passwordLineEdit->text(), QClipboard::Clipboard);

        if(clipboard->supportsSelection ()) {
            clipboard->setText(ui->passwordLineEdit->text(), QClipboard::Selection);
        }

        ui->statusBar->showMessage("Password Copied");
        QTimer::singleShot(3000, this, [ = ]() {
            ui->statusBar->showMessage ("");
        });

#if defined(Q_OS_LINUX)
        QThread::msleep(1);
#endif
    }
}

void MainWindow::on_generatePasswordButton_clicked() {
    ui->passwordLineEdit->setText("Success");
}

void MainWindow::getSettings() {

}

void MainWindow::setSetting(const QString& key, const QVariant& value) {

}
