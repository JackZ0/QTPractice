#include "convert.h"
#include "ui_convert.h"
#include <QDebug>
Convert::Convert(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Convert)
{
    ui->setupUi(this);
}

Convert::~Convert()
{
    delete ui;
}
/**
 * @brief Convert::convertStringToHex  QString 转换为 Hex ByteArray
 * @param str
 * @param byteData
 */
void Convert::convertStringToHex(const QString &str, QByteArray &byteData)
{
    int hexdata,lowhexdata;
        int hexdatalen = 0;
        int len = str.length();
        byteData.resize(len/2);
        char lstr,hstr;
        for(int i=0; i<len; )
        {
            //char lstr,
            hstr=str[i].toLatin1();
            if(hstr == ' ')
            {
                i++;
                continue;
            }
            i++;
            if(i >= len)
                break;
            lstr = str[i].toLatin1();
            hexdata = convertCharToHex(hstr);
            lowhexdata = convertCharToHex(lstr);
            if((hexdata == 16) || (lowhexdata == 16))
                break;
            else
                hexdata = hexdata*16+lowhexdata;
            i++;
            byteData[hexdatalen] = (char)hexdata;
            hexdatalen++;
        }
        byteData.resize(hexdatalen);
}

char Convert::convertCharToHex(char ch)
{
    if((ch >= '0') && (ch <= '9'))
            return ch-0x30;
        else if((ch >= 'A') && (ch <= 'F'))
            return ch-'A'+10;
        else if((ch >= 'a') && (ch <= 'f'))
            return ch-'a'+10;
       else return (-1);
}



void Convert::on_btn1_clicked()
{
    QString str1 = ui->txtACSII->text().trimmed();
    QByteArray array1;
    convertStringToHex(str1,array1);
    qDebug() << "str1" << str1<<endl;
    qDebug() << "array1" << array1<<endl;
    ui->txtHex1->setText(array1);
}

void Convert::on_btn2_clicked()
{

}

void Convert::on_btn3_clicked()
{

}
