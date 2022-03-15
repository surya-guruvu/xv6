#include "types.h"
#include "stat.h"
#include "user.h"


int
main(int argc, char *argv[])
{

	int n;
	n=5;
	int m=6*n;

	int pid;
	int k;
	int c1=0;
	int *count1=&c1;
	int c2=0;
	int *count2=&c2;
	int c3=0;
	int *count3=&c3;
	
	int cpu_bound1[3];
	int cpu_bound2[3];
	int cpu_bound3[3];
	
	int x=0;
	int i;
	for(i=0;i<3;i++){
		cpu_bound1[i]=0;
		cpu_bound2[i]=0;
		cpu_bound3[i]=0;
	}
	for (i = 0; i < m; i++) {
		pid = fork();
		if (pid == 0) {
			//printf(1," %d\n",getpid());
			int j=((getpid()-4)%3);
			switch(j) {
				case 0:
					printf(1,"pid: %d , prio:%d\n",getpid(),chpr(getpid(),1));
          				

 					break;

				case 1:
					printf(1,"pid: %d , prio:%d\n",getpid(),chpr(getpid(),2));

					break;

				case 2:
					printf(1,"pid: %d , prio:%d\n",getpid(),chpr(getpid(),3));

					break;
 			}
 			
 			  		for(int j=0;j<100;j++){
			 			for(k=0;k<4000000;k++){
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
		if((pid-4) % 3 ==0){
			printf(1, "pid: %d, priority=%d, readyTime: %d , runTime: %d , sleepTime: %d , turnaroundTime: %d \n", pid,((pid-4)%3)+1,arr[0],arr[1],arr[2],arr[0]+arr[1]+arr[2]);
			*count1=*count1+1;
			cpu_bound1[0]+=arr[0];
			cpu_bound1[1]+=arr[1];
			cpu_bound1[2]+=arr[2];
		}
		else if((pid-4) % 3 ==1){
			printf(1, "pid: %d, priority=%d, readyTime: %d , runTime: %d , sleepTime: %d , turnaroundTime: %d \n", pid,((pid-4)%3)+1,arr[0],arr[1],arr[2],arr[0]+arr[1]+arr[2]);
			*count2=*count2+1;
			cpu_bound2[0]+=arr[0];
			cpu_bound2[1]+=arr[1];
			cpu_bound2[2]+=arr[2];
		}
		else{
			printf(1, "pid: %d, priority=%d, readyTime: %d , runTime: %d , sleepTime: %d , turnaroundTime: %d \n", pid,((pid-4)%3)+1,arr[0],arr[1],arr[2],arr[0]+arr[1]+arr[2]);
			*count3=*count3+1;
			cpu_bound3[0]=cpu_bound3[0]+arr[0];
			cpu_bound3[1]+=arr[1];
			cpu_bound3[2]+=arr[2];
		}

	}



	printf(1, "Average Statistics\n");
	printf(1," \n");
	printf(1, "priority=1 Statistics\n");
	//printf(1, "Total ready Time: %d\n", cpu_bound1[0]);
	printf(1, "Average readyTime: %d\n",cpu_bound1[0]/(*count1));
	printf(1, "Average runTime: %d\n",cpu_bound1[1]/(*count1));
	printf(1, "Average sleepTime: %d\n",cpu_bound1[2]/(*count1));
	printf(1, "Average turnAroundTime: %d\n",(cpu_bound1[0]+cpu_bound1[1]+cpu_bound1[2])/(*count1));
	printf(1," \n");
	
	printf(1, "priority=2 Statistics\n");
	//printf(1, "Total ready Time: %d\n", cpu_bound2[0]);
	printf(1, "Average readyTime: %d\n",cpu_bound2[0]/(*count2));
	printf(1, "Average runTime: %d\n",cpu_bound2[1]/(*count2));
	printf(1, "Average sleepTime: %d\n",cpu_bound2[2]/(*count2));
	printf(1, "Average turnAroundTime: %d\n",(cpu_bound2[0]+cpu_bound2[1]+cpu_bound2[2])/(*count2));
	printf(1," \n");

	printf(1, "priority=3 Statistics\n");
	//printf(1, "Total ready Time: %d\n", cpu_bound3[0]);
	printf(1, "Average readyTime: %d\n",cpu_bound3[0]/(*count3));
	printf(1, "Average runTime: %d\n",cpu_bound3[1]/(*count3));
	printf(1, "Average sleepTime: %d\n",cpu_bound3[2]/(*count3));
	printf(1, "Average turnAroundTime: %d\n",(cpu_bound3[0]+cpu_bound3[1]+cpu_bound3[2])/(*count3));
	printf(1," \n");
	exit();
}
