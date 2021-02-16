#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

#include <QMainWindow>

namespace Ui {
class ventanaPrincipal;
}

class ventanaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    explicit ventanaPrincipal(QWidget *parent = nullptr);
    ~ventanaPrincipal();

private:
    Ui::ventanaPrincipal *ui;
};

#endif // VENTANAPRINCIPAL_H
