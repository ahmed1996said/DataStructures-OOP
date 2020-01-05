//
// Created by Ahmed Al Mahrooqi on 2019-03-24.
//


#include "IntMaxHeap.h"

IntMaxHeap::IntMaxHeap(){
    size = 4;
    array = new int[size];
    numItems=0;

    for(int i =0;i<=size;i++)       //create an empty array
        array[i]='\0';
}


void IntMaxHeap::insert(int x) {

    int index;
    if(numItems>=size){         //resize

        int old_size = size;
        size = size*2;
        int *temp = array;

        array = new int[size];

        for(int i = 0; i < old_size; i++)
            array[i]=temp[i];

        delete[] temp;
    }

    index = numItems;
    array[index]=x;

    percolateUp(index);

    numItems++;

}



bool IntMaxHeap::remove(int &out) {

    if(empty())return false;

    out = array[0];
    array[0]=array[numItems-1];             //replace root with last item
    array[numItems-1] ='\0';                //clear last space
    numItems--;

    percolateDown(0);

    return true;


}


bool IntMaxHeap::empty() {
    return numItems==0;
}

int IntMaxHeap::peek() {
    return array[0];
}

void IntMaxHeap::percolateUp(int n) {

    int parent;
    int temp;
    while(n>0){

        parent = (n-1)/2;
        if( array[n] <= array[parent])
            return;
        else{

            temp=array[parent];
            array[parent]=array[n];
            array[n]=temp;



            n=parent;
        }

    }


}

void IntMaxHeap::percolateDown(int n) {

    int childIndex = 2 * n + 1;
    int value = array[n];
    int maxValue;
    int maxIndex;

    int temp;



    while(childIndex<size){
        maxValue = value;
        maxIndex = -1;

        for(int i =0;i<2 && i+childIndex<size; i++){
            if(array[i+childIndex]>maxValue){
                maxValue=array[i+childIndex];
                maxIndex=i+childIndex;
            }
        }
        if(maxValue==value)
        break;
        else{
        temp= array[n];            //swap

        array[n]=array[maxIndex];
        array[maxIndex]=temp;

        n=maxIndex;
        childIndex= 2 * n + 1;
        }
    }

}

