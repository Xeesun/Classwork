#include <stdio.h>
#include <iostream>
#include <conio.h>

using namespace std;

int Union(int g1[],int g2[],int m,int n){
    int i=0,j=0;
    while(i<m && j<n){
        if(g1[i]<g2[j]){
            printf("%d",g1[i++]);
        }else if(g2[j]<g1[i]){
            printf("%d",g2[j++]);
        }else{
            printf("%d",g2[j++]);
            i++;
        }
    }
    while(i<m){
        printf("%d",g1[i++]);
    }
    while(j<n){
        printf("%d",g2[j++]);
    }
}

int Intersection(int g1[], int g2[], int m, int n){
	int i = 0,j = 0;
	while(i<m && j<n){
		if(g1[i] < g2[i]){
			i++;
		} else if(g2[j] < g1[i]){
			j++;
		} else {
			printf("%d", g2[j++]);
			i++;
		}
	}
}

int RingSum(int g1[],int g2[],int m,int n){
    int i=0,j=0;
    while(i<m && j<n){
        if(g1[i]<g2[j]){
            printf("%d",g1[i++]);
        }else if(g2[j]<g1[i]){
            printf("%d",g2[j++]);
        }else{
            printf("%d",g2[j++]);
            i++;
        }
    }
    while(i<m){
        printf("%d",g1[i++]);
    }
    while(j<n){
        printf("%d",g2[j++]);
    }
}

    
int main(){
    int v1[]={0,1};
    int v2[]={0,1,2};
    int i,j,k;
    int m=sizeof(v1)/sizeof(v1[0]);
    int n=sizeof(v2)/sizeof(v2[0]);
    int g1[m][m], g2[n][n], g3[m+n][m+n], g4[m+n][m+n], g5[m+n][m+n];
    
    printf("Adjacency matrix for graph G1:\n");
    for( i=0;i<m;i++){
        for( j=0;j<m;j++){
            printf("g1[%d][%d]=",i,j);
            scanf("%d",&g1[i][j]);
        }
    }
    
    printf("Adjacency matrix for graph G2:\n");
    for(i=0;i<n;i++){
        for( j=0;j<n;j++){
            printf("g2[%d][%d]=",i,j);
            scanf("%d",&g2[i][j]);
        }
    }
    
    printf("\nSet of vertices in ring sum of the graphs G1 and G2 is:\n");
    RingSum(v1,v2,m,n);
    printf("\n");
    for(i=0;i<n;i++){
        for( j=0;j<n;j++){
            if(g1[i][j]==g2[i][j] && i<m && j<m){
                g3[i][j]=0;
            
            }else if(g1[i][j]<g2[i][j] && i<m && j<m){
                g3[i][j]=g2[i][j];
            }if(g1[i][j]<g2[i][j] && i<m && j<m){
                g3[i][j]=g1[i][j];
            }else{
                g3[i][j]=g2[i][j];
            }
        }
    }
    
        printf("Adjacency matrix of ring sums of graphs G1 and G2 is\n\t");
        for(i=0;i<n;i++){
            printf("%d\t",i);
        }
        printf("\n\t");
        for(i=0;i<n;i++){
            printf(" ");
        }
        for(i=0;i<n;i++){
            printf("\n%d\t",i);
            for(j=0;j<n;j++){
                printf("%d\t",g3[i][j]);
            }
        }
        
    
    printf("\n Set of vertices in intersection of the graphs G1 and G2 is: \n");
    Intersection(v1, v2, m, n);
    printf("\n");
    
    for(i = 0; i<n; i++){
    	for(int j = 0; j<n; j++){
    		if(g1[i][j] > g2[i][j] && i<m){
    			g4[i][j] = g1[i][j];
			} else {
				g4[i][j] = g2[i][j];
			}
		}
	}
	
	printf("Adjacency matrix of intersection of graphs G1 and G2 is: \n\t");
	for(i = 0; i<m; i++){
		printf("%d\t", i);
	}
	
	printf("\n\t");
	
	for(i=0; i<m; i++){
		printf(" ");
	}
	
	
	for(i = 0; i<m; i++){
		printf("\n%\t", i);
		for(j = 0; j<m; j++){
			printf("%d\t", g4[i][j]);
		}
	}
	
    printf("\nSet of vertices in union of the graphs G1 and G2 is:\n");
    Union(v1,v2,m,n);
    printf("\n");
    for(i=0;i<n;i++){
        for( j=0;j<n;j++){
            if(g1[i][j] > g2[i][j] && i<m){
                g5[i][j]=g1[i][j];
            }else if(g1[i][j]<g2[i][j] && i<m){
                g5[i][j]=g2[i][j];
            } else {
                g5[i][j]=g2[i][j];
            }
        }
    }
        printf("Adjacency matrix of union of graphs G1 and G2 is\n\t");
        for(i=0;i<n;i++){
            printf("%d\t",i);
        }
        printf("\n\t");
        for(i=0;i<n;i++){
            printf(" ");
        }
        for(i=0;i<n;i++){
            printf("\n%d\t",i);
            for(j=0;j<n;j++){
                printf("%d\t",g5[i][j]);
            }
        }
        	    
        getch();
    }
