//COMSC-210 | Lab 12: Pointers II | Toma Dimov
//IDE used: VSC w/gbd compiler
#include <iostream>
#include <fstream>
#include <array>
using namespace std;

const int SFX_SIZE = 30;

/*
Write a program that will exercise STD::array functions. Code a real-world simulation of something that could be simulated by an array. The requirements are:
    *Use an STD::array
    *Use a large variety of the <array> member functions from this module to demonstrate your understanding of the STD::array.
*/

int main(){
    //declaration
    array<string,SFX_SIZE> sfx;
    
    //import data from file
    ifstream fin;
    fin.open("data.txt");
    if(fin.good()){
        string input;
        int i =0;
        for(int i=0;i<sfx.size();i++){
            getline(fin,input);
            sfx[i] = input;
        }
        fin.close();
    }
    else
        cout<<"File not found.\n";
    
    //report size:
    cout<<"Array Size: "<<sfx.size()<<endl;
    cout<<"Elements:";
    for(string val: (sfx)) cout<< val<<" "; cout<<endl;
    return 0;
}