//
// Created by noa on 13/01/2020.
//

#include "StringReverser.h"

string StringReverser::solve(string s){
    reverse(s.begin(), s.end());
    return s;
}
StringReverser:: ~StringReverser(){

}
StringReverser* StringReverser::clone() {
    return new StringReverser();
}
int StringReverser::getNumOfNodes() {
    return 0;
}