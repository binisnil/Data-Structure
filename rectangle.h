//
// Created by 박윤빈 on 2022/04/12.
//

#ifndef SOONGSIL_RECTANGLE_H
#define SOONGSIL_RECTANGLE_H



class Rectangle {

private:
    int width=0;
    int height=0; //멤버변수


public:
    Rectangle(int w, int h);
    int area(); //멤버함수
    int perimeter(); //멤버함수
};




#endif //SOONGSIL_RECTANGLE_H
