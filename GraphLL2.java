import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class GraphLL2 {
        public static void main(String[] args) {
            
            int tv,te; 
            Scanner scr  = new Scanner(System.in); 
            System.out.println("How many Vertex? ");
            tv= scr.nextInt();//6 
            System.out.println("How many Edges? ");
            te = scr.nextInt();//8
           
             Graph g = new Graph(tv,te); 
           

             for(int i=1;i<=g.totalEdges;i++){
                System.out.println("Enter Source And Destination");

                Edge e1= new Edge(); 
                e1.src = scr.nextInt();  //1   1   1 
                e1.dest = scr.nextInt(); //2   4   5 

                Edge e2 = new Edge();
                e2.src = e1.dest;
                e2.dest = e1.src; 
                
                g.edges.add(e1);
                g.edges.add(e2);
                
             }

             //DFS 
             //BFS 



            
            
    }
}

class Graph{
       int totalVertex;//6 
       int totalEdges; //8 
        //src:1 
        //dest:2 
       ArrayList<Edge> edges;
        HashMap<Integer,Boolean> visited = new HashMap<>(); 
            
       Graph(int tv,int te){
            this.totalVertex = tv;
            this.totalEdges = te; 
            this.edges = new ArrayList<>(this.totalEdges*2);//8*2 
       }

       void dfs(int initialVertex){//1  2   3  4 
            if(visited.size() == totalVertex){

            }else{ 
            System.out.println(initialVertex);//1  2   3  4 
            visited.put(initialVertex,true); //1   2   3  4 
            int x = initialVertex; //1  2  3  4 
            for(Edge e:this.edges){ // 16times 
                if(e.src == x  && visited.get(e.dest) == null ){
                    x = e.dest; // 2  3  4 
                    dfs(x); //2  3  4 
                }
            }
        }
       }


}

class Edge{
    int src;//1 1 1 
    int dest; //2 4 5 
}
