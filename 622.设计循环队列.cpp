/*
 * @lc app=leetcode.cn id=622 lang=cpp
 *
 * [622] 设计循环队列
 * 
 */

#include <vector>
using namespace std;
class MyCircularQueue {

private:

vector<int > data_;
int max_size_;
int current_size_;
int p_start_;
int p_end_;




public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        current_size_=0;
        max_size_=k;
        data_.resize(max_size_);
        p_start_= 0;
        p_end_= -1;
        
        
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull()){
            return false;
            
        }

        p_end_=(p_end_+1)%max_size_;
        data_[p_end_]=value;
        current_size_++;       
        return true;
       
        
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty()){
            return false;
        } 

        p_start_=(p_start_+1)%max_size_;
        current_size_--; 
        return true;      
        
        
    }
    
    /** Get the front item from the queue. */
    int Front() {

        if(isEmpty()){
            return -1;
        }
        return data_[p_start_];
        
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty()){
            return -1;
        }
        return data_[p_end_];
        
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return (current_size_==0);
        
    }
    
    /** Checks whether the circ-ular queue is full or not. */
    bool isFull() {

        return (current_size_==max_size_);
        
        
    }


};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

