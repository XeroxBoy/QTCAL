#ifndef WIDGET_H
#define WIDGET_H
#include <math.h>
#include <QLineEdit>
#include <QWidget>
#include <QString>
#include <QLabel>
#include <string.h>
#include <QPainter>
#include "Gstack.h"
#include "Gstack.cpp"
#include <stdlib.h>
#include <QMessageBox>
#include <QDebug>
#include <QStack>
#include <math.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    int compareOp(char a,char b);//检查运算符优先级
    int invert(char a); //将运算符转换为数组下标，方便操作
    static const char pri[9][9];//运算符优先级
    int operate(double a, char op);//一元运算符的运算
    void paintEvent(QPaintEvent *p);//绘制函数图像
    void Printx(double low1,double high1);//画横坐标
    void Printy(double low2,double high2);//画纵坐标
    int optrCode(char op);//字符转换
    int number(const char *str, int i0, double &v);//字符串转浮点数
    bool number(const char *str, int &i0, double &v,double x1);//sin log cos转浮点数
    double operate(double a, char op, double b);//计算
    bool eval(const char *express, double &v, double x1);//求值
    bool sanjiaoeval(const char *str, int &i0, int begin, double &v, double x1, int type);//三角函数括号内表达式求值
private:
    Ui::Widget *ui;
    bool whetherPic;//画不画的开关
    double low; //获取的x最大值和最小值
    double high;
    double min;//y的大小范围
    double max;
    double Accuracy;//精度
    double Yvalue[11001];//排序后y的值，仅用于确定坐标范围
    bool toomany; //根是否太多
    bool drawornot;//绘画开关
    QLineEdit *expE; //表达式
    bool haveX;//表示是否输入X区间
    double sqrt[20];//根数组
    double erfensqrt;//二分法求出的根
    int length1; //根的个数
    bool stop;//用于停止二分法计算
    /* （仅用于记UI里控件的名字）
     * QLabel functionL;
    QLabel MinL;
    QLabel MaxL;
    QPushButton QBPaint;
    QPushButton QBCalculate;
    QVBoxLayout mainLayout;
    QHBoxLayout firstLayout;
    QHBoxLayout secondLayout;
    QLineEdit InputE;
    QLineEdit MaxXE;
    QLineEdit MinXE;*/
public slots:
    void Calculate();//求根按键对应的槽
    void Printimage();//绘制图像按键对应的槽
    void on_pushButton_clicked(); //激活
};


#endif // WIDGET_H
