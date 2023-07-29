// Creating vector

#include <iostream>
using namespace std;


class DynamicArray{

    private:

        int *arr = NULL;
        int capacity;
        int size;

    public:
        // default array
        DynamicArray(){
            capacity = 1;
            size = 0;
            arr = new int[1];
        }

        // array capacity initialised by user
        DynamicArray(int capacity){
            this -> capacity = capacity;
            size = 0;
            arr = new int[capacity];
        }

        int getSize(){
            return size;
        }

        int getCapacity(){
            return capacity;
        }

        bool isEmpty(){
            if(size == 0)
                return true;
            return false;
        }

        int peek(){
            if(isEmpty()){
                cout << "Garbage!";
            }
            return arr[size - 1];
        }

        void pushBack(int item){
            
            if(size == capacity){
                growArray();
            }

            arr[size] = item;
            size++;
        }

        void popBack(){

            if(isEmpty()){
                return;
            }

            arr[size - 1] = -1;
            size--;

            if(size == (capacity/2)){
                shrinkArray();
            }
        }

        void growArray(){
            int *temp = new int[capacity * 2];
            capacity *= 2; // new capacity

            for(int i = 0; i < capacity; i++){
                temp[i] = 0;
            }

            // copy old array into new
            for(int i = 0; i < size; i++){
                temp[i] = arr[i];
            }

            // error
            // arr = newArr;
            // delete[] newArr;

            delete[] arr;
            arr = temp;
        }

        void shrinkArray(){
            capacity = size;
            int *temp = new int[capacity];
            
            for(int i = 0; i < size; i++){
                temp[i] = arr[i];
            }
            // delete old array 
            delete[] arr;
            // new array whose capacity is half of its original.
            arr = temp;
        }

        void print(){
            for(int i = 0; i < size; i++){
                cout << arr[i] << "\t";
            }   cout << endl;
        }

        int search(int key){
            // linear search
            for(int i = 0;  i < size; i++){
                if(arr[i] == key)
                    return i;
            }   return -1;
        }

        /*
            Insertion in ARRAY
            1. Shift all the elements by one to the right of destination index.
            2. Insert new element on reaching the destination index.
        */

        void insertAt(int idx, int item){
            if(!(idx >= 0 && idx < size)){
                cout << "Invalid index! " << idx;
                return;
            }

            if(size == capacity){
                growArray();
            }

            for(int i = size - 1;  i >= idx; i--){
                arr[i + 1] = arr[i];
            }

            arr[idx] = item;
            size++;
        }

        /*
            Deletion in ARRAY
            1. The element to be deleted is overwritten by elment on its right.
            2. Elements on the right of to be deleted element shifts to left by one step.
        */

       void deleteAt(int idx){

            if(!(idx >=0 && idx < size)){
                cout << "Invalid Index !\n";
                return;
            }

            int toBeDeleted = arr[idx];

            for(int i = idx; i < size; i++){
                arr[i] = arr[i + 1];
            }

            if(size == (capacity / 2)){
                shrinkArray();
            }
            size--;
       }

};


void create(){
    DynamicArray da;
    
    //..............................................................................
    cout << "Element\t" << "Capacity\t" << "Size" << endl;

    da.pushBack(10);
    cout << da.peek() << "\t" << da.getCapacity() << "\t\t" << da.getSize() << endl;

    da.pushBack(20);
    cout << da.peek() << "\t" << da.getCapacity() << "\t\t" << da.getSize() << endl;
    
    da.pushBack(30);
    cout << da.peek() << "\t" << da.getCapacity() << "\t\t" << da.getSize() << endl;
    
    da.pushBack(40);
    cout << da.peek() << "\t" << da.getCapacity() << "\t\t" << da.getSize() << endl;
    
    da.pushBack(50);
    cout << da.peek() << "\t" << da.getCapacity() << "\t\t" << da.getSize() << endl;
    
    da.pushBack(60);
    cout << da.peek() << "\t" << da.getCapacity() << "\t\t" << da.getSize() << endl;
    
    da.pushBack(70);
    cout << da.peek() << "\t" << da.getCapacity() << "\t\t" << da.getSize() << endl;
    
    da.pushBack(80);
    cout << da.peek() << "\t" << da.getCapacity() << "\t\t" << da.getSize() << endl;
    
    da.pushBack(90);
    cout << da.peek() << "\t" << da.getCapacity() << "\t\t" << da.getSize() << endl;
    
    da.pushBack(100);
    cout << da.peek() << "\t" << da.getCapacity() << "\t\t" << da.getSize() << endl;
    
    da.pushBack(110);
    cout << da.peek() << "\t" << da.getCapacity() << "\t\t" << da.getSize() << endl;
    
    da.pushBack(120);
    cout << da.peek() << "\t" << da.getCapacity() << "\t\t" << da.getSize() << endl;
    
    da.pushBack(130);
    cout << da.peek() << "\t" << da.getCapacity() << "\t\t" << da.getSize() << endl;
    
    da.pushBack(140);
    cout << da.peek() << "\t" << da.getCapacity() << "\t\t" << da.getSize() << endl;
    
    da.pushBack(150);
    cout << da.peek() << "\t" << da.getCapacity() << "\t\t" << da.getSize() << endl;
    //..............................................................................

    //..............................................................................
    da.print();
    //..............................................................................

    //..............................................................................
    cout << endl;
    cout << "Element\t" << "Capacity\t" << "Size" << endl;
    da.popBack();
    cout << da.peek() << "\t" << da.getCapacity() << "\t\t" << da.getSize() << endl;
    da.popBack();
    cout << da.peek() << "\t" << da.getCapacity() << "\t\t" << da.getSize() << endl;
    da.popBack();
    cout << da.peek() << "\t" << da.getCapacity() << "\t\t" << da.getSize() << endl;
    da.popBack();
    cout << da.peek() << "\t" << da.getCapacity() << "\t\t" << da.getSize() << endl;
    da.popBack();
    cout << da.peek() << "\t" << da.getCapacity() << "\t\t" << da.getSize() << endl;
    da.popBack();
    cout << da.peek() << "\t" << da.getCapacity() << "\t\t" << da.getSize() << endl;
    da.popBack();
    cout << da.peek() << "\t" << da.getCapacity() << "\t\t" << da.getSize() << endl;
    da.popBack();
    cout << da.peek() << "\t" << da.getCapacity() << "\t\t" << da.getSize() << endl;
    da.popBack();
    cout << da.peek() << "\t" << da.getCapacity() << "\t\t" << da.getSize() << endl;
    da.popBack();
    cout << da.peek() << "\t" << da.getCapacity() << "\t\t" << da.getSize() << endl;
    da.popBack();
    cout << da.peek() << "\t" << da.getCapacity() << "\t\t" << da.getSize() << endl;
    da.popBack();
    cout << da.peek() << "\t" << da.getCapacity() << "\t\t" << da.getSize() << endl;
    da.popBack();
    cout << da.peek() << "\t" << da.getCapacity() << "\t\t" << da.getSize() << endl;
    da.popBack();
    cout << da.peek() << "\t" << da.getCapacity() << "\t\t" << da.getSize() << endl;
    //..............................................................................
}


void f1(){
    DynamicArray da;
    da.pushBack(10);
    da.pushBack(20);
    da.pushBack(30);
    da.pushBack(40);
    da.pushBack(50);
    da.pushBack(60);
    da.pushBack(70);
    da.pushBack(80);
    da.pushBack(90);

    cout << "Array : ";
    da.print();

    da.insertAt(0, 100);
    cout << "Array after inserting 100 at 0th index : ";
    da.print();

    da.insertAt(4, 200);
    da.print();
    cout << "Size of array = " << da.getSize() << endl;
    da.insertAt(12, 300);

    da.insertAt(11, 300);
    cout << endl;
    da.print();
}


void f2(){
    DynamicArray da;
    da.pushBack(10);
    da.pushBack(20);
    da.pushBack(30);
    da.pushBack(40);
    // da.pushBack(50);
    // da.pushBack(60);
    // da.pushBack(70);
    // da.pushBack(80);
    // da.pushBack(90);
    
    cout << "Capacity = " << da.getCapacity() << " Size = " << da.getSize() << endl;

    cout << "Original Array : ";
    da.print();

    da.deleteAt(3);
    cout << "Array after deletion operation : ";
    da.print();
}


int main(void){
    // create();
    // f1();
    f2();
    return 0;
}