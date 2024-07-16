### 누적합 알고리즘 (Prefix Sum Algorithm)
누적합 알고리즘은 주어진 **배열의 부분합을 빠르게 계산할 수 있도록 돕는 기법**입니다. 이 알고리즘은 주로 배열의 **특정 구간의 합을 자주 계산해야 할 때** 매우 유용합니다. 누적합을 미리 계산해두면, 구간합을 구하는데 소요되는 시간을 줄일 수 있습니다.
#### 알고리즘 설명
##### 1. 누적합 배열 생성
주어진 배열 arr에 대해 누적합 배열 `prefix_sum`을 생성합니다. `prefix_sum[i]`는 `arr[0]`부터 `arr[i-1]`까지의 합을 저장합니다.

예를 들어, 배열 `arr = [3, 1, 4, 1, 5]`가 주어졌을 때 누적합 배열 `prefix_sum`은 다음과 같이 생성됩니다:

```makefile
arr : [3, 1, 4, 1, 5]
prefix_sum : [0, 3, 4, 8, 9, 14]
```
##### 2. 구간합 계산
배열 `arr`의 `i`번째 요소부터 `j`번째 요소까지의 합을 구하려면, 다음 공식을 사용합니다:
```scss
sum(arr[i:j]) = prefix_sum[j] - prefix_sum[i]
```
이 공식은 누적합 배열의 두 값을 빼는 것으로 구간합을 빠르게 계산할 수 있게 합니다.

##### 3. 예제 문제
배열 `arr`와 여러 구간 `[i, j)`가 주어졌을 때, 각 구간의 합을 구하는 문제를 풀어봅시다.
```makefile
arr = {3, 1, 4, 1, 5, 9, 2, 6}
queries = {{1, 3}, {2, 5}, {0, 7}}
```

1. 누적합 배열을 생성합니다.
2. 주어진 구간에 대해 구간합을 계산합니다.

```cpp
#include <iostream>
#include <vector>

using namespace std;

// 누적합 배열을 생성하는 함수
vector<int> prefix_sum_array(const vector<int>& arr) {
    int n = arr.size();
    vector<int> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + arr[i];
    }
    return prefix_sum;
}

// 구간합을 계산하는 함수
int range_sum(const vector<int>& prefix_sum, int i, int j) {
    return prefix_sum[j] - prefix_sum[i];
}

int main() {
    // 입력 배열과 구간
    vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6};
    vector<pair<int, int>> queries = {{1, 3}, {2, 5}, {0, 7}};

    // 누적합 배열 생성
    vector<int> prefix_sum = prefix_sum_array(arr);

    // 각 구간의 합 계산 및 출력
    for (const auto& query : queries) {
        int i = query.first;
        int j = query.second;
        cout << "Sum of arr[" << i << ":" << j << "] is " << range_sum(prefix_sum, i, j) << endl;
    }

    return 0;
}
```

###### 결과
```csharp
Sum of arr[1:3] is 5
Sum of arr[2:5] is 10
Sum of arr[0:7] is 31
```

이 예제는 누적합을 이용하여 구간합을 빠르게 계산하는 방법을 보여줍니다. 이와 같은 방법은 대규모 데이터 처리나 빈번한 쿼리 처리가 필요한 상황에서 매우 유용하게 사용될 수 있습니다.

#### 마무리하며..

누적합 알고리즘은 구간 합을 구할 때 매우 유용합니다. 어느새 전체 중 반절 정도가 지났습니다. 문제를 풀어보면서 누적 합을 사용해야 하는 경우에 대한 감각을 키워봅시다.
