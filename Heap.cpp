template <typename T>
class MaxHeap{
    private:
        T * data;
        size_t index;
        
        void swim(size_t k){
            size_t curr = k;
            size_t parent = curr/2; 
            
            while(curr > 1 && data[parent] < data[curr]){
                std::swap(data[parent], data[curr]);
                
                size_t curr = parent;
                size_t parent = curr/2; 
            }
        }
        
        void sink(size_t k){
            size_t curr = k;
            
            while(curr*2 <= index){
                size_t next = curr * 2;
                if(next < k && data[next] < data[next + 1]){
                    ++next;
                }
                
                
                if(data[next] < data[curr]){
                    break;
                }
                
                std::swap(data[next], data[curr]);
                curr = next;
            }
        }
        
    public: 
        MaxHeap(size_t len) : index(0){
            data = new T[len];
        }
        
        ~MaxHeap(){
            delete [] data; 
        }
        
        void Insert(T element){
            data[++index] = element;
            if(index == 1){
                return;
            }
            swim(index);
        }
        
        T Remove(){
            if(index < 1){
                throw std::out_of_range("lol");
            }
            
            T val = data[1];
            std::swap(data[1], data[index--]);
            sink(1);
            return val;
        }
};
