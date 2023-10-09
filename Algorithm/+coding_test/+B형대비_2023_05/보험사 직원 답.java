import java.io.*;
import java.util.*;

class Solution 
{
    static class Node implements Comparable <Node>{
        int time;
        int caseID;
        int prior;
        Node(int time, int caseID, int prior) {
            this.time = time;
            this.caseID = caseID;
            this.prior = prior; 
        }
        @Override
        public int compareTo(Node o) {
            if(prior > o.prior) return -1;
            if(prior < o.prior) return 1;
            if(time < o.time) return -1;
            if(time > o.time) return 1;
            return 0; 
        }
    }
    
    static int[][] MAP;
    static ArrayList<Integer>c[];
    static int[] p; 
    static ArrayList<Integer>path; 
    
    static int[] townList; 
    static int[] cancelList;
    static PriorityQueue<Node>pq; 
    
    static int now;
    static int nowpos;
    static int nextpos;
    static int flag;
    static int n;
    
    static void dfs(int node) {
        path.add(node);
        for(int i = 0; i < path.size()-1; i++) {
            MAP[node][path.get(i)] = p[node];
            MAP[path.get(i)][node] = path.get(i+1);
        }
        MAP[node][node] = node; 
        for(int i = 0; i < c[node].size(); i++) {
            int next = c[node].get(i); 
            MAP[node][next] = next;
            dfs(next); 
        }
        path.remove(path.size() - 1); 
    }
    
    public void init(int N, int[]parent) 
    {
        n = N;
        MAP = new int[N][N];
        c = new ArrayList[N];
        p = new int[N];
        pq = new PriorityQueue<>();
        path = new ArrayList<>(); 
        townList = new int[100000]; 
        cancelList = new int[100000]; 

        now = -1;
        nowpos = 0; 
        flag = 0; 
        
        for(int i = 0; i < N; i++) {
            p[i] = parent[i];
            c[i] = new ArrayList<>();
            for(int j = 0; j < N; j++) {
                if(parent[j] == i)
                    c[i].add(j);
                MAP[i][j] = -1; 
            }
        }
        
        dfs(0); 
        
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(MAP[i][j] == -1)
                    MAP[i][j] = parent[i]; 
            }
        }
    }
    
    public int step(int target) {
        now++;
        if(flag == 0 && nowpos == target) { 
            flag = 1;
            return 1; 
        }
        nowpos = MAP[nowpos][target];
        return 0; 
    }
    
    public void play(int timeStamp) {
        while(!pq.isEmpty() && now < timeStamp) {
            int caseID = pq.peek().caseID;
            if(cancelList[caseID] == 1) {
                pq.remove();
                continue;
            }
            if(step(townList[caseID]) == 1) {
                pq.remove();
                flag = 0; 
            }
        }
        now = timeStamp; 
    }
    
    public void occur(int timeStamp, int caseID, int cityID, int priority)
    {
        play(timeStamp);
        pq.add(new Node(timeStamp, caseID, priority));
        townList[caseID] = cityID; 
    }
    
    public void cancel(int timeStamp, int caseID)
    {
        play(timeStamp);
        cancelList[caseID] = 1; 
    }
    
    public int position(int timeStamp) 
    {
        play(timeStamp);
        return nowpos; 
    }
}