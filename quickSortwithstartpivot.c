//Start element as pivot for Quick Sort

int partition1(int *a,int start,int end)

{

int pivot=a[start],p1=start+1,i,temp;

for(i=start+1;i<=end;i++)
{

if(a[i]<pivot)
    {
        if(i!=p1)
      {  
            temp=a[p1];
            a[p1]=a[i];
            a[i]=temp;
      }    p1++;
    }
}

        a[start]=a[p1-1];
        a[p1-1]=pivot;

return p1-1;
}




  void quicksort(int *a,int start,int end)
{
 int p1;
 if(start<end)
{
    p1=partition(a,start,end);
    quicksort(a,start,p1-1);
    quicksort(a,p1+1,end);
}
}
