<h2><a href="https://leetcode.com/problems/sorted-gcd-pair-queries">3583. Sorted GCD Pair Queries</a></h2><h3>Hard</h3><hr><p>You are given an integer array <code>nums</code> of length <code>n</code> and an integer array <code>queries</code>.</p>

<p>Let <code>gcdPairs</code> denote an array obtained by calculating the <span data-keyword="gcd-function">GCD</span> of all possible pairs <code>(nums[i], nums[j])</code>, where <code>0 &lt;= i &lt; j &lt; n</code>, and then sorting these values in <strong>ascending</strong> order.</p>

<p>For each query <code>queries[i]</code>, you need to find the element at index <code>queries[i]</code> in <code>gcdPairs</code>.</p>

<p>Return an integer array <code>answer</code>, where <code>answer[i]</code> is the value at <code>gcdPairs[queries[i]]</code> for each query.</p>

<p>The term <code>gcd(a, b)</code> denotes the <strong>greatest common divisor</strong> of <code>a</code> and <code>b</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [2,3,4], queries = [0,2,2]</span></p>

<p><strong>Output:</strong> <span class="example-io">[1,2,2]</span></p>

<p><strong>Explanation:</strong></p>

<p><code>gcdPairs = [gcd(nums[0], nums[1]), gcd(nums[0], nums[2]), gcd(nums[1], nums[2])] = [1, 2, 1]</code>.</p>

<p>After sorting in ascending order, <code>gcdPairs = [1, 1, 2]</code>.</p>

<p>So, the answer is <code>[gcdPairs[queries[0]], gcdPairs[queries[1]], gcdPairs[queries[2]]] = [1, 2, 2]</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [4,4,2,1], queries = [5,3,1,0]</span></p>

<p><strong>Output:</strong> <span class="example-io">[4,2,1,1]</span></p>

<p><strong>Explanation:</strong></p>

<p><code>gcdPairs</code> sorted in ascending order is <code>[1, 1, 1, 2, 2, 4]</code>.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [2,2], queries = [0,0]</span></p>

<p><strong>Output:</strong> <span class="example-io">[2,2]</span></p>

<p><strong>Explanation:</strong></p>

<p><code>gcdPairs = [2]</code>.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n == nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= queries[i] &lt; n * (n - 1) / 2</code></li>
</ul>

<hr>

## 🚀 Approach

A brute-force solution would calculate the GCD of every possible pair, store them, sort them, and answer the queries. However, this requires **O(n²)** time and memory, which is impossible for the given constraints.

Instead, this solution counts **how many pairs have each possible GCD** without ever generating the pairs.

---

## Step 1: Count Numbers Divisible by Each Divisor

For every number in the array, find all of its divisors and increment their count.

```cpp
for (int x : nums) {
    for (int d = 1; d * d <= x; d++) {
        if (x % d == 0) {
            cnt[d]++;
            if (x / d != d)
                cnt[x / d]++;
        }
    }
}
```

After this step,

- `cnt[d]` = Number of elements divisible by `d`.

For example,

```text
nums = [2, 3, 4]

Divisor 1 → 3 numbers
Divisor 2 → 2 numbers
Divisor 3 → 1 number
Divisor 4 → 1 number
```

---

## Step 2: Count Pairs Divisible by Each Divisor

If `k` numbers are divisible by a divisor `d`, then the number of pairs divisible by `d` is

```
k × (k - 1) / 2
```

However, this **does not** mean the GCD of those pairs is exactly `d`.

It also includes pairs whose GCD is any multiple of `d`.

For example,

```text
Pairs divisible by 2
=
Pairs with GCD 2
+
Pairs with GCD 4
+
Pairs with GCD 6
+ ...
```

---

## Step 3: Inclusion-Exclusion

To obtain the number of pairs whose **GCD is exactly `d`**, subtract the contribution of all larger multiples.

```cpp
pairs[d] -= pairs[2 * d];
pairs[d] -= pairs[3 * d];
pairs[d] -= pairs[4 * d];
...
```

Since divisors are processed from **largest to smallest**, all larger GCD counts are already known.

After this step,

```text
pairs[d] = Number of pairs whose GCD is exactly d
```

---

## Step 4: Prefix Sum

Convert the pair count array into a prefix sum.

```cpp
prefix[i] += prefix[i - 1];
```

Now,

```text
prefix[i]
```

represents the number of pairs whose GCD is **less than or equal to `i`**.

---

## Step 5: Answer Queries

The sorted GCD array is **never constructed**.

Instead, for each query `q`, perform a binary search on the prefix sum array.

```cpp
upper_bound(prefix.begin(), prefix.end(), q)
```

The first index where

```text
prefix > q
```

is exactly the answer for that query.

Each query is answered in **O(log M)** time.

---

# 📊 Complexity Analysis

| Operation | Complexity |
|-----------|------------|
| Counting divisors | **O(n√M)** |
| Inclusion-Exclusion | **O(M log M)** |
| Prefix Sum | **O(M)** |
| Each Query | **O(log M)** |

Where:

- `n` = Number of elements in `nums`
- `M` = Maximum value in `nums`

---

# 💡 Key Insight

The main observation is that we **never need to generate every pair**.

Instead of asking:

> *"What is the GCD of every pair?"*

we ask:

> *"How many pairs have GCD equal to each possible value?"*

Counting divisor frequencies, applying inclusion-exclusion, and using prefix sums allows us to answer every query efficiently without constructing the enormous sorted GCD array.
