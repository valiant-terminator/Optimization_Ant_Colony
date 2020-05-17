#include<stdio.h>
#include<math.h>
#include<stdlib.h>

double distance(int x1, int x2, int y1, int y2, int z1, int z2){ 
	return sqrt(pow((x2-x1),2)+pow((y2-y1),2)+pow((z2-z1),2)); 
}

double sigma_fun(double P[6][6], int alpha,double eta[6][6], int beta){
	double sum=0;
	int k,l;
	for(k=0;k<6;k++){
		for(l=0;l<6;l++)
			sum+=((pow(P[k][l],alpha))*(pow(eta[k][l],beta)));
	}
	return sum;
}
/*float slope_sum(float slope[6][6]){
	float sum=0;
	int k,l;
	for(k=0;k<6;k++){
		for(l=0;l<6;l++)
			sum+=slope[k][l];
	}
	return sum;
}*/
int visit_arr[4];
int alpha,indN1,n;
double dist[6][6];
int cord[6][3];
int init_pres;
int beta;
int pres_drop;
int threshold;
double P[6][6]; 
double eta[6][6];
double Prob[6][6];
//float slope[6][6];
int max_index(double *ant){
	double max=ant[0];
	int a1,b1;
	for(a1=0;a1<5;a1++){
		if(ant[a1]>max)
			max=ant[a1];
	}	
	for(b1=0;b1<5;b1++){
		if(ant[b1]==max)
			return b1;
	}
}

double* sort(double *ant){
	int i,j;
	double temp;
	for (i = 0; i < 5; i++){
		for (j = i + 1; j < 5; j++){
			if(ant[i] < ant[j]){
				temp = ant[i];
				ant[i] = ant[j];
				ant[j] = temp;
			}
			
		}
	}
	return ant;
}

static int count = 0;
int visit_arr[4]={0,0,0,0};
int visit[5]={1,1,1,1,1};
static int k=0;
int n=0;
int *route(int num,double *ant,double *antB,double *antC,double *antD,double *antE,double *antF){	
	switch(num){	
		case 0:
			{
				visit[0]=0;
				break;
			}
		case 1:
			{
				visit[1]=0;
				break;
			}
		case 2:
			{
				visit[2]=0;
				break;
			}
		case 3:
			{
				visit[3]=0;
				break;
			}
		case 4:
			{
				visit[4]=0;
				break;
			}
	}
	
	if(count==0){	
		n=num;
		indN1 = max_index(ant);
		visit_arr[k] = indN1;
		k++;
		count++;	
	}
	
	
	if(count<5 && count!=0){
		int i,j=0,s;
		double antS[5];
		switch(indN1){	
			case 0:
				{	int x1;
					if(count==1){
						visit[indN1]=0;
					}
					for(s=0;s<5;s++)
						antS[s]=antB[s];	
					double *sorted = sort(antS);
					for(x1=0;x1<5;x1++){
						for(i=0;i<5;i++){
							if(sorted[j]==antB[i]){	
								if( visit[i]!=0){	
									visit_arr[k]=i;
									k++;
									break;
								}
						
								else
								{	
									j++;
									
								}
							}
						}
						if(x1==5 || visit[i]!=0)
							break;
					}
					switch(i){
						case 0:
						{	indN1=i;
							count++;	
							route(0,antB,antB,antC,antD,antE,antF);
						}
						
						case 1:
						{	indN1=i;
							count++;
							route(1,antC,antB,antC,antD,antE,antF);
						}
						
						case 2:
						{	indN1=i;
							count++;
							route(2,antD,antB,antC,antD,antE,antF);
						}
						
						case 3:
						{	indN1=i;
							count++;
							route(3,antE,antB,antC,antD,antE,antF);
						}
						
						case 4:
						{	indN1=i;
							count++;
							route(4,antF,antB,antC,antD,antE,antF);
						}
					}
				}
				
				
			case 1:
				{	int x1;
					if(count==1){
						visit[indN1]=0;
					}
					for(s=0;s<5;s++)
						antS[s]=antC[s];
					double *sorted = sort(antS);
					for(x1=0;x1<5;x1++){
						for(i=0;i<5;i++){
							if(sorted[j]==antC[i] ){	
								if( visit[i]!=0){	
									visit_arr[k]=i;
									k++;
									break;
								}
						
								else
								{	
									j++;
									
								}
							}
						}
						if(x1==5 || visit[i]!=0)
							break;

					}
					switch(i){
						case 0:
						{	indN1=i;
							count++;
							route(0,antB,antB,antC,antD,antE,antF);
						}
						
						case 1:
						{	indN1=i;
							count++;
							route(1,antC,antB,antC,antD,antE,antF);
						}
						
						case 2:
						{	indN1=i;
							count++;
							route(2,antD,antB,antC,antD,antE,antF);
						}
						
						case 3:
						{	indN1=i;
							count++;
							route(3,antE,antB,antC,antD,antE,antF);
						}
						
						case 4:
						{	indN1=i;
							count++;
							route(4,antF,antB,antC,antD,antE,antF);
						}
					}
				}
			
			case 2:
				{	int x1;
					if(count==1){	
						visit[indN1]=0;
					}
					for(s=0;s<5;s++)
						antS[s]=antD[s];
					double *sorted = sort(antS);
					for(x1=0;x1<5;x1++){
						for(i=0;i<5;i++){
							if(sorted[j]==antD[i] ){	
								if( visit[i]!=0){	
									visit_arr[k]=i;
									k++;
									break;
								}
						
								else
								{	
									j++;
									
								}
							}
						}
						if(x1==5 || visit[i]!=0)
							break;
					}
					switch(i){
						case 0:
						{	indN1=i;
							count++;
							route(0,antB,antB,antC,antD,antE,antF);
						}
						
						case 1:
						{	indN1=i;
							count++;
							route(1,antC,antB,antC,antD,antE,antF);
						}
						
						case 2:
						{	indN1=i;
							count++;
							route(2,antD,antB,antC,antD,antE,antF);
						}
						
						case 3:
						{	indN1=i;
							count++;
							route(3,antE,antB,antC,antD,antE,antF);
						}
						
						case 4:
						{	indN1=i;
							count++;
							route(4,antF,antB,antC,antD,antE,antF);
						}
					}
				}	
			
			case 3:
				{	int x1;
					if(count==1){	
						visit[indN1]=0;
					}
					for(s=0;s<5;s++)
						antS[s]=antE[s];
					double *sorted = sort(antS);
					for(x1=0;x1<5;x1++){
						for(i=0;i<5;i++){
							if(sorted[j]==antE[i] ){	
								if( visit[i]!=0){	
									visit_arr[k]=i;
									k++;
									break;
								}
						
								else
								{	
									j++;
									
								}
							}
						}
						if(x1==5 || visit[i]!=0)
							break;

					}
					
					switch(i){	
						case 0:
						{	indN1=i;
							count++;
							route(0,antB,antB,antC,antD,antE,antF);
						}
						
						case 1:
						{	indN1=i;
							count++;
							route(1,antC,antB,antC,antD,antE,antF);
						}
						
						case 2:
						{	indN1=i;
							count++;
							route(2,antD,antB,antC,antD,antE,antF);
						}
						
						case 3:
						{	indN1=i;
							count++;
							route(3,antE,antB,antC,antD,antE,antF);
						}
						
						case 4:
						{	indN1=i;
							count++;
							route(4,antF,antB,antC,antD,antE,antF);
						}
					}
				}
			
			case 4:
				{
					int x1;
					if(count==1){
						visit[indN1]=0;
					}
					for(s=0;s<5;s++)
						antS[s]=antF[s];
					double *sorted = sort(antS);
					for(x1=0;x1<5;x1++){
						for(i=0;i<5;i++){
							if(sorted[j]==antF[i] ){	
								if( visit[i]!=0){	
									visit_arr[k]=i;
									k++;
									break;
								}
						
								else
								{	
									j++;
									
								}
							}
						}
						if(x1==5 || visit[i]!=0)
							break;
					}
					switch(i){	
						case 0:
						{	indN1=i;
							count++;
							route(0,antB,antC,antB,antD,antE,antF);
						}
						
						case 1:
						{	indN1=i;
						
							count++;
							route(1,antC,antB,antC,antD,antE,antF);
						}
						
						case 2:
						{	indN1=i;
						
							count++;
							route(2,antD,antB,antC,antD,antE,antF);
						}
						
						case 3:
						{	indN1=i;
							
							count++;
							route(3,antE,antB,antC,antD,antE,antF);
						}
						
						case 4:
						{	indN1=i;
							count++;
							route(4,antF,antB,antC,antD,antE,antF);
						}
					}
				}
		}
	}
	
	if(count==4){	
		switch(n){	
			case 0:
				{		
					printf("ANT B: ");
					int w1;
					printf("A-->B-->");
					for(w1=0;w1<4;w1++)
						switch(visit_arr[w1]){
							case 0:{
								printf("B-->");
								break;
							}
							case 1:{
								printf("C-->");
								break;
							}
							case 2:{
								printf("D-->");
								break;
							}
							case 3:{
								printf("E-->");
								break;
							}
							case 4:{
								printf("F-->");
								break;
							}
						}
					break;	
				}
			case 1:
				{
					printf("ANT C: ");
					int w2;
					printf("A-->C-->");
					for(w2=0;w2<4;w2++)
						switch(visit_arr[w2]){
							case 0:{
								printf("B-->");
								break;
							}
							case 1:{
								printf("C-->");
								break;
							}
							case 2:{
								printf("D-->");
								break;
							}
							case 3:{
								printf("E-->");
								break;
							}
							case 4:{
								printf("F-->");
								break;
							}
						}
					printf("\n");
					break;		
				}
			case 2:
				{
					printf("ANT D: ");
					int w3;
					printf("A-->D-->");
					for(w3=0;w3<4;w3++)
						switch(visit_arr[w3]){
							case 0:{
								printf("B-->");
								break;
							}
							case 1:{
								printf("C-->");
								break;
							}
							case 2:{
								printf("D-->");
								break;
							}
							case 3:{
								printf("E-->");
								break;
							}
							case 4:{
								printf("F-->");
								break;
							}
						}
					printf("\n");
					break;		
				}
			case 3:
				{	
				
						printf("ANT E: ");
						int w4;
						printf("A-->E-->");
						for(w4=0;w4<4;w4++)
							switch(visit_arr[w4]){
							case 0:{
								printf("B-->");
								break;
							}
							case 1:{
								printf("C-->");
								break;
							}
							case 2:{
								printf("D-->");
								break;
							}
							case 3:{
								printf("E-->");
								break;
							}
							case 4:{
								printf("F-->");
								break;
							}
						}
						printf("\n");
						break;
				}
			case 4:
				{
					printf("ANT F: ");
					int w5;
					printf("A-->F-->");
					for(w5=0;w5<4;w5++)
						switch(visit_arr[w5]){
							case 0:{
								printf("B-->");
								break;
							}
							case 1:{
								printf("C-->");
								break;
							}
							case 2:{
								printf("D-->");
								break;
							}
							case 3:{
								printf("E-->");
								break;
							}
							case 4:{
								printf("F-->");
								break;
							}
						}
					printf("\n");
					break;
				}	
		}
	
	}
	
}

void main(){
	//int cord[6][3];
 	cord[0][0]=0; cord[0][1]=7; cord[0][2]=0;
 	cord[1][0]=2; cord[1][1]=1; cord[1][2]=0;
 	cord[2][0]=5; cord[2][1]=12; cord[2][2]=0;
 	cord[3][0]=7; cord[3][1]=4; cord[3][2]=0;
 	cord[4][0]=11; cord[4][1]=3; cord[4][2]=0;
 	cord[5][0]=15; cord[5][1]=8; cord[5][2]=0;
	int Ax=cord[0][0];int Ay=cord[0][1];int Az=cord[0][2];
	int Bx=cord[1][0];int By=cord[1][1];int Bz=cord[1][2];
	int Cx=cord[2][0];int Cy=cord[2][1];int Cz=cord[2][2];
	int Dx=cord[3][0];int Dy=cord[3][1];int Dz=cord[3][2];
	int Ex=cord[4][0];int Ey=cord[4][1];int Ez=cord[4][2];
	int Fx=cord[5][0];int Fy=cord[5][1];int Fz=cord[5][2];

	//distance matrix
	dist[0][0]=0;//A-A
	dist[0][1]=distance(Ax,Bx,Ay,By,Az,Bz);//A-B
	dist[0][2]=distance(Ax,Cx,Ay,Cy,Az,Cz);//A-C
	dist[0][3]=distance(Ax,Dx,Ay,Dy,Az,Dz);//A-D
	dist[0][4]=distance(Ax,Ex,Ay,Ey,Az,Ez);//A-E
	dist[0][5]=distance(Ax,Fx,Ay,Fy,Az,Fz);//A-F
	dist[1][0]=distance(Bx,Ax,By,Ay,Bz,Az);//B-A
	dist[1][1]=0;//B-B
	dist[1][2]=distance(Bx,Cx,By,Cy,Bz,Cz);//B-C
	dist[1][3]=distance(Bx,Dx,By,Dy,Bz,Dz);//B-D
	dist[1][4]=distance(Bx,Ex,By,Ey,Bz,Ez);//B-E
	dist[1][5]=distance(Bx,Fx,By,Fy,Bz,Fz);//B-F
	dist[2][0]=distance(Cx,Ax,Cy,Ay,Cz,Az);//C-A
	dist[2][1]=distance(Cx,Bx,Cy,By,Cz,Bz);//C-B
	dist[2][2]=0;//C-C
	dist[2][3]=distance(Cx,Dx,Cy,Dy,Cz,Dz);//C-D
	dist[2][4]=distance(Cx,Ex,Cy,Ey,Cz,Ez);//C-E
	dist[2][5]=distance(Cx,Fx,Cy,Fy,Cz,Fz);//C-F
	dist[3][0]=distance(Dx,Ax,Dy,Ay,Dz,Az);//D-A
	dist[3][1]=distance(Dx,Bx,Dy,By,Dz,Bz);//D-B
	dist[3][2]=distance(Dx,Cx,Dy,Cy,Dz,Cz);//D-C
	dist[3][3]=0;//D-D
	dist[3][4]=distance(Dx,Ex,Dy,Ey,Dz,Ez);//D-E
	dist[3][5]=distance(Dx,Fx,Dy,Fy,Dz,Fz);//D-F
	dist[4][0]=distance(Ex,Ax,Ey,Ay,Ez,Az);//E-A
	dist[4][1]=distance(Ex,Bx,Ey,By,Ez,Bz);//E-B
	dist[4][2]=distance(Ex,Cx,Ey,Cy,Ez,Cz);//E-C
	dist[4][3]=distance(Ex,Dx,Ey,Dy,Ez,Dz);//E-D
	dist[4][4]=0;//E-E
	dist[4][5]=distance(Ex,Fx,Ey,Fy,Ez,Fz);//E-F
	dist[5][0]=distance(Fx,Ax,Fy,Ay,Fz,Az);//F-A
	dist[5][1]=distance(Fx,Bx,Fy,By,Fz,Bz);//F-B
	dist[5][2]=distance(Fx,Cx,Fy,Cy,Fz,Cz);//F-C
	dist[5][3]=distance(Fx,Dx,Fy,Dy,Fz,Dz);//F-D
	dist[5][4]=distance(Fx,Ex,Fy,Ey,Fz,Ez);//F-E
	dist[5][5]=0;//F-F
	// Eta matrix: Visibility of an edge	
	int i,j;
	for(i=0;i<6;i++){ 
		for(j=0;j<6;j++){
			if(i!=j){
				eta[i][j]=1.0/(dist[i][j]);
			}
			else
			{
				eta[i][j]=0;
			}
		}
	}
			
	init_pres=1000;
	beta = 5;
	alpha = 1;
 	pres_drop = 100;
 	threshold = 600; 
 	/*int sl1,sl2;
 	for(sl1=0;sl1<6;sl1++){
 			for(sl2=0;sl2<6;sl2++){
			 	if(sl1!=sl2)
 					slope[sl1][sl2]=(cord[sl2][2]-cord[sl1][2])/sqrt((pow(cord[sl2][0]-cord[sl1][0],2)+pow(cord[sl2][1]-cord[sl1][1],2)));
 				else
 					slope[sl1][sl2]=0;
 			}
	}
 	float sum_slope = slope_sum(slope);
	printf("this is sum %f",sum_slope);
	if(sum_slope==0){*/
	P[0][0]=0;P[1][1]=0;P[2][2]=0;P[3][3]=0;P[4][4]=0;P[5][5]=0;
	P[0][1]=1;P[0][2]=1;P[0][3]=1;P[0][4]=1;P[0][5]=1;
	P[1][0]=1;P[1][2]=1;P[1][3]=1;P[1][4]=1;P[1][5]=1;
	P[2][0]=1;P[2][1]=1;P[2][3]=1;P[2][4]=1;P[2][5]=1;
	P[3][1]=1;P[3][2]=1;P[3][0]=1;P[3][4]=1;P[3][5]=1;
	P[4][1]=1;P[4][2]=1;P[4][3]=1;P[4][0]=1;P[4][5]=1;
	P[5][1]=1;P[5][2]=1;P[5][3]=1;P[5][4]=1;P[5][0]=1;
	/*}
	else if(sum_slope!=0){
		int a,b;
		for(a=0;a<6;a++){
			for(b=0;b<6;b++){
				if(a!=b)
					P[a][b] = (pres_drop/(dist[a][b]*slope[a][b]));
				
				else
				 	P[a][b] = 0;
			}
		}
	}
	else;*/
	int m,n;
	double summation;
	summation = sigma_fun(P,alpha,eta,beta);
	for(m=0;m<6;m++){ 
		for(n=0;n<6;n++){
				Prob[m][n] = (pow(P[m][n],alpha)*pow(eta[m][n],beta))/summation;
		}
	}
	// Ants
	double antB[5]={Prob[1][1],Prob[1][2],Prob[1][3],Prob[1][4],Prob[1][5]};
	double antC[5]={Prob[2][1],Prob[2][2],Prob[2][3],Prob[2][4],Prob[2][5]};
	double antD[5]={Prob[3][1],Prob[3][2],Prob[3][3],Prob[3][4],Prob[3][5]};
	double antE[5]={Prob[4][1],Prob[4][2],Prob[4][3],Prob[4][4],Prob[4][5]};
	double antF[5]={Prob[5][1],Prob[5][2],Prob[5][3],Prob[5][4],Prob[5][5]};
	//Execution
	printf("COORDINATE MATRIX\n");
	int x;
	int y;
	for(x=0;x<6;x++){ 	
		
		for(y=0;y<3;y++){
			printf(" %d ",cord[x][y]);
		}
		printf("\n");
	}
	printf("\n") ;
	printf("DISTANCE MATRIX\n");
	int p;
	int q; 
	for(p=0;p<6;p++){ 
		for(q=0;q<6;q++){
			printf("%lf  ",dist[p][q]);
		}
		printf("\n");
	} 
	printf("\n") ;
	printf("ETA MATRIX\n");
	int s;
	int t; 
	for(s=0;s<6;s++){ 
		for(t=0;t<6;t++){
			printf("%lf  ",eta[s][t]);
		}
		printf("\n");
	} 
	printf("\n") ;
	printf("PHEROMONE MATRIX\n");
	int u;
	int v; 
	for(u=0;u<6;u++){ 
		for(v=0;v<6;v++){
			printf("%lf  ",P[u][v]);
		}
		printf("\n");
	} 
	printf("\n") ;
	printf("PROBABILITY MATRIX\n");
	int g;
	int h; 
	for(g=0;g<6;g++){
		for(h=0;h<6;h++){
			printf("%lf  ",Prob[g][h]);
		}
		printf("\n");
	}
	printf("\n");
	/*printf("SLOPE MATRIX\n");
	for(sl1=0;sl1<6;sl1++){
 			for(sl2=0;sl2<6;sl2++){
 				printf("%f ",slope[sl1][sl2]);
 			}
 			printf("\n");
	}*/
	//ITERATION - 1
	printf("FIRST ITERATION\n");
	//Ant B
	route(0,antB, antB, antC, antD, antE, antF);
	printf("\n");
	double distB=dist[0][1]+dist[1][visit_arr[0]+1]+dist[visit_arr[0]+1][visit_arr[1]+1]+
	dist[visit_arr[1]+1][visit_arr[2]+1]+dist[visit_arr[2]+1][visit_arr[3]+1];
	printf("Distance : %.4lf units",distB);	
	int visit_arrB[4],s1;
	for(s1=0;s1<4;s1++)
		visit_arrB[s1]=visit_arr[s1];
	printf("\n");
	printf("\n");
	//Ant C
	int z1,z2;
	for(z1=0;z1<5;z1++){
		visit[z1]=1;
	}
	for(z2=0;z2<4;z2++){
		visit_arr[z2]=0;
	}
	count = 0;
 	k=0;
	n=0;
	route(1,antC, antB, antC, antD, antE, antF);
	double distC=dist[0][2]+dist[2][visit_arr[0]+1]+dist[visit_arr[0]+1][visit_arr[1]+1]+
	dist[visit_arr[1]+1][visit_arr[2]+1]+dist[visit_arr[2]+1][visit_arr[3]+1];
	printf("Distance : %.4lf units",distC);	
	int visit_arrC[4],s2;
	for(s2=0;s2<4;s2++)
		visit_arrC[s2]=visit_arr[s2];
	printf("\n");
	printf("\n");
	//Ant D
	for(z1=0;z1<5;z1++){
		visit[z1]=1;
	}
	for(z2=0;z2<4;z2++){
		visit_arr[z2]=0;
	}
	count = 0;
 	k=0;
	n=0;
	route(2,antD, antB, antC, antD, antE, antF);
	double distD=dist[0][3]+dist[3][visit_arr[0]+1]+dist[visit_arr[0]+1][visit_arr[1]+1]+
	dist[visit_arr[1]+1][visit_arr[2]+1]+dist[visit_arr[2]+1][visit_arr[3]+1];	
	printf("Distance : %.4lf units",distD);
	int visit_arrD[4],s3;
	for(s3=0;s3<4;s3++)
		visit_arrD[s3]=visit_arr[s3];
	printf("\n");
	printf("\n");
	//Ant E
	for(z1=0;z1<5;z1++){
		visit[z1]=1;
	}
	for(z2=0;z2<4;z2++){
		visit_arr[z2]=0;
	}
	count = 0;
 	k=0;
	n=0;
	route(3,antE, antB, antC, antD, antE, antF);
	double distE=dist[0][4]+dist[4][visit_arr[0]+1]+dist[visit_arr[0]+1][visit_arr[1]+1]+
	dist[visit_arr[1]+1][visit_arr[2]+1]+dist[visit_arr[2]+1][visit_arr[3]+1];	
	printf("Distance : %.4lf units",distE);
	int visit_arrE[4],s4;
	for(s4=0;s4<4;s4++)
		visit_arrE[s4]=visit_arr[s4];
	printf("\n");
	printf("\n");
	// Ant F
	for(z1=0;z1<5;z1++){
		visit[z1]=1;
	}
	for(z2=0;z2<4;z2++){
		visit_arr[z2]=0;
	}
	count = 0;
 	k=0;
	n=0;
	route(4,antF, antB, antC, antD, antE, antF);
	double distF=dist[0][5]+dist[5][visit_arr[0]+1]+dist[visit_arr[0]+1][visit_arr[1]+1]+
	dist[visit_arr[1]+1][visit_arr[2]+1]+dist[visit_arr[2]+1][visit_arr[3]+1];	
	printf("Distance : %.4lf units",distF);
	int visit_arrF[4],s5;
	for(s5=0;s5<4;s5++)
		visit_arrF[s5]=visit_arr[s5];
	printf("\n");
	printf("\n");
	
	double dist_ant[]={distB,distC,distD,distE,distF};
	double copy_dist_ant[]={distB,distC,distD,distE,distF};
	sort(dist_ant);
	int dist4=dist_ant[4];
	int dis,booster=0;
	for(dis=0;dis<dist4;dis++){
		init_pres=init_pres-pres_drop;
		if(init_pres<threshold){
			booster++;
			init_pres=1000;
		}
	}
	init_pres = 1000;
	// Local update
	int p1,p2;
	for(p1=0;p1<6;p1++){
		for(p2=0;p2<6;p2++){
			P[p1][p2]=P[p1][p2]-(P[p1][p2]*0.15);
			//printf("%lf ",P[p1][p2]);
		}
		printf("\n");
	}
	printf("\n");
	// Global Update
	int c1;
	for(c1=0;c1<5;c1++){
		if(dist_ant[4]==copy_dist_ant[c1]){
			switch(c1){
				case 0:{
					
					   P[0][1]=P[0][1]+(P[0][1]*0.3);
					   P[1][visit_arrB[0]+1]=P[1][visit_arrB[0]+1]+(P[1][visit_arrB[0]+1]*0.3);
					   P[visit_arrB[0]+1][visit_arrB[1]+1]=P[visit_arrB[0]+1][visit_arrB[1]+1]+(P[visit_arrB[0]+1][visit_arrB[1]+1]*0.3);
					   P[visit_arrB[1]+1][visit_arrB[2]+1]=P[visit_arrB[1]+1][visit_arrB[2]+1]+(P[visit_arrB[1]+1][visit_arrB[2]+1]*0.3);
					   P[visit_arrB[2]+1][visit_arrB[3]+1]=P[visit_arrB[2]+1][visit_arrB[3]+1]+(P[visit_arrB[2]+1][visit_arrB[3]+1]*0.3);
					   break;}		
				case 1:{
					   P[0][2]=P[0][2]+(P[0][2]*0.3);
					   P[2][visit_arrC[0]+1]=P[2][visit_arrC[0]+1]+(P[2][visit_arrC[0]+1]*0.3);
					   P[visit_arrC[0]+1][visit_arrC[1]+1]=P[visit_arrC[0]+1][visit_arrC[1]+1]+(P[visit_arrC[0]+1][visit_arrC[1]+1]*0.3);
					   P[visit_arrC[1]+1][visit_arrC[2]+1]=P[visit_arrC[1]+1][visit_arrC[2]+1]+(P[visit_arrC[1]+1][visit_arrC[2]+1]*0.3);
					   P[visit_arrC[2]+1][visit_arrC[3]+1]=P[visit_arrC[2]+1][visit_arrC[3]+1]+(P[visit_arrC[2]+1][visit_arrC[3]+1]*0.3);
					   break;}		
				case 2:{
					   P[0][3]=P[0][3]+(P[0][3]*0.3);
					   P[3][visit_arrD[0]+1]=P[3][visit_arrD[0]+1]+(P[3][visit_arrD[0]+1]*0.3);
					   P[visit_arrD[0]+1][visit_arrD[1]+1]=P[visit_arrD[0]+1][visit_arrD[1]+1]+(P[visit_arrD[0]+1][visit_arrD[1]+1]*0.3);
					   P[visit_arrD[1]+1][visit_arrD[2]+1]=P[visit_arrD[1]+1][visit_arrD[2]+1]+(P[visit_arrD[1]+1][visit_arrD[2]+1]*0.3);
					   P[visit_arrD[2]+1][visit_arrD[3]+1]=P[visit_arrD[2]+1][visit_arrD[3]+1]+(P[visit_arrD[2]+1][visit_arrD[3]+1]*0.3);
					   break;}
				case 3:{
					   P[0][4]=P[0][4]+(P[0][4]*0.3);
					   P[4][visit_arrE[0]+1]=P[4][visit_arrE[0]+1]+(P[4][visit_arrE[0]+1]*0.3);
					   P[visit_arrE[0]+1][visit_arrE[1]+1]=P[visit_arrE[0]+1][visit_arrE[1]+1]+(P[visit_arrE[0]+1][visit_arrE[1]+1]*0.3);
					   P[visit_arrE[1]+1][visit_arrE[2]+1]=P[visit_arrE[1]+1][visit_arrE[2]+1]+(P[visit_arrE[1]+1][visit_arrE[2]+1]*0.3);
					   P[visit_arrE[2]+1][visit_arrE[3]+1]=P[visit_arrE[2]+1][visit_arrE[3]+1]+(P[visit_arrE[2]+1][visit_arrE[3]+1]*0.3);
					   break;}
				case 4:{
					   P[0][5]=P[0][5]+(P[0][5]*0.3);
					   P[5][visit_arrF[0]+1]=P[5][visit_arrF[0]+1]+(P[5][visit_arrF[0]+1]*0.3);
					   P[visit_arrF[0]+1][visit_arrF[1]+1]=P[visit_arrF[0]+1][visit_arrF[1]+1]+(P[visit_arrF[0]+1][visit_arrF[1]+1]*0.3);
					   P[visit_arrF[1]+1][visit_arrF[2]+1]=P[visit_arrF[1]+1][visit_arrF[2]+1]+(P[visit_arrF[1]+1][visit_arrF[2]+1]*0.3);
					   P[visit_arrC[2]+1][visit_arrF[3]+1]=P[visit_arrF[2]+1][visit_arrF[3]+1]+(P[visit_arrF[2]+1][visit_arrF[3]+1]*0.3);
					   break;}
			}
				
		}break;
				
	}
	//int g1,g2;
	//for(g1=0;g1<6;g1++){
	//	for(g2=0;g2<6;g2++){
	//		printf("%lf ",P[g1][g2]);
	//	}
	//	printf("\n");
	//}
	printf("Shortest distance: %lf units\n\n",dist_ant[4]);
	
	//ITERATION - 2
	printf("SECOND ITERATION\n");
	for(z1=0;z1<5;z1++){
		visit[z1]=1;
	}
	for(z2=0;z2<4;z2++){
		visit_arr[z2]=0;
	}
	count = 0;
 	k=0;
	n=0;
	route(0,antB, antB, antC, antD, antE, antF);
	printf("\n");
	distB=dist[0][1]+dist[1][visit_arr[0]+1]+dist[visit_arr[0]+1][visit_arr[1]+1]+
	dist[visit_arr[1]+1][visit_arr[2]+1]+dist[visit_arr[2]+1][visit_arr[3]+1];
	printf("Distance : %.4lf units",distB);	
	visit_arrB[4],s1;
	for(s1=0;s1<4;s1++)
		visit_arrB[s1]=visit_arr[s1];
	printf("\n");
	printf("\n");
	//Ant C
	for(z1=0;z1<5;z1++){
		visit[z1]=1;
	}
	for(z2=0;z2<4;z2++){
		visit_arr[z2]=0;
	}
	count = 0;
 	k=0;
	n=0;
	route(1,antC, antB, antC, antD, antE, antF);
	distC=dist[0][2]+dist[2][visit_arr[0]+1]+dist[visit_arr[0]+1][visit_arr[1]+1]+
	dist[visit_arr[1]+1][visit_arr[2]+1]+dist[visit_arr[2]+1][visit_arr[3]+1];
	printf("Distance : %.4lf units",distC);	
	visit_arrC[4],s2;
	for(s2=0;s2<4;s2++)
		visit_arrC[s2]=visit_arr[s2];
	printf("\n");
	printf("\n");
	//Ant D
	for(z1=0;z1<5;z1++){
		visit[z1]=1;
	}
	for(z2=0;z2<4;z2++){
		visit_arr[z2]=0;
	}
	count = 0;
 	k=0;
	n=0;
	route(2,antD, antB, antC, antD, antE, antF);
	distD=dist[0][3]+dist[3][visit_arr[0]+1]+dist[visit_arr[0]+1][visit_arr[1]+1]+
	dist[visit_arr[1]+1][visit_arr[2]+1]+dist[visit_arr[2]+1][visit_arr[3]+1];	
	printf("Distance : %.4lf units",distD);
	visit_arrD[4],s3;
	for(s3=0;s3<4;s3++)
		visit_arrD[s3]=visit_arr[s3];
	printf("\n");
	printf("\n");
	//Ant E
	for(z1=0;z1<5;z1++){
		visit[z1]=1;
	}
	for(z2=0;z2<4;z2++){
		visit_arr[z2]=0;
	}
	count = 0;
 	k=0;
	n=0;
	route(3,antE, antB, antC, antD, antE, antF);
	distE=dist[0][4]+dist[4][visit_arr[0]+1]+dist[visit_arr[0]+1][visit_arr[1]+1]+
	dist[visit_arr[1]+1][visit_arr[2]+1]+dist[visit_arr[2]+1][visit_arr[3]+1];	
	printf("Distance : %.4lf units",distE);
	visit_arrE[4],s4;
	for(s4=0;s4<4;s4++)
		visit_arrE[s4]=visit_arr[s4];
	printf("\n");
	printf("\n");
	// Ant F
	for(z1=0;z1<5;z1++){
		visit[z1]=1;
	}
	for(z2=0;z2<4;z2++){
		visit_arr[z2]=0;
	}
	count = 0;
 	k=0;
	n=0;
	route(4,antF, antB, antC, antD, antE, antF);
	distF=dist[0][5]+dist[5][visit_arr[0]+1]+dist[visit_arr[0]+1][visit_arr[1]+1]+
	dist[visit_arr[1]+1][visit_arr[2]+1]+dist[visit_arr[2]+1][visit_arr[3]+1];	
	printf("Distance : %.4lf units",distF);
	visit_arrF[4],s5;
	for(s5=0;s5<4;s5++)
		visit_arrF[s5]=visit_arr[s5];
	printf("\n");
	printf("\n");
	
	sort(dist_ant);
	dist4=dist_ant[4];
	booster=0;
	for(dis=0;dis<dist4;dis++){
		init_pres=init_pres-pres_drop;
		if(init_pres<threshold){
			booster++;
			init_pres=1000;
		}
	}
	init_pres = 1000;
	printf("Shortest distance: %lf units\n\n",dist_ant[4]);
	printf("Initial pressure is assumed to be: %d psi\n\n",init_pres);
	printf("Threshold pressure is assumed to be: %d psi\n\n",threshold);
	printf("Pressure drop per unit distance is assumed to be: %d psi\n\n",pres_drop);
	printf("Number of Booster Pumps required to transmit Gas: %d\n\n",booster);
}
//end of main	 	
