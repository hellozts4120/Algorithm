package puzzle8;

import edu.princeton.cs.algs4.Stack;

public class Board {
	
	private int[] board;
	private int pHamming, pManhattan;
	private int n, blankPos;
	
	public Board() {
		//null constructor
	}
	
    public Board(int[][] blocks) {
    	// construct a board from an N-by-N array of blocks
    	// (where blocks[i][j] = block in row i, column j)
    	this.n = blocks.length;
    	this.pHamming = 0;
    	this.pManhattan = 0;
    	int curPos = 0;
    	board = new int[n * n];
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < n; j++) {
    			board[curPos] = blocks[i][j];
    			if (board[curPos] == 0) {
    				blankPos = curPos;
    			}
    			curPos++;
    		}
    	}
    }
                                           
    public int dimension() {
    	// board dimension N
    	return this.n;
    }
    
    public int hamming() {
    	// number of blocks out of place
    	this.pHamming = 0;
    	for (int i = 0; i < n * n - 1; i++) {
    		if (i + 1 != this.board[i]) {
    			this.pHamming++;
    		}
    	}
    	return this.pHamming;
    }
    
    public int manhattan() {
    	// sum of Manhattan distances between blocks and goal
    	this.pManhattan = 0;
    	for (int i = 0; i < n * n; i++) {
    		if (board[i] == 0 || (i + 1 == this.board[i])) continue;
    		int rowDis = ceiling(board[i], this.n) - ceiling(i + 1, this.n);
    		if (rowDis < 0) {
    			rowDis *= -1;
    		}
    		int colDis = ((board[i] - 1) % this.n) - (i % this.n);
    		if (colDis < 0) {
    			colDis *= -1;
    		}
    		this.pManhattan += (colDis + rowDis);
    	}
    	return this.pManhattan;
    }
    
    private int ceiling(int pos, int size) {
    	int ceil = pos / size;
    	if (pos % size != 0) {
    		ceil++;
    	}
    	return ceil;
    }
    
    public boolean isGoal() {
    	// is this board the goal board?
    	for (int i = 0; i < n * n - 1; i++) {
    		if (i + 1 != this.board[i]) {
    			return false;
    		}
    	}
    	return true;
    }
    
    public Board twin() {
    	// a board that is obtained by exchanging any pair of blocks
    	Board twinBoard = new Board();
    	twinBoard.board = new int [n * n];
    	twinBoard.n = this.n;
    	for (int i = 0; i < n * n; i++) {
    		twinBoard.board[i] = this.board[i];
    		if (this.board[i] == 0) twinBoard.blankPos = i;
    		if (twinBoard.blankPos < 2) {
    			int exch = twinBoard.board[this.n];
    			twinBoard.board[this.n] = twinBoard.board[this.n + 1];
    			twinBoard.board[this.n + 1] = exch;
            } else {
                int exch = twinBoard.board[0];
                twinBoard.board[0] = twinBoard.board[1];
                twinBoard.board[1] = exch;
            }
    	}
    	return twinBoard;
    }
    
    public boolean equals(Object y) {
    	// does this board equal y?
    	if (this == y) {
    		return true;
    	}
    	if (!(y instanceof Board)) {
    		return false;
    	}
    	Board tempBoard = (Board)y;
    	if (tempBoard.n != this.n || tempBoard.pHamming != this.pHamming ||
    			tempBoard.pManhattan != this.pManhattan) {
    		return false;
    	}
    	for (int i = 0; i < n * n - 1; i++) {
    		if (tempBoard.board[i] != this.board[i]) {
    			return false;
    		}
    	}
    	return true;
    }
    
    public Iterable<Board> neighbors() {
    	// all neighboring boards
    	Stack<Board> neighbors = new Stack<Board>();
    	if (this.blankPos + 1 < this.n && (this.blankPos + 1) / this.n ==
    		this.blankPos / this.n) {
    		neighbors.push(makeNeighbor(this.blankPos + 1));
    	}
    	if (this.blankPos - 1 >= 0 && (this.blankPos - 1) / this.n ==
        		this.blankPos / this.n) {
    		neighbors.push(makeNeighbor(this.blankPos - 1));
    	}
    	if (this.blankPos + this.n < this.n * this.n) {
    		neighbors.push(makeNeighbor(this.blankPos + this.n));
    	}
    	if (this.blankPos - this.n >= 0) {
    		neighbors.push(makeNeighbor(this.blankPos - this.n));
    	}
    	return neighbors;
    }
    
    private Board makeNeighbor(int newBlankPos) {
        Board neighbor = new Board();
        neighbor.blankPos = newBlankPos;
        neighbor.n = n;
        neighbor.board = new int[n * n];
        for (int i = 0; i < n * n; i++) {
            if (i == this.blankPos) {
            	neighbor.board[i] = board[newBlankPos];
            }
            else if (i == newBlankPos) {
            	neighbor.board[i] = board[this.blankPos];
            }
            else {
            	neighbor.board[i] = board[i];
            }
        }
        return neighbor;
    }
    
    public String toString() {
    	// string representation of this board (in the output format specified below)
    	StringBuilder builder = new StringBuilder();
    	int index = 0;
    	builder.append(this.n + "\n");
    	for (int i = 0; i < this.n; i++) {
    		for (int j = 0; j < this.n; j++) {
    			builder.append(String.format("%2d ", this.board[index++]));
    		}
    		builder.append("\n");
    	}
    	return builder.toString();
    }

    public static void main(String[] args) {
    	// unit tests (not graded)
    	int n = 3;
        int[][] blocks3 = new int[][] {new int []{8,1,3}, new int [] {4,0,2}, new int []{7,6,5}};
        Board board = new Board(blocks3);
        System.out.printf("Manhatten %d, Hamming %d\n", board.manhattan(), board.hamming());
        System.out.println(board);
        for (Board b : board.neighbors()) {
            System.out.println("Neighbor");
            System.out.printf("Manhatten %d, Hamming %d\n", b.manhattan(), b.hamming());
            System.out.println(b);
        }
        System.out.println("Original Board");
        System.out.printf("Manhatten %d, Hamming %d\n", board.manhattan(), board.hamming());
        System.out.println(board);
        System.out.println("Twin Board");
        Board twin = board.twin();
        System.out.printf("Manhatten %d, Hamming %d\n", twin.manhattan(), twin.hamming());
        System.out.println(twin);
        int[][] blocks2 = new int[][] {new int []{1,2}, new int [] {3,0}};
        Board board00 = new Board(blocks2);
        System.out.printf("Manhatten %d, Hamming %d\n", board00.manhattan(), board00.hamming());
        System.out.println(board00);
    }
    
}
