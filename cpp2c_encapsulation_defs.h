#ifndef __CPP2C_ENCAPSULATION_DEFS_H__
#define __CPP2C_ENCAPSULATION_DEFS_H__

#include <stdbool.h>
#define NUM_BOXES  3
//// Box ////////////

// class Box
// {
// public:
//     Box(double dim = 1);
//     Box(double l, double w, double h);
//     ~Box();

//     double getWidth() const;
//     double getLength() const;
//     double getHeight() const;

//     double getVolume() const;
    
//     Box& operator*=(double mult);

// protected:
//     void print() const;

// private:    
//     double length;
//     double width;
//     double height;
// };
// Box operator*(const Box& box, double mult);
// Box operator*(double mult, const Box& box);
// bool operator==(const Box& lhs, const Box& rhs);
// bool operator!=(const Box& lhs, const Box& rhs);

struct b{
        double length;
        double width;
        double height;
}b;

typedef struct b box;
typedef box* boxptr;

// //// Box Defs ////////////

// inline double Box::getWidth() const
// {
//     return width;
// }

// inline double Box::getLength() const
// {
//     return length;
// }

// inline double Box::getHeight() const
// {
//     return height;
// }

// inline double Box::getVolume() const
// {
//     return width * length * height;
// }

// inline Box operator*(const Box& box, double mult)
// {
//     Box ret = box;
//     ret *= mult;
//     return ret;
// }

// inline Box operator*(double mult, const Box& box)
// {
//     return box * mult;
// }

// inline bool operator==(const Box& lhs, const Box& rhs)
// {
//     return lhs.getWidth() == rhs.getWidth() && lhs.getHeight() == rhs.getHeight() && lhs.getLength() == rhs.getLength();
// }

// inline bool operator!=(const Box& lhs, const Box&rhs)
// {
//     return !(lhs == rhs);
// }
void box_init_ddd(boxptr this, double length, double width, double highet);
void box_init_d(boxptr this, double dim);
void box_print_vC(const boxptr const this);
boxptr box_mult_eq_d(boxptr this , double mult);
double box_get_volume_C(const boxptr this);
void box_destroy(const boxptr this);
/*inline functions in place as the compiler does*/

//// Shelf ////////////
// class Shelf
// {
// public:
//     void setBox(int index, const Box& dims);
//     double getVolume() const;
//     Box& getBox(int index);
//     void print() const;
    
//     static int getNumBoxes();
//     static void setMessage(const char* msg);
    
// private:
//     static const unsigned int NUM_BOXES = 3;
//     static const char* const DEF_MSG;
//     static const char* message;

//     Box boxes[NUM_BOXES];
// };

struct s{
    box boxes[NUM_BOXES];
};
typedef struct s shelf;
typedef shelf* shelfptr;

// //// Shelf Defs ////////////

// inline Box& Shelf::getBox(int index)
// {
//     return boxes[index];
// }

// inline int Shelf::getNumBoxes()
// {
//     return NUM_BOXES;
// }

// inline void Shelf::setMessage(const char* msg)
// {
//     message = msg;
// }

void shelf_print_C(shelfptr this);
double shelf_get_volume_C(shelfptr this);
void shelf_set_box(shelfptr this, int index, const box dim);



#endif // __CPP2C_ENCAPSULATION_DEFS_H__

