#include <iostream>
#include <map>
#include <list>

using std::cout;
using std::endl;

class LRUCache{
        public:
                int capacity; 
                int count;
                struct Node{
                        int key;
                        int value;
                };
                std::map<int,std::list<Node>::iterator> index;
                std::list<Node> list_value;
        public:
                LRUCache(int capacity){
                        if(capacity == 0)
                                return;
                        this->capacity = capacity;
                        this->count = 0;
                }
                int get(int key){
                        std::map<int,std::list<Node>::iterator>::iterator it = index.find(key);
                        if(it == index.end())
                                return -1;
                        Node node= *(it->second);
                        list_value.erase(it->second); 
                        index.erase(it);
                        list_value.push_front(node);
                        index.insert(std::pair<int,std::list<Node>::iterator>(key,list_value.begin()));
                        return node.value;
                }
                void set(int key,int value){
                        std::map<int,std::list<Node>::iterator>::iterator it = index.find(key);
                        if(it != index.end())
                        {
                                list_value.erase(it->second); 
                                index.erase(it->first);
                                count--;
                        }
                        if(count == capacity)
                        {
                                index.erase(list_value.back().key);
                                list_value.pop_back();
                                count--;
                        }
                        count++;
                        Node node;
                        node.key=key;
                        node.value=value;
                        list_value.push_front(node);
                        index.insert(std::pair<int,std::list<Node>::iterator>(key,list_value.begin())); 
                }
};

int main(void){
        LRUCache lru(1);
        lru.set(2,1);
        lru.get(2);
        std::cout<<"get key=2 value="<<lru.get(2)<<std::endl;
        lru.set(3,2);
        std::cout<<"get key=2 value="<<lru.get(2)<<std::endl;
        std::cout<<"get key=3 value="<<lru.get(3)<<std::endl;

}
