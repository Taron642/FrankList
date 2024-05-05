#ifndef _FRANKLIST_H__
#define _FRANKLIST_H__

#include <cstddef>
#include <iostream>
#include <iterator>



template <typename T>
class FrankList;

template <typename T>
std::ostream& operator<<(std::ostream& out, const FrankList<T>& rhv);

template <typename T>
class FrankList
{
private:
    struct Node
    {
        T val;
        Node* next;
        Node* prev;
        Node* asc;
        Node* desc;
        Node();
        Node(T val);
    };
private:
    class base_iterator
    {
        friend FrankList<T>;
    public:
        ~base_iterator();
        bool operator==(const base_iterator& rhv) const; //O(1)
        bool operator!=(const base_iterator& rhv) const; //O(1)
    protected:
        explicit base_iterator(Node* ptr); //O(1)
    protected:
        Node* ptr = nullptr;
    };
public:
    class const_iterator : public base_iterator
    {
        friend FrankList<T>;
    public:
        const_iterator(const base_iterator& rhv); //O(1)
        const_iterator(base_iterator&& rhv); //O(1)
        
        const const_iterator& operator=(const base_iterator& rhv); //O(1)
        const const_iterator& operator=(base_iterator&& rhv); //O(1)
        const T& operator*() const; //O(1)
        const T* operator->() const; //O(1)

        const const_iterator& operator++(); //O(1)
        const const_iterator operator++(T); //O(1)
        const const_iterator& operator--(); //O(1)
        const const_iterator operator--(T); //O(1)

    protected:
        explicit const_iterator(Node* ptr); //O(1)
    };

public:
    class iterator : public const_iterator
    {
        friend FrankList<T>;
    public:
        iterator(const base_iterator& rhv); //O(1)
        iterator(base_iterator&& rhv); //O(1)

        T& operator*(); //O(1)
        T* operator->(); //O(1)

        const iterator& operator=(const base_iterator& rhv); //O(1)
        const iterator& operator=(base_iterator&& rhv); //O(1)
    protected:
        explicit iterator(Node* ptr); //O(1)
    };

public:
    class const_reverse_iterator : public base_iterator
    {
        friend FrankList<T>;
    public:
        const_reverse_iterator(const base_iterator& rhv); //O(1)
        const_reverse_iterator(base_iterator&& rhv); //O(1)
        
        const const_reverse_iterator& operator=(const base_iterator& rhv); //O(1)
        const const_reverse_iterator& operator=(base_iterator&& rhv); //O(1)
        const T& operator*() const; //O(1)
        const T* operator->() const; //O(1)

        const const_reverse_iterator& operator++(); //O(1)
        const const_reverse_iterator operator++(T); //O(1)
        const const_reverse_iterator& operator--(); //O(1)
        const const_reverse_iterator operator--(T); //O(1)

    protected:
        explicit const_reverse_iterator(Node* ptr); //O(1)
    };
public:
    class reverse_iterator : public const_reverse_iterator
    {
        friend FrankList<T>;
    public:
        reverse_iterator(const base_iterator& rhv); //O(1)
        reverse_iterator(base_iterator&& rhv); //O(1)

        T& operator*(); //O(1)
        T* operator->(); //O(1)

        const reverse_iterator& operator=(const base_iterator& rhv); //O(1)
        const reverse_iterator& operator=(base_iterator&& rhv); //O(1)
        
    protected:
        explicit reverse_iterator(Node* ptr); //O(1)
    };
public:
    class const_asc_iterator :public base_iterator
    {
        friend FrankList<T>;
    public:
        const_asc_iterator(const base_iterator& rhv); //O(1)
        const_asc_iterator(base_iterator&& rhv); //O(1)
        
        const const_asc_iterator& operator=(const base_iterator& rhv); //O(1)
        const const_asc_iterator& operator=(base_iterator&& rhv); //O(1)
        const T& operator*() const; //O(1)
        const T* operator->() const; //O(1)

        const const_asc_iterator& operator++(); //O(1)
        const const_asc_iterator operator++(T); //O(1)
        const const_asc_iterator& operator--(); //O(1)
        const const_asc_iterator operator--(T); //O(1)

    protected:
        explicit const_asc_iterator(Node* ptr); //O(1)
    };
public:
    class asc_iterator : public const_asc_iterator
    {
        friend FrankList<T>;
    public:
        asc_iterator(const base_iterator& rhv); //O(1)
        asc_iterator(base_iterator&& rhv); //O(1)

        T& operator*(); //O(1)
        T* operator->(); //O(1)

        const asc_iterator& operator=(const base_iterator& rhv); //O(1)
        const asc_iterator& operator=(base_iterator&& rhv); //O(1)
        
    protected:
        explicit asc_iterator(Node* ptr); //O(1)
    };
public:
    class const_desc_iterator : public base_iterator
    {
        friend FrankList<T>;
    public:
        const_desc_iterator(const base_iterator& rhv); //O(1)
        const_desc_iterator(base_iterator&& rhv); //O(1)
        
        const const_desc_iterator& operator=(const base_iterator& rhv); //O(1)
        const const_desc_iterator& operator=(base_iterator&& rhv); //O(1)
        const T& operator*() const; //O(1)
        const T* operator->() const; //O(1)

        const const_desc_iterator& operator++(); //O(1)
        const const_desc_iterator operator++(T); //O(1)
        const const_desc_iterator& operator--(); //O(1)
        const const_desc_iterator operator--(T); //O(1)

    protected:
        explicit const_desc_iterator(Node* ptr); //O(1)
    };
public:
    class desc_iterator : public const_desc_iterator
    {
        friend FrankList<T>;
    public:
        desc_iterator(const base_iterator& rhv); //O(1)
        desc_iterator(base_iterator&& rhv); //O(1)

        T& operator*(); //O(1)
        T* operator->(); //O(1)

        const desc_iterator& operator=(const base_iterator& rhv); //O(1)
        const desc_iterator& operator=(base_iterator&& rhv); //O(1)
        
    protected:
        explicit desc_iterator(Node* ptr); //O(1)
    };
public:
    class const_multi_iterator : public base_iterator
    {
        friend FrankList<T>;
    public:
        const_multi_iterator(const base_iterator& rhv); //O(1)
        const_multi_iterator(base_iterator&& rhv); //O(1)
        
        const const_multi_iterator& operator=(const base_iterator& rhv); //O(1)
        const const_multi_iterator& operator=(base_iterator&& rhv); //O(1)
        const T& operator*() const; //O(1)
        const T* operator->() const; //O(1)

        const const_multi_iterator& operator++(); //O(1)
        const const_multi_iterator operator++(T); //O(1)
        const const_multi_iterator& operator--(); //O(1)
        const const_multi_iterator operator--(T); //O(1)

        void chmod(); //O(1)
    protected:
        explicit const_multi_iterator(Node* ptr); //O(1)
        bool mode = true;
    };
public:
    class multi_iterator : public const_multi_iterator
    {
        friend FrankList<T>;
    public:
        multi_iterator(const base_iterator& rhv); //O(1)
        multi_iterator(base_iterator&& rhv); //O(1)

        T& operator*(); //O(1)
        T* operator->(); //O(1)

        const multi_iterator& operator=(const base_iterator& rhv); //O(1)
        const multi_iterator& operator=(base_iterator&& rhv); //O(1)
        
    protected:
        explicit multi_iterator(Node* ptr); //O(1)
    };
public:
    class const_multi_reverse_iterator : public base_iterator
    {
        friend FrankList<T>;
    public:
        const_multi_reverse_iterator(const base_iterator& rhv); //O(1)
        const_multi_reverse_iterator(base_iterator&& rhv); //O(1)
        
        const const_multi_reverse_iterator& operator=(const base_iterator& rhv); //O(1)
        const const_multi_reverse_iterator& operator=(base_iterator&& rhv); //O(1)
        const T& operator*() const; //O(1)
        const T* operator->() const; //O(1)

        const const_multi_reverse_iterator& operator++(); //O(1)
        const const_multi_reverse_iterator operator++(T); //O(1)
        const const_multi_reverse_iterator& operator--(); //O(1)
        const const_multi_reverse_iterator operator--(T); //O(1)


        void chmod(); //O(1)
    protected:
        explicit const_multi_reverse_iterator(Node* ptr); //O(1)
        bool mode = true;
    };
public:
    class multi_reverse_iterator : public const_multi_reverse_iterator
    {
        friend FrankList<T>;
    public:
        multi_reverse_iterator(const base_iterator& rhv); //O(1)
        multi_reverse_iterator(base_iterator&& rhv); //O(1)

        T& operator*(); //O(1)
        T* operator->(); //O(1)

        const multi_reverse_iterator& operator=(const base_iterator& rhv); //O(1)
        const multi_reverse_iterator& operator=(base_iterator&& rhv); //O(1)
        
    protected:
        explicit multi_reverse_iterator(Node* ptr); //O(1)
    };

public:
    FrankList(); //O(1)
    FrankList(std::size_t size); //O(n)
    FrankList(std::size_t size, const T& init); //O(n)
    FrankList(const FrankList<T>& rhv); //O(n)
    FrankList(FrankList<T>&& rhv); //O(1)
    FrankList(std::initializer_list<T> init); //O(n)
    template <typename input_iterator>
    FrankList(input_iterator f, input_iterator l); //O(n)
    ~FrankList();

public:
    void swap(FrankList<T>& rhv); //O(1)

    std::size_t size() const; //O(n)

    bool empty() const; //O(1)
    void resize(std::size_t s, const T& init = T()); //O(n)
    void clear() noexcept; //O(n)

    void push_front(const T& elem); //~O(1)
    void pop_front(); //O(1)
    void push_back(const T& elem); //~O(1)
    void pop_back(); //O(1)

    const T& front() const; //O(1)
    T& front(); //O(1)
    const T& back() const; //O(1)
    T& back(); //O(1)
    const T& min() const; //O(1)
    T& min(); //O(1)
    const T& max() const; //O(1)
    T& max(); //O(1)

    const FrankList<T>& operator=(const FrankList<T>& rhv); //O(n)
    const FrankList<T>& operator=(FrankList<T>&& rhv); //O(n)
    const FrankList<T>& operator=(std::initializer_list<T> init); //O(n)

    bool operator==(const FrankList<T>& rhv) const; //O(n)
    bool operator!=(const FrankList<T>& rhv) const; //O(n)
    bool operator<(const FrankList<T>& rhv) const; //O(n)
    bool operator<=(const FrankList<T>& rhv) const; //O(n)
    bool operator>(const FrankList<T>& rhv) const; //O(n)
    bool operator>=(const FrankList<T>& rhv) const; //O(n)

public:
    const_iterator cbegin() const; //O(1)
    const_iterator cend() const; //O(1)
    const_reverse_iterator crbegin() const; //O(1)
    const_reverse_iterator crend() const; //O(1)
    const_asc_iterator cabegin() const; //O(1)
    const_asc_iterator caend() const; //O(1)
    const_desc_iterator cdbegin() const; //O(1)
    const_desc_iterator cdend() const; //O(1)
    const_multi_iterator cmbegin() const; //O(1)
    const_multi_iterator cmend() const; //O(1)
    const_multi_iterator cmabegin() const; //O(1)
    const_multi_iterator cmaend() const; //O(1)
    const_multi_reverse_iterator cmrbegin() const; //O(1)
    const_multi_reverse_iterator cmrend() const; //O(1)
    const_multi_reverse_iterator cmrdbegin() const; //O(1)
    const_multi_reverse_iterator cmrdend() const; //O(1)

    iterator begin(); //O(1)
    iterator end(); //O(1)
    reverse_iterator rbegin(); //O(1)
    reverse_iterator rend(); //O(1)
    asc_iterator abegin(); //O(1)
    asc_iterator aend(); //O(1)
    desc_iterator dbegin(); //O(1)
    desc_iterator dend(); //O(1)
    multi_iterator mbegin(); //O(1)
    multi_iterator mend(); //O(1)
    multi_iterator mabegin(); //O(1)
    multi_iterator maend(); //O(1)
    multi_reverse_iterator mrbegin(); //O(1)
    multi_reverse_iterator mrend(); //O(1)
    multi_reverse_iterator mrdbegin(); //O(1)
    multi_reverse_iterator mrdend(); //O(1)

public:
    template <typename iter>
    typename std::enable_if<std::is_base_of<const_iterator, iter>::value ||
                              std::is_base_of<const_asc_iterator, iter>::value ||
                              std::is_base_of<const_multi_iterator, iter>::value, 
             iter>::type
    insert(iter pos, const T& val) { //O(1)
        return insert_def(pos, val);
    }
    
    template <typename iter>
    typename std::enable_if<std::is_base_of<const_reverse_iterator, iter>::value ||
                              std::is_base_of<const_desc_iterator, iter>::value ||
                              std::is_base_of<const_multi_reverse_iterator, iter>::value,
             iter>::type
    insert(iter pos, const T& val) { //O(1)
        return insert_rev(pos, val);
    }

    template <typename iter>
    iter insert(iter pos, std::size_t size, const T& val); //O(n)
    template <typename iter>
    iter insert(iter pos, std::initializer_list<T> init); //O(n)
    template <typename iter, typename input_iterator>
    iter insert(iter pos, input_iterator f, input_iterator l); //O(n)

    template <typename iter>
    iter erase(iter pos); //O(1)
    template <typename iter>
    iter erase(iter f, iter l); //O(n)

    std::size_t remove(const T& val); //O(n)
    template <typename unary_predicate>
    std::size_t remove_if(unary_predicate func); //O(n)

    void reverse(); //O(n)
    void sort(bool reversed = false); //O(n)

    iterator find(const T& elem); //O(n)
    iterator rfind(const T& elem); //O(n)

    template <typename unary_predicate>
    void traverse(unary_predicate func, bool sorted = false, bool reversed = false); //O(n)

    void print(bool sorted = false, bool reversed = false); //O(n)

protected:
    void put_in_sorted_order(Node* ptr); //O(n)
    void organize_left(Node* ptr); //O(1)
    void organize_right(Node* ptr); //O(1)
private:
    template <typename iter>
    iter insert_def(iter pos, const T& val); //O(1)
    
    template <typename iter>
    iter insert_rev(iter pos, const T& val); //O(1)

private:
    Node* head;
    Node* tail;
    Node* ahead;
    Node* atail;
};




#endif // _FRANKLIST_H__
