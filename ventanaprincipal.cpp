#include "ventanaprincipal.h"
#include "ui_ventanaprincipal.h"

ventanaPrincipal::ventanaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ventanaPrincipal)
{
    ui->setupUi(this);
    crearCarpetaGrabacion();
    this->disparos=0;
    this->timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(ejecutar()));
    ui->informacion->setText("Bienvenido");
}

ventanaPrincipal::~ventanaPrincipal()
{
    delete ui;
}

void ventanaPrincipal::on_salir_clicked()
{
    qApp->quit();
}




void ventanaPrincipal::crearCarpetaGrabacion()
{
    system("mkdir $HOME/webc");
}




void ventanaPrincipal::ejecutar()
{
    QDateTime dateTime = dateTime.currentDateTime();
    QString dateTimeString = dateTime.toString("yyyy-MM-dd hh:mm:ss");
    dateTimeString.replace(" ","");
    std::string time_now = "ffmpeg  -f video4linux2 -i /dev/video0 -f alsa -i hw:0 -acodec mp2 -qscale 0 -t 55 $HOME/webc/"+dateTimeString.toStdString()+".avi ";
    qDebug() << QString(time_now.c_str());
    system(time_now.c_str());
    this->disparos -= 1;
    if(disparos==0){
        timer->stop();
         ui->informacion->setText("Finalizado "+QString::number(this->disparos));
    }
    else {
        ui->informacion->setText("Restantes "+QString::number(this->disparos));
    }
}





void ventanaPrincipal::on_shoot1_clicked()
{
    system("notify-send 'Single Shoot'");
    this->disparos=1;
    ejecutar();
    ui->informacion->setText("Ejecutandose");

}


void ventanaPrincipal::on_dependencias_clicked()
{
    system("notify-send 'copie y pegue este comando en su terminal'");
    ui->informacion->setText("sudo apt-get install ffmpeg");
    ui->informacion->setStyleSheet("p align:center;");
}

void ventanaPrincipal::on_shoot10_clicked()
{
    system("notify-send '5 shoots'");
    this->disparos=5;
    ejecutar();
    this->timer->start(60000);
    ui->informacion->setText("Ejecutandose");
}

void ventanaPrincipal::on_shoot50_clicked()
{
    system("notify-send '10 shoots'");
    this->disparos=10;
    ejecutar();
    this->timer->start(60000);
    ui->informacion->setText("Ejecutandose");
}

void ventanaPrincipal::on_shoot100_clicked()
{
    system("notify-send '50 shoots'");
    this->disparos=50;
    ejecutar();
    this->timer->start(60000);
    ui->informacion->setText("Ejecutandose");
}
