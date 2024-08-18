

public class heap_sort{
    public static void heapsort(int arr[]){
        int n=arr.length;
        //making max heap function
        for(int i=n/2 -1;i>=0;i--){
            heapify(arr,n,i);
        }
        //deleating from the heap structure to sort the heap
        for(int i=n-1;i>=0;i--){
            int temp=arr[0];
            arr[0]=arr[i];
            arr[i]=temp;
            heapify(arr,i,0);
        }
    }
    public static void heapify(int arr[],int n,int i){
        int largest=i;
        int l=(2*i)+1;
        int r=(2*i)+2;
        while(l<n && arr[l]>arr[largest]){
            largest=l;
        }
        while(r<n && arr[r]>arr[largest]){
            largest=r;
        }
        if(largest!=i){
            int temp =arr[i];
            arr[i]=arr[largest];
            arr[largest]=temp;
            //now again calling recurcively function
            heapify(arr,n,largest);
        }

    }
    public static void main(String[]args){
        int arr[]={2,8,4,5,9,3,1,6};
        int n= arr.length;
        for(int i=0;i<n;i++){
            System.out.println(arr[i]);

        }
        System.out.println("We sorted the data");

        heapsort(arr);
        System.out.println("Printing the array");
        for(int i=0;i<n;i++){
            System.out.println(arr[i]);

        }

    }

}
