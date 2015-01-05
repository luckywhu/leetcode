#include <iostream>
#include <map>

using std::cout;
using std::endl;
//using std::map;

class LRUCache{
        public:
                struct Node{
                        int key;
                        int value;
                        int pre;
                        int next;
                };
                std::map<int,int> index;
                Node* nodes;
                int capacity;
                int header;
                int tail;
                int free;
        public :
                LRUCache(int capacity) {
                        if(capacity <= 0)
                            return;
                        nodes = new Node[capacity]; 
                        capacity = capacity;
                        header = -1;
                        tail = -1;
                        free = 0;
                        for(int i = 0;i<capacity;i++)
                        {
                                nodes[i].next=i+1;
                                nodes[i].pre=i-1;
                        }
                        nodes[0].pre=-1;
                        nodes[capacity-1].next=-1;
                }
                ~LRUCache(){
                        if(nodes)
                                delete []nodes;
                }
                void print(){
                    int index = header;
                    while(index != -1)
                    {
                        std::cout<<nodes[index].value<<" ";
                        index = nodes[index].next;
                    }
                    std::cout<<std::endl;
                }
                int get(int key) {
                        if(capacity==0)
                            return -1;
                        std::map<int,int>::iterator it;
                        it = index.find(key);
                        if( it == index.end())
                                return -1;
                        int value_index = it->second;
                        index.erase(it);
                        int value = nodes[value_index].value;
                        //delete the node
                        if(nodes[value_index].pre != -1)
                                nodes[nodes[value_index].pre].next = nodes[value_index].next;
                        else
                                header = nodes[value_index].next;
                        if(nodes[value_index].next != -1)
                                nodes[nodes[value_index].next].pre = nodes[value_index].pre;
                        else
                                tail = nodes[value_index].pre;
                        nodes[value_index].next = free; 
                        nodes[value_index].pre = -1;
                        if(free!=-1)
                            nodes[free].pre=value_index;
                        free = value_index;

                        //add to the header
                        int node_index = free;
                        free = nodes[free].next;
                        nodes[node_index].key = key;
                        nodes[node_index].value = value;
                        nodes[node_index].pre = -1;
                        nodes[node_index].next = header;
                        if(header != -1)
                            nodes[header].pre = node_index;
                        header = node_index;
                        if(tail == -1)
                            tail = node_index;
                        index.insert(std::pair<int,int>(key,node_index));
                        return value;
                }
                void set(int key,int value) {
                        if(capacity == 0)
                            return;
                        std::map<int,int>::iterator it;
                        it = index.find(key);
                        if( it != index.end() )
                        {
                                int value_index = it->second;
                                if(nodes[value_index].pre != -1)
                                        nodes[nodes[value_index].pre].next = nodes[value_index].next;
                                else
                                        header = nodes[value_index].next;
                                if(nodes[value_index].next != -1)
                                        nodes[nodes[value_index].next].pre = nodes[value_index].pre;
                                else
                                        tail = nodes[value_index].pre;
                                nodes[value_index].next = free; 
                                nodes[value_index].pre = -1;
                                if(free != -1)
                                    nodes[free].pre = value_index;
                                free = value_index;
                                index.erase(it);
                        }
                        if(free == -1) //there is no space ,free one in lru
                        {
                                nodes[tail].next = free;
                                free = tail;
                                if(tail != -1)
                                {
                                    int del_key = nodes[tail].key;
                                    std::map<int,int>::iterator it = index.find(del_key);
                                    if(it != index.end())
                                    {
                                        index.erase(it);
                                        std::cout<<"set cause del key="<<nodes[tail].key<<" value="<<nodes[tail].value<<std::endl; 
                                    }
                                }
                                tail = nodes[tail].pre;
                                if(tail == -1)
                                    header = -1;
                                if( tail != -1 )
                                        nodes[tail].next = -1;
                                if( free != -1 )
                                        nodes[free].pre = -1;
                                //std::cout<<nodes[free].value<<std::endl;
                        }
                        int node_index = free;
                        free = nodes[free].next;
                        nodes[node_index].key = key;
                        nodes[node_index].value = value;
                        nodes[node_index].pre = -1;
                        nodes[node_index].next = header;
                        if(header != -1)
                            nodes[header].pre = node_index;
                        header = node_index;
                        if(tail == -1)
                            tail = node_index;
                        index.insert(std::pair<int,int>(key,node_index));
                }
};
int main(void) {
        LRUCache lru(1);
        lru.set(2,1);
        lru.get(2);
        std::cout<<"get key=2 value="<<lru.get(2)<<std::endl;
        lru.set(3,2);
        std::cout<<"get key=2 value="<<lru.get(2)<<std::endl;
        std::cout<<"get key=3 value="<<lru.get(3)<<std::endl;
}
