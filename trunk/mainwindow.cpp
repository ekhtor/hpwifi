#include <QtGui/QApplication>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "dialog2.h"
#include <QListWidgetItem>
#include <QProcess>
#include <iostream>
#include <fstream>
#include <iostream>
#include <QDialog>
#include "ui_dialog.h"
#include "ui_mainwindow2.h"
#include "mainwindow2.h"
#include "string.h"
#include "stdio.h"
#include <QString>
#include <QCheckBox>
#include <QMessageBox>
#include "tinyxml.h"
#include <pthread.h>
#include "form.h"
using namespace std;
MainWindow2 *f;//=new MainWindow2();
int refresco=2;
string dir="";
QString aux;
string aux2;
bool interValida=false;
void *arg;
pthread_attr_t tattr;
pthread_t tid;

int ret;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    f=new MainWindow2();
    ui->setupUi(this);
    ui->tableWidget->setSortingEnabled(0);
    QProcess pro;
    QStringList argumentos;
    QString command = "cat aux";

    argumentos << "ls";
    system("ifconfig -a | egrep HW | cut -d' ' -f1 | sed -e '/^$/d;/^#$/d' >> aux");
    fstream fichero;
    char texto[200];
ui->comboBox_2->addItem("");
    fichero.open("aux", ios::in);
    fichero >> texto;           // Leo una primera linea
    while (!fichero.eof())      // Mientras se haya podido leer algo
    {
        //cout << texto <<":texto"<< endl;    // Muestro lo que lei
        ui->comboBox_2->addItem(texto);
        if (ui->textEdit_3->toPlainText() == ""){
            ui->textEdit_3->setText(texto);
        }
        else{
            ui->textEdit_3->setText(ui->textEdit_3->toPlainText() + "\n" + texto);
        }
        fichero >> texto;         // Y vuelvo a intentar leer
    }
    fichero.close();
    system("rm aux");


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // ui->;
}



void MainWindow::on_pushButton_2_clicked()
{


    ui->tableWidget->clearFocus();
    ui->tableWidget->clearMask();
    ui->tableWidget->clearContents();
    ui->tableWidget->clearSpans();
    ui->tableWidget->setSortingEnabled(0);

    //ui->tableWidget->setRowCount(10);
    //ui->tableWidget->setColumnCount(10);
    QString item[8];
    QTableWidgetItem *newItem;
    int i=0;
    int j=0;
    int pos=0;
    //for (int i = 0 ; i < 10; i++ ){
    //for (int j = 0 ; j < 10; j++){
    // QTableWidgetItem *newItem = new QTableWidgetItem((i+j).toString);
    //ui->tableWidget->setItem(i, j, newItem);
    // }
    //}

    TiXmlDocument doc;
    if ( !doc.LoadFile( "ejemplo10.xml" ) )  {
        cout <<"Error: Can't load file ejemplo.xml" << endl;
        //return EXIT_FAILURE;
    }
    else{
        string attribute, str_aux="";
        QString aux;
        TiXmlElement *element;
        element = doc.FirstChildElement( "detection-run" );
        TiXmlElement *wifi;
        wifi = element->FirstChildElement( "wireless-network");
        TiXmlElement *ssid;
        TiXmlElement *signal;
        TiXmlElement *paquetes;
        TiXmlElement *tmp;

        // ui->tableWidget->setRowCount(1);
        do{


            if ( wifi->Attribute( "number" ) != NULL )
                attribute = string ( wifi->Attribute( "number" ) );



            //PROCESO EL SSID PARA OBTENER EL NOMBRE
            ssid = wifi->FirstChildElement("SSID");
            tmp = ssid->FirstChildElement("essid");
            if ( tmp != NULL ){
                if ( tmp->FirstChild() != NULL ){
                    str_aux = string( ( ( tmp->FirstChild() )->ToText() )->Value() );
                }
                else{
                    str_aux ="";
                }
            }
            item[pos]=str_aux.c_str();
            pos++;

            //PROCESO LA SEÑAL PARA OBTENER LA POTENCIA
            signal=wifi->FirstChildElement("snr-info");
            tmp = signal->FirstChildElement("last_signal_dbm");
            if ( tmp != NULL ){
                if ( tmp->FirstChild() != NULL ){
                    str_aux = string( ( ( tmp->FirstChild() )->ToText() )->Value() );
                }
                else{
                    str_aux ="";
                }
            }

            item[pos]=str_aux.c_str();
            pos++;

            //PROCESO LOS PAQUETES PARA OBTENER LOS DATOS
            paquetes=wifi->FirstChildElement("packets");
            tmp = paquetes->FirstChildElement("data");
            if ( tmp != NULL )           {
                if ( tmp->FirstChild() != NULL ){
                    str_aux = string( ( ( tmp->FirstChild() )->ToText() )->Value() );
                }
                else{
                    str_aux ="";
                }
            }
            item[pos]=str_aux.c_str();
            pos++;

            //PROCESO LA SEÑAL PARA OBTENER EL CANAL
            tmp=wifi->FirstChildElement("channel");
            if ( tmp->FirstChild() != NULL ){
                str_aux = string( ( ( tmp->FirstChild() )->ToText() )->Value() );
                if (str_aux == "-1"){
                    wifi = wifi->NextSiblingElement("wireless-network");
                    pos=0;
                    // i++;
                    continue;
                    }
            }
            else{
                str_aux ="";
            }
            item[pos]=str_aux.c_str();
            pos++;


            //PROCESO LA SEÑAL PARA OBTENER LA ENCRIPTACION
            tmp=ssid->FirstChildElement("encryption");
            if ( tmp != NULL ){
                if ( tmp->FirstChild() != NULL ){
                    str_aux = string( ( ( tmp->FirstChild() )->ToText() )->Value() );
                }
                else{
                    str_aux ="";
                }
            }


            //if (aux2.length() >= 7){
            //string aux2 = str_aux.substr(4,7);//0.3
            //}
            // else{
            // if (str_aux.length() == 3){
            // string aux2 = str_aux.substr(0,3);
            //}
            //}
            // pos++;
            QString hola="WPA ";


            QString aux2 = str_aux.c_str();

            //if ( str_aux.find(aux2,0) == string::npos){ //cout<<"Noexiste" ;
            if ((aux2.contains(hola)) and ui->checkBox_wpa->checkState() ){
                //cout<<aux2.contains(hola);
                wifi = wifi->NextSiblingElement("wireless-network");
                pos=0;
                // i++;
                continue;
            }
            item[pos]=str_aux.c_str();
            pos++;




            //PROCESO  WIRELESS PARA OBTENER BSSID
            tmp=wifi->FirstChildElement("BSSID");
            if ( tmp != NULL ){
                if ( tmp->FirstChild() != NULL ){
                    str_aux = string( ( ( tmp->FirstChild() )->ToText() )->Value() );
                }
                else{
                    str_aux ="";
                }
            }

            item[pos]=str_aux.c_str();



            ui->tableWidget->setRowCount(i+1);
            wifi = wifi->NextSiblingElement("wireless-network");
            for (int x = 0 ; x < 7; x++ ){
                newItem = new QTableWidgetItem(item[x]);

                ui->tableWidget->setItem(i, x, newItem);
                item[x]="";
                //j++;

            }
            pos=0;
            i++;

        } while ( wifi );
    }
    ui->tableWidget->setFixedHeight(ui->tableWidget->height() + 234);
    /*int i=1;
    int j=3;
    QString s;
    s.sprintf("%d",i+j);
    QTableWidgetItem *newItem = new QTableWidgetItem(s);
    ui->tableWidget->setItem(0, 0, newItem);
    QTableWidgetItem *newItem2 = new QTableWidgetItem("dos");
    ui->tableWidget->setItem(0, 1, newItem2);
    QTableWidgetItem *newItem3 = new QTableWidgetItem("tres");
    ui->tableWidget->setItem(0, 2, newItem3);
    QTableWidgetItem *newItem4 = new QTableWidgetItem("cuatro");
    ui->tableWidget->setItem(1, 0, newItem4);
    QTableWidgetItem *newItem5 = new QTableWidgetItem("cinco");
    ui->tableWidget->setItem(1, 1, newItem5);
    QTableWidgetItem *newItem6 = new QTableWidgetItem("seis");
    ui->tableWidget->setItem(1, 2, newItem6);*/
    /*
    for (int i = 0 ; i < 10; i++ ){
    for (int j = 0 ; j < 10 ; j++){
        ui->tableWidget->setCellWidget(i,j,new QTextEdit);
    }}*/
    //new QListWidgetItem("item", listWidget);

    //ui->listWidget->addItem("otromas");

    // ui->tableWidget->
    //ui->tableWidget->setItem(1,1,new QTableWidgetItem);
    //ui->listWidget->add
    //ui->listWidget->addItem("hola");

}

void MainWindow::on_tableWidget_itemClicked(QTableWidgetItem* item)
{
    //ui->listWidget->addItem(item->text());
    //ui->tableWidget->item(item->row(),1);
    ui->listWidget->addItem(ui->tableWidget->item(item->row(),0)->text());
}




void MainWindow::on_pushButton_3_clicked()
{
    QProcess pro;
    QStringList argumentos;


    argumentos << "ls";

    pro.start("gksu",argumentos); //o puede ser kdesudo

    QByteArray res;

    //Esperamos a que acabe
    while (!pro.waitForFinished()){
    }
    res = pro.readAllStandardOutput();
    cout << QString(res).toLatin1().data() <<endl;
    //Para obtener el home y el nombre de usuario
    QString home = getenv("HOME");
    char *user = getenv("USER");

    //cout << home <<" "<< user << endl;

    ui->textEdit_2->setText(res);
    //Para obtener el uid del usuario actual
    cout << getuid() << endl;
}



void MainWindow::on_spinBox_valueChanged(int valor)
{
    refresco=valor;
    cout << refresco<<endl;

}

void MainWindow::on_pushButton_4_clicked()
{
    cout<<ui->spinBox->value()<<endl;
}

void MainWindow::on_pushButton_5_clicked()
{
    QProcess pro;
    QStringList argumentos;
    QString command = "cat aux";

    argumentos << "ls";
    system("ifconfig -a | egrep HW | cut -d' ' -f1 | sed -e '/^$/d;/^#$/d' >> aux");
    //system("firefox >> aux2 &");
    /* pro.start(command); //o puede ser kdesudo
    if (system("yum install jander") > 0){
        cout<<"error"<<endl;
    }

    QByteArray res;

    //Esperamos a que acabe
    while (!pro.waitForFinished()){
    }
    res = pro.readAllStandardOutput();
    cout << QString(res).toLatin1().data() <<endl;
    //Para obtener el home y el nombre de usuario
   // QString home = getenv("HOME");
    //char *user = getenv("USER");

    //cout << home <<" "<< user << endl;

    ui->textEdit_2->setText(res);*/

    fstream fichero;
    char texto[200];
    // Abro para lectura
    fichero.open("aux", ios::in);
    fichero >> texto;           // Leo una primera linea
    while (!fichero.eof())      // Mientras se haya podido leer algo
    {
        //cout << texto <<":texto"<< endl;    // Muestro lo que lei
        ui->comboBox_2->addItem(texto);
        if (ui->textEdit_3->toPlainText() == ""){
            ui->textEdit_3->setText(texto);
        }
        else{
            ui->textEdit_3->setText(ui->textEdit_3->toPlainText() + "\n" + texto);
        }
        fichero >> texto;         // Y vuelvo a intentar leer
    }
    fichero.close();

    // ui->textEdit_3->setText();


    system("rm aux");
    //Para obtener el uid del usuario actual
    //cout << getuid() << endl;

}

void MainWindow::on_pushButton_6_clicked()
{
    //ui->comboBox_2->addItem("wlan0");



}

void MainWindow::on_pushButton_7_clicked()
{

    Dialog *d = new Dialog;
    if (d->exec()){
        ui->comboBox_2->addItem("dialogo accepted");
    }
    else{
        ui->comboBox_2->addItem("dialogo rejected");
    }
} /*fichero = popen (texto.c_str(), "r");
                if (fichero == NULL)
                {
                        perror ("Fallo en la ejecución del comando airmon-ng");
                        //exit (-1);
                }


               fgets (aux, 100, fichero);
               while (!feof (fichero)){
                     monInter[i]=aux;i++;
                     cout << aux << endl;
                     fgets (aux, 100, fichero);
                     }


               pclose (fichero);*/


void MainWindow::on_pushButton_8_clicked()
{




    f->show();
    // Dialog2 d2;
    //d2.exec();

}



void MainWindow::on_pushButton_9_clicked()
{
    QMessageBox msgBox(QMessageBox::Warning, trUtf8("QMessageBox::warning()"),
                       trUtf8("Este es un mensaje de advertencia"), 0, this);
    msgBox.exec();


}







void MainWindow::on_pushButton_10_clicked()
{

    //do{
    //sleep(5);
    on_pushButton_2_clicked();
    //}while(true);
}



/*
void MainWindow::on_comboBox_2_textChanged(){

QMessageBox msgBox;

msgBox.setText("holahola");
msgBox.addButton("fuera",QMessageBox::AcceptRole);
msgBox.exec();
}*/

void MainWindow::on_comboBox_2_activated(QString )
{
    string monInter[20]="";
    int i=0;
    if (ui->comboBox_2->itemText(0) == "") {
    ui->comboBox_2->removeItem(0);
    }

    system("iwconfig > .interfaces");

    FILE *fichero=NULL;


            char aux[100]="";
            fichero = popen ("egrep  Mode:Monitor .interfaces |cut -d' ' -f1", "r");
            if (fichero == NULL)
            {
                    perror ("Fallo en la ejecución del comando egrep & cut");
                    //exit (-1);
            }


           fgets (aux, 100, fichero);
           while (!feof (fichero)){
                 monInter[i]=aux;i++;
                 fgets (aux, 100, fichero);
                 }


           pclose (fichero);

    string interSelec="";
    bool esMon=false;
    interSelec=ui->comboBox_2->currentText().toStdString();
   // cout << interSelec.length()<<monInter[0].length()<< endl;

    for (int j=0;j<i;j++){
        if (interSelec.substr(0,interSelec.length()) == monInter[j].substr(0,monInter[j].length()-1)){
            esMon=true;
        }
    }

    if (!esMon){
    QMessageBox msgBox;
    string texto="La interfaz "+ interSelec +  " no se encuentra en modo monitor.\nPulsa aceptar para activarla";
    msgBox.setText(texto.c_str());
    msgBox.addButton("Cancelar",QMessageBox::RejectRole);
    msgBox.addButton("Aceptar",QMessageBox::AcceptRole);


            if (msgBox.exec()){
                texto= "airmon-ng start " + interSelec +" >> "+ dir + ".interfacesmon";
                //sleep(3);

                system("rm .interfacesmon");

                system(texto.c_str());
                texto="egrep 'monitor mode enabled' "+ dir + ".interfacesmon | cut -d' ' -f5 | cut -d')' -f1 >> "+ dir + ".intersel";
                system(texto.c_str());
                string inter="";
                int count = 0;

                while (inter == "" and count < 4){
                fstream fichero;
                char textoFich[200];
                // Abro para lectura
                fichero.open(".intersel", ios::in);
                fichero >> textoFich;           // Leo una primera linea
                while (!fichero.eof())      // Mientras se haya podido leer algo
                {
                    inter = textoFich;
                    //cout << textoFich;// << endl;    // Muestro lo que lei
                    fichero >> textoFich;         // Y vuelvo a intentar leer

                }
                fichero.close();
                sleep(1);count++;

                }
                system("rm .intersel");
                if (inter == ""){
                    QMessageBox msgBox2;
                    msgBox2.setText("No es posible habilitar el modo monitor en esta interfaz.\nSelecciona otra.");
                    msgBox2.addButton("Aceptar",QMessageBox::AcceptRole);
                    msgBox2.exec();
                }
                else{
                    ui->comboBox_2->addItem(inter.c_str());
                    ui->comboBox_2->setCurrentIndex(ui->comboBox_2->count()-1);
                    interValida=true;

                }

            }
            else{
                interValida=false;
            }
    }
}
void MainWindow::start_routine(void *arg){
    while (1){
    system("ls");
    }
}

void MainWindow::on_pushButton_11_clicked()
{

    /* default behavior*/
    //ret = pthread_create(&tid, NULL, MainWindow::start_routine*, arg);

    /* initialized with default attributes */
    //ret = pthread_attr_init(&tattr);
    /* default behavior specified*/
    //ret = pthread_create(&tid, &tattr, start_routine, arg);
}
