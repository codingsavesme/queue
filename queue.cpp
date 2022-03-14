#include <iostream> 
using namespace std; 

/* implementing queue
first in first out 
is_empty (check if queue is empty), remove (remove the front element) 
front (return front), add (add at the back of a queue);
*/

class queue 
{
private : 
 queue *first , *last; 
 queue *next; 
int count; 
int value; 
public : 
queue(); 
~queue(); 
bool is_empty (); 
void remove (); 
int front (); 
void add (int new_thing); 
}; 

int main  ()
{
queue queue1; 
queue1.add (1); 
queue1.add (2); 
queue1.add (3); 
queue1.add (4); 
queue1.add (5); 
queue1.add (6); 
queue1.add (7); 
queue1.add (8); 
queue1.remove(); 
queue1.remove(); 
cout << "first value is " << queue1.front () << endl; 


}


void queue:: add (int new_thing)
{
count ++; 

// new node (last)
queue* temp = new queue; // new node created
temp -> next = NULL; 
temp->value = new_thing; 

if (first == NULL) {first = temp;}
last = temp; 
}

void queue:: remove () // remove front
{
if (count == 0)
{
    cout << "queue is empty" << endl; 
    return; 
}
// B4 change first's value to ->next as  will delete fisrt  
queue* temp = first; 
first = first -> next; 
delete temp; // deleting this allocated memory (first node); 

count --; 
}

bool queue::is_empty ()
{
if (count == 0) {return 1;}
cout << "total nodes : " << count << endl; 
return 0; 
} 
int queue::front () // return front value
{
    return first->value; 
}


queue::queue ()
{
    first = NULL; 
    last = NULL; 
    count = 0; 
}
queue::~queue ()
{
    cout << "****deleted (destructor) ****" << endl; 
}