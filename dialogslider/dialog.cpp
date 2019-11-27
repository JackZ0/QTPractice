#include "dialog.h"
#include <QSlider>
#include <QLineEdit>
#include <QHBoxLayout>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    spin = new QSpinBox();

    slider = new QSlider(Qt::Horizontal);
    slider->setMinimum(0);
    slider->setMaximum(100);
    slider->setTickInterval(10);
    slider->setTickPosition(QSlider::TicksAbove);
    slider->setSingleStep(10);
    spin->setRange(0,100);


    connect(slider,SIGNAL(valueChanged(int)),spin,SLOT(setValue(int)));
    connect(spin,SIGNAL(valueChanged(int)),slider,SLOT(setValue(int)));

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(spin);
    layout->addWidget(slider);

    this->setLayout(layout);
    this->resize(600,50);
    this->setWindowTitle("QSliderDemo");
}

Dialog::~Dialog()
{

}
