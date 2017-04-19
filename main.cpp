#include <iostream>
#include <fstream>
using namespace std;

int main(){
    
    string nameArray[]={};
    string name, nextName, onePass = "start" , swapCount = "swap" , stopSort = "don't stop";
    int letterNum = 0 , total = 0 , nameTotal = 0;
    int size = sizeof(nameArray)/sizeof(nameArray[0]);
    //TODO read from file and stor names in nameArray.
    

    
    
    
    // puts nameArray into alphabetical order
    while(swapCount == "swap"){
        swapCount = "stop";
        
        for(int wordNum = 0; wordNum < size - 1; wordNum++){
            onePass = "start";
            letterNum = 0;
            
            while (onePass != "stop"){
                
                if(nameArray[wordNum][letterNum] > nameArray[wordNum+1][letterNum]){
                    swap(nameArray[wordNum],nameArray[wordNum+1]);
                    onePass= "stop";
                    swapCount = "swap";}
                
                else if(nameArray[wordNum][letterNum] == nameArray[wordNum+1][letterNum]){
                    letterNum++;}
                
                else{
                    onePass="stop";}
            }
        }
    }
    
    // changes names in list to numbers and creates a total
    for(int i = 0; i < size; i++){
        name = nameArray[i];
        
        for(int j = 0; j < name.length(); j++){
            nameTotal = nameTotal + (name[j]-64); }
        
        nameTotal = nameTotal * i;
        total = total + nameTotal;
        nameTotal = 0;
    }
    
    //prints out final list
    for(int i = 0; i < size; i++){
        cout<< nameArray[i]<<endl;}
    
    //prints out total number of list
    cout << "the total for all names is " << total << endl;
    
    return 0;
}
