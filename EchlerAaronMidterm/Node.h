
// EchlerAaronMidterm : 
// 
// Name: Aaron Echler
// Course Section (CIS 2207 N01)
// Date: 3/14/22
// 
//      Description: This class is an implementation of a Node. Nodes act as a container for data inside a linked list. Nodes also contain the location 
// of the next node in the sequence of a linked list.
//  


#ifndef _NODE_H
#define _NODE_H

#include <memory>

template <class ItemType>
class Node
{
private:
	/// <summary>
	///		The item located in the node
	/// </summary>
	ItemType item;

	/// <summary>
	///		Address for the next node.
	/// </summary>
	std::shared_ptr<Node<ItemType>> next;
public:
	/// <summary>
	///		Default Constructor
	/// </summary>
	Node();
	/// <summary>
	///		Constructor that stores item reference in the node.
	/// </summary>
	/// <param name="anItem"> The item reference to be stored in this node. </param>
	Node(const ItemType& anItem);
	
	/// <summary>
	///		Constructor that stores item reference and next node location.
	/// </summary>
	/// <param name="anItem"> The item reference to be stored in the node </param>
	/// <param name="nextNodePtr"> Location of the next node for the list. </param>
	Node(const ItemType& anItem, std::shared_ptr<Node<ItemType>> nextNodePtr);
	
	/// <summary>
	///		Sets item reference for this node.
	/// </summary>
	/// <param name="anItem"> The item reference to be added to this node.</param>
	void setItem(const ItemType& anItem);

	/// <summary>
	///		Set the next nodes location
	/// </summary>
	/// <param name="nextNodePtr"> Next nodes location </param>
	void setNext(std::shared_ptr<Node<ItemType>> nextNodePtr);
	
	/// <summary>
	///		Get the Item reference stored in this node.
	/// </summary>
	/// <returns> The item reference. </returns>
	ItemType getItem() const;
	
	/// <summary>
	///		Retrieve the next node
	/// </summary>
	/// <returns></returns>
	std::shared_ptr<Node<ItemType>> getNext() const;
	virtual ~Node();
};

#endif

template <class ItemType>
inline Node<ItemType>::Node() : next(nullptr)
{

}

template <class ItemType>
inline Node<ItemType>::Node(const ItemType& anItem) : item(anItem), next(nullptr)
{

}

template <class ItemType>
inline Node<ItemType>::Node(const ItemType& anItem, std::shared_ptr<Node<ItemType>> nextNodePtr) : item(anItem), next(nextNodePtr)
{

}

template <class ItemType>
inline void Node<ItemType>::setItem(const ItemType& anItem)
{
	item = anItem;
}

template <class ItemType>
inline void Node<ItemType>::setNext(std::shared_ptr<Node<ItemType>> nextNodePtr)
{
	next = nextNodePtr;
}

template <class ItemType>
inline ItemType Node<ItemType>::getItem() const
{
	return item;
}

template <class ItemType>
inline std::shared_ptr<Node<ItemType>> Node<ItemType>::getNext() const
{
	return next;
}

template <class ItemType>
inline Node<ItemType>::~Node()
{
}