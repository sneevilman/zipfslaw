/* 
 * File:   main.cpp
 * Author: Caeleb Moeller
 * Created on 
 * Purpose: 
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//User Libraries Here


//Function Prototypes Here
bool Restart();

//Program Execution Begins Here

int main() {
    //Declare and process variables
    short size=1000;
    bool restart;
    short cnt[size]={0};
    long q;
    string word[size];
    string place[size];
    bool check=false;
    bool chkd[size]={false};
    
    //Process/Calculations Here
    do {
        ifstream in;
        in.open("zipf.txt");
        
        q=0;
        
        for(short i=0;i<=q;i++){
            in>>word[i];
            cout<<word[i]<<endl;
            if(word[i]==""){
                in.close();
            }else q++;
        }
        cout<<"q: "<<q<<endl;
        
        short n=0;
        for(short i=0;i<q;i++){
            if(chkd[i]==false){
                place[n]=word[i];
                cnt[n]++;
                chkd[i]=true;
                for(short l=i+1;l<q;l++){
                    if(word[i]==word[l]){
                        cnt[i]++;
                        chkd[l]=true;
                    }
                }
            
            }
            
            if(cnt[n]>0)n++;
        }
        cout<<"n: "<<n<<endl;
        for (short i=0;i<n;i++){
            cout<<place[i]<<": "<<cnt[i]<<endl;
        }
            
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