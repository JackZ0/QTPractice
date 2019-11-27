class test():

    def setUI(self,w):
        #设置工具窗口的大小
        w.setGeometry(400,400,400,200)
        #设置工具窗口的标题
        w.setWindowTitle("Test")
        #设置窗口的图标
        self.setWindowIcon(QtGui.QIcon('icon.png'))
　　　　 #设置提示框中文本的字体样式，大小
　　　　 QtWidgets.QToolTip.setFont(QtGui.QFont('SansSerif',20))
　　　　 #在窗口中添加一个提示框
        w.setToolTip('这是Window关机工具')
        w.show()

if __name__=='__main__':
    #创建应用程序和对象
    app = QtWidgets.QApplication(sys.argv)
    w = QtWidgets.QWidget()
    ui = test()
    ui.setUI(w)
    sys.exit(app.exec_())
