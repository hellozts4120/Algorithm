package Percolation;

import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdStats;

public class PercolationStats {
	
	private double[] AverageOpenSite;
	
	public PercolationStats(int N, int T) {     // perform T independent experiments on an N-by-N grid

		if(N <= 0 || T <= 0) {
			throw new IllegalArgumentException("negative num find used!");
		}
		
		this.AverageOpenSite = RunExperiment(N, T);
	}
	
	public double mean() {   // sample mean of percolation threshold
		
		return StdStats.mean(AverageOpenSite);
	}
	
	public double stddev() { // sample standard deviation of percolation threshold
		
		return StdStats.stddev(AverageOpenSite);
	}
	
	public double confidenceLo() { // low  endpoint of 95% confidence interval
		
		double point = (this.stddev() * 1.96) / (Math.sqrt(AverageOpenSite.length));
		return this.mean() - point;
	}
	
	public double confidenceHi() { // high endpoint of 95% confidence interval
		
		double point = (this.stddev() * 1.96) / (Math.sqrt(AverageOpenSite.length));
		return this.mean() + point;
	}

	private double[] RunExperiment(int N, int T) {
		
		double[] OpenSiteNum = new double[T];
		
		for(int i = 0; i < T; i++) {
			Percolation temp = new Percolation(N);
			int count = 0;
			while(!temp.percolates()) {
				int row = StdRandom.uniform(1, N+1);
				int col = StdRandom.uniform(1, N+1);
				if(!temp.isOpen(row, col)) {
					temp.open(row, col);
					count++;
				}
			}
			OpenSiteNum[i] = ((double)count) / (N * N);
		}
		return OpenSiteNum;
	}
	
	public static void main(String[] args) {    // test client (described below)
		
		PercolationStats test = new PercolationStats(200,100);
		
		System.out.println("Experiment Complete: ");
		System.out.println();
		System.out.printf("%-20s %.20f\n", "mean():", test.mean());
		System.out.printf("%-20s %.20f\n", "stddev():", test.stddev());
		System.out.printf("%-20s %.20f\n", "confidenceLow():", test.confidenceLo());
		System.out.printf("%-20s %.20f\n", "confidenceHigh():", test.confidenceHi());
		
		PercolationStats test1 = new PercolationStats(2,10000);
		
		System.out.println("Experiment Complete: ");
		System.out.println();
		System.out.printf("%-20s %.20f\n", "mean():", test1.mean());
		System.out.printf("%-20s %.20f\n", "stddev():", test1.stddev());
		System.out.printf("%-20s %.20f\n", "confidenceLow():", test1.confidenceLo());
		System.out.printf("%-20s %.20f\n", "confidenceHigh():", test1.confidenceHi());
	}
}