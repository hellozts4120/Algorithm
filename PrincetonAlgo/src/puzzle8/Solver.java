package puzzle8;

import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.Stack;
import edu.princeton.cs.algs4.MinPQ;

public class Solver {
	
	private boolean isSolvable;
	private Node ansNode;
	private Board prevBoard, prevTwinBoard;
	
    public Solver(Board initial) {
    	// find a solution to the initial board (using the A* algorithm)
    	if (initial == null) {
    		throw new java.lang.NullPointerException("initial board found to be null!");
    	}
    	MinPQ<Node> minPQ = new MinPQ<Node>();
    	MinPQ<Node> minTwinPQ = new MinPQ<Node>();
    	minPQ.insert(new Node(initial));
    	minTwinPQ.insert(new Node(initial.twin()));
    	Node solution;
    	this.isSolvable = false;
    	do {
    		solution = BFS(minPQ, true);
    		if (solution != null) {
    			isSolvable = true;
    			this.ansNode = solution;
    		}
    		else {
    			solution = BFS(minTwinPQ, false);
    		}
    	} while (solution == null);
    }
    
    private Node BFS(MinPQ<Node> mPQ, boolean status) {
    	Node minNode = mPQ.delMin();
    	if (minNode.board.isGoal()) return minNode;
    	for (Board neighbor : minNode.board.neighbors()) {
    		if (status && this.prevBoard != null && 
    				this.prevBoard.equals(neighbor)) {
    			continue;
    		}
    		if (!status && this.prevTwinBoard != null && this.prevTwinBoard != null
    				&& this.prevTwinBoard.equals(neighbor)) {
    			continue;
    		}
    		mPQ.insert(new Node(neighbor, minNode));
    	}
    	if (status) {
    		this.prevBoard = minNode.board;
    	}
    	else {
    		this.prevTwinBoard = minNode.board;
    	}
    	return null;
    }
    
    public boolean isSolvable() {
    	// is the initial board solvable?
    	return this.isSolvable;
    }
    
    public int moves() {
    	// min number of moves to solve initial board; -1 if unsolvable
    	return isSolvable ? this.ansNode.moveNum : -1;
    }
    
    public Iterable<Board> solution() {
    	// sequence of boards in a shortest solution; null if unsolvable
    	if (!this.isSolvable) return null;
    	Node curNode = this.ansNode;
    	Stack<Board> solutionStack =  new Stack<Board>();
    	solutionStack.push(curNode.board);
    	while (curNode.preNode != null) {
    		curNode = curNode.preNode;
    		solutionStack.push(curNode.board);
    	}
    	return solutionStack;
    }
    
    private static class Node implements Comparable {
    	private Board board;
    	private int moveNum = 0;
    	private Node preNode;
    	
    	private Node(Board b) {
    		this.board = b;
    	}
    	
    	private Node(Board b, Node n) {
    		this.board = b;
    		this.preNode = n;
    		this.moveNum += n.moveNum;
    		this.moveNum++;
    	}
    	
    	@Override
    	public int compareTo(Object o) {
    		Node that = (Node)o;
    		int manhattanDiff = (this.board.manhattan() + this.moveNum) - 
    				(that.board.manhattan() + that.moveNum);
    		if (manhattanDiff == 0) {
    			return (this.board.hamming() + this.moveNum) - (that.board.hamming()
    					 + that.moveNum);
    		}
    		else {
    			return manhattanDiff;
    		}
    	}
    }
    
    public static void main(String[] args) {
    	// solve a slider puzzle (given below)
    	// create initial board from file
        In in = new In(args[0]);
        int N = in.readInt();
        int[][] blocks = new int[N][N];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                blocks[i][j] = in.readInt();
        Board initial = new Board(blocks);

        // solve the puzzle
        Solver solver = new Solver(initial);

        // print solution to standard output
        if (!solver.isSolvable())
            StdOut.println("No solution possible");
        else {
            StdOut.println("Minimum number of moves = " + solver.moves());
            for (Board board : solver.solution())
                StdOut.println(board);
        }
    }
    
}