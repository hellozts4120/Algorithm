package RandomizedQueuesAndDeques;

import java.util.Iterator;

public class RandomizedQueue<Item> implements Iterable<Item> {
	
	private Item items[];
	private int size;
	
	@SuppressWarnings("unchecked")
	public RandomizedQueue() {	// construct an empty randomized queue
		   
		this.items = (Item[]) new Object[2];
		this.size = 0;
	}
	   
	public boolean isEmpty() {	// is the queue empty?
		 
		return (this.size == 0);
	}
	   
	public int size() {		// return the number of items on the queue
		   
		return this.size;
	}
	   
	public void enqueue(Item item) {		// add the item
		   
		if (item == null) {
            throw new NullPointerException("Item is null!");  
		}
		if(this.size == items.length){
			resize(this.size * 2);
		}
		items[size++] = item;
	}
	   
	public Item dequeue() {		// remove and return a random item
		   
		if (isEmpty()) {
            throw new java.util.NoSuchElementException("Queue is null!");  
		}
		
		int randomNum = (int)(Math.random() * this.size);
		Item returnItem = this.items[randomNum];
		if(randomNum != this.size - 1) {
			this.items[randomNum] = this.items[this.size - 1];
		}
		this.size--;
		if((this.size > 0) && (this.size == items.length/4)) {
			resize(items.length / 2);
		}
		return returnItem;
	}
	   
	public Item sample() {		// return (but do not remove) a random item
		   
		if (isEmpty()) {
            throw new java.util.NoSuchElementException("Queue is null!");  
		}
		int randomNum = (int)(Math.random() * this.size);
		Item returnItem = this.items[randomNum];
		return returnItem;
	}
	   
	public Iterator<Item> iterator() {	// return an independent iterator over items in random order
		   
		return new ListIterator();
	}
	   
	public static void main(String[] args) {		// unit testing
		   
	}
	
	@SuppressWarnings("unchecked")
	private void resize(int n) {
		
		Item newItems[] = (Item[]) new Object[n]; 
		for(int i = 0; i < size; i++) {
			newItems[i] = items[i];
		}
		this.items = newItems;
	}
	
	private class ListIterator<Item> implements Iterator {

		int index;
		
		public ListIterator() {
			
			this.index = 0;
		}
		
		@Override
		public boolean hasNext() {
			// TODO Auto-generated method stub
			return (index < size);
		}

		@Override
		public Object next() {
			// TODO Auto-generated method stub
			if (!hasNext()) { 
                throw new java.util.NoSuchElementException(); 
			}
			int randomNum = (int)(Math.random() * (size - index));
			Object item = items[randomNum];
			if(randomNum != size-index-1) {  
                items[randomNum] = items[size-index-1];  
			}
            index++;  
            return item;
		}  
		
	}
}
