/*
06/07/2020
This program will check who wins tictactoe game
Input:3*3 Matrix with input

1-X
0-blank space
-1-O

Output:Who wins the game

*/


#include <stdio.h>
#include <stdlib.h>

void readMatrix(char fname[],int pa[3][3]);
int checkWin(int grid[3][3]);

int main(void){

	int grid[3][3];
	int i,j,in,result;
	char fname[100];
	printf("\nHow do you want to give input?\n1.From file.\n2.From console\n:");
	scanf("%d",&in);
	
	if(in==1){
		printf("\nEnter the file name:");
		scanf("%s",fname);
		readMatrix(fname,grid);
	
	}
	else{
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				printf("\nEnter value of %d%d th entry:",i+1,j+1);
				scanf("%d",&grid[i][j]);
			}
		}
	
	}

	printf("\nInput Matrix is:\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%2d ",grid[i][j]);
		}
		printf("\n");
	}

	result=checkWin(grid);
	//printf("\nPlayer %d wins 0\n",result);

	return 0;
}

/*int checkWin(int grid[3][3]){
	int i,j,n=3,prevVal,flag;
	//for rows
	for(i=0;i<3;++i){
		if(grid[i][0]==1){
			for(j=0;j<3;++j){
				if(grid[i][j]!=1)
					break;
				else{
					printf("\nI returned one");
					return 1;//To indicate 1 wins
					
					
				}
			}
		}
		else{
			for(j=0;j<3;++j){
				if(grid[i][j]!=-1)
					break;
				else{
					
					return -1;//To indicate -1 wins
				}
			}
		
		}
	}

	//for cols
	for(i=0;i<3;++i){
		if(grid[0][i]==1){
			for(j=0;j<3;++j){
				if(grid[j][i]!=1)
					break;
				else{
					printf("\nI returned one");
					return 1;//To indicate 1 wins
				}
			}
		}
		else{
			for(j=0;j<3;++j){
				if(grid[j][i]!=-1)
					break;
				else
					return -1;//To indicate -1 wins
			}
		
		}
	}


	prevVal=grid[0][0];
	
	if(prevVal!=0){
	flag=0;
	// for / diagonal
	for(i=0;i<3;++i){
		if(grid[i][i]!=prevVal)
			flag=1;
	}
	if(!flag)
		return prevVal;

	flag=0;
	//for \ diagonal
	for(i=0,j=2;i<3,j>=0;++i,--j){
		if(grid[i][j]!=prevVal)
			flag=1;
	}
	if(!flag)
		return prevVal;
	}


	return 0;
}
*/

int checkWin(int grid[3][3]){
	int i,j,flag,symbol;
	//For row check
	for(i=0;i<3;++i){
		flag=0;
		for(j=0;j<2;++j){
			if(grid[i][j]!=0){
				symbol=grid[i][j];
				if(grid[i][j]!=grid[i][j+1]){
					flag=1;
				}
			}
		}
		if(flag==0){
			printf("Player %d wins 1",symbol);
			break;
		}
	}
	//for column check
	if(flag){
		printf("\nChecking columns");	
		for(i=0;i<3;++i){
			flag=0;
			for(j=0;j<2;++j){
				if(grid[j][i]!=0){
					symbol=grid[j][i];
					if(grid[j][i]!=grid[j+1][i]){
						flag=1;
					}
				}
			}
			if(flag==0){
				printf("Player %d wins 2",symbol);
				break;
			}
		}
		if(flag){
			flag=0;
			for(i=0;i<2;++i){
				symbol=grid[i][j];
				if(grid[i][i]!=grid[i+1][i+1])
					flag=1;
			}
			if(flag==0){
				printf("Player %d wins 3",symbol);
			}
		}
		if(flag){
			flag=0;
			for(i=0,j=2;i<2,j>0;++i,--j){
				symbol=grid[i][j];
				if(grid[i][j]!=grid[i+1][j-1])
					flag=1;
			}
			if(flag==0){
				printf("Player %d wins 4",symbol);
			}
		}
	
	}

}

void readMatrix(char fname[],int pa[3][3])
{

	int i,m,n,k,numcnt,j,cnt=0;
	float x;
	char num[10],line[100];
	FILE *fp;

	//printf("I am read matrix");

	fp=fopen(fname,"r");
	if(fp==NULL)
	{
		printf("\nCannot open");
		exit(1);
	}

	/*if(!feof(fp))
		fscanf(fp,"%d %d",pm,pn);//Dimension of matrix
	m=*pm;
	n=*pn;*/
	m=3;
	n=3;
	//printf("%d %d",m,n);
	//(*pa)=(float **)malloc(sizeof(float*)*m);//Pointer to pointer array of length=rows

	for(k=0;k<m && !feof(fp);k++)
	{
		cnt++;
		//(*pa)[k]=(float *)malloc(sizeof(float)*n);
		fgets(line,100,fp);
		if(cnt==1)
			fgets(line,100,fp);

		//puts(line);
		i=0,j=-1,numcnt=-1;
		while(line[i])
		{
			if(line[i]!=32 && line[j]!='\n')
			{
				j++;
				num[j]=line[i];

			}
			else if(j > -1)
			{
				j++;
				numcnt++;
				num[j]='\0';
				x=atoi(num);
				//insertList(&(adjList[cnt]),x);
				//(*pa)[k][numcnt]=x;
				pa[k][numcnt]=x;
				//printf("\n:%d ",x);
				j=-1;
			}
			i++;

		}
		if(j >= 1)
		{
			num[j+1]=0;
			numcnt++;
			x=atoi(num);
			//(*pa)[k][numcnt]=x;
			pa[k][numcnt]=x;
			//insertList(&(adjList[cnt]),x);
			//printf("\n:%d ",x);
		}
	}


}

