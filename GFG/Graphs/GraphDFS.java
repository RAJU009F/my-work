import java.io.*;
import java.lang.*;
import java.util.*;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/Graphs
# Problem Statement	: Longest consecutive char path
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

class GraphDFS
{
	private int V;
	private LinkedList<Integer> adj[];

	GraphDFS (int v)
	{
		V = v;
		adj = new LinkedList[V];
		for(int i=0; i<V; i++)
			{
				adj[i] = new LinkedList();
			}
	}
	
	public void addEdge(int v,  int w)
	{
		adj[v].add(w);
		
	}
	
	public void DFSUtil(int v, boolean visited[])
	{
		visited[v] = true;
		System.out.println(v+" ");
		Iterator<Integer> i = adj[v].listIterator();
		while(i.hasNext())
		{
			int u = i.next();
			if(!visited[u])
			{DFSUtil(u, visited);
		   }
			
		}
		
		System.out.println("\n");
	}
	public void DFS()
	{
		boolean[] visited=  new boolean[V];
		for(int i=0; i<V; i++)
			visited[i] = false;
		
		 for(int i=0; i<V; i++)
		 {
			 if(!visited[i])
			 DFSUtil(i, visited);
			
		 }
		
	}
	
	public static void main(String args[])
	{
		GraphDFS g  =  new GraphDFS(4);
		//g.addEdge(0,1);
		
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(2, 0);
        g.addEdge(2, 3);
        g.addEdge(3, 3);
		
		g.DFS();
		
	}

}