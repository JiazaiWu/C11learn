#include <iostream>
#include <algorithm>
#include <thread>
#include <vector>
template<typename Iterator,typename T>
struct accumulate_block
{
	void operator()(Iterator first,Iterator last,T& result)
	{
		result=std::accumulate(first,last,result);
	}
};

template<typename Iterator,typename T>
T parallel_accumulate(Iterator first,Iterator last,T init)
{
	unsigned long const length=std::distance(first,last);
	if(!length) // 1
		return init;
	unsigned long const min_per_thread=25;
	unsigned long const max_threads=
		(length+min_per_thread-1)/min_per_thread; // 2
	unsigned long const hardware_threads=
		std::thread::hardware_concurrency();
	unsigned long const num_threads= // 3
		std::min(hardware_threads != 0 ? hardware_threads : 2,max_threads);
	std::cout << "length " << length << " num_threads " << num_threads << std::endl;
	unsigned long const block_size=length/num_threads; // 4
	std::cout << "block_size " << block_size << std::endl;
	std::vector<T> results(num_threads);
	std::vector<std::thread> threads(num_threads-1); // 5
	Iterator block_start=first;
	for(unsigned long i=0; i < (num_threads-1); ++i)
	{
		Iterator block_end=block_start;
		std::advance(block_end,block_size); // 6
		threads[i]=std::thread( 
			accumulate_block<Iterator,T>(),
			block_start,block_end,std::ref(results[i]));// 7
		block_start=block_end; // 8
	}
	accumulate_block<Iterator,T>()(block_start,last,results[num_threads-1]); // 9
	std::for_each(threads.begin(),threads.end(), std::mem_fn(&std::thread::join)); // 10
	return std::accumulate(results.begin(),results.end(),init); //
}

int main()
{
	std::cout << std::thread::hardware_concurrency() << std::endl;
	std::vector<int> vect = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
	int ret = parallel_accumulate<std::vector<int>::iterator, int>(vect.begin(), vect.end(), 0);
	std::cout << "ret = " << ret << std::endl;
	return 0;
}