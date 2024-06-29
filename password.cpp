#include<iostream>
#include<cstdlib>
#include<cstdlib>
#include<ctime>

using namespace std;

int getKey(){
    srand(time(NULL));
    int key = rand() % 26;
    return key;
}

int select_array(){
    srand(time(NULL));
    int i = rand() % 5;
    if(i == 0){
        i++;
    }
    return i;
}

void generate_password(int length){
    
    string password = "";
    string C_Alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string symbol = "!@#$%&";
    string number = "0123456789"; 
    int key, count_Alphabet = 0, count_alphabet = 0, count_symbol = 0, count_number = 0;
    int count = 0;
    while(count < length){
        int k = select_array();
        if(count == 0){
            k = k % 3;
            if(k == 0){
                k++;
            }
        }
        switch(k){
            case 1:
            if((count_alphabet == 2) && (count_number == 0 || count_Alphabet ==0 || count_Alphabet == 1 || count_symbol == 0)){
                break;
            }
            key = getKey();
            password = password + alphabet[key];
            count_alphabet++;
            count++;
            break;
            
            case 2:
            if((count_Alphabet == 2) && (count_number == 0 || count_alphabet == 0 || count_alphabet == 1 || count_symbol == 0)){
                break;
            }
            key = getKey();
            password = password + C_Alphabet[key];
            count_Alphabet++;
            count++;
            break;

            case 3:
            if((count_number == 1) && (count_Alphabet == 0 || count_Alphabet == 1 || count_alphabet == 0 || count_alphabet == 1 || count_symbol == 0)){
                break;
            }
            key = getKey();
            password = password + number[key];
            count_number++;
            count++;
            break;

            case 4:
            if((count_symbol == 1) && (count_Alphabet == 0 || count_Alphabet == 1 || count_alphabet == 0 || count_alphabet == 1 || count_number == 0)){
                break;
            }
            key = getKey();
            password = password + symbol[key];
            count_symbol++;
            count++;
            break;
        }
        cout << "\n-----------------------------\n";
        cout << "         Password             \n";
        cout << "------------------------------\n\n";
        cout << " " << password;
        cout << "\n\nPress any key continue \n";
        getchar();
    }
}

int main(){

    int n,length;
    do{
        cout << "Random Password Generator" << endl;
        cout << "1. Generate Password" << endl;
        cout << "2. Exit" << endl;
        cin >> n;
        switch(n){
            case 1:
            cout <<"Enter lenght : ";
            cin >> length;
            if(length < 7){
                cout << "Error!! Password lenght should be at least 7" <<endl;
                cout << "Press any key to try again" <<endl;
                getchar();
            }
            else if(length>100){
                cout << "Error!! Minimum Password length should be in 100" <<endl;
                cout << "Press any key to try again" <<endl;
                getchar();
            }
            else{
                generate_password(length);
            }
            default:
            if(n != 2){
                cout << "Invalid choice!!!" <<endl;
                cout << "Press (1) to generate password and (2) to exit" <<endl;
                cout << "Press any key to try again" <<endl;
                getchar();
            }
            break;
        }
    }while(n!=2);
    return 0;
}
