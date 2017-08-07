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
    long q(64000);
    string word[q],
            place[q];
    bool check=false;
    
    //Process/Calculations Here
    do {
        q=0;
        ifstream in;
        in.open("zipf.txt");
        while(in){
            in>>word[q];
            cout<<q<<": "<<word[q]<<endl;
            if(word[q]==""){
                cout<<"it worked"<<endl;
                in.close();
            }
            q++;
        }
        short n=0;
        short cnt[q]={0};
            
            for(short i=0;i<q;i++){
                check=true;
                if(i>0){
                    for(short l=0;l<i;l++){
                        if(word[i]==word[l]){
                            check=false;
                        }
                    }
                }
                if(check==true){
                    for(short l=0;l<q;l++){
                        if(word[i]==word[l]){
                            cnt[n]++;
                        }
                    }
                    place[n]=word[i];
                    n++;
                }
            }
        for (short i=0;i<n;i++){
            cout<<place[i]<<": "<<cnt[i]<<endl;
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