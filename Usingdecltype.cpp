//Microsoft (R) C/C++ Optimizing Compiler Version 19.00.23506 for x86

#include <iostream>

enum Color
{
    red,
    blue,
    green
};

enum Day
{
    Mon,
    Tue
};
int GetGoalEnum(Color c)
{
    return 3;
}

template<typename T>
struct has_size
{
    private:
    template<typename U>
        static decltype(std::declval<U>().size(),std::true_type()) test(int);
    template<typename>
        static std::false_type test(...);
    
    public:
     typedef decltype(test<T>(0)) type;
    enum {value = type::value};
};
    
template<typename U>
struct GoalEnumExists
{
    private:
    template<typename T>
    static decltype(GetGoalEnum(std::declval<T>()),std::true_type()) test(int);
    template<typename>
        static std::false_type test(...);
    
    public:
    typedef decltype(test<U>(0)) type;
    enum {value = type::value};
    
};
class test
{
    public:
    int size() { return 2; }
    
};

class nosize
{
    public:
    int sizeless() { return 3;}
};

template<typename T, bool val = std::is_enum<T>::value && GoalEnumExists<T>::value>
    struct doSomeThing;


template<typename T>
struct doSomeThing<T, false>
{
    void print()
    {
        std::cout << "In the False Case" << std::endl;
    }
};

template<typename T>
struct doSomeThing<T, true>
{
    void print()
    {
        std::cout << "In the True Case" << std::endl;
    }
};


int main()
{
    //std::cout << has_size<test>::value << std::endl;
    //std::cout << has_size<nosize>::value << std::endl;
    std::cout << GoalEnumExists<Color>::value << std::endl;
    std::cout << GoalEnumExists<Day>::value << std::endl;
    doSomeThing<Color>().print();
    std::cout << "Hello, world!\n";
}