#include <iostream>
#include<fstream>
using namespace std;

int file1;
ofstream out("output.txt",ios::app);
 ifstream in("output.txt",ios::app);
 
int fifo(int n, int a[])
{
    
    out<<"fifo faults"<<"\n";
    
    int p[4], flag, r = 0, count = 0,k,i,j;
    
    
     for(i=0;i<4;i++)
     {
     p[i]=-1;  // initialize all page frame to -1
     }
    
     cout<<"\n|ref string |\t  page  frames \t  \t  |    Hit/Fault  |\n";
     cout<<"\n| intially  |\t-1|\t-1|\t-1|\t-1|       -       |\n";
     
    for (i = 0; i < n; i++) //go to the next page
    {
     cout<<"| \t"<<a[i]<<"   | ";
     
        for (j = 0; j < 4; j++) // find the page numbwer already exist or not 
        {
        
            if (p[j] == a[i]) //  used to compare input page and content of frame
            {
                flag = 0;
                
                for(k=0;k<4;k++) 
                {
                  cout<<"\t"<<p[k]<<"|   ";   // Print Current state of FRAME
                          
                }
                cout<<"\t H        |";
                break;
                
            }
            flag = 1;
        }
        if (flag == 1) // after comparison if page is not hit then replace the page in queue 
        {
            p[r] = a[i];
            r++;
            count++;
            if (r == 4) // to reset the queue 
            {
                r = 0;
            }
            for(k=0;k<4;k++)
            {
              cout<<"\t"<<p[k]<<"| ";   // Print Current state of FRAME
            }
            cout<<"\t F        |";
        }
        cout<<"\n";
    }
    
    cout << "\nnumber of page faults in fifo page replacement is :" << count <<"\n"<< endl;
    out<<count<<"\n";
    out.flush();
   
    return count;
}

int lru(int n, int a[])
{
 
    
    out<<"lru faults"<<"\n";
    
    int p[4], flag, count = 0, i, j, k;
    int t[4] = {-1, -1, -1, -1};

    for (i = 0; i < 4; i++) 
    {
        p[i] = -1;
    }

    cout << "\n|ref string |\t  page  frames \t  \t  |    Hit/Fault  |\n";
    cout << "\n| intially  |\t-1|\t-1|\t-1|\t-1|       -       |\n";

    for (i = 0; i < n; i++) 
    { 
        cout << "| \t" << a[i] << "   | ";

        flag = 0; 

        for (j = 0; j < 4; j++) 
        { 
            if (p[j] == a[i]) 
            {
                flag = 1;
                for (k = 0; k < 4; k++) 
                {
                    cout << "\t" << p[k] << "|   "; 
                }
                cout << "\t H        |";
                break;
            }
        }

        if (flag == 0) 
        { 
            int min= 0;
            for (k = 1; k < 4; k++) 
            {
                if (t[k] < t[min]) 
                {
                    min= k;
                }
            }

            p[min] = a[i]; 
            t[min] = i;
            count++; 
            for (k = 0; k < 4; k++)
             {
                cout << "\t" << p[k] << "| ";
             }
            cout << "\t F        |";
        }
        for (k = 0; k < 4; k++) 
        {
            if (p[k] == a[i]) 
            {
                t[k] = i;
                break;
            }
        }

        cout << "\n";
    }

    cout << "\nnumber of page faults in LRU page replacement is: " << count << "\n" << endl;
    out<<count<<"\n";
     out.flush();
    
   
          
    return count;
}
void compare(int x,int y) //compare fifo and lru algorithm
{
  
    if (x < y)
    {
        cout << "\npage faults are less in FIFO page replacement\n" ;
    }
    else if (x == y)
    {
        cout << "\npage faults are equal in LRU & FIFO page replacement\n" ;
    }
    else
    {
        cout << "\npage faults are less in LRU page replacement\n";
    }
}

void help()
{
cout<<"First In First Out (FIFO): This is the simplest page replacement algorithm. \nIn this algorithm,the operating system keeps track of all pages in \nthe memory in a queue, the oldest page is in the front of the queue. \nWhen a page needs to be replaced page in the front of the queue is selected for removal. \n\nExample: Consider page reference string 1, 3, 0, 3, 5, 6, 3 with 3 page frames.\nFind the number of page faults. \nInitially, all slots are empty, so when 1, 3, 0 came they are allocated to the empty slots —> 3 Page Faults. when 3 comes, it is already in memory so —> 0 Page Faults. \nThen 5 comes, it is not available in memory so it replaces the oldest page slot \n i.e 1. —>1 Page Fault. 6 comes, it is also not available in memory so it replaces the oldest page slot i.e 3 —>1 Page Fault. \nFinally, when 3 come it is not available so it replaces 0 1 page fault.\n\n\nLeast Recently Used: In this algorithm, page will be replaced which is least recently used.\n\nExample: Consider the page reference string 7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 3 with 4 page frames. \nFind number of page faults.initially, all slots are empty, \nso when 7 0 1 2 are allocated to the empty slots —> 4 Page faults \n0 is already their so —> 0 Page fault. when 3 came it will take the place of 7 because \n it is least recently used —>1 Page fault \n0 is already in memory so —> 0 Page fault. \n4 will takes place of 1 —> 1 Page Fault \nNow for the further page \nreference string —> 0 Page fault because they are already available in the memory. ";
}

int main()
{
    int n1,n,x,y,file1;
    label :
    cout << "\nenter how many pages you want : " << endl;
    cin >> n;
    cout << "\nframe size is :4\n" << endl;
    int a[n], p[4];
    cout << "enter pages " << endl;
    
    out<<"reference string"<<"\n";
    
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        out<<a[i]<<"\n";
    }
    for( ; ; )
    {
    cout << "Select from below option\n\n1)FIFO Page Replacement Algorithm\n\n2)LRU Page Replacement Algorithm\n\n3)Compare FIFO and LRU Page Replacement Algorithm\n\n4)Change Input Data\n\n5)Help\n\n6)Read file\n\n7)Exit\n";
    cout<<"\nEnter the choice =";
    cin>>n1;
     out.flush();
    
          
    switch(n1)
    {
    case 1: x=fifo(n, a);
             break;
    case 2: y=lru(n, a);
             break;         
    case 3: cout<<"Output from FIFO algorithm is:\n";
            x=fifo(n, a); 
            cout<<"Output from LRU algorithm is:\n";
            y=lru(n, a);
            compare(x, y);
            break; 
    case 4: goto label;
             break; 
    case 5: help();
             break;
    case 6:  out.close();
             
             in>>file1;
             cout<<file1;
             break;
             
    case 7: exit(0);
             break;
    
    default:cout<<"Invalid Choice" ; 
            break;
    }
    }
 return 0;
}
