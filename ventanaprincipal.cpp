#include "ventanaprincipal.h"
#include "ui_ventanaprincipal.h"

ventanaPrincipal::ventanaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ventanaPrincipal)
{
    ui->setupUi(this);
}

ventanaPrincipal::~ventanaPrincipal()
{
    delete ui;
}
