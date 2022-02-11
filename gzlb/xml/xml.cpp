#include "xml.h"
#include <QDebug>

Xml::Xml()
{

}

void Xml::WriteXml(QString fileName)
{
    //打开或创建文件
  //  QFile file("test.xml"); //相对路径、绝对路径、资源路径都可以
    QFile file(fileName); //相对路径、绝对路径、资源路径都可以
    if(!file.open(QFile::WriteOnly|QFile::Truncate)) //可以用QIODevice，Truncate表示清空原来的内容
       return;

    QDomDocument doc;
    //写入xml头部
    QDomProcessingInstruction instruction; //添加处理命令
    instruction=doc.createProcessingInstruction("xml","version=\"1.0\" encoding=\"UTF-8\"");
    doc.appendChild(instruction);
    //添加根节点
    QDomElement root=doc.createElement("library");
    doc.appendChild(root);
    //添加第一个子节点及其子元素
    QDomElement book=doc.createElement("book");
    book.setAttribute("id",1); //方式一：创建属性  其中键值对的值可以是各种类型
    QDomAttr time=doc.createAttribute("time"); //方式二：创建属性 值必须是字符串
    time.setValue("2013/6/13");
    book.setAttributeNode(time);
    QDomElement title=doc.createElement("title"); //创建子元素
    QDomText text; //设置括号标签中间的值
    text=doc.createTextNode("C++ primer");
    book.appendChild(title);
    title.appendChild(text);
    QDomElement author=doc.createElement("author"); //创建子元素
    text=doc.createTextNode("Stanley Lippman");
    author.appendChild(text);
    book.appendChild(author);
    root.appendChild(book);

    //添加第二个子节点及其子元素，部分变量只需重新赋值
    book=doc.createElement("book");
    book.setAttribute("id",2);
    time=doc.createAttribute("time");
    time.setValue("2007/5/25");
    book.setAttributeNode(time);
    title=doc.createElement("title");
    text=doc.createTextNode("Thinking in Java");
    book.appendChild(title);
    title.appendChild(text);
    author=doc.createElement("author");
    text=doc.createTextNode("Bruce Eckel");
    author.appendChild(text);
    book.appendChild(author);
    root.appendChild(book);

    //输出到文件
    QTextStream out_stream(&file);
    doc.save(out_stream,4); //缩进4格
    file.close();

}

void Xml::ReadXml(QString fileName)
{
//打开或创建文件
   //QFile file("test.xml"); //相对路径、绝对路径、资源路径都行
   QFile file(fileName); //相对路径、绝对路径、资源路径都可以
   if(!file.open(QFile::ReadOnly))
       return;

   QDomDocument doc;
   if(!doc.setContent(&file))
   {
       file.close();
       return;
   }
   file.close();

   QDomElement root=doc.documentElement(); //返回根节点
   qDebug()<<root.nodeName();
   QDomNode node = root.firstChild(); //获得第一个子节点
   while(!node.isNull())  //如果节点不空
   {
       if(node.isElement()) //如果节点是元素
       {
           QDomElement e=node.toElement(); //转换为元素，注意元素和节点是两个数据结构，其实差不多
           qDebug()<<e.tagName()<<" "<<e.attribute("id")<<" "<<e.attribute("time"); //打印键值对，tagName和nodeName是一个东西
           QDomNodeList list = e.childNodes();
           for(int i=0;i<list.count();i++) //遍历子元素，count和size都可以用,可用于标签数计数
           {
               QDomNode n=list.at(i);
               if(node.isElement())
                   qDebug()<<n.nodeName()<<":"<<n.toElement().text();
           }
       }
       node=node.nextSibling(); //下一个兄弟节点,nextSiblingElement()是下一个兄弟元素，都差不多
   }
}

void Xml::AddXml(QString fileName)
{
//打开文件
   //QFile file("test.xml"); //相对路径、绝对路径、资源路径都可以
   QFile file(fileName); //相对路径、绝对路径、资源路径都可以
   if(!file.open(QFile::ReadOnly))
       return;

   //增加一个一级子节点以及元素
   QDomDocument doc;
   if(!doc.setContent(&file))
   {
       file.close();
       return;
   }
   file.close();

   QDomElement root=doc.documentElement();
   QDomElement book=doc.createElement("book");
   book.setAttribute("id",3);
   book.setAttribute("time","1813/1/27");
   QDomElement title=doc.createElement("title");
   QDomText text;
   text=doc.createTextNode("Pride and Prejudice");
   title.appendChild(text);
   book.appendChild(title);
   QDomElement author=doc.createElement("author");
   text=doc.createTextNode("Jane Austen");
   author.appendChild(text);
   book.appendChild(author);
   root.appendChild(book);

   if(!file.open(QFile::WriteOnly|QFile::Truncate)) //先读进来，再重写，如果不用truncate就是在后面追加内容，就无效了
       return;
   //输出到文件
   QTextStream out_stream(&file);
   doc.save(out_stream,4); //缩进4格
   file.close();
}

void Xml::RemoveXml(QString fileName)
{
    //打开文件
    //QFile file("test.xml"); //相对路径、绝对路径、资源路径都可以
    QFile file(fileName); //相对路径、绝对路径、资源路径都可以
    if(!file.open(QFile::ReadOnly))
        return;

    //删除一个一级子节点及其元素，外层节点删除内层节点于此相同
    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();  //一定要记得关掉啊，不然无法完成操作

    QDomElement root=doc.documentElement();
    QDomNodeList list=doc.elementsByTagName("book"); //由标签名定位
    for(int i=0;i<list.count();i++)
    {
        QDomElement e=list.at(i).toElement();
        if(e.attribute("time")=="2007/5/25")  //以属性名定位，类似于hash的方式，warning：这里仅仅删除一个节点，其实可以加个break
            root.removeChild(list.at(i));
    }

    if(!file.open(QFile::WriteOnly|QFile::Truncate))
        return;
    //输出到文件
    QTextStream out_stream(&file);
    doc.save(out_stream,4); //缩进4格
    file.close();
}

void Xml::UpdateXml(QString fileName)
{
//打开文件
   //QFile file("test.xml"); //相对路径、绝对路径、资源路径都可以
   QFile file(fileName); //相对路径、绝对路径、资源路径都可以
   if(!file.open(QFile::ReadOnly))
       return;

   //更新一个标签项,如果知道xml的结构，直接定位到那个标签上定点更新
   //或者用遍历的方法去匹配tagname或者attribut，value来更新
   QDomDocument doc;
   if(!doc.setContent(&file))
   {
       file.close();
       return;
   }
   file.close();

   QDomElement root=doc.documentElement();
   QDomNodeList list=root.elementsByTagName("book");
   QDomNode node=list.at(list.size()-1).firstChild(); //定位到第三个一级子节点的子元素
   QDomNode oldnode=node.firstChild(); //标签之间的内容作为节点的子节点出现,当前是Pride and Projudice
   node.firstChild().setNodeValue("Emma");
   QDomNode newnode=node.firstChild();
   node.replaceChild(newnode,oldnode);

   if(!file.open(QFile::WriteOnly|QFile::Truncate))
       return;
   //输出到文件
   QTextStream out_stream(&file);
   doc.save(out_stream,4); //缩进4格
   file.close();
}


