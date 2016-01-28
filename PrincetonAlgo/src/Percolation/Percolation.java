package Percolation;
import edu.princeton.cs.algs4.WeightedQuickUnionUF;

public class Percolation {
	
	private int maxSize;
	private boolean Grid[][];
	private WeightedQuickUnionUF UnionFind;
	private WeightedQuickUnionUF siteStore;
	private int topSite;
	private int bottomSite;
	private int sitesNum;
	
	
	public Percolation(int N) { // create N-by-N grid, with all sites blocked
		
		if(N <= 0) {
			throw new IllegalArgumentException("Grid cannot be initalized with a negative value");
		}
		
		this.maxSize = N;
		this.Grid = new boolean[N][N];
		this.sitesNum = N * N;
		this.topSite = this.sitesNum;
		this.bottomSite = this.sitesNum + 1;
		this.UnionFind = new WeightedQuickUnionUF((sitesNum + 2));
		this.siteStore = new WeightedQuickUnionUF((sitesNum + 1));
		
		for(int i = 0; i < maxSize; i++) {
			//the top row's sites are assumed to be connected, so are the bottom row's sites;
			this.UnionFind.union(i, topSite);
			this.siteStore.union(i, topSite);
			this.UnionFind.union(sitesNum - (1 + i), bottomSite);
		}
		
	}
	
	public void open(int i, int j) {          // open site (row i, column j) if it is not open already
	
		int row = i - 1;
		int col = j - 1;
		if(row < 0 || row > maxSize-1 || col < 0 || col > maxSize-1) {
			throw new IndexOutOfBoundsException("find parameter out of bounds!");
		}
		
		this.Grid[row][col] = true;
		
		if(row-1 >= 0 && Grid[row-1][col]) {
			this.UnionFind.union(getIndex(row-1, col), getIndex(row, col));
			this.siteStore.union(getIndex(row-1, col), getIndex(row, col));
		}
		
		if(row+1 < maxSize && Grid[row+1][col]) {
			this.UnionFind.union(getIndex(row+1, col), getIndex(row, col));
			this.siteStore.union(getIndex(row+1, col), getIndex(row, col));
		}
		
		if(col-1 >= 0 && Grid[row][col-1]) {
			this.UnionFind.union(getIndex(row, col-1), getIndex(row, col));
			this.siteStore.union(getIndex(row, col-1), getIndex(row, col));
		}
		
		if(col+1 < maxSize && Grid[row][col+1]) {
			this.UnionFind.union(getIndex(row, col+1), getIndex(row, col));
			this.siteStore.union(getIndex(row, col+1), getIndex(row, col));
		}
	}
	
	public boolean isOpen(int i, int j) {     // is site (row i, column j) open?
		
		if(i <= 0 || i > maxSize || j <= 0 || j > maxSize) {
			throw new IndexOutOfBoundsException("find parameter out of bounds!");
		}
		return this.Grid[i-1][j-1];
	}
	
	public boolean isFull(int i, int j) {     // is site (row i, column j) full?
		
		if(i <= 0 || i > maxSize || j <= 0 || j > maxSize) {
			throw new IndexOutOfBoundsException("find parameter out of bounds!");
		}
		if(!isOpen(i, j)) {
			return false;
		}
		return siteStore.connected(topSite, getIndex(i-1, j-1));
	}
	
	public boolean percolates() {             // does the system percolate?

		return this.UnionFind.connected(topSite, bottomSite);
	}
	
	private int getIndex(int i, int j) { 	//method to get the index of specific site;
		
		return maxSize * i + j;
	}
	
	public static void main(String[] args) {  // test client (optional)
		
		Percolation perc = new Percolation(4);
		
		perc.open(4, 1);
		perc.open(3, 1);
		System.out.println(perc.percolates());
		perc.open(2, 1);
		System.out.println(perc.percolates());
		perc.open(1, 2);
		System.out.println(perc.percolates());
		System.out.println(perc.isOpen(1, 2));
		System.out.println(perc.isFull(3, 1));
		perc.open(1, 1);
		System.out.println(perc.percolates());
		
		Percolation perc1 = new Percolation(4);
		
		//perc1.open(1, 1);
		System.out.println(perc1.percolates());
	}
}