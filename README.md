*This project has been created as part of the 42 curriculum by andry-ha, mamiandr.*

# Description

## What is push swap ?
``push_swap`` is a program which calculates and displays on the standard output the smallest program,  
made of Push swap language operations, that sorts the integers received as arguments.

## Goal
The goal of this project is to help us discover algorithmic complexities in a very concrete way.

## The rules
* We have <font color="cyan">2</font> stacks named <font color="orange">a</font> and <font color="orange">b</font>.
* At the beginning:
	* The stack <font color="orange">a</font> contains a random amount of negative and/or positive numbers
	without any duplicate.
	* The stack <font color="orange">b</font> is empty.
* The goal is <font color="orange">to sort in ascending order numbers into stack a</font>. To do so you have the
following operations at your disposal: ``swap`` ``rotate`` ``reverse_rotate`` ``push``

## Required strategies :
To enforce a rigorous understanding of algorithmic complexity (time and space),  
we must implement four distinct sorting strategies and integrate them into our ``push_swap`` program
* Simple algorithm (O(n²))
* Medium algorithm (O(n√n))
* Complex algorithm (O(n log n)):
* Custom adaptive algorithm (learner’s design)

# Instructions
### Installation
```Shell
git@vogsphere.42antananarivo.mg:vogsphere/intra-uuid-[intra-uuid]-[login]
cd folder_name

#And type the command `make` to compile the program.
make
```

```Shell
#Once compiled, you should have a program named `push_swap`. You can run the program as follows:
./push_swap 2 1 3 6 5 8

ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker_linux $ARG

ARG="4 67 3 87 23"; ./push_swap --adaptive $ARG | wc -l
```


# Detailed explaination and algorythme :  
* In the <font color="orange">simple algorithm (O(n²)) strategy</font>, we chose the sort insertion method for its simplicity. It is very easy to understand and code, ideal for learning.  
Its time complexity is always O(n²), regardless of the initial order of the data.
**Selection sort** involves virtually dividing a list into two parts: a sorted part (on the left) and an unsorted part (on the right).  
The algorithm progressively moves elements from the unsorted part to the sorted part by following these steps:
	1. **Find the smallest**: Start at the first position and scan the rest of the list to find the lowest value.
	2. **Swap**: Swap that lowest value with the element at the current starting position.
	3. **Advance**: Move the boundary of the "sorted" section one step to the right.
	4. **Repeat**: Continue until the entire list is sorted.

* In the <font color="orange">Medium algorithm (O(n√n))</font>, we chose the chunk-based sorting (divide into <font color="orange">√n</font> chunks)  
Instead of scanning every single element to find the minimum (which takes <font color="orange">O(n)</font> time), you divide the array into <font color="orange">√n</font> blocks, each of size √n.
	1. **Preprocessing**: For each block, we pre-calculate and store its local minimum.
	2. **Finding the Global Minimum**: To find the smallest element in the entire array, we only compare the √n local minima of the blocks.  
	This takes <font color="orange">O(√n)</font> time instead of <font color="orange">O(n)</font>.
	3. **Update**: Once the element has been extracted and moved to the sorted part,  
	only the minimum of the block concerned is updated (by traversing its <font color="orange">√n</font> remaining elements).
	4. **Repeat**: We repeat this process <font color="orange">n</font> times until all elements are sorted.

* In the <font color="orange">Complex algorithm (O(n log n))</font>, we chose the Quick sort adaptation with stack partitioning.  
Instead of the function calling itself to handle the left and right sub-arrays, you manually push the boundaries (low and high indices) onto a stack.  
	1. **Initialize**: Push the initial low and high indices of the array onto the stack.  
	2. **Loop**: While the stack is not empty:  
		a. **Pop**: Get the low and high indices for the current segment.  
		b. **Partition**: Pick a pivot and rearrange the array (just like standard Quick Sort). The pivot is now in its final sorted position.  
		c. **Push**: Push the boundaries of the two new unsorted segments (left of pivot and right of pivot) back onto the stack.  
	3. **Finish**: The process repeats until the stack is empty.

## ***Notes***
```C
Before choosing the best strategy to apply for sorting, we need to calculate the disorder
```
### Method for Measuring Array Disorder:
```C
/**Inversion Counting O(nlogn): The most common measure of disorder for numerical arrays is the number of inversions.
An inversion is a pair of elements A[i], A[j] such that i < j but A[i] > A[j].

* A sorted array has 0 inversions;
* A reversed array has ( (n(n-1)) / 2) inversions.

For numerical data, a common quick check for disorder is simply (number of inversions / max possible inversions)

For example :
Input: arr[] = [2, 4, 1, 3, 5]
Number of inversions or the total of pairs : 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
Output disorder : 0.30
*/
float	compute_disorder(int stack[], int size)
{
	int		mistakes;
	int		total_pairs;
	int i;
    int j;

	mistakes = 0;
	total_pairs = 0;
    i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			total_pairs++;
			if (stack[i] > stack[j])
				mistakes++;
			j++;
		}
		i++;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((float)mistakes / (float)total_pairs);
}
```









## Operations in push swap : ``swap`` ``rotate`` ``reverse_rotate`` ``push``
Let’s explain some push swap rules, and know how we can move in and between the stacks:

- <font color="orange">**sa :**</font> swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
- <font color="orange">**sb :**</font> swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
- <font color="orange">**ss :**</font> sa and sb at the same time.
- <font color="orange">**pa :**</font> push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- <font color="orange">**pb :**</font> push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- <font color="orange">**ra :**</font> rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
- <font color="orange">**rb :**</font> rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
- <font color="orange">**rr :**</font> ra and rb at the same time.
- <font color="orange">**rra :**</font> reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
- <font color="orange">**rrb :**</font> reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
- <font color="orange">**rrr :**</font> rra and rrb at the same time.

## What is Big-O notation?
Big-O notation is a method used to determine the complexity of an algorithm. It measures the performance of an algorithm. The most common are O(1) (constant), O(n) (linear), and O(n^2) (quadratic).


### Main Big-O Notations (from fastest to slowest):

- <font color="orange">**O(1) Constant execution time:**</font> The algorithm takes the same amount of time regardless of the size of the data (e.g., accessing the first element of an array).
 ```Python
 # In Python
def first_element(values):
	return values[0]

# Tests
assert first_element([1]) == 1
assert first_element([1, 2]) == 1
assert first_element([1, 2, 3]) == 1
assert first_element([1, 2, 3, 4]) == 1
```

- <font color="orange">**O(log n)Logarithmic execution time:**</font>

	**Are you familiar with binary search?**

	It's a technique used to search sorted lists of data. The middle element of the dataset is selected and compared to a target value. If the values ​​match, the result is positive.  
	If the search value is greater than the target value, the upper half of the dataset is processed, and the same operation is performed.

	The algorithm reduces the problem by half at each step (e.g., binary search).
```Python
# In Python
def binary_search(array, item):
	low = 0
	high = len(array) - 1
	while low <= high:
		mid = low + (high - low) // 2
		guess = array[mid]
		if guess == item:
			return mid
		if guess > item:
			high = mid - 1
		if guess < item:
			low = mid + 1
	return None
assert binary_search([1, 3, 5, 7, 9], 3) == 1
assert binary_search([1, 3, 5, 7, 9], 7) == 3
```

```C
int	binary_search(int *arr, int size, int x)
{
	int	low;
	int	high;
	int	mid;

	low = 0;
	high = size - 1;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (arr[mid] < x)
			low = mid + 1;
		else if (arr[mid] > x)
			high = mid - 1;
		else
			return (mid);
	}
	return (-1);
}
```

- <font color="orange">**O(n)Linear execution time:**</font> An algorithm is said to have O(n) complexity if, during its execution, it requires traversing each input element. The time increases proportionally to the size of the data.
	* If you have 10 input elements, you will have 10 iterations.
	* With 10 million elements, you will have 10 million iterations: complexity O(n).

- <font color="orange">**O(n log n)Log-linear time:**</font> Typical of efficient sorting methods such as merge sort.
- <font color="orange">**O(n^2)Quadratic execution time:**</font> The time increases with the square of the data size (e.g., nested loops, bubble sort).
- <font color="orange">**O(2^n)Exponential time:**</font> The time doubles with each addition of an element. Very slow.

|   Big O   | Number of operations for 10 input elements | Number of operations for 100 input elements |
| :--- | :--- | :--- |
|    O(1)   |            1             |             1             |
|  O(log n) |            3             |             7             |
|    O(n)   |            10            |            100            |
|    O(n log n)   |            10            |            200            |
|  O(n^2)   |           100            |           10000           |
|  O(2^n)   |           1024            |           1.2676506e+30           |

## ***Notes***
```c
When you want to move an element to the top:

1️⃣ You calculate its position (index)
2️⃣ You compare it to half the size of the stack

If the element is (in the first half):
	→ move forward
Else (in the second half)
	→ move backward

If : index <= (size / 2)
👉 We use ra
Otherwise:
👉 We use rra
```

## Radix sort explanation
```C
static int	get_max_bits(int size)
{
	int	max;
	int	bits;

	max = size - 1;
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_stack **a, t_stack **b, t_config *cfg)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	size = stack_size(*a);
	i = 0;
	max_bits = get_max_bits(size);
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			/**
			 * 1️⃣ on décale les bits
			 * 2️⃣ on regarde seulement le dernier bit
			 * 0110 & 0001 = 0
			 */
			//Equivalent : ((((*a)->index / 2^i) % 2) == 0)
			if ((((*a)->index >> i) & 1) == 0)
				pb(a, b, cfg);
			else
				ra(a, cfg);
			j++;
		}
		while (*b)
			pa(a, b, cfg);
		i++;
	}
}
```

```C
void	radix_sort_2bits(t_stack **a, t_stack **b, t_config *cfg)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;
	int val;

	size = stack_size(*a);
	i = 0;
	max_bits = get_max_bits(size);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			val = ((*a)->index >> i) & 3; // Récupère 2 bits (0, 1, 2 ou 3)
			if (val == 0) // Cas 00 : On garde dans A (en bas)
				ra(a, cfg);
			else // Cas 01, 10, 11 : On envoie vers B
				pb(a, b, cfg);
		}
		// Ici, on peut ajouter une logique pour trier B avant de tout repousser
		while (*b)
			pa(a, b, cfg);
		i += 2; // On avance de 2 bits
	}
}
```

```md
push_swap/
│
├── libft/
│
├── operations/
│   ├── swap.c
│   ├── push.c
│   ├── rotate.c
│   └── reverse_rotate.c
|
├── parsing/
│   ├── parse_args.c
│   ├── check_numbers.c
│   ├── check_duplicates.c
│   └── stack_init.c
|
├── sorting/
│   ├── sort_3.c
│   ├── sort_5.c
│   └── radix_sort.c
│
│── utils/
│	├── stack_utils.c
│	└── free_stack.c
|
├── push_swap.c
├── push_swap.h
├── Makefile
├── README.md
```
 # Resources
 * [The Big-O notation - On medium.com](https://medium.com/@nioperas06/la-notation-big-o-4767d188f875)
 * [The Big-O notation and examples](https://www.youtube.com/watch?v=QaNwlm8AzMA&t=333s) Youtube video
 * [Introduction to Big O Notation - Neso Academy](https://www.youtube.com/watch?v=4nUDZtRX38U&list=PLBlnK6fEyqRhe8C6qXX0d8fq0TnuQS8Wd) Youtube video
 * [BigOCast - Heap sort](https://www.youtube.com/watch?v=jtshKZDqeYo) Youtube video
 * [BigOCast - Buble sort](https://www.youtube.com/watch?v=D6XBpxL9Q6E&list=PL5bEHOjkmh1M4NDksyK0f1huaXkzbUA2H&index=7) Youtube video