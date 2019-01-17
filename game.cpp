#include "game.h"
#include "ui_game.h"

game::game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::game)
{
    ui->setupUi(this);
    timer = new QTimer();
    timer->setInterval(300);
    connect(timer, SIGNAL(timeout()), this, SLOT(gamerule()));
}

game::~game()
{
    delete ui;
}
void game::paintEvent(QPaintEvent *event){

    Q_UNUSED(event);
    QPainter p(this);
    QRect borders(0, 0, width()-1, height()-1);
    QColor gridColor = Qt::red;
    gridColor.setAlpha(10);
    p.setPen(gridColor);
    double cellWidth = (double)width()/WSize;
    for(double k = cellWidth; k <= width(); k += cellWidth)
            p.drawLine(k, 0, k, height());
    double cellHeight = (double)height()/WSize;
    for(double k = cellHeight; k <= height(); k += cellHeight)
            p.drawLine(0, k, width(), k);
    for(int k=1; k <= WSize; k++) {
           for(int j=1; j <= WSize; j++) {
               if(universe(k-1,j-1) == true) {
                   qreal left = (qreal)(cellWidth*j-cellWidth);
                   qreal top  = (qreal)(cellHeight*k-cellHeight);
                   QRectF r(left, top, (qreal)cellWidth, (qreal)cellHeight);
                   p.fillRect(r, QBrush(Qt::red));
               }
           }
       }
}
void game::gamerule(){
    int count = 0;
    int changed = 0;
        generation = universe;
    for(int i = 0; i<WSize; i++){

        for(int j = 0; j<WSize; j++){
            count = 0;
            if(universe(i,j) == false){
                for(int v = 0; v<3; v++){
                    if(count > 3) break;
                    for(int k = 0; k<3; k++){
                        if((universe(i+v-1,j+k-1))==true && ((i+v-1==i) && (j+k-1 == j)) != 1) count++;
                    }
                }
                if(count == 3) {generation(i,j) = true; changed++;}
            }
            else{
                for(int v = 0; v<3; v++){
                    for(int k = 0; k<3; k++){
                        if(universe(i+v-1,j+k-1)==true && ((i+v-1==i) && (j+k-1 == j)) != 1 ) count++;
                    }
                }
                if((count <2) || (count >3) ) {generation(i,j) = false; changed++;}
            }
            }
        }
    universe = generation;
    if(changed == 0) stop();
    update();
    }
void game::stop(){
    timer->stop();
}
void game::startgame(){
    timer->start();
}
void game::mousePressEvent(QMouseEvent *event){
    double cellWidth = (double)width()/WSize;
    double cellHeight = (double)height()/WSize;
    int k = floor(event->y()/cellHeight);
    int j = floor(event->x()/cellWidth);
    universe(k,j) = !universe(k,j);
    update();
}
