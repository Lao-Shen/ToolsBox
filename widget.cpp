#include "widget.h"
#include "ui_widget.h"
#include "QLabel"
#include "QMenu"
#include "QMessageBox"
#include "QFileDialog"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    /***********************************/

    this->resize(930,550);

    // 设置背景
    this->setBgImage();

    // -------------------
//    ui->listWidget = new QListWidget(this);
    ui->listWidget->setViewMode(QListView::IconMode);
    ui->listWidget->setIconSize(QSize(100,100));
    ui->listWidget->setResizeMode(QListView::Adjust);
    ui->listWidget->setMovement(QListView::Static);
    ui->listWidget->setFlow(QListView::LeftToRight); // 设置从左到右排列
    ui->listWidget->setWrapping(true); // 允许项目换行

    ui->listWidget->setStyleSheet("QListWidget::item { margin: 10px;}");
    ui->listWidget->setWindowOpacity(0.5);

    ui->listWidget->setContextMenuPolicy(Qt::CustomContextMenu);


//    connect(ui->listWidget, &QWidget::customContextMenuRequested, this, &Widget::on_listWidget_customContextMenuRequested);

//    ui->Layout->addWidget(ui->listWidget);

    // ++++++++++++++++++++

    // 重新布局
    this->reArrage();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::reArrage()
{

    for (int i = 0; i < 40; i++) {
        QListWidgetItem *item = new QListWidgetItem(ui->listWidget);

        QPixmap pixMap(":/image/default.jpg");
        if (pixMap.isNull()) {
            qWarning("Failed to load image");
        } else {
            item->setIcon(QIcon(pixMap));
        }

        item->setText("默认图标");
        item->setTextAlignment(Qt::AlignCenter);
        ui->listWidget->addItem(item);
    }
}

void Widget::setBgImage(){
    QPixmap pixMap(":/image/bg1.jpg");
    QPalette palette;
    palette.setBrush(this->backgroundRole(),QBrush(pixMap));
    this->setPalette(palette);
}


void Widget::on_listWidget_customContextMenuRequested(const QPoint &pos)
{
    // 创建上下文菜单
    QMenu contextMenu(this);

    // 添加菜单项
    QAction *action1 = contextMenu.addAction("添加");
    QAction *action2 = contextMenu.addAction("设置");
//    QAction *action3 = contextMenu.addAction("Action 3");

    // 连接菜单项的触发事件到槽函数
    connect(action1, &QAction::triggered, this, [this]() {
        auto filepath = QFileDialog::getOpenFileName(nullptr,"Open File",QDir::homePath(), "All Files (*);;Text Files (*.exe)");

//        if (this->set == nullptr) {
//            this->set = new Setting;
//            this->set->show();
//        } else {
//            this->set->show();
//        }
    });
    connect(action2, &QAction::triggered, this, []() { qDebug() << "Action 2 triggered"; });
//    connect(action3, &QAction::triggered, this, []() { qDebug() << "Action 3 triggered"; });

    // 显示菜单
    contextMenu.exec(ui->listWidget->mapToGlobal(pos));

}

//void Widget::addIcon()
//{
//    // todo

//    // 1. if dir not exist,make dir
//    if (!fileExist(this->getIconPath())) {
//        if (!makeDir(this->getIconPath())) {
//            // create err
//            QMessageBox::information(nullptr,"提示","创建文件夹失败");
//            return;
//        }
//    }

//    // 2. extra icon and put in dir


//    // 3. add in json

//}

//void Widget::extraIconFromExe(QString exePath)
//{
//    auto currentDir = getCurrentPath();
//    auto scriptPath = currentDir + "\\bin\\ExtractIcon.ps1";
//    toWindowsPath(scriptPath);

//    /********** extra exe icon ********/
//    // 构建PowerShell命令
//    std::string command = "powershell.exe -File \"" + scriptPath + "\" -ExePath \"" + exePath.toStdString() + "\" -SavePath \"" + savePath + "\"";

//    // 设置进程启动信息
//    STARTUPINFOA si;
//    PROCESS_INFORMATION pi;
//    ZeroMemory(&si, sizeof(si));
//    si.cb = sizeof(si);
//    ZeroMemory(&pi, sizeof(pi));

//    // 创建进程
//    if (!CreateProcessA(NULL, const_cast<LPSTR>(command.c_str()), NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
//        std::cerr << "CreateProcess failed: " << GetLastError() << std::endl;
//        return;
//    }

//    // 等待进程完成
//    WaitForSingleObject(pi.hProcess, INFINITE);

//    // 关闭进程和线程句柄
//    CloseHandle(pi.hProcess);
//    CloseHandle(pi.hThread);


//}

//void Widget::getIconPath()
//{
//    if (this->iconPath == "") {
//        this->iconPath = getCurrentPath();
//        this->iconPath += "\\icons";
//        toWindowsPath(this->iconPath);
//    }

//    return this->iconPath;
//}
