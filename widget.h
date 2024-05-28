#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QListWidget>
#include "QDebug"
#include "setting.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    /****************/
    void reArrage();

    void setBgImage();


private slots:
    void on_listWidget_customContextMenuRequested(const QPoint &pos);

    // 添加图标到本地
//    void addIcon();

    // 导出exe图标
//    void extraIconFromExe(QString exePath);

//    void getIconPath();

private:
    Ui::Widget *ui;

    //
    std::string iconPath;

    Setting *set = nullptr;

};

#endif // WIDGET_H
