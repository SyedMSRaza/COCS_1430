#include <iostream>
#include <fstream>
using namespace std;

int main(){

    string nameArray[5164] = {};
    string name, nextName, onePass = "start" , swapCount = "swap";
    int letterNum = 0 , total = 0 , nameTotal = 0, lineNum = 0;
    int size = sizeof(nameArray)/sizeof(nameArray[0]);
    
    //reads from file and stor names in nameArray.
    ifstream fin;
    string temp = "";
    fin.open("names.txt");
    
    while (!fin.eof()){
        getline(fin, temp);
        nameArray[lineNum] = temp;
        lineNum++;
    }
    
    // puts nameArray into alphabetical order
    while(swapCount == "swap"){
        swapCount = "stop";
        
        for(int wordNum = 0; wordNum < size - 1; wordNum++){
            onePass = "start";
            letterNum = 0;
            
            while (onePass != "stop"){
                
                if(nameArray[wordNum][letterNum] > nameArray[wordNum+1][letterNum] && nameArray[wordNum] != nameArray[wordNum + 1]){
                    swap(nameArray[wordNum],nameArray[wordNum+1]);
                    onePass= "stop";
                    swapCount = "swap";
                    }
                
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
            
            if (name[j]-64 >= 1 && name[j]-64 <= 26){
                nameTotal = nameTotal + (name[j]-64);}
            }
    
        nameTotal = nameTotal * i;
        total = total + nameTotal;
        nameTotal = 0;
    }

    cout << "the total for all names is " << total << endl;
    
    return 0;
}
