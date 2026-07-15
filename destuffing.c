#include<stdio.h>
void main(){
				int n;
				printf("enter n value");
				scanf("%d",&n);
				int a[n],b[50],c[50],i,j=0,count=0;
				printf("enter stuffed data");
				for(i=0;i<n;i++){
								scanf("%d",&a[i]);
				}
				for(i=0;i<n;i++){
								b[j]=a[i];
								j++;
								if(a[i]==1){
												count++;
								}else{
													count=0;
								}
								if(count==5){
																i++;
																count=0;
								}
				}
				printf("\ndestuffed data");
				for(i=0;i<j;i++){
								printf("%d",b[i]);
				}
}
