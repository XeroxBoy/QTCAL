#include "widget.h"
#include "ui_widget.h"

#define INTMAX 65536
#define INTMIN -65536

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setFixedSize(630,456);//设置固定大小 因为程序按坐标关系做的 放大后会出问题
    //FPoint=Point();
    whetherPic=false;
    expE=new QLineEdit(this);
    expE->setGeometry(80,15,440,20);
    ui->calB->setEnabled(false);//绘图后才能求根
    ui->label_2->setWordWrap(true);
    ui->label_2->setAlignment(Qt::AlignTop); //注释自动换行
   drawornot=false;
}

Widget::~Widget()
{
    delete ui;
}

int Widget::operate(double a, char op) //一元运算符 阶乘
{
    switch(op)
    {
     case 5:{
        int temp=a;
        while(--a)
        {
            temp*=a;
        }
        return temp;
    }
    }
    return 0;
}
//运算符优先级数组
const char Widget::pri[9][9]={
        '>','>','<','<','<','<','<','>','>',//+
        '>','>','<','<','<','<','<','>','>',//-
        '>','>','>','>','<','<','<','>','>',//*
        '>','>','>','>','<','<','<','>','>',// /
        '>','>','>','>','>','<','<','>','>',// ^
        '>','>','>','>','<','<','<','>','>',// !
        '<','<','<','<','<','<','<','=',' ',// (
        ' ',' ',' ',' ',' ',' ',' ',' ',' ', //)
        '<','<','<','<','<','<','<',' ','=' //  \0
};




void Widget::paintEvent(QPaintEvent *p)
{

    QPainter painter(this);
    painter.setPen(Qt::red);
    for(int i=0;i<=10;i++){  //74.5 50 519.5 435 44.5 35 画的11X11的方格
    painter.drawLine(74.5+i*44.5,50,74.5+i*44.5,435);
    painter.drawLine(74.5,50+i*35,519.5,50+i*35);
    }
    painter.drawLine(74.5,435,519.5,435);
    if(drawornot) //每个点的函数值计算成功后打开的，进行画图
     {
        double y1=0;
        double y2=0;
     //   double y3,y4;
        double x1=30;
        QString Exprecord=expE->text();
        double step=(high-low)/11000;//每个微元 x的改变量
        double changex=(519.5-74.5)/11000;
        painter.setPen(Qt::black);
        painter.setRenderHint(QPainter::Antialiasing);//抗锯齿
       for(double i=low;i<=high;i+=step)   //设置点之间对应关系后进行绘画，将1万个相邻点连到一起形成图像
       {
           eval(Exprecord.toLatin1().data(),y1,i);

           eval(Exprecord.toLatin1().data(),y2,i+step);
           y1=435-(435-50)*(y1-min)/(max-min);
           y2=435-(435-50)*(y2-min)/(max-min);
           x1=74.5+(519.5-74.5)*(i-low)/(high-low);
           painter.drawLine(x1,y1,x1+changex,y2);

       }

       update(); //更新 显示出图像
    }


}

void Widget::Printx(double low1, double high1) //输出横坐标
{
    if(low1>=high1)
    {
        QMessageBox::information(this,"wrong","区间输入有误",QMessageBox::Yes);
        return;
    }
    double i=low1;
    double step=(high1-low1)/10; //从lineedit中得到X在区间内最大值，最小值，十一等分 在label上画出坐标

    QString temp;
    temp=QString::number(i,10,1);
    ui->label_3->setText(temp);
    i+=step;
    temp=QString::number(i,10,1);
    ui->label_4->setText(temp);
    i+=step;
    temp=QString::number(i,10,1);
    ui->label_5->setText(temp);
    i+=step;
    temp=QString::number(i,10,2);
    ui->label_6->setText(temp);
    i+=step;
    temp=QString::number(i,10,2);
    ui->label_7->setText(temp);
    i+=step;
    temp=QString::number(i,10,2);
    ui->label_8->setText(temp);
    i+=step;
    temp=QString::number(i,10,2);
    ui->label_9->setText(temp);
    i+=step;
    temp=QString::number(i,10,2);
    ui->label_10->setText(temp);
    i+=step;
    temp=QString::number(i,10,2);
    ui->label_11->setText(temp);
    i+=step;
    temp=QString::number(i,10,2);
    ui->label_12->setText(temp);
    i+=step;
    temp=QString::number(i,10,2);
    ui->label_13->setText(temp);
}

void Widget::Printy(double low2, double high2) //输出纵坐标
{   if(low2>=high2) return;
    double step=(high2-low2)/11;//算出函数在区间内最大值，最小值，十二等分 在label上画出坐标
    double i=low2;
    QString  temp=QString::number(i,10,2);
    ui->label1->setText(temp);
    i+=step;
        temp=QString::number(i,10,2);

    ui->label2->setText(temp);
    i+=step;
        temp=QString::number(i,10,2);

    ui->label3->setText(temp);
    i+=step;
        temp=QString::number(i,10,2);

    ui->label4->setText(temp);
    i+=step;
        temp=QString::number(i,10,2);

    ui->label5->setText(temp);
    i+=step;
        temp=QString::number(i,10,2);

    ui->label6->setText(temp);
    i+=step;
        temp=QString::number(i,10,2);

    ui->label7->setText(temp);
    i+=step;
        temp=QString::number(i,10,2);

    ui->label8->setText(temp);
    i+=step;
        temp=QString::number(i,10,2);

    ui->label9->setText(temp);
    i+=step;
        temp=QString::number(i,10,2);

    ui->label10->setText(temp);
    i+=step;
        temp=QString::number(i,10,2);

    ui->label11->setText(temp);
    i+=step;
        temp=QString::number(i,10,2);

    ui->label12->setText(temp);
}



int Widget::optrCode(char op)//字符串 数字互转
{
    switch(op)
    {
    case '+':return 0;
    case '-':return 1;
    case '*':return 2;
    case '/':return 3;
    case '^':return 4;
    case '!':return 5;
    case '(':return 6;
    case ')':return 7;
    case '\0':return 8;
    default:return -1;
    }
}

int Widget::number(const char *str, int i0, double &v) //把输入在字符串中的浮点数提取出来 存入操作数栈中(不带x时）
{
    int i, j;
    bool firstDot = true; //一个浮点数只能有一个小数点
    static char tmp[128] = {0};//用来装浮点数 以便用atof转换为浮点数

    for(i=i0, j=0; str[i]!='\0'; i++,j++)
    {
        char c = str[i];
        if(c=='-' && i==i0)  //负号
        {
            tmp[j]=c;
        }
        else if(c=='-' && str[i-1]=='(')
        {
            tmp[j]=c;
        }
        else if (c >= '0' && c <= '9') //数字
        {
            tmp[j] = c;
        }
        else if (c == '.' && firstDot) //小数点
        {
            tmp[j] = c;
            firstDot = false;
        }

        else //读完了这个数
        {
            break ;
        }
    }

    tmp[j] = '\0'; //atof接受字符串 所以应在最后加0
    v = atof(tmp);
    return i;
}

bool Widget::number(const char *str, int &i0, double &v, double x1) //把输入在字符串中的浮点数提取出来 存入操作数栈中(带x时）
{
    int i,j;
    bool firstDot = true;
    static char tmp[128] = {0};
    double temp;
    //观察下一位是否是s c l开头 如果是 读完前三个字符 如果是cos sin log中的一种 则将下标跳到数学函数后，将数学函数的参数从字符串中提取出来
    //如果有X 带值运算 如果没有 直接计算sin cos log的值 压入操作数栈中   && str[i0+3]<='9' && str[i0+3]>='0'
    if(str[i0]=='s' && str[i0+1]=='i' && str[i0+2]=='n' )
        {

        if(str[i0+3]=='x' || str[i0+3]=='X') //针对sinx这种不带数字写法进行的处理
        {
              haveX=true;
               v=sin(x1);
               i0=i0+4;
             return true;
        }
        else if(str[i0+3]<='9' && str[i0+3]>='0') //带系数的写法 如sin2.5x
         {

             i=number(str,i0+3,temp);//将函数的系数计算出来 存入temp

             if(str[i]=='x' || str[i]=='X')
              {
                haveX=true;
                v=sin(temp*x1);
                i0=i+1;
                return true;
              }
              else //常数函数
             {
                v=sin(temp);
                i0=i;
                return true;
             }
         }
        else if(str[i0+3]=='(') //sin(nx+m)的解决
        {
           int begin=3+i0;
           bool success=sanjiaoeval(str,i0,begin,v,x1,1);
           return success;
        }
        else if(str[i0+3]!='-'){ //sin后乱输的情况 如sinax
            QMessageBox::information(this,"Wrong expression","您输入有误",QMessageBox::Ok);
            ui->calB->setEnabled(false);
            return false;

        }
        if(str[i0+3]=='-') //sin-....的解决
              {
                  if(str[i0+4]>'9' && str[i0+4]<'0' && str[i0+4]!='x' && str[i0+4]!='X')
                  {
                      QMessageBox::information(this,"Wrong expression","您输入有误",QMessageBox::Ok);
                      ui->calB->setEnabled(false);
                      return false;
                  }
                  if(optrCode(str[i0+4])!=-1)
                  {
                      QMessageBox::information(this,"Wrong expression","您输入了连续的运算符",QMessageBox::Ok);
                      ui->calB->setEnabled(false);
                      return false;
                  }
                  if(str[i0+4]=='x' || str[i0+4]=='X')
                  {
                      haveX=true;
                      v=sin(-x1);
                      i0=i0+5;
                      return true;
                   }
                  i=number(str,i0+4,temp);//将i移到系数后
                  if(str[i]=='x' || str[i]=='X')
                  {
                      haveX=true;
                      v=sin(-temp*x1);
                      i0=i+1;
                  }

                  else  //常数函数
                  {
                      v=sin(-temp);
                      i0=i;
                      return true;
                  }
              }
          }
    if(str[i0]=='c' && str[i0+1]=='o' && str[i0+2]=='s' )
          {

            if(str[i0+3]=='x' || str[i0+3]=='X')
            {
              haveX=true;
                v=cos(x1);
                i0=i0+4;
                return true;
            }
            else if(str[i0+3]<='9' && str[i0+3]>='0')
            {
                  i=number(str,i0+3,temp);//将函数的系数计算出来 存入temp

                  if(str[i]=='x' || str[i]=='X')
                  {
                      haveX=true;
                      v=cos(temp*x1);
                      i0=i+1;
                      return true;
                  }
                  else //常数函数
                  {
                      v=cos(temp);
                      i0=i;
                      return true;
                  }
             }

            else if(str[i0+3]=='(') //cos(nx+m)的解决
            {
                int begin=3+i0;
               return sanjiaoeval(str,i0,begin,v,x1,2);
            }
            else if(str[i0+3]!='-') { //cos后乱输的情况 如cosax
                QMessageBox::information(this,"Wrong expression","您输入有误",QMessageBox::Ok);
                ui->calB->setEnabled(false);
                return false;

            }

            if(str[i0+3]=='-')
        {
            if(optrCode(str[i0+4])!=-1)
            {
                QMessageBox::information(this,"Wrong expression","您输入了连续的运算符",QMessageBox::Ok);
                ui->calB->setEnabled(false);
                return false;
            }
            else if(str[i0+4]>'9' && str[i0+4]<'0' && str[i0+4]!='x' && str[i0+4]!='X')
            {
                QMessageBox::information(this,"Wrong expression","您输入有误",QMessageBox::Ok);
                ui->calB->setEnabled(false);
                return false;
            }
           else if(str[i0+4]=='x' || str[i0+4]=='X')
            {
                haveX=true;
                v=cos(-x1);
                i0=i0+5;
                return true;

             }
            i=number(str,i0+4,temp);
            if(str[i]=='x' || str[i]=='X')
            {
                haveX=true;
                v=cos(-temp*x1);
                i0=i+1;
                return true;
            }

            else  //常数函数
            {
                v=cos(-temp);
                i0=i;
                return true;
            }
        }
             return true;
          }
    if(str[i0]=='l' && str[i0+1]=='o' && str[i0+2]=='g' )
          {
     if(str[i0+3]=='x' || str[i0+3]=='X')
            {
              haveX=true;
                v=log(x1);
                i0=i0+4;
                return true;
            }
     else if(str[i0+3]<='9' && str[i0+3]>='0')
            {
             i=number(str,i0+3,temp); //将x前系数计算出来 存入temp
             if(str[i]=='x' || str[i]=='X')
                  {
                      haveX=true;
                      v=log(temp*x1);
                      i0=i+1;
                      return true;
                  }
               else //常数函数
                  {
                      v=log(temp);
                      i0=i;
                      return true;
                  }
            }
     else if(str[i0+3]=='(') //log(nx+m)的解决
     {
         int begin=3+i0;
         return sanjiaoeval(str,i0,begin,v,x1,3);
     }
     else if(str[i0+3]!='-') { //log后乱输的情况 如logax
                QMessageBox::information(this,"Wrong expression","您输入有误",QMessageBox::Ok);
                ui->calB->setEnabled(false);
                return false;
            }

     if(str[i0+3]=='-')
        {
            if(str[i0+4]>'9' && str[i0+4]<'0' && str[i0+4]!='x' && str[i0+4]!='X')
            {
                QMessageBox::information(this,"Wrong expression","您输入有误",QMessageBox::Ok);
                ui->calB->setEnabled(false);
                return false;
            }
            if(optrCode(str[i0+4])!=-1) //待解决
            {
                QMessageBox::information(this,"Wrong expression","您输入了连续的运算符",QMessageBox::Ok);
                ui->calB->setEnabled(false);
                return false;
            }
            if(str[i0+4]=='x' || str[i0+4]=='X')
            {
                haveX=true;
                v=log(-x1);
                i0=i0+5;
                return true;
             }
            i=number(str,i0+4,temp);
            if(str[i]=='x' || str[i]=='X')
            {
                haveX=true;
                v=log(-temp*x1);
                i0=i+1;
                return true;
            }
            else  //常数函数
            {
                v=log(-temp);
                i0=i;
                return true;
            }
        }
         }
     if(str[i0]=='a' && str[i0+1]=='s' && str[i0+2]=='i' && str[i0+3]=='n' )
      {
            if(str[i0+4]=='x' || str[i0+4]=='X')
            {
                if(x1>1 || x1<-1)
                {
                   QMessageBox::information(this,"wrong","超出定义域(可能是您输入错误,或者是二分法求根时代入了超出定义域的数)",QMessageBox::Yes);
                   return false;
                }
                haveX=true;
                v=asin(x1);
                i0=i0+5;
                return true;
            }

            else if(str[i0+4]=='(') //asin(nx+m)的解决
            {
                int begin=4+i0;
                return sanjiaoeval(str,i0,begin,v,x1,4);
            }

            else if(str[i0+4]<='9' && str[i0+4]>='0')
            {
             i=number(str,i0+4,temp); //将x前系数计算出来 存入temp
             if(str[i]=='x' || str[i]=='X') //asin0.nX
              {
                 if(temp*high>1 ||temp*high<-1 || temp*low>1 ||temp*low<-1)
                 {
                    QMessageBox::information(this,"wrong","超出定义域(可能是您输入错误,或者是二分法求根时代入了超出定义域的数)",QMessageBox::Yes);
                    return false;
                 }
                      haveX=true;
                      v=asin(temp*x1);
                      i0=i+1;
                      return true;
             }


             else if(str[i0+4]!='-') { //asin后乱输的情况 如asinax
                 QMessageBox::information(this,"Wrong expression","您输入有误",QMessageBox::Ok);
                 ui->calB->setEnabled(false);
                 return false;
             }

               else //常数函数
               {
                 if(temp>=1 || temp<=-1)
                 {
                    QMessageBox::information(this,"wrong","超出定义域",QMessageBox::Yes);
                    return false;
                 }
                 v=asin(temp);
                 i0=i;
                 return true;
               }
            }


    if(str[i0+4]=='-')
        {
            if(str[i0+5]>'9' && str[i0+5]<'0' && str[i0+5]!='x' && str[i0+5]!='X') //负号后的系数
            {
                QMessageBox::information(this,"Wrong expression","您输入有误",QMessageBox::Ok);
                ui->calB->setEnabled(false);
                return false;
            }
            if(optrCode(str[i0+5])!=-1) //连着输运算符
            {
                QMessageBox::information(this,"Wrong expression","您输入了连续的运算符",QMessageBox::Ok);
                ui->calB->setEnabled(false);
                return false;
            }
            if(str[i0+5]=='x' || str[i0+5]=='X') // asin-x
            {
                if(x1>1 || x1<-1)
                {
                   QMessageBox::information(this,"wrong","超出定义域",QMessageBox::Yes);
                   return false;
                }
                haveX=true;
                v=asin(-x1);
                i0=i0+6;
                return true;
             }
            i=number(str,i0+5,temp);
            if(str[i]=='x' || str[i]=='X')
            {
                if(temp*high>1 ||temp*high<-1 || temp*low>1 ||temp*low<-1)
                {
                   QMessageBox::information(this,"wrong","超出定义域",QMessageBox::Yes);
                   return false;
                }
                haveX=true;
                v=asin(-temp*x1);
                i0=i+1;
                return true;
            }
            else  //常数函数
            {
                if(temp>=1 || temp<=-1)
                {
                   QMessageBox::information(this,"wrong","超出定义域",QMessageBox::Yes);
                   return false;
                }
                v=asin(-temp);
                i0=i;
                return true;
            }
        }
     }
     if(str[i0]=='a' && str[i0+1]=='c' && str[i0+2]=='o' && str[i0+3]=='s' )
          {
            if(str[i0+4]=='x' || str[i0+4]=='X') //acosx
            {
                if(x1>1 || x1<-1)
                {
                   QMessageBox::information(this,"wrong","超出定义域",QMessageBox::Yes);
                   return false;
                }
                haveX=true;
                v=acos(x1);
                i0=i0+5;
                return true;
            }
            else if(str[i0+4]=='(') //acos(nx+m)的解决
            {
               int begin=4+i0;
               return sanjiaoeval(str,i0,begin,v,x1,5);
            }
            else if(str[i0+4]<='9' && str[i0+4]>='0') //acosnx
            {
             i=number(str,i0+4,temp); //将x前系数计算出来 存入temp
             if(str[i]=='x' || str[i]=='X')
                  {
                 if(temp*high>1 ||temp*high<-1 || temp*low>1 ||temp*low<-1)
                 {
                    QMessageBox::information(this,"wrong","超出定义域",QMessageBox::Yes);
                    return false;
                 }
                      haveX=true;
                      v=acos(temp*x1);
                      i0=i+1;
                      return true;
                  }
               else //常数函数
                  {
                 if(temp>=1 || temp<=-1)
                 {
                    QMessageBox::information(this,"wrong","超出定义域",QMessageBox::Yes);
                    return false;
                 }
                      v=acos(temp);
                      i0=i;
                      return true;
                  }
            }
            else if(str[i0+4]!='-') { //acos后乱输的情况 如acosx
                QMessageBox::information(this,"Wrong expression","您输入有误",QMessageBox::Ok);
                ui->calB->setEnabled(false);
                return false;
            }
        if(str[i0+4]=='-') //前面有负号的情况
        {
            if(str[i0+5]>'9' && str[i0+5]<'0' && str[i0+5]!='x' && str[i0+5]!='X')
            {
                QMessageBox::information(this,"Wrong expression","您输入有误",QMessageBox::Ok);
                ui->calB->setEnabled(false);
                return false;
            }
            if(optrCode(str[i0+5])!=-1)
            {
                QMessageBox::information(this,"Wrong expression","您输入了连续的运算符",QMessageBox::Ok);
                ui->calB->setEnabled(false);
                return false;
            }
            if(str[i0+5]=='x' || str[i0+5]=='X') //直接跟x的情况
            {
                if(x1>1 || x1<-1)
                {
                   QMessageBox::information(this,"wrong","超出定义域",QMessageBox::Yes);
                   return false;
                }
                haveX=true;
                v=acos(-x1);
                i0=i0+6;
                return true;
             }
            i=number(str,i0+5,temp);
            if(str[i]=='x' || str[i]=='X') //asin0.nX 形式
            {
                if(temp*high>1 ||temp*high<-1 || temp*low>1 ||temp*low<-1)
                {
                   QMessageBox::information(this,"wrong","超出定义域",QMessageBox::Yes);
                   return false;
                }
                haveX=true;
                v=acos(-temp*x1);
                i0=i+1;
                return true;
            }
            else  //常数函数
            {
                if(temp>=1 || temp<=-1)
                {
                   QMessageBox::information(this,"wrong","超出定义域",QMessageBox::Yes);
                   return false;
                }
                v=acos(-temp);
                i0=i;
                return true;
            }
        }
         }
    else // 应对情况：s，l，c开头的乱输的英文
       QMessageBox::information(this,"Wrong expression","请不要在表达式中乱输英文",QMessageBox::Ok);
       ui->calB->setEnabled(false);
       return false;

}

double Widget::operate(double a, char op, double b) //运算函数
{
    switch(op)
        {
        case 0:		return a + b;
        case 1:		return a - b;
        case 2:		return a * b;
        case 3:		return a / b;
        case 4:     return pow(a,b); //次方
        }
        return 0;
}

bool Widget::eval(const char *express, double &v, double x1) //表达式求值
{
    int i;//字符数组下标
    double a, b; //用于接收栈顶变量 进行运算
    char c, code;
    Gstack<double> opnd;//操作数栈
    Gstack<char> optr; //操作符栈
    optr.push(6);//安个6 在优先级数组中对应( 让后进来的数满足条件就进栈
    bool haveexp=false; //表示表达式输入与否
    i = 0; //遍历字符数组的指针
    c = express[i]; //所指向字符
    haveX=false;
    while(c != '\0' || optr.Top() != 6)
    {
        haveexp=true;
        if (c >= '0' && c <= '9' ) //常数
        {
            i = number(express, i, a);
            opnd.push(a);
            c = express[i];
        }
        else if (c==' ')
        {
            c=express[++i];
            continue;
        }
        else if(i==0 && express[i]=='-')
        {
            if(optrCode(express[i+1])!=-1) //-前面不是左括号的话，则写错了运算符
            {
            QMessageBox::critical(this,"wrong!","别连着输运算符",QMessageBox::Yes);
            ui->calB->setEnabled(false);
            return false;
            }
            i=number(express,i+1,a);
            opnd.push(-a);
            c=express[i];
        }
        //前面是运算符的话
        else if(c=='-' && optrCode(express[i-1])!=-1)
        {
           if(optrCode(express[i-1])!=6) //-前面不是左括号的话，则写错了运算符
           {
           QMessageBox::critical(this,"wrong!","请将负数用括号括起来",QMessageBox::Yes);
           ui->calB->setEnabled(false);
           return false;
           }

           i=number(express,i+1,a);
           opnd.push(-a);
           if(express[i]==')') //用括号包起来的负数 直接无视掉左右括号 将指针移到后面进行计算
            {
                  optr.pop(); //弹出左括号
                  c=express[++i];//将)后面的值赋给c
                  continue;
            }
            else c=express[i]; //如果不是用括号包起来的，继续按照表达式求值规则处理



        }
        else if(c=='s' || c=='c' || c=='l' || c=='a') //sin cos log 反三角
        {
            bool isMathfunction=false;
            isMathfunction=number(express,i,a,x1); //计算三角函数的值
            if(isMathfunction)
             opnd.push(a);
            else return false;
            c=express[i];
        }
        else if (c=='x' || c=='X') //遇到x时
        {
            haveX=true;
            opnd.push(x1);
            c=express[++i];
        }
        else if((c<='z' && c>='a') ||( c>='A' && c<='Z') && c!='X' && c!='x' && optrCode(c)==-1 && c!='-') //用户乱输时
        {
            QMessageBox::information(this,"Wrong expression","请不要在表达式中乱输英文",QMessageBox::Ok); //这有问题 得改
            ui->calB->setEnabled(false);
            return false;
        }
        else if(optrCode(c)==5)  //一元运算符
        {
            if(opnd.isEmpty())
            {
                QMessageBox::information(this,"Wrong expression","请不要在表达式中乱输运算符",QMessageBox::Ok);
                ui->calB->setEnabled(false);
                return false;
            }
           opnd.push(operate(opnd.pop(),optrCode(c))); //一元运算符直接计算后入栈
           c=express[++i];
           continue;
        }
        else //运算符
        {
            code = optrCode(c);
            if (code < 0)
            {
                QMessageBox::information(this,"Wrong expression","请不要在表达式中输入不支持的运算符",QMessageBox::Ok);
                ui->calB->setEnabled(false);
                return false;
            }
            if(opnd.isEmpty() && code!=6)
            {
                QMessageBox::information(this,"Wrong expression","您真幽默，运算符都比数多了！",QMessageBox::Ok);
                ui->calB->setEnabled(false);
                return false;
            }

            switch(pri[optr.Top()][code])
            {
            case '<':	optr.push(code);  //优先级大者进栈，小者则弹栈运算后 将结果入栈
                        c = express[++i];
                        break ;
            case '=':	optr.pop();
                        c = express[++i];
                        break ;
            case '>':
                        code = optr.pop();
                        if(opnd.isEmpty())
                        {
                        QMessageBox::information(this,"Wrong expression","你没输数",QMessageBox::Ok);
                        ui->calB->setEnabled(false);
                        return false;
                        }
                        b = opnd.pop();
                        int zhengfu=1/b; //根号次数
                        int zhengfu1=zhengfu%2;//根号次数·
                        if(opnd.isEmpty()) //栈为空
                        {
                        QMessageBox::information(this,"Wrong expression","你没输够数或者你的系数没加运算符",QMessageBox::Ok);
                        ui->calB->setEnabled(false);
                        return false;
                        }
                        if(code==3)//除0
                        {

                            if((b<pow(10,-5) && b>=0)||(b>-pow(10,-5) && b<=0))
                            {
                            QMessageBox::information(this,"Wrong expression","除0错误",QMessageBox::Ok);
                            return false;
                            }
                        }
                        if(code==4 && !zhengfu1 && b<1 && opnd.Top()<0) //^,次数的倒数为2的倍数 意思就是偶次根号 偶次根号内数不能小于0
                        {
                            QMessageBox::information(this,"Wrong expression","根号内数字小于0,计算失败(可能因二分法计算程序时带入大值导致)",QMessageBox::Ok);
                            ui->calB->setEnabled(false);
                            return false;
                        }
                        a = opnd.pop();
                        opnd.push(operate(a, code, b));
                        break ;
            }
        }
    }
    if(!haveX)
    {
        QMessageBox::information(this,"Wrong expression","请在表达式中加入自变量",QMessageBox::Ok);
        ui->calB->setEnabled(false);
        return false;
    }
    if(!haveexp)
    {//没进while 也就是表达式为空
    QMessageBox::information(this,"Wrong expression","你还没输呢",QMessageBox::Ok);
    ui->calB->setEnabled(false);
    return false;
    }
    v = opnd.Top(); //最终运算结果
    return true;
}



bool Widget::sanjiaoeval(const char *str, int &i0, int begin, double &v, double x1,int type) //对三角函数括号内的表达式进行运算
{
    int numberofleft=1;//左括号个数
    int start=begin;//第一个左括号
    int im=0;//承载系数的新数组下标
    double result;
    static char tmp1[128] = {0}; //单独用个数组装三角函数，并对其进行计算
    int xishu=1;//x前系数正负
    while(numberofleft!=0 && str[++start]!='\0')
   {
     if(str[start]=='(') ++numberofleft;
     if(str[start]==')') --numberofleft;
     if(numberofleft==0 && str[start]==')') break; //右括号比左括号多或者已到了
     tmp1[im++]=str[start];
   }

   if(numberofleft!=0 || str[start]=='\0') //右括号比左括号少
   {
     QMessageBox::information(this,"wrong","您的括号输入有问题",QMessageBox::Yes);
     return false;
   }
   tmp1[im]='\0';
   bool success1=eval(tmp1,result,x1);
   if(!success1)
       {
           QMessageBox::information(this,"wrong","计算失败",QMessageBox::Yes);
           return false;
       }
   switch(type) //确定用什么对应函数对函数进行计算
   {
   case 1:v=sin(result);break;
   case 2:v=cos(result);break;
   case 3:if(result<=0) //log值域判定
       {
           stop=true;
       }
       v=log(result);break;
   case 4:
       if(result<=-1  || result>=1) //反三角函数值域判定
        {
            stop=true;
        }
       v=asin(result);break;
   case 5:
       if(result<=-1  || result>=1)
       {
           stop=true;
       }
       v=acos(result);break;
   default:
       QMessageBox::information(this,"wrong","您的函数输入有问题",QMessageBox::Yes);
       return false;
   }
   i0=start+1;
   return true;
}

void Widget::Calculate() //注:只用二分法求出其中一个根，其他根用穷举法求
{
    double y1,y2,y3;
    QString Exprecord=expE->text();//表达式文本
    double upper=INTMAX; //从-2^16到2^16中取根
    double lower=INTMIN;
    Accuracy=pow(10,-5);//精度为10的-5次 方
    double midder=0;
    bool NumberofFunc=true;//根的有无
    int times=0; //穷举方法 测试函数有无根 times达到50 则认为函数无根
    bool erfensuccess=false;
    if(toomany) //区间内有超出20个根
    {
      QMessageBox::information(this,"Please","区间内根太多 请缩小区间",QMessageBox::Yes);
      return;
    }
    while(upper-lower>Accuracy) //模仿的二分查找所写
    {
    bool success=eval(Exprecord.toLatin1().data(),y3,upper);//检测是否输入表达式
    if(!success) break;
    if(stop) break;
    eval(Exprecord.toLatin1().data(),y1,lower);
    if(stop) break;
    midder=(upper+lower)/2;
    eval(Exprecord.toLatin1().data(),y2,midder);
    if(stop) break;
    if(y1==0 && y2==0 && y3==0) break;  //常数函数
    if(y1==0) {midder=lower;break;} //lower对应的函数值为0时 lower为根
    if(y2==0) break; //mider对应的函数值为0时 mider为根
    if(y3==0) {midder=upper;break;}  //upper对应的函数值为0时 upper为根
    if(y1*y2<0) {upper=midder;continue;} //在前面一半找根
    else if(y2*y3<0) {lower=midder;continue;} //在后面一半找根
    else if(y1*y2>0 && y2*y3>0) //三个函数值都同号时 缩小范围找根
    {   times++;
        upper=upper/2;
        lower=lower/2;
        if(times==30){    //穷举法，如x^2-5*x+6三个端点都大于０　用二分法很难求根
            //于是我决定把区间的范围缩小到无限逼近０　如果这样　三个ｙ都同号　那么这个函数就确定没有根了
        NumberofFunc=false;
        break;
    }
    }
    }
    if(!stop) //不是由于超出定义域造成无法用二分法时
    {
    erfensqrt=midder; //得到二分结果的根
    if(times<30)
    erfensuccess=true; //二分法成功
    }
    QString str;
    QString erfenstr="";
    if(length1==0) NumberofFunc=false;
    if(erfensuccess)
    {
       erfenstr.append("函数用二分法求出的根为： ");
       erfenstr.append(QString::number(erfensqrt,10,2));
       erfenstr.append(" ");
    }
    if(NumberofFunc) //有根时 numberoffunc bool值为true
    {

     while(length1--!=0)
     {
      str.append(QString::number(sqrt[length1],10,2));
      str.append("  ");
     }
    QMessageBox::information(this,"Success!",erfenstr+"函数在区间内的根有"+str,QMessageBox::Yes);
    }

    else if(!NumberofFunc)
        QMessageBox::information(this,"Defeat!",erfenstr+"此区间内求根失败",QMessageBox::Yes);

    ui->calB->setEnabled(false);
    ui->printB->setEnabled(false);
}

void Widget::Printimage() //画坐标轴 如果每个点都计算成功 则打开paintevent开关 绘画图像
{
     whetherPic=true;//打开paintevent开关
     toomany=false;
     QString Maxrecord=ui->maxE->text();
     QString Minrecord=ui->minE->text();
     if(Maxrecord.isEmpty() || Minrecord.isEmpty())
     {
         QMessageBox::warning(this,"wrong","请输入区间！，本计算器求根是在区间内求的！",QMessageBox::Yes);
         ui->calB->setEnabled(false);
         return;
     }
     ui->calB->setEnabled(true);
     low =Minrecord.toDouble();
     high=Maxrecord.toDouble();
     double y=1.0;
     length1=0;
     //获取文本框中的字符 转换成点的坐标
    if(whetherPic==true) {

     double step=(high-low)/11000;

     Printx(low,high);
     int i=0;
     QString Exprecord;
     bool success;
     double yend;
     for(double x2=low;x2<=high;x2+=step){
         //计算一万一千个点对应的函数值，装入Yvalue数组 再进行排序
            Exprecord=expE->text();
          //y的值
            double x3=x2+step;

            success=eval(Exprecord.toLatin1().data(),y,x2);
            if(!success) break;
            eval(Exprecord.toLatin1().data(),yend,x3);//穷举法入根数组

            if(length1<=20) //区间内根小于等于20
            {
            if(y*yend<0) sqrt[length1++]=(x2+x3)/2;   //取两个小点X的平均值为根
            else if(y*yend==0) sqrt[length1++]=(y==0)?x2:x3; //取根
            }
            else if(length1>20)
            {
                QMessageBox::information(this,"Please","区间内根太多 请缩小区间",QMessageBox::Yes);
                toomany=true;
                return;
            }
            if(y>max) max=y; //获取函数最大最小值
            if(min>y) min=y;
       }
     if(success){
       Printy(min,max); //在最大值，最小值之间十等分，输出刻度
       drawornot=true; //计算成功 则画函数图像
     }

    }

     expE->setEnabled(false);
    ui->maxE->setEnabled(false);
     ui->minE->setEnabled(false);

}

//降低误操作，在修改函数时图像会动态变化 面对报错会很烦 故增加这个按钮 减少烦恼
void Widget::on_pushButton_clicked()
{
    ui->calB->setEnabled(false);
    expE->setEnabled(true);
    ui->maxE->setEnabled(true);
    ui->minE->setEnabled(true);
    whetherPic=false;
    drawornot=false; //关闭绘图开关 防止改变表达式时图像动态变化
    ui->printB->setEnabled(true);
    length1=0;
}









