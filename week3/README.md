#### 1. 도입

***



###### 정렬 알고리즘
> 데이터를 일정한 순서로 나열하는 알고리즘

정렬은 **데이터 처리의 기본적인 작업** 중 하나로, 효율적인 검색과 데이터 분석을 위해 필수적입니다. 이번 글에서는 몇 가지 대표적인 정렬 알고리즘에 대해 알아보겠습니다.




***


#### 2. 버블 정렬(Bubble Sort)


***

버블 정렬은 **인접한 두 원소를 비교하여 순서가 잘못된 경우 서로 교환하는 방식**으로 정렬합니다. 가장 간단한 정렬 알고리즘 중 하나 입니다.

1.  첫 번째 원소부터 시작하여 인접한 두 원소를 비교합니다.
2.  두 원소의 순서가 잘못되었으면 서로 교환합니다.
3.  배열의 끝까지 이를 반복합니다.
4.  각 반복이 끝날 때마다 가장 큰 원소가 끝으로 이동합니다.
5.  마지막 원소가 정렬될 때까지 이 과정을 반복합니다.

* 장점 : **구현이 쉽고 직관적**입니다.
* 단점 : 시간복잡도가 O(n2)$O(n^2)$로, **비효율적**입니다.

###### 예제 코드
```cpp
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
```


***


#### 3. 선택 정렬 (Selection Sort)


****

선택 정렬은 **매 단계에서 가장 작은 (또는 큰) 원소를 선택하여 정렬된 부분에 추가**하는 방식입니다.

1. 주어진 배열에서 가장 작은 원소를 찾습니다.
2. 그 원소를 배열의 첫 번째 원소와 교환합니다.
3. 나머지 배열에 대해 위의 과정을 반복합니다.
4. 배열이 정렬될 때까지 이를 반복합니다.

* 장점 : **구현이 쉽고**, 버블 정렬보다 비교 횟수가 적습니다.
* 단점 : 시간 복잡도가 O(n2)$O(n^2)$로, **비효율적**입니다.

###### 예제 코드
```cpp
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}
```


***

#### 4. 삽입 정렬 (Insertion Sort)


***


삽입 정렬은 **이미 정렬된 부분에 새로운 원소를 알맞은 위치에 삽입**하여 정렬하는 방식입니다.

1. 두 번째 원소부터 시작하여 해당 원소를 앞의 정렬된 부분과 비교합니다
2. 알맞은 위치에 삽입합니다.
3. 배열의 끝까지 이를 반복합니다.


* 장점 : 대부분의 경우 효율적이며, 시간 복잡도가 O(n)$O(n)$일 수 있습니다.
* 단점 : **최악의 경우** 시간 복잡도가 O(n2)$O(n^2)$ 입니다.

###### 예제 코드
```cpp
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
```


***


#### 5. 합병 정렬 (Merge Sort)


***

합병 정렬은 분할 정복 기법을 사용하는 효율적인 정렬 알고리즘입니다. **배열을 반으로 나누고 각각을 정렬한 후 병합**합니다.

1. 배열을 반으로 나눕니다.
2. 각각의 반을 재귀적으로 합병 정렬합니다.
3. 정렬된 두 부분을 병합합니다.

* 장점 : 시간 복잡도가 O(nlgn)$O(nlgn)$ 으로,** 안정적**입니다.
* 단점 : **추가적인 메모리 공간**이 필요합니다.

###### 예제 코드
```cpp
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
```



***


#### 6. 퀵 정렬 (Quick Sort)



***


퀵 정렬은 **피벗을 기준으로 배열을 나누고, 각 부분을 정렬하는 분할 정복 알고리즘**입니다.

1. 배열에서 피벗을 선택합니다.
2. 피벗보다 작은 원소는 왼쪽에, 큰 원소는 오른쪽에 배치합니다.
3. 피벗을 기준으로 배열을 두 부분으로 나눕니다.
4. 각 부분을 재귀적으로 퀵 정렬합니다.

* 장점 : 평균적으로 매우 빠르며, 시간 복잡도가 O(nlgn)$O(nlgn)$입니다.
* 단점 : **최악의 경우** 시간 복잡도가 O(n2)$O(n^2)$입니다.

###### 예제 코드
```cpp
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

```



***


#### 7. 언어별 정렬 함수들



***


1. Python : sorted(), list.sort()
2. Java : Arrays.sort()
3. C++ : std::sort()
4. JavaScript : Array.prototype.sort()
5. Swift : sorted(), sort()



***


#### 8. 마무리 하며



***



정렬 알고리즘은 데이터 처리의 기본적인 작업 중 하나로 매우 중요합니다. 각 알고리즘은 특성과 장단점이 다르므로, 상황에 맞는 적절한 알고리즘을 선택하는 것이 중요합니다. 위에서 소개한 버블 정렬, 선택 정렬, 삽입 정렬, 합병 정렬, 퀵 정렬을 이해하고 구현해보면서 정렬 알고리즘의 원리를 깊이 있게 공부해보세요.

이번 한 주도 화이팅입니다! 정렬을 정복하는 그날까지!!
