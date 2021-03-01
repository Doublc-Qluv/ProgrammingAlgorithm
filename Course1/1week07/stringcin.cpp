#include <iostream>
#include <cstring>

using namespace std;
int main(){
    char title[] = "Prison Break";
    char hero[100] = "Michael Scofield";
    char prisonName[100];
    char response[100];

    cout << "What's the name of the prison in " << title << endl;
    cin >> prisonName;
    if(strcmp(prisonName, "Fox-river") == 0){
        cout << "Yeah! Do you love " << hero << endl;
    }
    else{
        strcpy(response,"It seems you havn't watched it!\n");
        cout << response << endl;
    }
    title[0] = 't';
    title[3] = 0;
    cout << title ;
    return 0;
}