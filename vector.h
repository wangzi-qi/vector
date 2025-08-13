#ifndef VECTOR_H
#define VECTOR_H
#include<iostream>
using namespace std;

template <typename T> class vector;
template <typename T> istream& operator>>(istream& in, vector<T>& c);
template <typename T> ostream& operator<<(ostream& out, const vector<T>& c);

template <typename T>
class vector
{
    private:
        T *data;
        int s_size;
        int c_capacity;
        
        void reallocate(int c);

    public:
        vector();
        //默认构造函数

        vector(const vector <T> &obj);
         //拷贝构造函数

        vector(T *arr,int size);
        //数组构造
        
        bool empty();
        //判断是否为空
        
        int capacity();
        //内存

        int size();
       //大小

        T pop();
        //弹出

        void push(T v);
       //增添

        T at(int index);
        //取出

        vector & operator=(const vector <T> &obj);
        //=重载

        T operator[] (int index);
        // [] 重载

        vector operator+(const vector <T> &obj);
         //连接

        vector operator++();
        //前置++

        vector operator++(int);
        //后置++

       
        friend istream& operator>> <T>(istream& in,vector <T> & c);
          //输入重载
    
        friend ostream& operator<< <T>(ostream& out,const vector<T>& c);
              //输出重载

        void reserve(int d_c);
       //预留空间

        void shrink_to_fit();
       //释放多余内存

        void insert(int index,T num,int length=1);
        //插入元素

        void erase(int index,int length =1);
        //删除元素

        void swap(vector <T> &a);
        //交换

        ~vector();
        //析构函数
};

template <typename T>
void vector<T>::reallocate(int c)
        {
            T *newdata = new T [c];
            c_capacity = c;
            for(int i=0;i<s_size;i++)
                newdata[i] = data[i];
                delete [] data;
            data = newdata;
        } //改变内存

        template <typename T>
         vector<T> ::vector():data(nullptr),s_size(0),c_capacity(0){}
        //默认构造函数

        template <typename T>
        vector<T>::vector(const vector <T> &obj)
        {
            data = new T [obj.c_capacity];
            for(int i=0;i<obj.s_size;i++)
                data[i] = obj.data[i];
            s_size = obj.s_size;
            c_capacity = obj.c_capacity;
        }  //拷贝构造函数

        template <typename T> 
        vector<T>::vector(T *arr,int size)
        {
            data = new T [size];
            for(int i=0;i<size;i++)
                data[i] = arr[i];
            s_size = size;
            c_capacity = size;
        }  //数组构造
        
        template <typename T>
        bool vector<T>::empty()
        {
            return s_size==0 ? true : false;
        } //判断是否为空
        
        template <typename T>
        int vector<T>::capacity()
        {
            return c_capacity;
        } //内存
        
        template <typename T>
        int vector<T>::size()
        {
            return s_size;
        }//大小

        template <typename T>
        T vector<T>::pop()
        {
          if (empty())
          {
            throw out_of_range("Vector is empty");/* code */
          }
          else{ 
            T a=data[--s_size];
            return a;
          }

        } //弹出

        template <typename T>
        void vector<T>::push(T v)
        {
            if(c_capacity>s_size)
                data[s_size++]=v;
            else
            {
                reallocate((c_capacity+1)*2);
                data[s_size++]=v;
            }
        }//增添

        template <typename T>
       T vector<T>::at(int index)
        {
            if((index>=0)&&(index<s_size))
                return data[index];
            else 
            {
                throw out_of_range("index is not in the range");
            }
        } //取出

        template <typename T>
        vector<T> & vector<T>::operator=(const vector<T> &obj)
        {
            if(this != &obj)
            {
                delete[] data;
                data = new T [obj.c_capacity];
                for(int i=0;i<obj.s_size;i++)
                    data[i] = obj.data[i];
                s_size = obj.s_size;
                c_capacity = obj.c_capacity;
            }
            return *this;
        } //=重载

        template <typename T>
        T vector<T>::operator[] (int index)
        {
            if((index>=0)&&(index<s_size))
                return data[index];
            else 
            {
                throw out_of_range("index is not in the range");
            }
        } // [] 重载

        template <typename T>
        vector<T> vector<T>::operator+(const vector &obj)
        {
            vector result(*this);
            if(result.c_capacity<result.s_size + obj.s_size)
                result.reallocate(2*result.s_size + obj.s_size);

            for(int i=result.s_size;i<result.s_size + obj.s_size;i++)
                    result.data[i]=obj.data[i-result.s_size];
            
            result.s_size = result.s_size + obj.s_size;

            return result;
        } //连接

        template <typename T>
        vector<T> vector<T>::operator++(int)
        {
            vector result (*this);
            for(int i=0;i<s_size;i++)
               ++data[i];
            return result;
        } //后置++

        template <typename T>
        vector<T>  vector<T>::operator++( )
        {
            for(int i=0;i<s_size;i++)
               ++data[i];
            vector result(*this);
            return result;
        } //前置++
        
        template <typename T>
         istream& operator>>(istream& in,vector<T> & c)
        {
            c = vector<T>();
            T v;
            if (in.peek() == '\n') 
            {
                in.get(); // 消耗换行符
                return in; // 直接返回，vec为空
            }
            while(in>>v)
            {
                c.push(v);
                if (in.peek() == '\n') 
               {
                  in.get();   // 消耗换行符
                  return in;  // 直接返回，vec为空
               }
            }
            return in;
        }    //输入重载
    

        template <typename T>
        ostream& operator<<(ostream& out,const vector<T>& c)
        {
            out<<'[';
            for(int i=0;i<c.s_size;i++)
            {
                out<<c.data[i];
                if(i<c.s_size-1)
                 out<<',';
            }
            out<<']';
            return out;
        }       //输出重载

        template <typename T>
        void vector<T>::reserve(int d_c)
        {
           if((c_capacity-s_size)!=d_c)
                reallocate(d_c+s_size);
        } //预留空间

        template <typename T>
        void vector<T>::shrink_to_fit()
        {
            if(c_capacity!=s_size)
                reallocate(s_size);
        } //释放多余内存

        template <typename T>
        void vector<T>::insert(int index,T num,int length)
        {
            if((index>=0)&&(index<=s_size))
            {
                if(c_capacity<s_size+length)
                    reallocate(s_size+length);
                for(int i=s_size-1;i>=index;i--)
                    data[i+length]=data[i];
                for(int i=0;i<length;i++)
                    data[index+i] = num;        
                s_size+=length;
            }
        } //插入元素

        template <typename T>
        void vector<T>::erase(int index,int length)
        {
           if((index>=0)&&(index<s_size))
           {    
                if(length > s_size-index)
                    length= s_size -index;
                for(int i=index+length;i<s_size;i++)
                    data[i+1-length] = data[i];
                s_size-=length;
           }
        }    //删除元素

        template <typename T>
        void vector<T>::swap(vector &a)
        {
           vector temp(a);
           a=*this;
           data = new T [temp.c_capacity];
           for(int i=0;i<temp.s_size;i++)
             data[i] = temp.data[i];
             s_size = temp.s_size;
            c_capacity = temp.c_capacity;          
        } //交换

        template <typename T>
        vector<T>::~vector()
        {
            delete[] data;
        } //析构函数

#endif