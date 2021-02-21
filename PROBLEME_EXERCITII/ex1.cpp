#include <iostream>
using namespace std;

void fun(struct node **head_ref)
{
struct node *temp = NULL;
struct node *current = *head_ref;
while (current != NULL)
{
temp = current->prev;
current->prev = current->next;
current->next = temp;
current = current->prev;
}
if(temp != NULL )
*head_ref = temp->prev;
}

int main(){
	int x;
	while(cin>>x){
		
	}
}