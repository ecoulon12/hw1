#include <cstddef>
#include <stdexcept>
#include<iostream>
#include "ulliststr.h"
#include <string>


ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

//MY WORK HERE

//PUSH_BACK 
void ULListStr::push_back(const std::string& val){
  if (empty()){
    //create new node
    Item* newNode = new Item;
    //update head_ and tail_ to point at this node
    this->head_ = newNode;
    this->tail_ = newNode;
    //add the val to location 0 //WHY NO WORK
    newNode->val[0] = val;
    //set last to 1 (IN THIS ITEM)
    newNode->last = 1;
    std::cout<<"list is empty!, adding "<< val <<" to the item "<<std::endl;
    //prev and next don't need to be updated because there are no other nodes
  }else{
    if (tail_->last == 10){ //if the end node is full (lastitem.last == 10) tail_.last
      //create new node
      Item* newNode = new Item;
      //update tail_, prev, next
      newNode->prev = tail_;
      tail_->next = newNode;
      tail_ = newNode;
      //add val to location 0
      newNode->val[0] = val;
      //set last to 1
      newNode->last = 1;

    }else{//if the end node is not full
      //add the value to current tail_
      tail_->val[tail_->last] = val;
      tail_->last++;
    }
  } 
  size_++; 
}

//PUSH_FRONT - Adds a new value to the front of the list
//use the front() function and add the value at front()-1 (because back val is not inclusive)
//check to make sure 
void ULListStr::push_front(const std::string& val){
  if (empty()){
    //create new node
    Item* newNode = new Item;
    //update head_ and tail_ to point at this node
    this->head_ = newNode;
    this->tail_ = newNode;
    //add the val to the last element in array //WHY NO WORK
    newNode->val[ARRSIZE-1] = val;
    //set last to 1 (IN THIS ITEM)
    newNode->first = ARRSIZE-1;
    newNode->last = ARRSIZE;    
    //newNode->last = 9;
    //prev and next don't need to be updated because there are no other nodes
    std::cout<<"first element added to index 9"<<std::endl;
  }else{
    if (head_->first == 0){ 
      //create new node
      Item* newNode = new Item;
      //update tail_, prev, next
      newNode->next = head_;
      head_->prev = newNode;
      head_ = newNode;
      //add val to location 0
      newNode->val[ARRSIZE-1] = val;
      //set last to 1
      newNode->first = ARRSIZE-1;
      newNode->last = ARRSIZE;
      std::cout<< "There is a value at index 0 already, created new node and added "<<newNode->val[ARRSIZE-1]<<" at "<<ARRSIZE-1<<std::endl;

    }else{//if the end node is not full
      //add the value to current head_
      std::cout<< "current node not full yet, added " <<val<<" to index "<<head_->first-1<<std::endl;
      head_->val[head_->first-1] = val;
      head_->first--;
    }
  } 
  size_++; 
}

//POP_BACK - check to see if is empty
// if not empty, remove the value at the back()-1 location
//find the back value location 
void ULListStr::pop_back(){
  if (empty()){
    std::cout<<"empty list, nothing to pop_back"<<std::endl;
    return;}
  Item* currNode = tail_;
  //check size of the list. If size_ == 1, then removing the only element means we should delete that node and reset head_ and tail_ to nullptr
  if(size_ == 1){
    delete currNode;
    head_ = nullptr;
    tail_ = nullptr;
    size_--;
    return;
  }
  //check to see if the back most value is at location 0 of a node --> in this case, we need to delete the node
  if(tail_->last == 0){
    tail_ = currNode->prev;
    delete currNode;
    tail_->next = nullptr;
  }
  //else, we just need to adjust the last value
  else{
    currNode->val[currNode->last-1] = "";
    tail_->last--;
  }
  size_--;
  return;

}

//POP_BACK - check to see if is empty
// if not empty, remove the value at the front() location
void ULListStr::pop_front(){
  if (empty()){
    std::cout<<"empty list, nothing to pop_front"<<std::endl;   
    return;}
  Item* currNode = head_;
  //check size of the list. If size_ == 1, then removing the only element means we should delete that node and reset head_ and tail_ to nullptr
  if(size_ == 1){
    delete currNode;
    head_ = nullptr;
    tail_ = nullptr;
    size_--;
    return;
  }
  //check to see if the front most value is at location ARRSIZE-1 of a node --> in this case, we need to delete the node
  if(head_->first == ARRSIZE-1){
    head_ = currNode->next;
    delete currNode;
    head_->prev = nullptr;
  }
  //else, we just need to adjust the last value
  else{
    currNode->val[currNode->first] = "";
    head_->first++;
  }
  size_--;
  return;
}

//BACK - return the tail_->last
std::string const& ULListStr::back() const{
  if (empty())
  {return nullptr;}
  else
  {return tail_->val[tail_->last- 1];}
}

//FRONT - return head_->first
std::string const & ULListStr::front() const{
  if (empty())
  {return nullptr;}
  else
  {return head_->val[head_->first];}

}

//GET VAL AT LOC - used in the get function. Basically, I am gonna check edge cases (out of bounds n stuff),
//then set the current node to the head and then start at the first of head and iterate through the list
//if you get to the end of 
std::string* ULListStr::getValAtLoc(size_t loc) const {
  std::cout << "finding value at location " << loc << "..." << std::endl;

  if (loc >= size_ || loc < 0) { //if teh location is outside of the bounds (size) of the list, it is not a valid location
    throw std::out_of_range("Invalid location in getValatloc");
  }

  Item* currNode = head_;
  while (loc >= currNode->last - currNode->first) {
    loc -= currNode->last - currNode->first; //count down witih loc until you reach destination
    if (currNode->next == nullptr) { // if there isn't another node to go to, that means we are out of bounds
      throw std::out_of_range("Invalid location in getValAtLoc");
    }
    currNode = currNode->next; // go to the next node until loc has run out
  }

  size_t index = (currNode->first + loc) % ARRSIZE;
  std::cout << "Here with retval name: " << currNode->val[index] << std::endl;
  std::string* retval = &currNode->val[index];

  return retval;
}



