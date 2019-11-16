#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <thread>
#include <mutex>
#include <unistd.h> 
#define timeout 1000

using namespace std;

queue<int> consumer_task_queue;
mutex producer_mutex, consumer_mutex;
int input_size, flag = 0;
int total_time = 0;
int current_task_number = 0;
int tasks_completed = 0;
int idle_time;
int start[10];
int end_time[10];
double consumer_task_queue_length = 0;


void produce(vector< pair<int, int> > input){
	
	while(current_task_number < input.size()){
		producer_mutex.lock();
		cout << "Time is : " << total_time << "\n";
		producer_mutex.unlock();
		while(total_time == input[current_task_number].first){
			producer_mutex.lock();
			cout << "Task " << current_task_number << " at time : " << total_time << "\n";
			producer_mutex.unlock();

			consumer_task_queue.push(input[current_task_number].second);
			current_task_number++;
		}
		usleep(timeout);
	}
	flag += 1;
}

void consume(){

	while(tasks_completed < input_size){
		int time_for_task;
		consumer_mutex.lock();
		while(true){
			if(!consumer_task_queue.empty()){
				time_for_task = consumer_task_queue.front(); consumer_task_queue.pop();
				tasks_completed++;
				break;
			}else{
				// Wait till next cycle and check again if task is put in queue
				idle_time++;
				usleep(timeout);
			}
		}
		// consumer_mutex.unlock();

		// consumer_mutex.lock();
		start[current_task_number] 		= total_time;
		end_time[current_task_number]	= total_time + time_for_task;
		consumer_mutex.unlock();

		// Sleep until task is completed
		for(int k = 0; k < time_for_task; k++){
			usleep(timeout);
		}

		producer_mutex.lock();
		producer_mutex.unlock();
	}
	flag += 1;
	
}

void global_time(){

	// Until both producer and consumers are finished working, keep increasing time.
	while(flag <= 1)
	{
		usleep(timeout);
		consumer_task_queue_length += consumer_task_queue.size();
		total_time++;
	}
}

int main(int argc, char const *argv[])
{

	vector< pair<int, int> > input;
	cin >> input_size;
	int time_of_arrival = 0;
	for (int i = 0; i < input_size; ++i)
	{
		int inter_arrival_time, service_time;
		cin >> inter_arrival_time >> service_time;
		time_of_arrival += inter_arrival_time;
		input.push_back(make_pair(time_of_arrival, service_time));
	}

	thread clock(global_time);
	thread producer(produce, input);
	thread consumer(consume);

	producer.join();
	clock.join();
	consumer.join();
	cout << "Tasks Finished" << endl;
    double avg_wait = 0;

    for (int i = 1; i <= input_size; ++i)
    {
    	cout << "Waiting time of task " << i << " is " << max(start[i]-input[i-1].first,0) << "\n";	
    	// cout << "Waiting time of task " << i << " is " << start[i] << " - " << input[i-1].first  << "=" << start[i]-input[i-1].first << "\n";	
    	avg_wait += max(start[i]-input[i-1].first,0);
    	cout << "Cumulative departure time for task " << i << " is " << end_time[i] << "\n";
    }
    cout << "Average queue length is : " << consumer_task_queue_length/(1.0*total_time) << "\n";
    cout << "Average waiting time is : " << avg_wait/(1.0*input_size) << "\n";
	cout << "Idle time of worker is " << idle_time << "\n";


	return 0;
}

/*
8
0 20
10 15
15 10
35 5
30 15
10 15
5 10
5 10
*/