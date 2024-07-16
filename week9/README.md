## 분할 정복 알고리즘 (Divide and Conquer Algorithm)
분할 정복 알고리즘은 큰 문제를 작은 부분 문제로 나누어 해결하는 알고리즘 디자인 패러다임입니다. 각 부분 문제는 독립적으로 해결될 수 있으며, 이 해결된 부분 문제들을 결합하여 전체 문제의 해를 구하는 방식입니다. 주로 재귀적인 방법을 사용하여 구현됩니다.

***

### 1. 개요
분할 정복 알고리즘의 기본 아이디어는 큰 문제를 해결 가능한 **작은 문제로 분할**하고, 각각의 작은 문제에 대해 **독립적으로 해결**한 후, 그 **결과를 조합**하여 원래 문제의 해를 구하는 것입니다.

***

### 2. 과정
#### 분할 (Divide)
주어진 문제를 작은 크기의 동일한 문제들로 분할합니다. 이는 보통 반으로 나누는 것이 일반적이지만, 문제의 특성에 따라 다르게 구성될 수 있습니다.
#### 정복 (Conquer)
각 부분 문제를 **재귀적**으로 해결합니다. 부분 문제의 크기가 충분히 작으면 직접적인 방법으로 해결할 수 있습니다.
#### 결합 (Combine)
각 부분 문제의 해를 결합하여 전체 문제의 해를 구합니다. 이 단계에서 각 부분 문제의 해결 결과를 통합하는 과정을 수행합니다.

***

### 3. 예제 알고리즘
#### 3-1. 병합 정렬 (Merge Sort)
병합 정렬은 분할 정복 알고리즘의 대표적인 예로, 다음과 같은 과정을 따릅니다:
1. 분할 : 배열을 반으로 나눕니다.
2. 정복 : 각 부분 배열을 재귀적으로 정렬합니다.
3. 결합 : 정렬된 부분 배열들을 병합하여 전체 배열을 정렬합니다.

```python
def merge_sort(arr):
    if len(arr) <= 1:
        return arr
    
    mid = len(arr) // 2
    left_half = merge_sort(arr[:mid])
    right_half = merge_sort(arr[mid:])
    
    return merge(left_half, right_half)

def merge(left, right):
    merged = []
    while left and right:
        if left[0] <= right[0]:
            merged.append(left.pop(0))
        else:
            merged.append(right.pop(0))
    
    while left:
        merged.append(left.pop(0))
    
    while right:
        merged.append(right.pop(0))
    
    return merged

# Example usage:
arr = [38, 27, 43, 3, 9, 82, 10]
sorted_arr = merge_sort(arr)
print("Sorted array:", sorted_arr)

```

#### 3-2. 퀵 정렬 (Quick Sort)
퀵 정렬은 다음과 같은 과정을 따르며, 평균적으로 빠른 정렬 알고리즘으로 알려져 있습니다:
1. 분할: 기준 원소(pivot)를 선택하고 배열을 pivot을 기준으로 분할합니다.
2. 정복: 각 부분 배열을 재귀적으로 정렬합니다.
3. 결합: 추가적인 작업 없이 배열이 이미 정렬되어 있습니다.

```python
def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    
    return quick_sort(left) + middle + quick_sort(right)

# Example usage:
arr = [38, 27, 43, 3, 9, 82, 10]
sorted_arr = quick_sort(arr)
print("Sorted array:", sorted_arr)

```


***

### 4. 장단점
#### 장점
* 문제를 작은 부분 문제로 나누어 해결하기 때문에 **구현이 간단하고 이해하기 쉽습니다**.
* 문제의 분할과 병합 과정에서 병렬 처리가 가능하여 **성능을 향상** 시킬 수 있습니다.

#### 단점
* 재귀 호출이 많이 일어날 수 있어 **메모리 사용량이 증가**할 수 있습니다.
* 일부 문제에서는 분할할 때 추가적인 비용이 발생할 수 있습니다.



***

### 5. 마무리

분할 정복 알고리즘은 많은 알고리즘 디자인과 문제 해결에 중요한 역할을 합니다. 위와 같은 정렬 알고리즘이나 다른 많은 알고리즘에도 분할 정복의 요소들이 많이 있습니다. 이번 주 문제가 많이 어려운데 화이팅 해서 풀 수 있는 데 까지 최선을 다해봅시다!
