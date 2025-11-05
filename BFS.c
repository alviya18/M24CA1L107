#include<stdio.h>
#include<stdlib.h>

#define MAX 20

int queue[MAX], front=-1, rear=-1, visited[MAX];

void enqueue(int vertex){
	if(rear==MAX-1){
		printf("Queue is full!");
	}
	else{
		if(front==-1){
			front=0;
		}
		rear++;
		queue[rear]=vertex;
	}
}

int dequeue(){
	int vertex;
	if(front==-1 || front>rear){
		return -1;
	}
	else{
		vertex=queue[front];
		front++;
		return vertex;
	}
}

void BFS(int adj[MAX][MAX], int n, int start){
	int i, vertex;
	for(i=0; i<n; i++)
		visited[i]=0;

	front = rear = -1;
	enqueue(start);
	visited[start]=1;

	printf("BFS Traversal Starting from vertex %d\n", start);

	while(front!=-1 && front<=rear){
		vertex=dequeue();
		printf("%d ", vertex);
		for(i=0; i<n; i++){
			if(adj[vertex][i]==1 && visited[i]==0){
				enqueue(i);
				visited[i]=1;
			}
		}
	}
	printf("\n");
}

int main(){
	int adj[MAX][MAX], n, i, j, start;
	printf("\nVertices? : ");
	scanf("%d", &n);
	printf("Adjacency Matrix ? \n");
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			scanf("%d", &adj[i][j]);
		}
	}
	printf("Starting vertex ? : ");
	scanf("%d", &start);
	BFS(adj, n, start);
	return 0;
}

