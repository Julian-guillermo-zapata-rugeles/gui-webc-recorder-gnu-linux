#include "ventanaprincipal.h"
#include "ui_ventanaprincipal.h"

ventanaPrincipal::ventanaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ventanaPrincipal)
{
    ui->setupUi(this);
    crearCarpetaGrabacion();
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





void ventanaPrincipal::on_shoot1_clicked()
{
    //system("notify-send 'Single Shoot'");
    QDateTime dateTime = dateTime.currentDateTime();
    QString dateTimeString = dateTime.toString("yyyy-MM-dd hh:mm:ss");
    std::string time_now = "ffmpeg  -f video4linux2 -i /dev/video0 -f alsa -i hw:0 -acodec mp2 -qscale 0 -t 55 $HOME/webc/"+dateTimeString.toStdString()+".avi ";
    qDebug() << QString(time_now.c_str());
    system(time_now.c_str());
}

void ventanaPrincipal::on_dependencias_clicked()
{
    system("notify-send 'copie y pegue este comando en su terminal'");

}
