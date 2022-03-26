// EchlerAaronMidterm : 
// 
// Name: Aaron Echler
// Course Section (CIS 2207 N01)
// Date: 3/14/22
// 
//      Description: Implementation of the linked list datastructure. A linked list is a chain of nodes 
//	that holds data and the location of the next node. Accessing data in a linked list is sequential.  
// 
//	Benefits of a Linked List
//		* You can modify it at runtime
//		* All the data is linked and can be accessed.
//		* Inserting and Removing data is 0(1), constant time
// 
//	Disadvantages 
//		* A linked list has a time complexity of 0(n) which is linear time complexity. This means the size of the list determines how fast data is accessed.
//		  With a linked list going from Node 1 to Node 50 is relivatively quick, however when going from Node 1 to Node 10000, its going to take longer.
//  



#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <memory>
#include <cassert>

#include "ListInterface.h"
#include "PrecondViolatedExcept.h"
#include "Node.h"

template <class ItemType>
class LinkedList : public ListInterface<ItemType>
{
public:
	LinkedList();
	LinkedList(const LinkedList<ItemType>& aList);
	virtual ~LinkedList();

	/// <summary>
	///		Checks if the list is empty or not.
	/// </summary>
	/// <returns> Whether the list is empty or not. </returns>
	bool isEmpty() const;

	/// <summary>
	///		Holds the size of the linked list.
	/// </summary>
	/// <returns> Size of the list. </returns>
	int getLength() const;

	/// <summary>
	///		Insert an item at a specific location in the list.
	/// </summary>
	/// <param name="atIndex"> The index requested to store item. </param>
	/// <param name="newEntry"> Entry to be stored in the list. </param>
	/// <returns> If the entries insertion is successful or not. </returns>
	bool insert(int atIndex, const ItemType& newEntry);
	/// <summary>
	///		Remove an entry from the linked list.
	/// </summary>
	/// <param name="atIndex"> The index of the target item.</param>
	/// <returns> Whether the entry is removed successfully or not.</returns>
	bool remove(int atIndex);

	/// <summary>
	///		Clear all the data inside the linked list.
	/// </summary>
	void clear();
	
	/// <summary>
	///		Throws exception when the index is less than 0 or when the index is greater the the linked lists length.
	/// </summary>
	/// <param name="atIndex">The index the requested</param>
	/// <returns>The entry located that requested index</returns>
	ItemType getEntry(int atIndex) const throw(PrecondViolatedExcept);
	
	/// <summary>
	///		Throws exception when the index is less than 0 or when the index is greater the the linked lists length.
	/// </summary>
	/// <param name="atIndex"></param>
	/// <param name=""></param>
	/// <returns></returns>
	ItemType replace(int atIndex, const ItemType&) throw(PrecondViolatedExcept);


private:
	/// <summary>
	///		Head of the linked list.
	/// </summary>
	std::shared_ptr<Node<ItemType>> headPtr;
	/// <summary>
	///		The amount of items contained in the linked list.
	/// </summary>
	int itemCount;

	/// <summary>
	///		Finds the requested node in the linked list.
	/// </summary>
	/// <param name="atIndex"> Index of the node to search for in the list</param>
	/// <returns>Nodes Location</returns>
	std::shared_ptr<Node<ItemType>> getNodeAt(int atIndex) const;
	std::shared_ptr<Node<ItemType>> insertNode(int atIndex, std::shared_ptr<Node<ItemType>> newNodePtr, std::shared_ptr<Node<ItemType>> subChainPtr);
};

#endif // !_LINKED_LIST_H





template <class ItemType>
inline LinkedList<ItemType>::LinkedList() : itemCount(0), headPtr(nullptr)
{
}

template <class ItemType>
inline LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList)
{
	for (int i = 0; i < aList.getLength(); i++)
	{
		insert(i, aList.getEntry(i));
	}
}

template <class ItemType>
inline LinkedList<ItemType>::~LinkedList()
{
	clear();
}

template <class ItemType>
inline bool LinkedList<ItemType>::isEmpty() const
{
	return itemCount == 0;
}

template <class ItemType>
inline int LinkedList<ItemType>::getLength() const
{
	return itemCount;
}

template <class ItemType>
inline std::shared_ptr<Node<ItemType>> LinkedList<ItemType>::getNodeAt(int atIndex) const
{
	assert(atIndex >= 0 && atIndex < itemCount);
	std::shared_ptr<Node<ItemType>> curPtr = headPtr;
	for (int i = 0; i < atIndex; i++)
	{
		curPtr = curPtr->getNext();
	}

	return curPtr;
}

template <class ItemType>
inline std::shared_ptr<Node<ItemType>> LinkedList<ItemType>::insertNode(int atIndex, std::shared_ptr<Node<ItemType>> newNodePtr, std::shared_ptr<Node<ItemType>> subChainPtr)
{
	if (atIndex == 0)
	{
		newNodePtr->setNext(subChainPtr);
		subChainPtr = newNodePtr;
		itemCount++;
	}
	else
	{
		std::shared_ptr<Node<ItemType>> afterPtr = insertNode(atIndex - 1, newNodePtr, subChainPtr->getNext());
		subChainPtr->setNext(afterPtr);
		afterPtr = nullptr;
	}
	return subChainPtr;
}

template <class ItemType>
inline bool LinkedList<ItemType>::insert(int atIndex, const ItemType& newEntry)
{
	if (atIndex >= 0 && atIndex <= itemCount)
	{
		std::shared_ptr<Node<ItemType>> newNodePtr = std::make_shared<Node<ItemType>>(newEntry);
		headPtr = insertNode(atIndex, newNodePtr, headPtr);
		return true;
	}
	return false;
}

template <class ItemType>
inline bool LinkedList<ItemType>::remove(int atIndex)
{
	if (atIndex < 0 || atIndex >= itemCount)
	{
		return false;
	}
	std::shared_ptr<Node<ItemType>> nodeToDelete = nullptr;
	if (atIndex == 0)
	{
		nodeToDelete = headPtr;
		headPtr = nodeToDelete->getNext();
	}
	else
	{
		std::shared_ptr<Node<ItemType>> prevNode = getNodeAt(atIndex - 1);
		nodeToDelete = prevNode->getNext();
		prevNode->setNext(nodeToDelete->getNext());
		prevNode = nullptr;
	}
	nodeToDelete = nullptr;
	itemCount--;

	return true;
}



template <class ItemType>
inline void LinkedList<ItemType>::clear()
{
	headPtr = nullptr;
	itemCount = 0;
}

template <class ItemType>
inline ItemType LinkedList<ItemType>::getEntry(int atIndex) const throw(PrecondViolatedExcept)
{
	if (atIndex < 0 || atIndex >= itemCount)
	{
		throw PrecondViolatedExcept("getEntry() called with an empty List or invalid position");
	}
	return getNodeAt(atIndex)->getItem();
}

template <class ItemType>
inline ItemType LinkedList<ItemType>::replace(int atIndex, const ItemType& newEntry) throw(PrecondViolatedExcept)
{
	if (atIndex < 0 || atIndex >= itemCount)
	{
		throw PrecondViolatedExcept("replace() called with an empty List or invalid position");
	}
	std::shared_ptr<Node<ItemType>> nodeToReplace = getNodeAt(atIndex);
	ItemType oldEntry = nodeToReplace->getItem();
	nodeToReplace->setItem(newEntry);
	return oldEntry;
}

