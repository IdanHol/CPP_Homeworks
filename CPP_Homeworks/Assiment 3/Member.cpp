#include <iostream>
#include <list>
#include <vector>
#include <iterator>
#include <algorithm>
#include "Member.h"
using namespace std;

int Member:: counter=0;
  /**
     * Jump the counter while we create new member
     */
Member::Member(){
   counter++;
}
 /**
     * Check if the member follow him already
     * If yes it's doesn't do nothing,if not it's add this
     */ 
void Member:: follow(Member &m){
    if(std::find(std::begin(follows),std::end(follows),&m)==std::end(follows)){//Check the term
    follows.push_front(&m);
    m.followers.push_front(this);
    }
}
/**
 * Remove the elment in the list only if it's contain it
 */
void Member::unfollow(Member &m){
    follows.remove(&m);
    m.followers.remove(this);
}
/**
 * Return the size of the Followers List
 */
 int Member:: numFollowers(){
    return followers.size();
}
/**
 * Return the size of the Followering List
 */
int Member:: numFollowing(){
    return follows.size();
}
/**
 * Return how many members are using the soical network
 */
int Member::count(){
    return counter;
    }
    /**
     * Destractor
     */
Member::~Member(){
    counter--;
    /**
     * Delete the member in the follows list in their followers list
     */
    while(follows.size()>0){
        follows.front()->followers.remove(this);
        follows.pop_front();
    }
        /**
     * Delete the member in the followers list in their  follows  list
     */
    while(followers.size()>0){
        followers.front()->follows.remove(this);
        followers.pop_front();
    }
    follows.~list();
    followers.~list();
}