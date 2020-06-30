#ifndef __CPP2C_ENCAPSULATION_DEFS_H__
#define __CPP2C_ENCAPSULATION_DEFS_H__

#include <stdbool.h>
#define NUM_BOXES  3
//// Box ////////////
struct b{
        double length;
        double width;
        double height;
}b;
typedef struct b box;
typedef box* boxptr;
void box_init_ddd(boxptr this, double length, double width, double highet);
void box_init_d(boxptr this, double dim);
void box_print_vC(const boxptr const this);
boxptr box_mult_eq_d(boxptr this , double mult);
double box_get_volume_C(const boxptr this);
void box_destroy(const boxptr this);
/*********inline***********/
double box_get_width_C(const boxptr this);
double box_get_length_C(const boxptr this);
double box_get_hight_C(const boxptr this);
box g_mult_box_d(const boxptr this, double mult);
box g_mult_d_box(double mult,const boxptr box);
bool g_eq_box_box(const boxptr lhs ,  const boxptr rhs);
bool g_neq_box_box(const boxptr lhs ,  const boxptr rhs);
/**************inline*****************/
//// Shelf ////////////
//    static const char* const DEF_MSG;
//    static const char* message;
struct s{
    box boxes[NUM_BOXES];
};
typedef struct s shelf;
typedef shelf* shelfptr;
void shelf_print_C(shelfptr this);
double shelf_get_volume_C(shelfptr this);
void shelf_set_box(shelfptr this, int index, const box dim);
/****************inline********************/
box shelf_get_box(shelfptr s , int index);
int shelf_get_num_books(shelfptr s);
//inline void Shelf::setMessage(const char* msg)
/***********inline********/
#endif // __CPP2C_ENCAPSULATION_DEFS_H__

