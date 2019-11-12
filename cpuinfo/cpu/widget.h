#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <string.h>
#include <iostream>
#include <windows.h>

#ifdef __GNUC__
#include <cpuid.h>
#elif defined(_MSC_VER)
#if _MSC_VER >= 1400
#include <intrin.h>
#endif
#else
#error Only supports MSVC or GCC
#endif
using namespace  std;
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

   QString get_cpuId();
    void getcpuid(unsigned int CPUInfo[4], unsigned int InfoType);

    void getcpuidex(unsigned int CPUInfo[4], unsigned int InfoType, unsigned int ECXValue);
};

#endif // WIDGET_H
