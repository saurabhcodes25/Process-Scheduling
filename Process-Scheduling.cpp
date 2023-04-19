#include <bits/stdc++.h>

using namespace std;


// FCFS Scheduling Algorithm

class FCFS
{

public:

	// Function to find the waiting Time of the Program

	void findWaitingTime(vector<int> processes, int n, vector<int> bt, int wt[])
	{
		wt[0] = 0;

		for (int i = 1; i < n; i++)
		{
			wt[i] = bt[i - 1] + wt[i - 1];
		}
	}

	// Function to find TAT


	void findTurnAroundTime(vector<int> processes, int n, vector<int> bt, int wt[], int tat[])
	{

		for (int i = 0; i < n; i++)
		{
			tat[i] = bt[i] + wt[i];
		}
	}

	// Function to find Average time of FCFS

	void findAverageTime(vector<int> processes, int n, vector<int> bt)
	{
		int wt[n], tat[n], total_wt = 0, total_tat = 0;

		findWaitingTime(processes, n, bt, wt);

		findTurnAroundTime(processes, n, bt, wt, tat);

		cout << "\nProcesses  "
			 << " Burst time  "
			 << " Waiting time  "
			 << " Turn around time\n";

		for (int i = 0; i < n; i++)
		{
			total_wt = total_wt + wt[i];
			total_tat = total_tat + tat[i];
			cout << "   " << i + 1 << "\t\t" << bt[i] << "\t    " << wt[i] << "\t\t  " << tat[i] << endl;
		}

		cout << "Average waiting time = " << (float)total_wt / (float)n;
		cout << "\nAverage turn around time = " << (float)total_tat / (float)n;
	}
};


// Priority Scheduling Algorithm


class Priority
{

public:
	// Function to find the waiting Time of the Program

	void findWaitingTime(vector<int> processes, int n, int wt[])
	{
		wt[0] = 0;

		for (int i = 1; i < n; i++)
		{
			wt[i] = processes[i - 1] + wt[i - 1];
		}
	}


	// Function to find TAT

	void findTurnAroundTime(vector<int> processes, int n, int wt[], int tat[])
	{
		for (int i = 0; i < n; i++)
		{
			tat[i] = processes[i] + wt[i];
		}
	}


	// Function to find Average time of Priority

	void findavgTime(vector<int> processes, int n)
	{
		int wt[n], tat[n], total_wt = 0, total_tat = 0;

		findWaitingTime(processes, n, wt);

		findTurnAroundTime(processes, n, wt, tat);

		cout << "\nProcesses  "
			 << " Burst time  "
			 << " Waiting time  "
			 << " Turn around time\n";

		for (int i = 0; i < n; i++)
		{
			total_wt = total_wt + wt[i];
			total_tat = total_tat + tat[i];
			cout << "   " << processes[i] << "\t\t"
				 << processes[i] << "\t    " << wt[i]
				 << "\t\t  " << tat[i] << endl;
		}

		cout << "\nAverage waiting time = "
			 << (float)total_wt / (float)n;

		cout << "\nAverage turn around time = "
			 << (float)total_tat / (float)n;
	}

	// Function to sort the processes according to priority

	void priorityScheduling(vector<int> processes, int n)
	{
		sort(processes.begin(), processes.end(), greater<>());

		cout << "Order in which processes gets executed \n";
		for (int i = 0; i < n; i++)
			cout << processes[i] << " ";

		findavgTime(processes, n);
	}
};


// Shortest Job First Scheduling Algorithm


class SJF
{

public:

	// Function to find the turn around time of the Program


	void findTurnAroundTimeSJF(vector<int> processes, int n, vector<int> bt, int wt[], int tat[])
	{
		for (int i = 0; i < n; i++)
		{
			tat[i] = bt[i] + wt[i];
		}
	}

	// Function to find the waiting Time of the Program

	void findWaitingTimeSJF(vector<int> processes, int n, vector<int> bt, int wt[])
	{
		for (int i = 1; i < n; i++)
		{
			wt[i] = wt[i - 1] + bt[i];
		}
	}


	// Function to find Average time of SJF

	void SJFFunc(vector<int> processes, int n, vector<int> bt)
	{
		int wt[n] = {0}; int tat[n] = {0};

		findWaitingTimeSJF(processes, n, bt, wt);

		findTurnAroundTimeSJF(processes, n, bt, wt, tat);

		cout << "\nProcesses "
		     << "BurstTime "
		     << " WaitingTime "
		     << "TurnAroundTime ";

		cout << "\n";

		for (int i = 0; i < n; i++)
		{
			cout << i + 1 << "\t\t" << bt[i] << "\t\t" << wt[i] << "\t" << tat[i] << "\n";
		}

		cout << "Average waiting time is = " << float(accumulate(wt, wt + n, 0)) / float(n) << "\n";

		cout << "Average Turn Around Time is =" << float(accumulate(tat, tat + n, 0)) / float(n) << "\n";
	}
};


// Round Robin Scheduling

class RR
{
public:

	// Function to find the waiting Time of the Program

	void findWaitingTime(vector<int> processes, int n, vector<int> bt, int wt[], int quantum)
	{

		int rem_bt[n];
		for (int i = 0; i < n; i++)
			rem_bt[i] = bt[i];

		int t = 0;

		while (1)
		{
			bool done = true;

			for (int i = 0; i < n; i++)
			{

				if (rem_bt[i] > 0)
				{
					done = false;

					if (rem_bt[i] > quantum)
					{
						t += quantum;

						rem_bt[i] -= quantum;
					}

					else
					{

						t = t + rem_bt[i];

						wt[i] = t - bt[i];

						rem_bt[i] = 0;
					}
				}
			}

			if (done == true)
				break;
		}
	}


	// Function to find the turn around Time of the Program


	void findTurnAroundTime(vector<int> processes, int n,
							vector<int> bt, int wt[], int tat[])
	{

		for (int i = 0; i < n; i++)
		{
			tat[i] = bt[i] + wt[i];
		}
	}


	// Function to find Average time of RR

	void findavgTime(vector<int> processes, int n, vector<int> bt,
					 int quantum)
	{
		int wt[n], tat[n], total_wt = 0, total_tat = 0;

		findWaitingTime(processes, n, bt, wt, quantum);

		findTurnAroundTime(processes, n, bt, wt, tat);

		cout << "\nProcesses "
			 << " Burst time "
			 << " Waiting time "
			 << " Turn around time\n";

		for (int i = 0; i < n; i++)
		{
			total_wt = total_wt + wt[i];
			total_tat = total_tat + tat[i];
			cout << " " << i + 1 << "\t\t" << bt[i] << "\t "
				 << wt[i] << "\t\t " << tat[i] << endl;
		}

		cout << "Average waiting time = "
			 << (float)total_wt / (float)n;
		cout << "\nAverage turn around time = "
			 << (float)total_tat / (float)n;
	}
};

int main()
{

	cout << R"(


																			               
                                                                             ██████  ███████     ██████  ██████   ██████       ██ ███████  ██████ ████████ 
                                                                            ██    ██ ██          ██   ██ ██   ██ ██    ██      ██ ██      ██         ██    
                                                                            ██    ██ ███████     ██████  ██████  ██    ██      ██ █████   ██         ██    
                                                                            ██    ██      ██     ██      ██   ██ ██    ██ ██   ██ ██      ██         ██    
                                                                             ██████  ███████     ██      ██   ██  ██████   █████  ███████  ██████    ██                                                                                                                                                                                                           
                                                                               
                                                                               



)";

	vector<int> processes;

	int n;

	cout << "Enter the number of processes: ";

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x;
		cout << "Enter The Process: ";
		cin >> x;
		processes.push_back(x);
	}

	vector<int> burst_time;

	for (int i = 0; i < n; i++)
	{
		int y;
		cout << "Enter the burst time of the processes: ";
		cin >> y;
		burst_time.push_back(y);
	}

	char ch = 'y';

	do
	{
		cout << "Enter your choice\n";
		cout << "Enter 1 for FCFS Scheduling\n";
		cout << "Enter 2 for Priority Scheduling\n";
		cout << "Enter 3 for RR Scheduling\n";
		cout << "Enter 4 for Shortest Job First Algorihm\n";
		cout << "Any other key to exit\n";

		int choice;
		cin >> choice;


		// FCFS Scheduling Alogorithm Block

		if (choice == 1)
		{
			FCFS f;
			cout << R"(



███████  ██████ ███████ ███████     ███████  ██████ ██   ██ ███████ ██████  ██    ██ ██      ██ ███    ██  ██████  
██      ██      ██      ██          ██      ██      ██   ██ ██      ██   ██ ██    ██ ██      ██ ████   ██ ██       
█████   ██      █████   ███████     ███████ ██      ███████ █████   ██   ██ ██    ██ ██      ██ ██ ██  ██ ██   ███ 
██      ██      ██           ██          ██ ██      ██   ██ ██      ██   ██ ██    ██ ██      ██ ██  ██ ██ ██    ██ 
██       ██████ ██      ███████     ███████  ██████ ██   ██ ███████ ██████   ██████  ███████ ██ ██   ████  ██████  




                                                                                                
			)";
			f.findAverageTime(processes, n, burst_time);
		}



		// Priority Scheduling Block

		else if (choice == 2)
		{
			Priority P;

			cout << R"(



██████  ██████  ██  ██████  ██████  ██ ████████ ██    ██     ███████  ██████ ██   ██ ███████ ██████  ██    ██ ██      ██ ███    ██  ██████  
██   ██ ██   ██ ██ ██    ██ ██   ██ ██    ██     ██  ██      ██      ██      ██   ██ ██      ██   ██ ██    ██ ██      ██ ████   ██ ██       
██████  ██████  ██ ██    ██ ██████  ██    ██      ████       ███████ ██      ███████ █████   ██   ██ ██    ██ ██      ██ ██ ██  ██ ██   ███ 
██      ██   ██ ██ ██    ██ ██   ██ ██    ██       ██             ██ ██      ██   ██ ██      ██   ██ ██    ██ ██      ██ ██  ██ ██ ██    ██ 
██      ██   ██ ██  ██████  ██   ██ ██    ██       ██        ███████  ██████ ██   ██ ███████ ██████   ██████  ███████ ██ ██   ████  ██████  
                                                                                                                                            



							 
							                                                                                                                
)";
			P.findavgTime(processes, n);
		}

		// Round Robin Block

		else if (choice == 3)
		{
			RR r;

			cout << R"(



██████   ██████  ██    ██ ███    ██ ██████      ██████   ██████  ██████  ██ ███    ██ 
██   ██ ██    ██ ██    ██ ████   ██ ██   ██     ██   ██ ██    ██ ██   ██ ██ ████   ██ 
██████  ██    ██ ██    ██ ██ ██  ██ ██   ██     ██████  ██    ██ ██████  ██ ██ ██  ██ 
██   ██ ██    ██ ██    ██ ██  ██ ██ ██   ██     ██   ██ ██    ██ ██   ██ ██ ██  ██ ██ 
██   ██  ██████   ██████  ██   ████ ██████      ██   ██  ██████  ██████  ██ ██   ████ 
                                                                                      
                                                                                      
)";
			r.findavgTime(processes, n, burst_time, 3);
		}


		// SJF Block

		else if (choice == 4)
		{
			SJF s;

			cout << R"(



███████ ██   ██  ██████  ██████  ████████ ███████ ███████ ████████          ██  ██████  ██████      ███████ ██ ██████  ███████ ████████ 
██      ██   ██ ██    ██ ██   ██    ██    ██      ██         ██             ██ ██    ██ ██   ██     ██      ██ ██   ██ ██         ██    
███████ ███████ ██    ██ ██████     ██    █████   ███████    ██             ██ ██    ██ ██████      █████   ██ ██████  ███████    ██    
     ██ ██   ██ ██    ██ ██   ██    ██    ██           ██    ██        ██   ██ ██    ██ ██   ██     ██      ██ ██   ██      ██    ██    
███████ ██   ██  ██████  ██   ██    ██    ███████ ███████    ██         █████   ██████  ██████      ██      ██ ██   ██ ███████    ██    
                                                                                                                                        
                                                                                                                                       

			)";

			s.SJFFunc(processes, n, burst_time);
		}

		// Default Case

		else
		{
			cout << "\n";
			cout << R"(
                                                                                          
                                                                                        ███████ ██   ██ ██ ████████ ██ ███    ██  ██████           
                                                                                        ██       ██ ██  ██    ██    ██ ████   ██ ██                
                                                                                        █████     ███   ██    ██    ██ ██ ██  ██ ██   ███          
                                                                                        ██       ██ ██  ██    ██    ██ ██  ██ ██ ██    ██          
                                                                                        ███████ ██   ██ ██    ██    ██ ██   ████  ██████  ██ ██ ██ 
                                                                                                                                                

												                                                                                                



												


                                                                                                       


                                                                             
                                                                                                                                                                                  
                                                                                                                                                                                                                    
)";
			exit(0);
		}

		cout << "\n\nWant to Enter More?, Enter y or n\n";
		cin >> ch;

	} while (ch == 'y');
}

/*


██████  ██████   ██████   ██████ ███████ ███████ ███████     ███████  ██████ ██   ██ ███████ ██████  ██    ██ ██      ██ ███    ██  ██████  
██   ██ ██   ██ ██    ██ ██      ██      ██      ██          ██      ██      ██   ██ ██      ██   ██ ██    ██ ██      ██ ████   ██ ██       
██████  ██████  ██    ██ ██      █████   ███████ ███████     ███████ ██      ███████ █████   ██   ██ ██    ██ ██      ██ ██ ██  ██ ██   ███ 
██      ██   ██ ██    ██ ██      ██           ██      ██          ██ ██      ██   ██ ██      ██   ██ ██    ██ ██      ██ ██  ██ ██ ██    ██ 
██      ██   ██  ██████   ██████ ███████ ███████ ███████     ███████  ██████ ██   ██ ███████ ██████   ██████  ███████ ██ ██   ████  ██████  
                                                                                                                                          

██████  ██    ██    
██   ██  ██  ██  ██ 
██████    ████      
██   ██    ██    ██ 
██████     ██       
                   

                                                                                
                                                                                                                                                                                                     
                                                                                                                                     
███████  █████  ██    ██ ██████   █████  ██████  ██   ██     ██   ██ ██    ██ ███    ███  █████  ██████           ██ ██   ██  █████  
██      ██   ██ ██    ██ ██   ██ ██   ██ ██   ██ ██   ██     ██  ██  ██    ██ ████  ████ ██   ██ ██   ██          ██ ██   ██ ██   ██ 
███████ ███████ ██    ██ ██████  ███████ ██████  ███████     █████   ██    ██ ██ ████ ██ ███████ ██████           ██ ███████ ███████ 
     ██ ██   ██ ██    ██ ██   ██ ██   ██ ██   ██ ██   ██     ██  ██  ██    ██ ██  ██  ██ ██   ██ ██   ██     ██   ██ ██   ██ ██   ██ 
███████ ██   ██  ██████  ██   ██ ██   ██ ██████  ██   ██     ██   ██  ██████  ██      ██ ██   ██ ██   ██      █████  ██   ██ ██   ██ 
                                                                                                                                     
                                                                                                                                     
 █████  ██████  ██ ████████ ██    ██  █████      ██████   █████  ███    ██ ██████  ███████ ██    ██                                  
██   ██ ██   ██ ██    ██     ██  ██  ██   ██     ██   ██ ██   ██ ████   ██ ██   ██ ██       ██  ██                                   
███████ ██   ██ ██    ██      ████   ███████     ██████  ███████ ██ ██  ██ ██   ██ █████     ████                                    
██   ██ ██   ██ ██    ██       ██    ██   ██     ██      ██   ██ ██  ██ ██ ██   ██ ██         ██                                     
██   ██ ██████  ██    ██       ██    ██   ██     ██      ██   ██ ██   ████ ██████  ███████    ██                                     
                                                                                                    


*/