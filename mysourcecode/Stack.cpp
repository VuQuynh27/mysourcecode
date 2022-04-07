 #include<stdio.h>
 #include<stdlib.h>

	typedef long long item;
	
	struct Node {
		item data;
		Node *next;
	};
	
	struct Stack{
		Node *top;
	};
	
	// Ham khoi tao
	Stack *StackInit(Stack *s){
		s=(Stack*)malloc(sizeof(Stack));
		if(s==NULL) printf("Khong du bo nho");
		s->top=NULL;
		return s;
	}
			
	//Ham tao Node
	Node *Make_StackNode(item x){
		Node *p;
		p=(Node*)malloc(sizeof(Node));
		p->data=x;
		p->next=NULL;
		return p;
	}
	
	// Ham push
	void StackPush(Stack *s, item x){
		Node *p=Make_StackNode(x); 
		p->next=s->top;
		s->top=p;
	}
	

	void print(Stack *s){
		while(s->top!=NULL){	
		item x=s->top->data;
		s->top=s->top->next;
		printf("%d",x);
		};
		printf("\n");
		}
	
	
	void ConvertBinary(item x){
		Stack *Binary;
		Binary=StackInit(Binary);
		while(x!=0){
			StackPush(Binary,(x%2)); 
			x=x/2;
		}
		print(Binary);
	}
	
	
	int main(){
	item n;
	scanf("%ld",&n);
	item arr[n];
	for(int i=0; i<n; i++){
		scanf("%ld", &arr[i]);
		ConvertBinary(arr[i]);
	}

	return 0;
}
 
    
    

