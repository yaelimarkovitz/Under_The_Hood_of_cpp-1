#include <stdio.h>
#include "cpp2c_encapsulation_defs.h"
extern const char* def_msg;
extern const char* message;
static box largeBox;
void __attribute__((constructor)) calledFirst();
void __attribute__((destructor)) calledEnd();
static box box99;
static box box88;
/*0583223202*/
void thisFunc()
{
    static  int count =0;
    printf("\n--- thisFunc() ---\n\n");
    if(count==0){
        box_init_d(&box99,99);
    }
    box_mult_eq_d(&box99,10);
    count++;
}

void thatFunc()
{
    static int count =0;
    printf("\n--- thatFunc() ---\n\n");
    if(count==0){
        box_init_d(&box88,88);
    }
    box_mult_eq_d(&box88,10);
    count++;
}

void doBoxes()
{
    printf("\n--- Start doBoxes() ---\n\n");
    box b1;
    box_init_d(&b1,3);
    box b2;
    box_init_ddd(&b2,4,5,6);
    printf("b1 volume: %f\n", box_get_volume_C(&b1));
    printf("b2 volume: %f\n", box_get_volume_C(&b2));
    box_mult_eq_d(&b1,1.5);
    box_mult_eq_d(&b2,0.5);
    printf("b1 volume: %f\n", box_get_volume_C(&b1));
    printf("b2 volume: %f\n", box_get_volume_C(&b2));
    box b3 = b2;
    box b4 =b2;
    box_mult_eq_d(&b4,3);
    printf("b3 %s b4\n",(b3.width==b4.width) && (b3.height == b4.height) && (b3.length==b4.length) ? "equals" : "does not equal");
    box_mult_eq_d(&b3,1.5);
    box_mult_eq_d(&b4,0.5);
    printf("Now, b3 %s b4\n", (b3.width==b4.width) && (b3.height == b4.height) && (b3.length==b4.length) ? "equals" : "does not equal");
    printf("\n--- End doBoxes() ---\n\n");
    box_destroy(&b1);
    box_destroy(&b2);
    box_destroy(&b3);
    box_destroy(&b4);
}
void doShelves()
{
    printf("\n--- start doShelves() ---\n\n");
    box aBox ;
    box_init_d(&aBox,5);
    shelf aShelf;
    box_init_d(&(aShelf.boxes[0]),1);
    box_init_d(&(aShelf.boxes[1]),1);
    box_init_d(&(aShelf.boxes[2]),1);
    shelf_print_C(&aShelf);
    shelf_set_box(&aShelf,0,aBox);
    shelf_set_box(&aShelf,1,largeBox);
    shelf_print_C(&aShelf);
    char* tmp ="This is the total volume on the shelf:";
    message =tmp;
    shelf_print_C(&aShelf);
    tmp = "Shelf's volume:";
    message =tmp;
    shelf_print_C(&aShelf);
    box b1;
    box_init_ddd(&b1,2,4,6);
    shelf_set_box(&aShelf,1,b1);
    box_destroy(&b1);
    box b2;
    box_init_d(&b2,2);
    shelf_set_box(&aShelf,2,b2);
    box_destroy(&b2);
    shelf_print_C(&aShelf);
    printf("\n--- end doShelves() ---\n\n");
    box_destroy(&(aShelf.boxes[0]));
    box_destroy(&(aShelf.boxes[1]));
    box_destroy(&(aShelf.boxes[2]));
    box_destroy(&aBox);
}

int main()
{
    printf("\n--- Start main() ---\n\n");

    doBoxes();

    thisFunc();
    thisFunc();
    thisFunc();
    thatFunc();
    thatFunc();
    doShelves();

    printf("\n--- End main() ---\n\n");

    return 0;
}
void calledFirst(){
    box_init_ddd(&largeBox,10,20,30);

}
void calledEnd(){
    box_destroy(&largeBox);
    box_destroy(&box99);
    box_destroy(&box88);
}

