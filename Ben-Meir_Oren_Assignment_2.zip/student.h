#ifndef STUDENT_H_
#define STUDENT_H_


namespace Oren_BenMeir_ccny_csc212{
    class student{
    public:
        student();
        void Set_Math_Grade(int);
        void Set_English_Grade(int);
        int Get_Math_Grade();
        int Get_English_Grade();
    private:
        int Math, English;
    };
}


#endif /* STUDENT_H_ */

