#include<chrono>
#include<iostream>


using namespace std;

class Timer
{
public:
    Timer()
        : start_(std::chrono::high_resolution_clock::now())
    {
    }

    ~Timer()
    {
        const auto finish = std::chrono::high_resolution_clock::now();
        std::cout << std::chrono::duration_cast<std::chrono::microseconds>(finish - start_).count() << " us" << std::endl;
    }

private:
    const std::chrono::high_resolution_clock::time_point start_;
};

int main()
{

constexpr size_t n = 10000;
int** a;
a = new int*[n];
for (int i = 0; i<n; i++){
a[i] = new int[n];
};
int sum = 0;

Timer* t1 = new Timer();

for (int i = 0;i<n; i++) //rows
 for (int j = 0; j<n; j++){
  sum = sum + a[i][j];
 };

delete t1;

Timer* t2 = new Timer();

for (int j = 0;j<n; j++) //columns
 for (int i = 0; i<n; i++){
  sum = sum + a[i][j];
 };

delete t2;


return 0;
}
