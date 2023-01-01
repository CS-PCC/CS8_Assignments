# Car Wash Simulation

## Specification

The precise program specifications are given by the following input/output descriptions:

**Input**
The program has three input items: 
1. the amount of time needed to wash one car (in total seconds); 
2. the probability that a new customer arrives during any given second (we assume that, at most, one customer arrives in a second); 
3. the total length of time to be simulated (in seconds).

**Output**
The program produces two pieces of output information: 
1. the number of customers serviced in the simulated time;
2. the average time that a customer spent in line during the simulation (in seconds).


## Design

We will carry out a design of the program in a way that is common for many simulation tasks. The approach is to propose a collection of related object types that correspond to real-world objects in the situation that we are simulating. There are many possibilities our particular approach focuses on the use of our queue class, which will be used to simulate a line of customers waiting to have their cars washed. We first discuss the queue and then propose the other objects needed for the simulation.

We need to simulate a queue of customers, but we do not have real live customers, so we must decide how we will represent them. There are many ways to represent customers: We could use their names and place them in a queue of names; we could assign an arbitrary number to each customer and store that number in a queue of numbers; we could represent each customer by the make and year of the customer’s automobile, or even by how dirty the automobile is. However, none of those representations has any relevance to the specified simulation. For this simulation, all we need to know about a customer is how long the customer waits in the queue. Hence, a good way to represent a customer is to use a number that represents the time that the customer entered the queue. Thus, our queue will be a queue of numbers. In a more complex simulation, it would be appropriate to implement the customers as objects, and one of the customer’s member functions would be a function that returns the customer’s arrival time.

The numbers that record the arrival times are called **time stamps**. Our simulation works in seconds, so a time stamp is just the number of simulated seconds that have passed since the start of the simulation. When the customer (represented by the time stamp) is removed from the queue, we can easily calculate the time the customer spent waiting: The time spent waiting is the total number of seconds simulated so far minus the time stamp.



**Washer**. A washer is an object that simulates the automatic car-washing mechanism. The simulation program requires one washer object. This washer is initialized with its constructor, and each time another second passes, the simulation program indicates the passage of one second for the washer. This suggests the following constructor and member function:

```cpp
washer::washer(unsigned int s);
// Precondition: The value of s is the number of seconds needed to
// complete one wash cycle.
// Postcondition: The washer has been initialized so that all other member // functions may be used.
void washer::one_second();
// Postcondition: The washer has recorded (and simulated) the passage of // one more second of time.
```

**Pseudocode**

1. Declare a queue of unsigned integers, which will be used to keep track of arrival times of customers who are waiting to wash their cars. Unsigned integers are the data type used in C++ for numbers that can never be negative. We also declare the following objects:

    (a) A *washer*:The washer’s constructor has an argument in dicating the amount of time (in seconds) needed by the washer to wash one car.
    (b) A *bool_source*: The constructor has an argument that specifies how frequently the bool_source returns true (indicating how often customers arrive).
    (c) An *averager*.

2. 
for (current_second = 1; current_second <= the simulation length; ++current_second) 
{
    Each iteration of this loop simulates the passage of one second of time, as follows: Ask the *bool_source* whether a new customer arrives during this second, and
    if so, enter the *current_second* into the queue.
    if (the *washer* is not busy and the queue is not empty)
    {
        Remove the next integer from the queue, and call this integer next.
        This integer is the arrival time of the customer whose car we will now wash. So, compute how long the customer had to wait (*current_second - next*), and send this value to the *averager*. Also, tell the *washer* that it should
        start washing another car.
    }
    Indicate to the *washer* that another simulated second has passed. This allows the washer to correctly determine whether it is still busy.
}

3. At this point, the simulation is completed. So we can get and print two items of information from the averager: (1) how many numbers the averager was given (i.e., the number of customers whose cars were washed); and (2) the average of all the numbers that it was given (i.e., the average waiting time for the customers, expressed in seconds).


Notice that the constructor argument is an *unsigned integer*, which is a data type that forbids negative values. Throughout our simulation, we will use unsigned integers for time values that cannot be negative. As usual, we should provide a default value for this argument (perhaps 60 seconds), so that the constructor can be used as a default constructor.

The other two responsibilities of a washer are to tell the simulation program whether the washing mechanism is currently available and to begin the washing of a new car. These responsibilities are accomplished with two additional member functions:

```cpp
bool washer::is_busy() const;
// Postcondition: The return value is true if the washer is busy (in a wash // cycle); otherwise the return value is false.
void washer::start_washing();
// Precondition: The washer is not busy.
// Postcondition: The washer has started simulating one wash cycle. // Therefore, is_busy() will return true until the required number of // simulated seconds has passed.
```


**Bool_source**. An object of the *bool_source* class provides a sequence of boolean values. Some of the elements in the sequence are true, and some are false. During the simulation, we will have one *bool_source* object that we query once per simulated second. If the query returns true as its response, this indicates that a new customer has arrived during the simulated second; a false return value indicates that no customer has arrived during the simulated second. With this in mind, we propose two functions, described next.

The first function is a constructor for the *bool_source*. This constructor has one argument, which is the probability that the bool_source returns true to a query. The probability is expressed as a decimal value between 0 and 1. For example, suppose that our program uses the name arrival for its bool_source, and we want to simulate the situation where a new customer arrives during 1% of the simulated seconds. Then our program would have the declaration:

`bool_source arrival(0.01);`

The argument to this constructor should have a default argument, perhaps 0.5, so that the constructor can also be used as a default constructor.

There is another member function that can be called to obtain the next value in the bool_source’s sequence of values. Here is the prototype:

```cpp
bool bool_source::query() const;
// Postcondition: The return value is either true or false, with the probability // of a true value being determined by the argument to the constructor.
```

There are several ways of generating random boolean values, but at this stage we don’t need to worry about such implementation details.


**Averager**. An *averager* computes the average of a sequence of numbers. For example, we might send the following four numbers into an averager: 10, 20, 2, and 12. The averager could then tell us that the average of these numbers is 11.0. The averager can also tell us how many numbers it has processed—in our example the averager processed four numbers. We’ll use an averager to keep track of the average waiting time and the total number of cars washed.
The averager has a default constructor that resets the averager so that it is ready to accept a sequence of numbers. The sequence will be given to the averager one number at a time through a member function called *next_number*. For example, suppose that our averager is named wait_times, and the next number in the sequence is 10. Then we will activate *wait_times.next_number(10)*;. The averager also has two member functions to retrieve its results: One function returns the average of all the numbers that have been given to the averager, and the other function returns the count of how many numbers the averager has been given. Here are the four prototypes:

```cpp
averager::averager();
// Postcondition: The averager has been initialized so that it is ready to // accept a sequence of numbers to average.
void averager::next_number(double value);
// Postcondition: The averager has accepted the value as the next number // in the sequence of numbers that it is averaging.
size_t averager::how_many_numbers() const;
// Postcondition: The return value is a count of how many times // next_number has been activated.
double averager::average() const;
// Precondition: how_many_numbers() > 0.
// Postcondition: The return value is the average of all the numbers that // have been given to the averager.
```

Notice that the argument to *next_number* is actually a double number rather than an integer. This will allow us to use the averager in situations where the sequence is more than just whole numbers.


## Implementation

**Implementation of the bool_source**. The *bool_source* class has one member variable, probability, which stores the *probability* that an activation of query will return true. The implementation of the query member function first uses the rand function to generate a random number between 0 and *RAND_MAX* (including the endpoints), where *RAND_MAX* is a constant defined in `<cstdlib>`. (See the discussion of rand on page 271.) Hence, if the member variable probability is the desired probability of returning true, then query should return true provided the following relationship holds:

`rand() < probability * RAND_MAX`

For example, suppose we want a 10% chance that query returns true, so that *probability* is 0.1. If rand returns a value less than 0.1\**RAND_MAX*, then query will return true. The chance that rand returns a value less than 0.1\**RAND_MAX* is approximately 10%, since 0.1**RAND_MAX* marks a point that is approximately 10% of the way through rand’s output range. Therefore, there is about a 10% chance that the expression `rand() < 0.1 * RAND_MAX` will be true. It is this boolean expression that is used in the return statement of query.

**Implementation of the averager**. The implementation of the averager is a direct implementation of the definition of "average" and some straightforward details. The class has two member variables: one to keep track of how many numbers the averager has been given, and another to keep track of the sum of all those numbers. When the average member function is activated, the function returns the average calculated as the sum of all the numbers divided by the count of how many numbers the averager was given.

Notice that the averager does not need to keep track of all the numbers individually. It is sufficient to keep track of the sum of the numbers and the count of how many numbers there were.

**Implementation of the washer**. The washer class has two member variables. The first member variable, *seconds_for_wash*, is the number of seconds needed for one complete wash cycle. This variable is set by the constructor and remains constant thereafter. The second member variable, *wash_time_left*, keeps track of how many seconds until the current wash is completed. This value can be zero if the washer is not currently busy.

The washer’s *one_second* member function simulates one second of washing time. In our simulation, the only piece of information that might be altered by the *one_second* function is the number of seconds until the washer is no longer busy. So, the *one_second* function checks whether a car is currently being washed. And if there is a car being washed, then the function subtracts one from *wash_time_left*.

The washer’s *is_busy* function simply checks whether *wash_time_left* is greater than zero. If so, then there is a car in the washing mechanism. Otherwise, the washing mechanism is ready for another car.

When the car-washing mechanism is not busy, the *start_washing* member function may be activated to start another car through the washer. The function starts the wash by setting *wash_time_left* equal to *seconds_for_wash*.
