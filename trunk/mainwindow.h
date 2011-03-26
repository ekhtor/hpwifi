#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QTableWidgetItem>


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:

    //void on_tableWidget_clicked(QModelIndex index);

    void on_pushButton_10_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_4_clicked();
    void on_spinBox_valueChanged(int );
    void on_pushButton_3_clicked();
    void on_tableWidget_itemClicked(QTableWidgetItem* item);
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_comboBox_2_currentIndexChanged(int index);
    void on_comboBox_2_textChanged(QString );
    void on_comboBox_2_activated(QString );
    void on_comboBox_2_editTextChanged(QString );
    void on_comboBox_2_activated(int index);
    void on_comboBox_2_highlighted(int index);
    void on_comboBox_2_highlighted(QString );
    void on_pushButton_11_clicked();
    void start_routine(void *arg);
};

#endif // MAINWINDOW_H
