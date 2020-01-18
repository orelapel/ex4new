//
// Created by noa on 13/01/2020.
//

#ifndef EX4_FILECACHEMANAGER_H
#define EX4_FILECACHEMANAGER_H
#include "CacheManager.h"
#include "string"

template <typename T>
class FileCacheManager:public CacheManager<T> {
private:
    list <string> listOfCashe;
    unordered_map<std::string,std::pair<T, std::list<string>::iterator>> _cashe;
    unsigned int capacityRam;
public:
    FileCacheManager(unsigned int capacity){
        capacityRam=capacity;
    }

    void insert(string key, T obj) {
        fstream fileForWriteObj;
        string file_name = key+".txt";
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
                string lastValueInList =listOfCashe.back();
                listOfCashe.remove(lastValueInList);
                _cashe.erase (lastValueInList);
            }
            _cashe.insert( pair<std::string,std::pair<T, std::list<string>::iterator>> (key,std::make_pair(obj,listOfCashe.begin())));
        }
    }

    T get(string key) {
        // if the object exist in the map we will find it in the map, return it and update his use in the data
        if (_cashe.find(key) != _cashe.end()) {
            listOfCashe.remove(key);
            listOfCashe.push_front(key);
            return _cashe[key].first ;
        }
            //else we will search him in the files - if we find we will read the file into object and return this object
        else {
            fstream fileForReadObj;
            string file_name = key+".txt";
            fileForReadObj.open(file_name,ios::in|ios::binary);
            T obj;
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

    void foreach(void (*func)(T &obj)) {
        for (std::list<string>::iterator it=listOfCashe.begin(); it != listOfCashe.end(); ++it) {
            func(_cashe[*it].first);
        }
    }

    bool isSoulutaionExist(T key){
        if (_cashe.find(key) != _cashe.end()) {
            return true;
        }
        else {
            fstream fileForReadObj;
            string file_name = key+".txt";
            fileForReadObj.open(file_name,ios::in|ios::binary);
            T obj;
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
