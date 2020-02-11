#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <typeinfo>
#include <queue>
#include <stack>
#include "Point.h"


template <class T> 
void vectorInfo(std::vector<T> v) {
    std::cout  << "size( ): " << v.size( ) 
        << "; capacity(): " << v.capacity() 
        << "; max_size(): " << v.max_size() << std::endl;
}

template <class T> 
void vectorPrint(std::vector<T> v) {
    for(int i =0;i<v.size(); i ++) {
        std::cout << "v.at(" << i << ") " << v.at(i) << std::endl;
    } 
}
 
template <class T> 
void vectorPrint(std::vector<std::vector<T>> v) {
    for(int i =0;i<v.size(); i ++) {
        std::cout << "Row v.at(" << i << ")" << std::endl;
        vectorPrint(v.at(i));
    } 
}

template <class T> 
void listPrint(std::list<T> l) {
    for (T n : l) {
        std::cout << n << std::endl;
    }
}

void listPrint(std::list<Point> l) {
    for (Point n : l) {
        std::cout << "Point{x:" << n.getX() 
                << ", y:" <<  n.getY() << "}" << std::endl;
    }
}

void vectorPrint(std::vector<Point> v) {
    for(int i =0;i<v.size(); i ++) {
        std::cout << "v.at(" << i << ") Point{x:" << v.at(i).getX() 
                << ", y:" <<  v.at(i).getY() << "}" << std::endl;
    } 
}

template <class T> 
void itPrint(T cont) {
    auto it = cont.begin();
    std::cout << "=================== " << typeid(cont).name() 
             << " ==================="  << typeid(it).name() 
            << " ===================" << std::endl;
    while(it != cont.end()) {
        std::cout << *it << std::endl;
        it ++;
    }
}



 template <typename T1, typename T2>
 void itPrint(std::map<T1, T2> mf) {
     std::cout << "=================== " << typeid(mf).name() 
             << " ==================="  << mf.size()           
            << " ===================" << std::endl; 
    auto it = mf.begin(); 
    while(it != mf.end()) {
        std::cout << "Pair {key: " << (*it).first << ", value: " << (*it).second  << "}" << std::endl;
        it ++;
    }
 }
 

template <typename T1, typename T2>
void itPrint(std::map<T1, std::vector<T2>> mf) { 

 std::cout << "=================== " << typeid(mf).name() 
             << " ==================="  << mf.size()           
            << " ===================" << std::endl;  
    auto it = mf.begin(); 
    while(it != mf.end()) {
        std::cout << "Pair {key: " << (*it).first << ", value: "; 
        itPrint((*it).second);
        std::cout << "}" << std::endl;
        it ++;
    }    
}


//multimap
template <typename T1, typename T2>
void itPrint(std::multimap<T1, T2> mf) { 

 std::cout << "=================== " << typeid(mf).name() 
             << " ==================="  << mf.size()           
            << " ===================" << std::endl;  
    auto it = mf.begin(); 
    while(it != mf.end()) {
        std::cout << "Pair {key: " << (*it).first << ", value: " << (*it).second  << "}" << std::endl;
        it ++;
    }    
}


template <typename T1, typename T2, typename T3>
void itPrint(std::map<T1, std::map<T2, T3>> mf) { 
 
 std::cout << "=================== " << typeid(mf).name() 
             << " ==================="  << mf.size()           
            << " ===================" << std::endl;  
    auto it = mf.begin(); 
    while(it != mf.end()) {
        std::cout << "Pair {key: " << (*it).first << ", value: "; 
        itPrint((*it).second);
        std::cout << "}" << std::endl;
        it ++;
    }    
}


template <class T>
void stPrint( T s) {
    std::cout << "=================== " << typeid(s).name() 
             << " ==================="  << s.size()           
            << " ===================" << std::endl; 
    while(!s.empty()) { 
        std::cout << s.top()<< std::endl; 
        s.pop();
    }     
}



template <typename TN>
void stPrint( std::vector<TN> v) {
    std::cout << "=================== " << typeid(v).name() 
             << " ==================="  << v.size()           
            << " ===================" << std::endl; 
    for(auto s : v) { 
        std::cout << s << std::endl;
    }    
}

template <typename TN>
void stPrint( std::queue<TN> s) {
    std::cout << "=================== " << typeid(s).name() 
             << " ==================="  << s.size()           
            << " ===================" << std::endl;
    while(!s.empty()) { 
        std::cout << s.front() << std::endl; 
        s.pop();
    } 
}


template <>
void stPrint( std::queue<Point*> s) {
    std::cout << "=================== " << typeid(s).name() 
             << " ==================="  << s.size()           
            << " ===================" << std::endl;
    while(!s.empty()) { 
        std::cout << *s.front() << std::endl; 
        s.pop();
    }     
}


template <class T> 
void stPrintTop(T s) {  
}


template <class T, class C> 
void dequeRemoveIF(std::deque<T> &deque, C cond) {
     auto it = deque.begin();
     while(it != deque.end()) {
        if(cond(*it)) {
            deque.erase(it);
        }
        ++ it;
    }
}

//
void vectorPrint(std::vector<Point*> v) {
    for(int i =0;i<v.size(); i ++) {
        std::cout << "v.at(" << i << ") Point{x:" << v.at(i)->getX() 
                << ", y:" <<  v.at(i)->getY() << "}" << std::endl;
    } 
}


template <class T> 
void removePair(std::vector<T> &v) {
    T last;
    int n = 0, s = 0;
   /* for(std::vector<T>::iterator it = v.begin(); it != v.end(); ++it)*/
    
    while(v.size() > n) {
        if(n == 0 || v.at(n) != last) { //первый раз или новый элемент
            last = v.at(n);
            s = n; 
            n ++; 
        } else  {
            while(v.size() > n && v.at(n) == last) {     //удаляем последовательности   
                n ++;
                v.erase(v.begin()+s, v.begin()+n);                            
            } 
            n = s; //встаем на место откуда начали удалять
            
        }   
    }     
}


//
template<class T>
void myReverse(T first, T last)
{
    while ((first != last) && (first != --last)) {
        std::swap(*first++, *last);
    }
}

//  
template<class T1, class T2>
void itPrint( std::vector<std::pair<T1, T2>> cont) {
    auto it = cont.begin();
    
    std::cout << "=================== " << typeid(cont).name() 
             << " ==================="  << typeid(it).name()       
            << " ===================" << std::endl;
    while(it != cont.end()) {
        std::cout << "Pair {key: " << (*it).first << ", value: " << (*it).second << "}" << std::endl;
        it ++;
    }
} 