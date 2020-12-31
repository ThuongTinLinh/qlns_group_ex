#include "IO.h"

IO::IO(){
    MemberIO.clear();
};

void IO::DataOut(){
    ToMapIO();
    map<string, string>::iterator it;
    for (it = MemberIO.begin(); it != MemberIO.end(); it++){
        cout << "Value for " << it->first << " = "<< it->second << endl;
    }
    cout << "-------------------------------------"<< endl;
};

void IO::DataIn(){    
    ToMapIO();
    map<string, string>::iterator it;
    for (it = MemberIO.begin(); it != MemberIO.end(); it++){
        cout << "enter value for " << it->first << " = ";
        getline(cin, it->second);
    };
    cout << "-------------------------------------"<< endl;
    FromMapIO();
};