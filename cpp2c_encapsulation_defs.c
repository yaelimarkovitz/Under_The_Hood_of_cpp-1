#include <stdio.h>
#include "cpp2c_encapsulation_defs.h"
const char* def_msg = "The total volume held on the shelf is";
const char* message ="The total volume held on the shelf is";
////////// Box ////////////

void box_init_ddd(boxptr this, double length, double width, double highet){
    this->length =length;
    this->height = highet;
   this->width =width;
    box_print_vC(this);

}
void box_init_d(boxptr this, double dim){
   this->length =dim;
    this->height = dim;
    this->width =dim;
    box_print_vC(this);
}

double box_get_volume_C(const boxptr this)
{
    return this->width * this->length * this->height;
}
void box_destroy(const boxptr this){
    printf("Box destructor, %f x %f x %f\n", this->width,this-> height,this-> length);
}

boxptr box_mult_eq_d(boxptr this , double mult){
    this->width *=mult;
    this->length *=mult;
    this->height*=mult;
    return this;
}
void box_print_vC(const boxptr const this){
    printf("Box: %f x %f x %f\n", this->length,this->width, this->height);
}

//// Shelf ////////////

//const char* const Shelf::DEF_MSG = "The total volume held on the shelf is";
//const char* Shelf::message = Shelf::DEF_MSG;
void shelf_set_box(shelfptr this, int index, const box dim){
    this->boxes[index] = dim;
}
void shelf_print_C(shelfptr s){
    printf("%s %f\n",message,shelf_get_volume_C(s));
}
double shelf_get_volume_C(shelfptr this){
    double vol = 0;
    for (size_t i = 0; i < NUM_BOXES; ++i)
        vol += box_get_volume_C(&(this->boxes[i]));
    return vol;
}



