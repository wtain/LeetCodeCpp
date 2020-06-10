
#include <thread>
#include <future>

//template <typename T>
//using myGeneric = T;

/*double processor(int i, double(*f[])(int), int idx)
{
	return f[idx](i);
}*/

int func1(std::future<int>& delayedParam)
{
	int x = delayedParam.get();

	int y = 1; // throw exception()
	return y;
}

void func2(std::promise<int> & result, std::promise<bool>& done)
{
	result.set_value(10);
	done.set_value(true);
}

int main()
{
	//myGeneric<int> a;

	std::promise<int> promisedArgument;
	std::future<int> futureArgument = promisedArgument.get_future();

	auto f = std::async(std::launch::async, func1, std::ref(futureArgument));

	promisedArgument.set_value(4);

	try
	{
		bool isValid = f.valid();
		int y1 = f.get();

		isValid = f.valid();
		int y2 = f.get();
	}
	catch(...)
	{

	}

	std::promise<int> resultPromise;
	std::promise<bool> donePromise;

	std::future<int> resultFuture = resultPromise.get_future();
	std::future<bool> doneFuture = donePromise.get_future();

	std::async(std::launch::async, func2, std::ref(resultPromise), std::ref(donePromise));

	bool done = doneFuture.get();
	int result_f2 = resultFuture.get();

    return 0;
}

