#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

#include <QMainWindow>
#include <QDateTime>
#include <cstdlib>
#include <QDebug>
#include <QTimer>

namespace Ui {
class ventanaPrincipal;
}

class ventanaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    explicit ventanaPrincipal(QWidget *parent = nullptr);
    ~ventanaPrincipal();

private slots:
    void on_salir_clicked();

    void on_shoot1_clicked();

    void on_dependencias_clicked();

private:
    Ui::ventanaPrincipal *ui;
    void crearCarpetaGrabacion();
};

#endif // VENTANAPRINCIPAL_H
