#include <iostream>
#include <random>
#include <string>
#include <math.h>
using namespace std;

string doomDay(int m, int d, int y);


int main(){
    int m=1; //change here.
    int d=1; //change here.
    int y=1850; //change here.

    srand(time(NULL));

    for(int i = 0;i<=100;i++){
        m = rand() % 12 + 1;
        d= rand() % 27 + 1;
        y = rand() % 350 + 1800;
        cout<<m<<'/'<<d<<'/'<<y<<'\t';
        cout<<doomDay(m,d,y)<<endl;
    }
    return 0;
}    

string doomDay(int m, int d, int y){
    string weeks[] ={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
    int doommonthday[] = {0,3,28,0,4,9,6,11,8,5,10,7,12};
    int anchorIndex[] = {2,0,5,3};
    int century = (y/100);
    int l2dig = y-((y/100)*100);
    int anchor= anchorIndex[century%4];

    //takes care leap year.
    if (y%400 == 0 || y%4 ==0){
        doommonthday[1]=4;
        doommonthday[2]=29;
    }

    int dc = d-doommonthday[m];
    int mc = l2dig/12+l2dig%12+(l2dig%12)/4;
    int result = anchor+dc+mc;
    while(result<7)
        result+=7;
    return weeks[result%7];
}