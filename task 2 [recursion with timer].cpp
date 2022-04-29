#include <iostream>
#include <chrono>
#include <math.h>

using namespace std;

#define INITRD(low, high) random_device randev;                                 \
                          mt19937 gen(randev());                                \
                          uniform_int_distribution<int> dist((low), (high))     

class Timer {
private:
    chrono::time_point<chrono::high_resolution_clock> m_startTime;
    chrono::time_point<chrono::high_resolution_clock> m_endTime;
    long long ms;
    long long us;
public:
    Timer(bool immidiatelyStart) {
        us = 0LL;
        ms = 0LL;
        if (immidiatelyStart == true) {
            start();
        }
    }

    void start() {
        m_startTime = chrono::high_resolution_clock::now();
    }

    void stop() {
        m_endTime = chrono::high_resolution_clock::now();

        auto alpha = chrono::time_point_cast<chrono::microseconds>(m_startTime).time_since_epoch().count();
        auto omega = chrono::time_point_cast<chrono::microseconds>(m_endTime).time_since_epoch().count();
        auto duration = omega - alpha;
        ms = duration / 1000LL;
        us = duration;
    }

    long long getms() {
        return ms;
    }

    long long getus() {
        return us;
    }

    ~Timer() {
        stop();
    }
};

long long int UsingRecursion(long long int x){
    //base case
    if(x == 0){
        return 0;
    }else if(x == 1){
        return 1;
    }else{
        return UsingRecursion(x-1) + UsingRecursion(x-2);
    }
}
 
long long int UsingIteration(long long int y){
    int a = 0, b = 1, result = 0;
    if(y == 0){
        return 0;
    }else if(y == 1){
        return 1;
    }else{
        for (int i = 1; i < y; i++){
            result = a + b;
            a = b;
            b = result; 
        }
        return result;
    }

}

int main(){

    //first calculation
    cout << "\n[FIRST CALCULATION]" << endl;
    Timer DurationUsingRecursion1(false);
    DurationUsingRecursion1.start();
    cout << "Using Recursion (44) = " << UsingRecursion(44) << endl;
    DurationUsingRecursion1.stop();
    cout << "Duration of Program Using Recursion = " << DurationUsingRecursion1.getus() << " microseconds" << endl;

    cout << "\n";
    Timer DurationUsingIteration1(false);
    DurationUsingIteration1.start();
    cout << "Using Iteration (44) = " << UsingIteration(44) << endl; 
    DurationUsingIteration1.stop();
    cout << "Duration of Program Using Iteration = " << DurationUsingIteration1.getus() << " microseconds" << endl;
    cout << "\n----------------------------------------";

    //second calculation
    cout << "\n[SECOND CALCULATION]" << endl;
    Timer DurationUsingRecursion2(false);
    DurationUsingRecursion2.start();
    cout << "Using Recursion (45) = " << UsingRecursion(45) << endl;
    DurationUsingRecursion2.stop();
    cout << "Duration of Program Using Recursion = " << DurationUsingRecursion2.getus() << " microseconds" << endl;

    cout << "\n";
    Timer DurationUsingIteration2(false);
    DurationUsingIteration2.start();
    cout << "Using Iteration (45) = " << UsingIteration(45) << endl; 
    DurationUsingIteration2.stop();
    cout << "Duration of Program Using Iteration = " << DurationUsingIteration2.getus() << " microseconds" << endl;
    cout << "\n----------------------------------------";

    //third calculation
    cout << "\n[THIRD CALCULATION]" << endl;
    Timer DurationUsingRecursion3(false);
    DurationUsingRecursion3.start();
    cout << "Using Recursion (46) = " << UsingRecursion(46) << endl;
    DurationUsingRecursion3.stop();
    cout << "Duration of Program Using Recursion = " << DurationUsingRecursion3.getus() << " microseconds" << endl;

    cout << "\n";
    Timer DurationUsingIteration3(false);
    DurationUsingIteration3.start();
    cout << "Using Iteration (46) = " << UsingIteration(46) << endl; 
    DurationUsingIteration3.stop();
    cout << "Duration of Program Using Iteration = " << DurationUsingIteration3.getus() << " microseconds" << endl;
    cout << "\n----------------------------------------";
    
    }
