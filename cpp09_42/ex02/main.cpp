// #include "PmergeMe.hpp"
#include "PmergeMe.hpp"

long	get_relative_us(struct timeval begin_tv)
{
	struct timeval	current_tv;
	long			sec_interval;
	long			usec_interval;

	gettimeofday(&current_tv, NULL);
	sec_interval = current_tv.tv_sec - begin_tv.tv_sec;
	usec_interval = current_tv.tv_usec - begin_tv.tv_usec;
	return (usec_interval + sec_interval * TIME_FACTOR * TIME_FACTOR);
}

long int	__gettime(struct timeval begin_tv)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec - begin_tv.tv_sec) * 1000
		+ (now.tv_usec - begin_tv.tv_usec) / 1000);
}

int main(int ac, char **av)
{
    struct timeval before;
    long InsertTimeVector = 0;
    if (ac < 3)
    {
        std::cout << "Error." << std::endl;
        return (4);
    }
    //VECTOR JOB
    MERGE<std::vector<int> >   *second;

    second = new MERGE<std::vector<int> >;

    gettimeofday(&before, NULL);
    int i = 1;
    while (av[i])
    {
        second->putInCont(av[i]);
        i++;
    }
    InsertTimeVector = get_relative_us(before);

    i = 0;

    //DEQUE JOB

    MERGE<std::deque<int> >  *third;
    third = new MERGE<std::deque<int> >;
    long InsertTimeDeque = 0;

    gettimeofday(&before, NULL);
    i = 1;
    while (av[i])
    {
        third->putInCont(av[i]);
        i++;
    }
    InsertTimeDeque = get_relative_us(before);


    struct timeval sortBefore;
    gettimeofday(&sortBefore, NULL);


    int argsVec = second->getNbrOfArgs();
    std::cout << "Before : ";
    second->printFill();
    

    std::vector<int> fillone = second->getFill();
    long VectorSortTime = get_relative_us(sortBefore);
    second->sort(fillone);
    
    second->mergeBoth();
    std::cout << "After : ";
    second->printTab();
    // std::cout << "Time to process a range of " << argsVec << " elements with std::vector : " << vecDuration.count() << " microSeconds" << std::endl;

    delete second;

    std::cout << "[VECTOR] - Insert time : " << InsertTimeVector << " us" << std::endl;
    std::cout << "[DEQUE] - Insert time : " << InsertTimeDeque << " us " << std::endl;
    //===============

    
    // std::cout << "[DEQUE] - Insert time : " << get_relative_us(before) << " us " << std::endl;
    int nbrArgs = third->getNbrOfArgs();
    // auto start2 = std::chrono::high_resolution_clock::now();
    
    std::deque<int> filltwo = third->getFill();
    long DequeueSortTime = get_relative_us(sortBefore);
    third->sort(filltwo);
    third->mergeBoth();

    std::cout << "Time to process a range of " << argsVec << " elements with [STD::VECTOR] : ";
    std::cout << VectorSortTime << " us." << std::endl;
    std::cout << "Time to process a range of " << nbrArgs << " elements with [STD::DEQUE] : ";
    std::cout << DequeueSortTime << " us." << std::endl; 
    // auto stop2 = std::chrono::high_resolution_clock::now();
    // std::cout << std::endl;
    // std::cout << "[DEQUE] - After merge : ";
    // third->printTab();
    // auto dekDuration = std::chrono::duration_cast<std::chrono::microseconds>(stop2 - start2);
    // std::cout << "Time to process a range of " << nbrArgs << " elements with std::deque : " << dekDuration.count() << " microseconds" << std::endl;

    delete third;

    //



}