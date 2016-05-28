import java.util.*;

public class quickSort {
    public static void main(String[] args) {
	int[] A = {13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11};
	int low = 0;
	int high = A.length - 1;

	System.out.println(Arrays.toString(A));
	qSort(A, low, high);
	System.out.println(Arrays.toString(A));
	
    }

    public static void qSort(int[] arr, int low, int high) {
    	int middle = low + (high - low) / 2;
    	int pivot = arr[middle];

    	int i = low;
    	int j = high;
    	while (i <= j) {
    	    while (arr[i] < pivot) {
    		i++;
    	    }
    	    while (arr[j] > pivot) {
    		j--;
    	    }

    	    if (i <= j) {
    		int temp = arr[i];
    		arr[i] = arr[j];
    		arr[j] = temp;
    		i++;
    		j--;
    	    }
    	}
	
	if (j > low) {
	    qSort(arr, low, j);
	}

	if (i < high) {
	    qSort(arr, i, high);
	}
    }
}
