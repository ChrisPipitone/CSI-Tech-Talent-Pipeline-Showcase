#include"sequence.h"

template<class value_type>
sequence<value_type>::sequence()
{
	capacity = 10;
	data = new value_type[10];
	num_used = 0;
}

template<class value_type>
sequence<value_type>::sequence(int size) 
{ 	
	capacity = size; 
	data = new value_type[capacity];
	num_used = 0;
}
template<class value_type>
sequence<value_type>::~sequence(){ delete[] data; }

template<class value_type>
bool sequence<value_type>::full() const
{ 
	assert(num_used <= capacity);

	if (num_used == capacity )
		return true;
	else 
		return false;
}

template<class value_type>
bool sequence<value_type>::empty()const
{
	assert(num_used >= 0);
	if (num_used == 0)
		return true;
	else
		return false;
}

template<class value_type>
int sequence<value_type>::num_element()const { return num_used; }

template<class value_type>
int sequence<value_type>::max_capacity()const { return capacity; }

template<class value_type>
value_type sequence<value_type>::at(int position) const
{
	//ensure the position is within bounds of data array
	assert(position >= 0 && position <= num_used-1);
	return data[position];
}

template<class value_type>
void sequence<value_type>::set(const value_type& entry, int position)
{
	//overwrite an element at a given position 
	//must already be an element present in array 
	//cannot be used to initalize a position
	assert(position >= 0 && position <= num_used-1);
	data[position] = entry;
}

template<class value_type>
void sequence<value_type>::push_back(const value_type& entry)
{
	//part B
	if (full())
		doubleSize();
	data[num_used] = entry;
	num_used++;
}

template<class value_type>
void sequence<value_type>::insert(const value_type& entry, int position)
{
	//part B
	if (full())
		doubleSize();

	//ensure position is in the bounds of the array and
	//its current used area
	assert(position >= 0 && position <= num_used-1);

	//determine size of data that is after the insertion point
	int tempCapacity = num_used - position;
	value_type* temp = new value_type[tempCapacity];
	
	//fill with the area of data that is after the insertion point
	for(int i = 0; i < tempCapacity; i++)
	{
		temp[i] = data[position + i];
	}
	
	//insert entry
	data[position] = entry;

	//an entry added to the array
	num_used++;

	//shift elements over by one 
	int j = 0;
	for (int i = position + 1; i < num_used; i++)
	{
		data[i] = temp[j];
		j++;
	}

	delete[] temp;
}

template<class value_type>
void sequence<value_type>::remove_current(int position)
{
	//ensure position is in the bounds of the array and
	//its used area
	assert(position >= 0 && position <= num_used - 1);

	//overwrite the position with 
	for (int i = position; i < num_used-1; i++)
	{
		data[i] = data[i + 1];
	}
	num_used--;
}

template<class value_type>
void sequence<value_type>::print()const
{
	//used the classes own methods for data output for testing purposes
	if (empty())
		std::cout << "This sequence is empty\n";
	if (full())
		std::cout << "This sequence is full\n";

	std::cout << "number of elements: " << num_element() << std::endl;
	std::cout << "max capacity: " << max_capacity() << std::endl;

	//display contents
	std::cout << "contents:\n";
	for (int i = 0; i < num_used; i++)
	{
		std::cout << data[i] << " | ";
	}
	std::cout << std::endl;
}

//private
template<class value_type>
void sequence<value_type>::doubleSize()
{
	int newCapacity = capacity * 2;
	value_type* temp = new value_type[newCapacity];

	//copy data from data array to new location in memory
	//that has double the size allocated
	for (int i = 0; i < capacity; i++)
	{
		temp[i] = data[i];
	}

	//delete old dynamic data
	delete[] data;

	//have data array point to its new location in memory
	//and prevent dangling pointer 
	data = temp;
	temp = NULL;
	
	capacity = newCapacity;
	//num_used remains the same
}