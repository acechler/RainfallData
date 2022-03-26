// EchlerAaronMidterm : 
// 
// Name: Aaron Echler
// Course Section (CIS 2207 N01)
// Date: 3/14/22
// 
//      Description: This is the list interface, it is an abstract class that holds the functionality for list data structures. This class is used for the linked list.
//  
#ifndef _LIST_INTERFACE_H
#define _LIST_INTERFACE_H
#include <iostream>
template <class ItemType>
class ListInterface
{
public:
	/// <summary>
	///		Check if the list is empty or not.
	/// </summary>
	/// <returns> whether the list is empty or not. </returns>
	virtual bool isEmpty() const = 0;

	/// <summary>
	///		Retrieve the total amount of items in the list.
	/// </summary>
	/// <returns> The amount of items in the list </returns>
	virtual int getLength() const = 0;
	
	/// <summary>
	///		Adds item at a target location in the list.
	/// </summary>
	/// <param name="atIndex"> Index where the item is stored. </param>
	/// <param name="newEntry"> The item to be placed in the list. </param>
	/// <returns> Whether the insertion of the item into the list is succesful or not. </returns>
	virtual bool insert(int atIndex, const ItemType& newEntry) = 0;

	/// <summary>
	///		Removes a target Item from a specific index in this list
	/// </summary>
	/// <param name="atIndex">The index of the target. </param>
	/// <returns> Whether the removal of the item is successful or not. </returns>
	virtual bool remove(int atIndex) = 0;

	/// <summary>
	///		Clears out all the items in this list.
	/// </summary>
	virtual void clear() = 0;

	/// <summary>
	///		Retrieve an item at the requested index.
	/// </summary>
	/// <param name="atIndex"> The index of the target item. </param>
	/// <returns> The target item. </returns>
	virtual ItemType getEntry(int atIndex) const = 0;

	/// <summary>
	///		Replace an item at a specific location in the list.
	/// </summary>
	/// <param name="atIndex"> The index where the requested item is to be stored.</param>
	/// <param name="newEntry"> The item to be stored </param>
	/// <returns> The replaced item. </returns>
	virtual ItemType replace(int atIndex, const ItemType& newEntry) = 0;

	
	/// <summary>
	///		Destroy object and release memory.
	/// </summary>
	virtual ~ListInterface() {}
};
#endif
