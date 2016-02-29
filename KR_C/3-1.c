/* 折半查找 */
int bin_search(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    mid = (low + high)/2;
    while (low <= high && x != v[mid]) {
	if (x > v[mid]) {
	    low = mid + 1;
	}
	else {
	    high = mid - 1;
	}
	mid = (low + high)/2;
    }
    if (x == v[mid]) {
	return mid;
    }
    else {
	return -1;
    }
}
