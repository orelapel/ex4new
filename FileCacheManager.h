//
// Created by noa on 13/01/2020.
//

#ifndef EX4_FILECACHEMANAGER_H
#define EX4_FILECACHEMANAGER_H
#include "CacheManager.h"
#include "string"
#include <functional>
using namespace std;

template <class Problem>
class FileCacheManager:public CacheManager<Problem> {
private:
    list <Problem> listOfCashe;
    unordered_map<Problem,std::pair<string, typename std::list<Problem>::iterator>> _cashe;
    unsigned int capacityRam;
public:
    FileCacheManager(unsigned int capacity){
        capacityRam=capacity;
    }

    void insert(Problem key, string obj) {
        fstream fileForWriteObj;
        hash<Problem> hash;
        string file_name = hash(key)+".txt";
        fileForWriteObj.open(file_name,ios::out|ios::binary);
        //if from any reason the program failed in open the file we will throw an error
        if(!fileForWriteObj){
            throw("Error in creating file");
        }
        //write the object for file
//        fileForWriteObj.write((char*)&obj,sizeof(obj));
        fileForWriteObj<<obj<<endl;
        fileForWriteObj.close();
        //for update the data of the object
        if (_cashe.find(key) != _cashe.end()) {
            listOfCashe.remove(key);
            listOfCashe.push_front(key);
            _cashe[key].first = obj;
            _cashe[key].second = listOfCashe.begin();
        }
        else {
            listOfCashe.push_front(key);
            //If we add another object and go beyond the existing memory limit we will
            // removed the Least Recently Used
            if (listOfCashe.size()>capacityRam) {
                Problem lastValueInList =listOfCashe.back();
                listOfCashe.remove(lastValueInList);
                _cashe.erase (lastValueInList);
            }
            _cashe.insert( pair<Problem,std::pair<string, typename std::list<Problem>::iterator>> (key,std::make_pair(obj,listOfCashe.begin())));
        }
    }

    string get(Problem key) {
        // if the object exist in the map we will find it in the map, return it and update his use in the data
        if (_cashe.find(key) != _cashe.end()) {
            listOfCashe.remove(key);
            listOfCashe.push_front(key);
            return _cashe[key].first ;
        }
            //else we will search him in the files - if we find we will read the file into object and return this object
        else {
            fstream fileForReadObj;
            hash<Problem> hash;
            string file_name = hash(key)+".txt";
            fileForReadObj.open(file_name,ios::in|ios::binary);
            string obj;
            //if the file not found or from any reason the program failed in open it- we will throw an error
            if(!fileForReadObj){
                throw("error in find the object");
            }
            else {
//                fileForReadObj.read((char*)&obj,sizeof(obj));
                getline(fileForReadObj, obj);
                fileForReadObj.close();
                //insert the value to the Ram
                insert(key,obj);
                return obj;
            }
        }
    }

    void foreach(void (*func)(string &obj)) {
        for (typename std::list<Problem>::iterator it=listOfCashe.begin(); it != listOfCashe.end(); ++it) {
            func(_cashe[*it].first);
        }
    }

    bool isSoulutaionExist(Problem key){
        if (_cashe.find(key) != _cashe.end()) {
            return true;
        }
        else {
            fstream fileForReadObj;
            hash<Problem> hash;
            string file_name = hash(key)+".txt";
            fileForReadObj.open(file_name,ios::in|ios::binary);
            string obj;
            //if the file not found or from any reason the program failed in open it- we will throw an error
            if(!fileForReadObj){
                return false;
            }
            else {
                return true;
            }
        }
    }
};


#endif //EX4_FILECACHEMANAGER_H
