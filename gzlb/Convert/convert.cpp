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

char *Convert::chstohex(char *chs)
{
    char hex[16] = { '0', '1', '2', '3', '4', '5', '6', \
            '7', '8','9', 'A', 'B', 'C', 'D', 'E', 'F'
        };

    int len = strlen ( chs );
    char* ascii = NULL ;
    ascii = (char*)calloc ( len * 3 + 1, sizeof(char) );            // calloc ascii

    int i = 0;
    while( i < len )
    {
        ascii[i*2] = hex[(int)( (char)chs[i] / 16 )] ;
        ascii[i*2 + 1] = hex[(int)( (char)chs[i] % 16 )] ;
        ++i;
    }

    return ascii;                    // ascii 返回之前未释放
}

char *Convert::hextochs(char *ascii)
{
    int len = strlen ( ascii ) ;
       if( len%2 != 0 )
           return NULL ;
       char *chs = NULL ;
       chs = (char*)calloc( len / 2 + 1, sizeof(char) );                // calloc chs

       int  i = 0 ;
       char ch[2] = {0};
       while( i < len )
       {
           ch[0] = ( (int)ascii[i] > 64 ) ? ( ascii[i]%16 + 9 ) : ascii[i]%16 ;
           ch[1] = ( (int)ascii[i + 1] > 64 ) ? ( ascii[i + 1]%16 + 9 ) : ascii[i + 1]%16 ;

           chs[i/2] = (char)( ch[0]*16 + ch[1] );
           i += 2;
       }

       return chs ;            // chs 返回前未释放
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
    QString str2;
    str2 = ui->txtHex2->text().trimmed();
    QByteArray array2 = str2.toLatin1();
    bool ok;
    uint8_t data[5] = {0};	//data数组中的长度要比输入的字符串长度大
    for(int i = 0, j = 0; j < str2.length(); i += 2, j++)
        data[j] = str2.mid(i, 2).toInt(&ok, 16);
    qDebug() << data << endl;


}

void Convert::on_btn3_clicked()
{

}
