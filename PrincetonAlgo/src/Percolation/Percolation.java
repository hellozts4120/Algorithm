package Percolation;
import edu.princeton.cs.algs4.WeightedQuickUnionUF;

public class Percolation {
	
	private int maxSize;
	private boolean Grid[][];
	WeightedQuickUnionUF UnionFind;
	int topSite;
	int bottomSite;
	int sitesNum;
	
	
	public Percolation(int N){ // create N-by-N grid, with all sites blocked
		if(N < 0){
			throw new IllegalArgumentException("Grid cannot be initalized with a negative value");
		}
		
		this.maxSize = N;
		this.Grid = new boolean[N][N];
		this.sitesNum = N * N;
		this.UnionFind = new WeightedQuickUnionUF(sitesNum + 1);
		
		
	}
	
	public void open(int i, int j){          // open site (row i, column j) if it is not open already
	
	}
	
	public boolean isOpen(int i, int j){     // is site (row i, column j) open?
	
		return false;
	}
	
	public boolean isFull(int i, int j){     // is site (row i, column j) full?
		
		return false;
	}
	
	public boolean percolates(){             // does the system percolate?

		return false;
	}
	
	public static void main(String[] args){  // test client (optional)
		
	}
}