//COMSC-210 | Lab 12: Pointers II | Toma Dimov
//IDE used: VSC w/gbd compiler
#include <iostream>
#include <algorithm> 
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
    
    //report size.
    cout<<"Array Size: "<<sfx.size()<<endl;
    cout<<"Elements:";
    for(string val: (sfx)) cout<< val<<" "; cout<<endl;
    cout<<"First Element: "<<sfx.front()<<endl;
    cout<<"Last Element: "<<sfx.back()<<endl;
    cout<<"Is it Empty? "<< (sfx.empty() ? "No": "Yes")<<endl;  //? operator can be used with booleans for terse expressions. (False : True) 
    cout<<"Address:" << sfx.data()<<endl;

    //using iterators.
    sort(sfx.begin(),sfx.end());
    cout<<"Array Sorted: ";
    for(string val : sfx) cout<<val<<" "; cout<<endl;
    //sort in reverse
    sort(sfx.rbegin(),sfx.rend());
    cout<<"Array Reverse Sorted: ";                 
    for(string val : sfx) cout<<val<<" "; cout<<endl;

    //find.
    string target = "zap";
    array<string,SFX_SIZE>::iterator it =find(sfx.begin(),sfx.end(),target); //make iterator and fill it with the find target (the element's location)
    if(it!=sfx.end())   //not pointing to end means it is found
        cout<<"Element \""<< target<<"\" found in index position " << it - sfx.begin()<<endl;
    else
        cout<<"Element "<<target<<" not found.\n";

    //fill.
    fill(sfx.begin(),sfx.end(),"empty");
    cout<<"Array filled with \"empty\": ";
    for(string val: sfx) cout<< val<<" "; cout<<endl;

    array<char, 3> row1 = {'x','o',' '};
    array<char, 3> row2 = {'o','x','x'};
    array<char, 3> row3 = {'o',' ','o'};
    array<array<char,3>,3> master = {row1,row2,row3};
    cout<<"Middle Element of a 2d Array "<<master[1][1]<<endl;
    return 0;
}