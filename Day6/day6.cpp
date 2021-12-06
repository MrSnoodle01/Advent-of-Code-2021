#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>


using namespace std;

int main(){

    ifstream myFile("input.txt");

    vector<int> fishTimer;

    string line;
    getline(myFile, line);


    for(int i = 0; i < line.size(); i++){
        fishTimer.push_back(line[i] - '0');
        i++;
    }

    unsigned long long int num0 = 0, num1 = 0, num2 = 0, num3 = 0, num4 = 0, 
    num5 = 0, num6 = 0, num7 = 0, num8 = 0;
    for(int i = 0; i < fishTimer.size(); i++){
        switch (fishTimer[i])
        {
        case 0:
            num0++;
            break;
        case 1:
            num1++;
            break;
        case 2:
            num2++;
            break;
        case 3:
            num3++;
            break;
        case 4:
            num4++;
            break;
        case 5:
            num5++;
            break;
        case 6:
            num6++;
            break;
        case 7:
            num7++;
            break;
        case 8:
            num8++;
            break;
        default:
            break;
        }
    }

    unsigned long long int temp, temp2;
    for(int i = 0; i < 256; i++){
        temp = num0 + num1 + num2 + num3 + num4 + num5 + num6 + num7 + num8;
        cout << "temp " << temp << endl;
        cout << "num0 " << num0 << endl;
        cout << "num1 " << num1 << endl;
        cout << "num2 " << num2 << endl;
        cout << "num3 " << num3 << endl;
        cout << "num4 " << num4 << endl;
        cout << "num5 " << num5 << endl;
        cout << "num6 " << num6 << endl;
        cout << "num7 " << num7 << endl;
        cout << "num8 " << num8 << endl;
        cout << endl;
            temp2 = num0;
            
            num0 = num1;

            num1 = num2;

            num2 = num3;

            num3 = num4;

            num4 = num5;

            num5 = num6;

            num6 = num7;
            num6 = num6 + temp2;

            num7 = num8;

            num8 = temp2;
    }

    temp = num0 + num1 + num2 + num3 + num4 + num5 + num6 + num7 + num8;
    cout << temp << endl;

    return 0;
}
