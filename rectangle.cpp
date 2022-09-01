//
// Created by 박윤빈 on 2022/04/12.
//

#include "rectangle.h"

using namespace std;

Rectangle::Rectangle(int w, int h):width(w), height(h){

}
int Rectangle::area(){
    if(width<0){
        width=0;
    }
    if(height<0){
        height=0;
    }
        return (width*height);
}


int Rectangle::perimeter() {
    if(width<0){
        width=0;
    }
    if(height<0){
        height=0;
    }
        return 2*(width+height);
}
