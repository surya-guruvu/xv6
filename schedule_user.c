#include "types.h"
#include "stat.h"
#include "user.h"


int
main(int argc, char *argv[])
{
	if (argc != 2){
		printf(1, "please provide the n value:\n");
		exit();
 	}
	int n;
	n = atoi(argv[1]);
	//n=6;
	int m=5*n;
	int x=0;


	int pid;
	int k,k1;
	int c1=0;
	int *count1=&c1;
	int c2=0;
	int *count2=&c2;
	int c3=0;
	int *count3=&c3;

	int cpu_bound[3];
	int scpu_bound[3];
	int io_bound[3];
	int i;
	for(i=0;i<3;i++){
		cpu_bound[i]=0;
		scpu_bound[i]=0;
		io_bound[i]=0;
	}
	for (i = 0; i < m; i++) {
		pid = fork();
		if (pid == 0) {
			//printf(1," %d\n",getpid());
			if(getpid() % 3==0){
				//runs a dummy loop 100000 times.
				for(k=0;k<100000;k++){
			 				x=x+ (9%2)*0.001*7/100;
			 				x=x+ (9%2)*0.001*7/100;
			 				x=x+ (9%2)*0.001*7/100;
			 				x=x+ (9%2)*0.001*7/100;
			 				x=x+ (9%2)*0.001*7/100;
			 				x=x+ (9%2)*0.001*7/100;
			 				x=x+ (9%2)*0.001*7/100;
			 				x=x+ (9%2)*0.001*7/100;
			 				x=x+ (9%2)*0.001*7/100;
			 				x=x+ (9%2)*0.001*7/100;
			 				x=x+ (9%2)*0.001*7/100;
			 				x=x+ (9%2)*0.001*7/100;
			 				x=x+ (9%2)*0.001*7/100;
					//printf(1,"s\n");
				}
			}
			else if(getpid() % 3==1){
				for(k1=0;k1<100;k1++){
				
					for(k=0;k<100000;k++){
					//printf(1," d");
			 				x=x+ (9%2)*0.001*7/100;
			 				x=x+ (9%2)*0.001*7/100;
			 				x=x+ (9%2)*0.001*7/100;
			 				x=x+ (9%2)*0.001*7/100;
			 				x=x+ (9%2)*0.001*7/100;
			 				x=x+ (9%2)*0.001*7/100;
			 				x=x+ (9%2)*0.001*7/100;
			 				x=x+ (9%2)*0.001*7/100;
			 				x=x+ (9%2)*0.001*7/100;
			 				x=x+ (9%2)*0.001*7/100;
			 				x=x+ (9%2)*0.001*7/100;
			 				x=x+ (9%2)*0.001*7/100;
			 				x=x+ (9%2)*0.001*7/100;
					}					
					yield();
				}
			}
			else{
				for(k=0;k<1000;k++){
					sleep(1);
				}
			}
			exit(); 
		}
		continue; 
		
	}

	for(int q=0;q<m;q++){
		int arr[3];
		pid=genstat(arr);
		/*
		int a=arr[0];
		int b=arr[1];
		int c=arr[2];
		int *stat0=&a;
		int *stat1=&b;
		int *stat2=&c;
		*/
		//pid=arr[3];
		
		//printf(1," %d\n",pid);
		if(pid % 3 ==0){
			printf(1, "pid: %d, process: cpu_bound, readyTime: %d , runTime: %d , sleepTime: %d , turnaroundTime: %d \n", pid,arr[0],arr[1],arr[2],arr[0]+arr[1]+arr[2]);
			*count1=*count1+1;
			cpu_bound[0]+=arr[0];
			cpu_bound[1]+=arr[1];
			cpu_bound[2]+=arr[2];
		}
		else if(pid % 3 ==1){
			printf(1, "pid: %d, process: scpu_bound, readyTime: %d , runTime: %d , sleepTime: %d , turnaroundTime: %d \n", pid,arr[0],arr[1],arr[2],arr[0]+arr[1]+arr[2]);
			*count2=*count2+1;
			scpu_bound[0]+=arr[0];
			scpu_bound[1]+=arr[1];
			scpu_bound[2]+=arr[2];
		}
		else{
			printf(1, "pid: %d, process: io_bound, readyTime: %d , runTime: %d , sleepTime: %d , turnaroundTime: %d \n", pid,arr[0],arr[1],arr[2],arr[0]+arr[1]+arr[2]);
			*count3=*count3+1;
			io_bound[0]+=arr[0];
			io_bound[1]+=arr[1];
			io_bound[2]+=arr[2];
		}

	}



	printf(1, "Average Statistics\n");
	printf(1," \n");
	printf(1, "CPU-Bound Statistics\n");
	printf(1, "Average readyTime: %d\n",cpu_bound[0]/(*count1));
	printf(1, "Average runTime: %d\n",cpu_bound[1]/(*count1));
	printf(1, "Average sleepTime: %d\n",cpu_bound[2]/(*count1));
	printf(1, "Average turnAroundTime: %d\n",(cpu_bound[0]+cpu_bound[1]+cpu_bound[2])/(*count1));
	printf(1," \n");
	printf(1, "SCPU-Bound Statistics\n");
	printf(1, "Average readyTime: %d\n",scpu_bound[0]/(*count2));
	printf(1, "Average runTime: %d\n",scpu_bound[1]/(*count2));
	printf(1, "Average sleepTime: %d\n",scpu_bound[2]/(*count2));
	printf(1, "Average turnAroundTime: %d\n",(scpu_bound[0]+scpu_bound[1]+scpu_bound[2])/(*count2));
	printf(1," \n");
	printf(1, "IO-Bound Statistics\n");
	printf(1, "Average readyTime: %d\n",io_bound[0]/(*count3));
	printf(1, "Average runTime: %d\n",io_bound[1]/(*count3));
	printf(1, "Average sleepTime: %d\n",io_bound[2]/(*count3));
	printf(1, "Average turnAroundTime: %d\n",(io_bound[0]+io_bound[1]+io_bound[2])/(*count3));
	
	exit();
}
