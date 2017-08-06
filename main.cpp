/* 
 * File:   main.cpp
 * Author: Caeleb Moeller
 * Created on 
 * Purpose: 
 */

//System Libraries Here
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//User Libraries Here


//Function Prototypes Here
bool Restart();
//Program Execution Begins Here

int main() {
    //Declare and process variables
    bool restart;
    short cnt[10]={0};
    string word[10];
    bool check=false;
    
    //Process/Calculations Here
    do {
        ifstream in;
        in.open("zipf.txt");
        
            for(short i=0;i<10;i++){
                in>>word[i];
                cout<<i<<word[i]<<endl;
            }
        short n=0;
        for(short i=0;i<10;i++){
            for(short l=0;l<10;l++){
                if(word[i]==word[l-10]){
                    check=false;
                }else check=true;
                if(check==true){
                    if(word[i]==word[l]){
                        cnt[n]++;
                    }else n++;
                }
            }   
        }
        for (short i=0;i<10;i++){
            cout<<cnt[i]<<endl;
        }
        
            in.close();
            
        restart = Restart();
    } while (restart);

    //Output Located Here

    //Exit
    return 0;
}

bool Restart() {
    char ans;
    bool restart;
    cout << endl;
    cout << "Would you like to run this program again? y/n" << endl;
    cin>>ans;
    while (ans != 'y' && ans != 'n' && ans != 'Y' && ans != 'N') {
        cout << "Please enter y/n" << endl;
        cin>>ans;
    }
    if (ans == 'y' || ans == 'Y')
        restart = true;
    else
        restart = false;
    return restart;
}