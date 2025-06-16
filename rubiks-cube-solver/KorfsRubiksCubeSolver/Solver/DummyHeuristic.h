#ifndef DummyHeuristic_H
#define DummyHeuristic_H
template<typename T>
class DummyHeuristic
{
private:
    /* data */
public:
    DummyHeuristic(/* args */){};
    int operator()(const T & cube){
        return 0;
    }
    ~DummyHeuristic(){};
};


#endif //DummyHeuristic_H
