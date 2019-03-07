//
// Created by orenb on 6/25/2018.
//

#include "student.h"
namespace Oren_BenMeir_ccny_csc212{
    void student::Set_Math_Grade(int g){
        if(g>100){
            Math=100;
            return;
        }
        if(g<0){
            Math=0;
            return;
        }
        Math=g;
    }
    void student::Set_English_Grade(int g){
        if(g>100){
            English=100;
            return;
        }
        if(g<0){
            English=0;
            return;
        }
        English=g;
    }
    int student::Get_Math_Grade(){return Math;}
    int student::Get_English_Grade(){return English;}
    student::student(){Math=100;English=100;}
}
