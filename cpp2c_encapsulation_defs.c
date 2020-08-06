#include <stdio.h>
#include "cpp2c_encapsulation_defs.h"
const char* def_msg = "The total volume held on the shelf is";
const char* message ="The total volume held on the shelf is";
////////// Box ////////////


// Box::Box(double l, double w, double h) 
// :   length(l)
// ,   width(w)
// ,   height(h) 
// { 
//     print(); 
// }
void box_init_ddd(boxptr this, double length, double width, double highet){
    this->length =length;
    this->height = highet;
   this->width =width;
    box_print_vC(this);

}
// Box::Box(double dim) 
// :   length(dim)
// ,   width(dim)
// ,   height(dim) 
// { 
//     print();
// }
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
// Box::~Box()
// {
//     std::printf("Box destructor, %f x %f x %f\n", width, height, length);
// }
void box_destroy(const boxptr this){
    printf("Box destructor, %f x %f x %f\n", this->width,this-> height,this-> length);
}
// Box& Box::operator*=(double mult)
// {
//     width *= mult;
//     height *= mult;
//     length *= mult;

//     return *this;
// }
boxptr box_mult_eq_d(boxptr this , double mult){
    this->width *=mult;
    this->length *=mult;
    this->height*=mult;
    return this;
}
// void Box::print() const
// {
//     printf("Box: %f x %f x %f\n", length, width, height); 
// }
void box_print_vC(const boxptr const this){
    printf("Box: %f x %f x %f\n", this->length,this->width, this->height);
}

//// Shelf ////////////

//const char* const Shelf::DEF_MSG = "The total volume held on the shelf is";
//const char* Shelf::message = Shelf::DEF_MSG;
// void Shelf::setBox(int index, const Box& dims)
// {
//     boxes[index] = dims;
// }

void shelf_set_box(shelfptr this, int index, const box dim){
    this->boxes[index] = dim;
}

// void Shelf::print() const
// {
//     std::printf("%s %f\n", message, getVolume());
// }
void shelf_print_C(shelfptr s){
    printf("%s %f\n",message,shelf_get_volume_C(s));
}
// double Shelf::getVolume() const
// {
//     double vol = 0;
//     for (size_t i = 0; i < NUM_BOXES; ++i)
//         vol += boxes[i].getVolume();

//     return vol;
// }
double shelf_get_volume_C(shelfptr this){
    double vol = 0;
    for (size_t i = 0; i < NUM_BOXES; ++i)
        vol += box_get_volume_C(&(this->boxes[i]));
    return vol;
}



