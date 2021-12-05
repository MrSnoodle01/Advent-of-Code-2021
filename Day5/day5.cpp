#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main(){

    ifstream myFile("input.txt");

    vector<int> x1;
    vector<int> y1;
    vector<int> x2;
    vector<int> y2;

    // set up 2d array
    int diagram[1000][1000];
    for(int i = 0; i < 1000; i++){
        for(int j = 0; j < 1000; j++){
            diagram[i][j] = 0;
        }
    }

    string line;
    string first, second, arrow;
    string temp;
    while(getline(myFile, line)){
        istringstream ss(line);
        temp = "";
        if(ss >> first >> arrow >> second){
            for(int i = 0; i < 5; i++){
                // get x1
                if(first[i] != ','){
                    temp += first[i];
                }else if(first[i] == ','){
                    x1.push_back(stoi(temp));
                }
            }

            temp = "";
            for(int i = 0; i < first.size(); i++){
                // get y1
                if(first[i] == ','){
                    for(int j = 1; j < 4; j++){
                        if(first[i + j] != ' '){    
                            temp += first[i + j];
                        }
                    }
                    y1.push_back(stoi(temp));
                }
            }

            temp = "";
            for(int i = 0; i < 5; i++){
                // get x2
                if(second[i] != ','){
                    temp += second[i];
                }else if(second[i] == ','){
                    x2.push_back(stoi(temp));
                }
            }

            temp = "";
            for(int i = 0; i < second.size(); i++){
                // get y2
                if(second[i] == ','){
                    for(int j = 1; j < 4; j++){
                        if(second[i + j] != ' '){
                            temp += second[i + j];
                        }
                    }
                    y2.push_back(stoi(temp));
                }
            }
        }
    }

    for(int i = 0; i < x1.size(); i++){
        // calculate vertical lines
        if(x1[i] == x2[i]){
            if(y1[i] > y2[i]){
                for(int j = y2[i]; j <= y1[i]; j++){
                    diagram[x1[i]][j] += 1;
                }
            }else if(y2[i] > y1[i]){
                for(int j = y1[i]; j <= y2[i]; j++){
                    diagram[x1[i]][j] += 1;
                }
            }
        }

        // calculate horizontal lines
        if(y1[i] == y2[i]){
            if(x1[i] > x2[i]){
                for(int j = x2[i]; j <= x1[i]; j++){
                    diagram[j][y1[i]] += 1;
                }
            }else if(x2[i] > x1[i]){
                for(int j = x1[i]; j <= x2[i]; j++){
                    diagram[j][y1[i]] += 1;
                }
            }
        }

        // calculate diagonal lines
        if(y1[i] != y2[i] && x1[i] != x2[i]){
            if(x1[i] == y1[i] && x2[i] == y2[i]){
                if(x1[i] > x2[i]){
                    for(int j = x2[i]; j <= x1[i]; j++){
                        diagram[j][j] += 1;
                    }
                }else if(x1[i] < x2[i]){
                    for(int j = x1[i]; j <= x2[i]; j++){
                        diagram[j][j] += 1;
                    }
                }
            }else if(x1[i] > x2[i] && y1[i] > y2[i]){
                int n = y1[i];
                for(int j = x1[i]; j >= x2[i]; j--){
                    diagram[j][n] += 1;
                    n--;
                }
            }else if(x1[i] < x2[i] && y1[i] < y2[i]){
                int n = y2[i];
                for(int j = x2[i]; j >= x1[i]; j--){
                    diagram[j][n] += 1;
                    n--;
                }
            }else{
                int n = 0;
                if(x1[i] > x2[i]){
                    n = y2[i];
                    for(int j = x2[i]; j <= x1[i]; j++){
                        diagram[j][n] += 1;
                        n--;
                    }
                }else if(x1[i] < x2[i]){
                    n = y1[i];
                    for(int j = x1[i]; j <= x2[i]; j++){
                        diagram[j][n] += 1;
                        n--;
                    }
                }
            }
        }
    }

    // find the total amount of overlapping tiles
    int totalOverlap = 0;
    for(int i = 0; i < 1000; i++){
        for(int j = 0; j < 1000; j++){
            if(diagram[j][i] >= 2){
                totalOverlap++;
            }
        }
    }

    cout << totalOverlap << endl;

    // output test diagram
    // for(int i = 0; i < 10; i++){
    //     for(int j = 0; j < 10; j++){
    //         cout << diagram[j][i] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}