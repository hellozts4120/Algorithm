package RandomizedQueuesAndDeques;

import java.util.Iterator;  

public class Deque<Item> implements Iterable<Item> {
	
	private Node first;
	private Node last;
	private int size;
	
	public Deque() { 	// construct an empty deque
		   
		this.first = null;
		this.last = null;
		this.size = 0;
	}
	   
	public boolean isEmpty() { 	// is the deque empty?
		
		return (this.size == 0);
	}
	   
	public int size() {		// return the number of items on the deque
		
		return this.size;
	}
	   
	public void addFirst(Item item) {	// add the item to the front
		
		if(item == null) {
			throw new NullPointerException("Item found null!");
		}
		
		if(this.size == 0) {
			Node newNode = new Node();
			newNode.i = item;
			newNode.back = null;
			newNode.front = null;
			this.first = newNode;
			this.last = newNode;
			this.size++;
		}
		else {
			Node newNode = new Node();
			newNode.i = item;
			newNode.back = this.first;
			newNode.front = null;
			this.first.front = newNode;
			this.first = newNode;
			this.size++;
		}
	}
	   
	public void addLast(Item item) {		// add the item to the end
		
		if(item == null) {
			throw new NullPointerException("Item found null!");
		}
		
		if(this.size == 0) {
			Node newNode = new Node();
			newNode.i = item;
			newNode.back = null;
			newNode.front = null;
			this.first = newNode;
			this.last = newNode;
			this.size++;
		}
		else {
			Node newNode = new Node();
			newNode.i = item;
			newNode.front = this.last;
			newNode.back = null;
			this.last.back = newNode;
			this.last = newNode;
			this.size++;
		}
	}
	   
	public Item removeFirst() {		// remove and return the item from the front
		   
		if(isEmpty()) {
			throw new java.util.NoSuchElementException("Deque is empty!");
		}
		
		if(this.size == 1) {
			Item item = this.first.i;
			this.first = null;
			this.last = null;
			this.size--;
			return item;
		}
		else {
			Item item = this.first.i;
			this.size--;
			Node temp = this.first.back;
			first.back.front = null;
			first.back = null;
			first = temp;
			return item;
		}
	}
	   
	public Item removeLast() {	// remove and return the item from the end
		   
		if(isEmpty()) {
			throw new java.util.NoSuchElementException("Deque is empty!");
		}
		
		if(this.size == 1) {
			Item item = this.first.i;
			this.first = null;
			this.last = null;
			this.size--;
			return item;
		}
		else {
			Item item = this.last.i;
			this.size--;
			Node temp = this.last.front;
			last.front.back = null;
			last.front = null;
			last = temp;
			return item;
		}
	}
	   
	public Iterator<Item> iterator() {	// return an iterator over items in order from front to end
		   
		return new ListIterator();
	}
	   
	public static void main(String[] args) {		// unit testing
		   
	}
	
	private class Node {
		
		private Node front;
		private Node back;
		private Item i;
		
	}
	
	private class ListIterator implements Iterator<Item> { 
		
		private Node ptr;
		private Item i;
		
		@Override
		public boolean hasNext() {
			// TODO Auto-generated method stub
			if(ptr == null) {
				return false;
			}
			return true;
		}
		
		@Override
		public Item next() {
			// TODO Auto-generated method stub
			if(!hasNext()) {
				throw new java.util.NoSuchElementException();
			}
			else {
				i = ptr.i;
				ptr = ptr.back;
				return i;
			}
		}
	}
}
