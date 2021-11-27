#include <iostream>
#include <ctime>
#include <iomanip>

int main()
{
    std::tm time;
    std::time_t start=0, end;
    time=*std::localtime(&start);

    std::cout << "Input time: ";
    std::cin >> std::get_time(&time, "%M:%S");

    start=std::time(nullptr);
    end=start+std::mktime(&time);

    while(std::time(nullptr)<end)
    {
        if(std::time(nullptr)>start)
        {
            if(time.tm_sec>0)
                time.tm_sec--;
            else
            {
                time.tm_sec=59;
                time.tm_min--;
            }
            std::cout << std::put_time(&time, "%M:%S") << std::endl;
            start++;
        }
    }
    std::cout << "DING! DING! DING!";

    return 0;
}
